/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:54:39 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/10 21:37:51 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew2(void *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		if (content)
		{
			new->obj = content;
			new->dim = content_size;
		}
		else
		{
			new->obj = NULL;
			new->dim = 0;
		}
		new->next = NULL;
	}
	return (new);
}
