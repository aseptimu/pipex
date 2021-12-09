/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:46:51 by aseptimu          #+#    #+#             */
/*   Updated: 2021/10/12 15:17:36 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*cpyl;

	cpyl = (void *)0;
	while (lst)
	{
		newl = ft_lstnew(f(lst->content));
		if (!newl)
		{
			ft_lstclear(&cpyl, del);
			return ((void *)0);
		}
		ft_lstadd_back(&cpyl, newl);
		lst = lst->next;
	}
	return (cpyl);
}
