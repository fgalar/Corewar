/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:43:36 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:43:41 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listi		*ft_sort_list(t_listi *lst, int (*cmp)(int, int))
{
	t_listi	*temp;
	int		swp;
	int		ordenado;

	ordenado = 1;
	while (ordenado)
	{
		temp = lst;
		ordenado = 0;
		while (temp->next)
		{
			if (!(*cmp)(temp->data, temp->next->data))
			{
				swp = temp->data;
				temp->data = temp->next->data;
				temp->next->data = swp;
				ordenado = 1;
			}
			temp = temp->next;
		}
	}
	return (lst);
}
