/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:43:30 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/10 20:19:21 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>

void	parent_process(int pipefd[], char **argv, char **envp);
void	child_process(int pipefd[], char **argv, char **envp);
char	*get_path(char **cmdargs, char **envp);
void	error_exit(char *message);
void	free_split(char **string);

#endif