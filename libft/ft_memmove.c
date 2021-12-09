/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:59:53 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 16:58:13 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	size_t			i;

	i = 0;
	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	if (!src && !dst)
		return (dst);
	if (src >= dst)
	{
		while (i < len)
		{
			udst[i] = usrc[i];
			i++;
		}
		return (udst);
	}
	while (len--)
	{
		udst[len] = usrc[len];
	}
	return (udst);
}
