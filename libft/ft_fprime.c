/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:39:13 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:39:14 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_prime(int i)
{
	int n;

	n = 2;
	if (i < 2)
		return (0);
	else if (i <= 3)
		return (1);
	while (n <= i / 2)
	{
		if (i % n == 0)
			return (0);
		n++;
	}
	return (1);
}

static void		fprime(int num, int i)
{
	if (num == 1 && i == 1)
	{
		ft_putnbr(1);
	}
	if (num < 2)
	{
		return ;
	}
	if (num > 0)
	{
		if (is_prime(i) && (num % i == 0))
		{
			ft_putnbr(i);
			if (num / i >= 2)
				ft_putchar('*');
			fprime(num / i, i);
		}
		else
			fprime(num, i + 1);
	}
}

int				ft_fprime(int nb)
{
	fprime(nb, 1);
	ft_putchar('\n');
	return (0);
}
