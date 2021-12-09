/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:20:55 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 18:30:28 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	str1;
	unsigned char	str2;

	while (n-- > 0)
	{
		str1 = (unsigned char) *s1;
		str2 = (unsigned char) *s2;
		if (str1 > str2)
			return (1);
		if (str1 < str2)
			return (-1);
		if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}
