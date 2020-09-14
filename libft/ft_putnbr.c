/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:04 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:44:06 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long lg;

	lg = nb;
	if (lg == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		lg = 147483648;
		ft_putnbr(lg);
	}
	else if (lg < 0)
	{
		ft_putchar('-');
		lg *= -1;
		ft_putnbr(lg);
	}
	else if (lg >= 10)
	{
		ft_putnbr(lg / 10);
		ft_putchar(lg % 10 + 48);
	}
	else if (lg < 10)
	{
		ft_putchar(lg % 10 + '0');
	}
}
