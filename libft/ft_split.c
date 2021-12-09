/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 15:38:30 by aseptimu          #+#    #+#             */
/*   Updated: 2021/12/02 12:54:10 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	free_pls(char **p, size_t num_str)
{
	while (num_str--)
		free(p[num_str]);
	free(p);
}

char	**ft_give_me_the_memory(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return ((void *)0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return ((char **)malloc((count + 1) * sizeof(char *)));
}

char	**ft_splitter(char const *s, char c, char **p, size_t count)
{
	size_t	start;
	size_t	num_str;

	num_str = 0;
	while (s[count])
	{
		if (s[count] != c)
		{
			start = count;
			while (s[count] != c && s[count] != '\0')
				count++;
			p[num_str] = ft_substr(s, start, count - start);
			if (!p[num_str])
			{
				free_pls(p, num_str);
				return ((void *)0);
			}
			num_str++;
		}
		else
			count++;
	}
	p[num_str] = (void *)0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	count;

	p = ft_give_me_the_memory(s, c);
	if (!p)
		return ((void *)0);
	count = 0;
	return (ft_splitter(s, c, p, count));
}
