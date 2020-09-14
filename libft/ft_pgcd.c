/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:35 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:44:36 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pgcd(int a, int b)
{
	int temp;
	int i;
	int gcd;

	if (b < a)
	{
		temp = a;
		a = b;
		b = temp;
	}
	else if (b == a)
		return (a);
	i = 1;
	gcd = 1;
	while (i < a)
	{
		if ((a % i == 0) && (b % i == 0))
			gcd = i;
		i++;
	}
	return (gcd);
}

void		ft_pgcd(int a, int b)
{
	if (a > 0 && b > 0)
		ft_putnbr(pgcd(a, b));
	ft_putstr("\n");
}
