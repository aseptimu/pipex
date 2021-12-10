/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:41:13 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/10 20:56:58 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message)
{
	perror(message);
	exit(127);
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

static int	ft_fork(int pipefd[2], pid_t id, char **argv, char **envp)
{
	if (pipe(pipefd) == -1)
		error_exit("Pipe fail");
	id = fork();
	if (id == -1)
		error_exit("Fork fail");
	else if (id == 0)
		child_process(pipefd, argv, envp);
	id = fork();
	if (id == -1)
		error_exit("Fork fail");
	else if (id == 0)
		parent_process(pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	return (id);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	id;
	int		status;
	pid_t	pid;
	int		ret;

	id = 0;
	pid = 1;
	ret = 0;
	if (argc != 5)
	{
		ft_putstr_fd("Enter 5 arguments\n", 1);
		exit(1);
	}
	id = ft_fork(pipefd, id, argv, envp);
	while (pid > 0)
	{
		pid = wait(&status);
		if (pid == id)
			ret = status;
	}
	return (WEXITSTATUS(ret));
}
