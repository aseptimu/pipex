/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:33:47 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 17:09:11 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		lens1;
	int		lens2;
	int		i;

	if (!s1 && !s2)
		return ((void *)0);
	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	p = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (!p)
		return ((void *)0);
	i = 0;
	ft_memcpy(p, s1, lens1);
	ft_memcpy(&p[lens1], s2, lens2);
	p[lens1 + lens2] = '\0';
	return (p);
}
