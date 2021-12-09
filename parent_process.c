/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:32:06 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/09 17:42:07 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	find_exec(char **argv, char **envp)
{
	char	**cmdargs;
	char	*path;

	cmdargs = ft_split(argv[3], ' ');
	if (cmdargs == NULL)
		error_exit("string split error for cmdargs command2", 1);
	if (access(cmdargs[0], F_OK) == -1)
	{
		path = get_path(cmdargs, envp);
		if (path == NULL)
			error_exit("Command 2 not found", 127);
	}
	else
		path = ft_strdup(cmdargs[0]);
	if (execve(path, cmdargs, envp) == -1)
	{
		free(path);
		free(cmdargs);
		error_exit("Executing second command fail", 1);
	}	
}

void	parent_process(int pipefd[], char **argv, char **envp, pid_t id)
{
	int	status;
	int	fd2;

	fd2 = open (argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 == -1)
		error_exit("Open output file fail", 1);
	if (close(pipefd[1]) == -1)
		error_exit("Close pipewrite fail in parent process", 1);
	if (dup2(fd2, 1) == -1)
		error_exit("Outputfiledes to stdout dup fail in parent process", 1);
	if (close (fd2) == -1)
		error_exit("Close outputfiledes error in parent process", 1);
	if (dup2(pipefd[0], 0) == -1)
		error_exit("Piperead to stdin duplication fail in parent process", 1);
	if (close(pipefd[0]) == -1)
		error_exit("Close piperead error in parent process", 1);
	find_exec(argv, envp);
}
