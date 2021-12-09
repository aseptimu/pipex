/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:30:50 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/09 18:07:29 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_exec(char **argv, char **envp)
{
	char	*path;
	char	**cmdargs;

	cmdargs = ft_split(argv[2], ' ');
	if (cmdargs == NULL)
		error_exit("string split error for cmdargs command1", 1);
	if (access(cmdargs[0], F_OK) == -1)
	{
		path = get_path(cmdargs, envp);
		if (path == NULL)
			error_exit("Command 1 not found", 127);
	}
	else
		path = ft_strdup(cmdargs[0]);
	if (execve(path, cmdargs, envp) == -1)
	{
		free(path);
		free_split(cmdargs);
		error_exit("Executing first command fail", 1);
	}
}

void	child_process(int pipefd[], char **argv, char **envp)
{
	int		fd1;

	if (close(pipefd[0]) == -1)
		error_exit("Close pipe write error in child process", 1);
	fd1 = open (argv[1], O_RDONLY);
	if (fd1 == -1)
		error_exit("Open input file fail", 1);
	if (dup2(fd1, 0) == -1)
		error_exit("Inputfiledes to stdin dupl fail in child process", 1);
	if (close (fd1) == -1)
		error_exit("Close inputfiledes error in child process", 1);
	if (dup2(pipefd[1], 1) == -1)
		error_exit("Pipewrite to stdout duplication fail in child process", 1);
	if (close (pipefd[1]) == -1)
		error_exit("Close pipewrite fail in child process", 1);
	find_exec(argv, envp);
}
