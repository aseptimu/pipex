/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:59:14 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 17:13:21 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_memalloc(int n, long *digit)
{
	int		size;

	*digit = 1;
	size = 1;
	if (n == 0)
	{
		size++;
		*digit = *digit * 10;
	}	
	while (n)
	{
		if (n < 0)
		{
			n = -n;
			size++;
		}
		n /= 10;
		size++;
		*digit = *digit * 10;
	}
	*digit /= 10;
	return ((char *)malloc(size * sizeof(char)));
}

static char	*ft_convert(long n, char *arr, int digit)
{
	int		i;
	long	tmp;

	i = 0;
	if (n < 0)
	{
		n = -n;
		arr[i] = '-';
		i++;
	}
	tmp = 0;
	while (digit)
	{
		tmp = n / digit;
		arr[i] = (char)(tmp % 10 + '0');
		digit /= 10;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*arr;
	long	digit;

	arr = ft_memalloc(n, &digit);
	if (!arr)
		return ((void *)0);
	return (ft_convert((long)n, arr, (int)digit));
}
