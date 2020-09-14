/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:43:28 by ciglesia          #+#    #+#             */
/*   Updated: 2019/10/07 07:06:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_sqrt(int n)
{
	int		decimals;
	double	before;
	double	res;

	if (n < 1)
		return (0);
	decimals = 0;
	res = n / 2;
	while (decimals != 5)
	{
		before = res;
		res = (res + n / res) / 2;
		if ((int)res == (int)before)
			decimals++;
	}
	return (res);
}
