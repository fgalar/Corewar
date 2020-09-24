/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:18:38 by fgarault          #+#    #+#             */
/*   Updated: 2020/09/24 16:40:25 by fgarault         ###   ########.fr       */
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
