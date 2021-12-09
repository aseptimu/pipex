/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:41:13 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/09 17:36:22 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *message, int exitcode)
{
	perror(message);
	exit(exitcode);
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

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	id;

	if (argc != 5)
	{
		write(1, "Enter 5 arguments\n", 18);
		exit(1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("Pipe fail");
		exit(1);
	}
	id = fork();
	if (id == -1)
	{
		perror("Fork fail");
		exit(1);
	}
	else if (id == 0)
		child_process(pipefd, argv, envp);
	else
		parent_process (pipefd, argv, envp, id);
	return (0);
}
