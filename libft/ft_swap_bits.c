/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:40:30 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:40:30 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_pow(int num, int power)
{
	int i;
	int acum;

	i = 0;
	acum = 1;
	while (i < power)
	{
		acum *= num;
		i++;
	}
	return (acum);
}

static int		to_int(char *str)
{
	int i;
	int acum;
	int size;

	i = 0;
	acum = 0;
	while (str[i])
		i++;
	if (i > 0)
		i--;
	size = i;
	while (i > 0)
	{
		acum += (str[i] - 48) * ft_pow(2, size - i);
		i--;
	}
	return (acum);
}

unsigned char	swap_bits(unsigned char octet)
{
	char	*str;
	char	temp;
	int		i;
	int		a;

	str = ft_strnew(9);
	a = (int)octet;
	i = 0;
	while (i < 8)
	{
		str[i] = (a % 2) + 48;
		a /= 2;
		i++;
	}
	str[i] = '\0';
	str = ft_strrev(str, i);
	i = 0;
	while (i < 4)
	{
		temp = str[i];
		str[i] = str[i + 4];
		str[i + 4] = temp;
		i++;
	}
	return ((unsigned char)to_int(str) + 1);
}
