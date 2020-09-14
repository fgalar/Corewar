/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itersplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 13:48:35 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/08 15:42:47 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itersplit(char **split, int i)
{
	int x;
	int y;
	int count;

	x = 0;
	count = 0;
	while (split[x])
	{
		y = 0;
		while (split[x][y])
		{
			if (count == i)
				return (&split[x][y]);
			count++;
			y++;
		}
		x++;
	}
	return (NULL);
}
