/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:23 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:45:24 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *elem;

	if (!lst)
		return (NULL);
	elem = (*f)(lst);
	newlst = elem;
	while (lst->next)
	{
		lst = lst->next;
		if (!(elem->next = (*f)(lst)))
		{
			free(elem->next);
			return (NULL);
		}
		elem = elem->next;
	}
	return (newlst);
}
