/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:18:38 by fgarault          #+#    #+#             */
/*   Updated: 2020/09/29 17:03:00 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_power(int nb, int power)
{
	if (power >= 1)
		return (nb * ft_power(nb, power - 1));
	if (power == 0)
		return (1);
	else
		return (0);
}

t_uchar	*itob(t_uchar *dest, unsigned int nb, int size)
{
	if (!(dest = (t_uchar*)malloc(sizeof(t_uchar) * size)))
		return (NULL);
	ft_bzero(dest, size);
	while (--size && nb >= (16 * 16))
	{
		dest[size] = nb % (16 * 16);
		nb /= (16 * 16);
	}
	dest[size] = nb % (16 * 16);
	return (dest);
}
