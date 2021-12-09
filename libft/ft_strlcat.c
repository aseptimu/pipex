/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:01:47 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 17:03:51 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srcl;
	size_t	dstl;

	dstl = 0;
	srcl = 0;
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (dstl > dstsize || dstsize == 0)
		return (dstsize + srcl);
	j = dstl;
	i = 0;
	while (dstsize - dstl > 1 && src[i])
	{
		dst[j++] = src[i++];
		dstsize--;
	}
	dst[j] = '\0';
	return (dstl + srcl);
}
