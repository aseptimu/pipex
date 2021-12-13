/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:29:20 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/12 12:30:48 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*full_path(char *paths, char **cmdargs, char **path)
{
	char	**tmp;
	char	*cmd;

	tmp = path;
	while (*path)
	{
		paths = ft_strjoin(*path, "/");
		if (!paths)
			error_exit("Memory allocate error", 1);
		cmd = ft_strjoin(paths, cmdargs[0]);
		if (!cmd)
			error_exit("Memory allocate error", 1);
		if (access(cmd, F_OK) == 0)
		{		
			free_split(tmp);
			free(paths);
			return (cmd);
		}
		free(paths);
		free(cmd);
		path++;
	}
	free_split(tmp);
	return (NULL);
}

char	*get_path(char **cmdargs, char **envp)
{
	char	*paths;
	char	**path;

	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			paths = ft_strchr(*envp, '=');
			break ;
		}
		envp++;
	}
	if (*envp == NULL)
	{
		paths = ft_strjoin("/", cmdargs[0]);
		if (!paths)
			error_exit("Memory allocate error", 1);
		return (paths);
	}
	paths++;
	path = ft_split(paths, ':');
	if (!path)
		error_exit("Memory allocate error", 1);
	return (full_path(paths, cmdargs, path));
}
