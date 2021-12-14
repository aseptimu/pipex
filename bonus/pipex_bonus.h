/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:43:30 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/14 17:07:07 by aseptimu         ###   ########.fr       */
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
	int		here_doc;
}				t_fd;

void	child_process(t_fd *fd, char *argv, char **envp);
char	*get_path(char **cmdargs, char **envp);
void	error_exit(char *message, int errorcode);
void	free_split(char **string);
char	*ft_strjoin_bonus(char const *s1, char const *s2);
int		ft_strncmp_pipex(const char *s1, const char *s2, size_t n);
char	*ft_stdin(char **argv, char *buf, char *ret);
int		here_doc(t_fd fd, char ***argv, int argc);
int		ft_norma_strok(int argc, char **argv, t_fd fd, char **envp);
void	ft_fork(t_fd *fd, int argc, char **argv, char **envp);

#endif