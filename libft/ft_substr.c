/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:53:27 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 17:08:08 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	slen;

	if (!s)
		return ((void *)0);
	slen = ft_strlen(s);
	if ((size_t)start >= slen)
		return (ft_strdup("\0"));
	if (len > slen - start)
		len = slen;
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return ((void *)0);
	i = 0;
	while (len--)
	{
		p[i++] = s[start++];
	}
	p[i] = '\0';
	return (p);
}
