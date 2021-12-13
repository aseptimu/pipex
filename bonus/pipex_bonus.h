/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:43:30 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/13 16:03:02 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h> 
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct s_fdstruct
{
	int		pipefd[2];
	int		fd1;
	int		fd2;
	pid_t	id;
	pid_t	pid;
	int		status;
	int		flag;
	int		count;
}				t_fd;

void	child_process(t_fd *fd, char *argv, char **envp);
char	*get_path(char **cmdargs, char **envp);
void	error_exit(char *message, int errorcode);
void	free_split(char **string);

#endif