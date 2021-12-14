/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:41:13 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/14 20:44:11 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_exit(char *message, int errorcode)
{
	perror(message);
	exit(errorcode);
}

void	free_split(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
}

static void	show_me_the_file(t_fd *fd, char **argv, int argc)
{
	if (fd->here_doc == 0)
		fd->fd2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		fd->fd2 = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	fd->flag = 0;
	if (access(argv[argc - 1], W_OK) == -1)
		error_exit("access denied", 1);
}

void	ft_fork(t_fd *fd, int argc, char **argv, char **envp)
{
	if (fd->count < argc - 4)
	{
		if (pipe(fd->pipefd) == -1)
			error_exit("pipe fail", 1);
		fd->flag = 1;
	}
	else
		show_me_the_file(fd, argv, argc);
	fd->id = fork();
	if (fd->id == -1)
		error_exit ("fork fail", 1);
	else if (fd->id == 0)
		child_process (fd, argv[fd->count + 2], envp);
	if (fd->count < argc - 4)
	{
		close (fd->pipefd[1]);
		dup2 (fd->pipefd[0], 0);
		close (fd->pipefd[0]);
	}
	else
		close (0);
	fd->count++;
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	int		ret;

	ret = 0;
	fd.pid = 1;
	fd.count = 0;
	if (argc < 5)
	{
		ft_putstr_fd("Not enough arguments\n", 1);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc-- < 6)
		{
			ft_putstr_fd("Not enough arguments\n", 1);
			exit(1);
		}
		fd.here_doc = 1;
		fd.fd1 = here_doc(fd, &argv, argc);
	}
	else
		fd.fd1 = open(argv[1], O_RDONLY);
	return (ft_norma_strok(argc, argv, fd, envp));
}
