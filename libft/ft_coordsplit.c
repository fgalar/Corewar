/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordsplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 23:51:49 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/08 23:53:52 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_coords	ft_coordsplit(char **split, char *pos)
{
	int x;
	int y;
	t_coords c;

	x = 0;
	c.i = -1;
	c.j = -1;
	c.x = -1;
	c.y = -1;
	while (split[x])
	{
		y = 0;
		while (split[x][y])
		{
			if (&split[x][y] == pos)
			{
				c.i = x;
				c.j = y;
				return (c);
			}
			y++;
		}
		x++;
	}
	return (c);
}
