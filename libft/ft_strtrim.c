/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 11:55:22 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 17:10:05 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		start;
	int		len;

	if (!s1)
		return ((void *)0);
	if (!set)
		return ((char *)s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen((char *)s1) - 1;
	while (len && ft_strchr(set, s1[len]))
		len--;
	len = len - start;
	p = ft_substr(s1, start, len + 1);
	return (p);
}
