/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:10:13 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/14 17:07:50 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	char	*p;
	int		lens1;
	int		lens2;
	int		i;

	if (!s1 && !s2)
		return ((void *)0);
	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	if (s1 && !s2)
		return (ft_strdup((char *)s1));
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	p = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!p)
		return ((void *)0);
	i = 0;
	ft_memcpy(p, s1, lens1);
	ft_memcpy(&p[lens1], s2, lens2);
	p[lens1 + lens2] = '\0';
	return (p);
}

int	ft_strncmp_pipex(const char *s1, const char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;

	if (s1 == NULL || s2 == NULL)
		return (1);
	while (n-- > 0)
	{
		str1 = (unsigned char) *s1;
		str2 = (unsigned char) *s2;
		if (str1 > str2)
			return (1);
		if (str1 < str2)
			return (-1);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_stdin(char **argv, char *buf, char *ret)
{
	char	bufc[2];
	char	*tmp;

	tmp = NULL;
	bufc[1] = '\0';
	while (!buf || ft_strncmp_pipex(buf, argv[2], ft_strlen(argv[2])))
	{
		tmp = ret;
		ret = ft_strjoin_bonus (ret, buf);
		free (tmp);
		free (buf);
		buf = NULL;
		bufc[0] = '\0';
		ft_putstr_fd("heredoc> ", 1);
		while (bufc[0] != '\n')
		{
			read (0, &bufc[0], 1);
			tmp = buf;
			buf = ft_strjoin_bonus(buf, bufc);
			free (tmp);
		}
	}
	free (buf);
	return (ret);
}

int	here_doc(t_fd fd, char ***argv, int argc)
{
	char	*input;
	int		i;

	input = ft_stdin(*argv, NULL, NULL);
	if (pipe(fd.pipefd) == -1)
		error_exit("fork fail", 1);
	fd.id = fork();
	if (fd.id == 0)
	{
		close(fd.pipefd[0]);
		write(fd.pipefd[1], input, ft_strlen(input));
		close(fd.pipefd[1]);
		free(input);
		exit(1);
	}
	close(fd.pipefd[1]);
	i = 1;
	while (argc - 1)
	{
		(*argv)[i] = (*argv)[i + 1];
		i++;
		argc--;
	}
	return (fd.pipefd[0]);
}

int	ft_norma_strok(int argc, char **argv, t_fd fd, char **envp)
{
	int	ret;

	ret = 0;
	if (dup2(fd.fd1, 0) == -1)
		error_exit("dup fail", 1);
	close (fd.fd1);
	while (fd.count <= argc - 4)
		ft_fork(&fd, argc, argv, envp);
	while (fd.pid > 0)
	{
		fd.pid = wait(&(fd.status));
		if (fd.pid == fd.id)
			ret = fd.status;
	}
	return (WEXITSTATUS(ret));
}
