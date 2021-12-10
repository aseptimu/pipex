/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:32:06 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/10 20:58:33 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_exec(char **argv, char **envp)
{
	char	**cmdargs;
	char	*path;

	cmdargs = ft_split(argv[3], ' ');
	if (cmdargs == NULL)
		error_exit("string split error for cmdargs command2");
	if (access(cmdargs[0], F_OK) == -1)
	{
		path = get_path(cmdargs, envp);
		if (path == NULL)
			error_exit("command not found");
	}
	else
	{
		path = ft_strdup(cmdargs[0]);
		if (!path)
			error_exit("Path error");
	}
	if (execve(path, cmdargs, envp) == -1)
	{
		free(path);
		free(cmdargs);
		error_exit("Executing second command fail");
	}
}

void	parent_process(int pipefd[], char **argv, char **envp)
{
	int	fd2;

	fd2 = open (argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 == -1)
		error_exit("Open output file fail");
	if (close(pipefd[1]) == -1)
		error_exit("Close pipewrite fail in parent process");
	if (dup2(fd2, 1) == -1)
		error_exit("Outputfiledes to stdout dup fail in parent process");
	if (close (fd2) == -1)
		error_exit("Close outputfiledes error in parent process");
	if (dup2(pipefd[0], 0) == -1)
		error_exit("Piperead to stdin duplication fail in parent process");
	if (close(pipefd[0]) == -1)
		error_exit("Close piperead error in parent process");
	find_exec(argv, envp);
}
