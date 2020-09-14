/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:18 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/10 01:04:55 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		if (content)
		{
			if (!(new->obj = (void*)malloc(sizeof(void) *
										(content_size + 1))))
				return (NULL);
			ft_memcpy(new->obj, content, content_size);
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
