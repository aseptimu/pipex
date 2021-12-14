/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:30:50 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/14 20:30:52 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	find_exec(char *argv, char **envp)
{
	char	*path;
	char	**cmdargs;

	cmdargs = ft_split(argv, ' ');
	if (cmdargs == NULL)
		error_exit("string split error for cmdargs command", 1);
	if (access(cmdargs[0], F_OK) == -1)
	{
		path = get_path(cmdargs, envp);
		if (path == NULL)
			error_exit("command not found", 127);
	}
	else
	{
		path = ft_strdup(cmdargs[0]);
		if (!path)
			error_exit("Path error", 1);
	}
	if (execve(path, cmdargs, envp) == -1)
	{
		free(path);
		free_split(cmdargs);
		error_exit("Executing first command fail", 1);
	}
}

void	child_process(t_fd *fd, char *argv, char **envp)
{
	if (fd->flag == 1)
	{
		if (close(fd->pipefd[0]) == -1)
			error_exit("Close pipe write error in child process", 1);
		if (dup2(fd->pipefd[1], 1) == -1)
			error_exit("Pipewrite to stdout dup fail in child process", 1);
		if (close (fd->pipefd[1]) == -1)
			error_exit("Close pipewrite fail in child process", 1);
	}
	else
	{
		if (dup2(fd->fd2, 1) == -1)
			error_exit("dup fail", 1);
		if (close(fd->fd2) == -1)
			error_exit("close fail", 1);
	}
	find_exec(argv, envp);
}
