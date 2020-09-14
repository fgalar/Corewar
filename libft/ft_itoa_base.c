/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:51 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/08 09:54:36 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_number(int value, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

static int	to_string(int value, char *result, char *basee, int base)
{
	int i;

	i = 0;
	while (value != 0)
	{
		result[i] = basee[ft_abs(value % base)];
		value /= base;
		i++;
	}
	return (i);
}

static int	ft_sign(int sign, int i, char *result)
{
	if (sign < 0)
	{
		result[i] = '-';
		i++;
	}
	result[i] = '\0';
	return (i);
}

static void	create_base(int base, char *basee)
{
	int i;

	i = 0;
	while (i < base)
	{
		basee[i] = (i > 9) ? i + 55 : i + 48;
		i++;
	}
	basee[i] = '\0';
}

char		*ft_itoa_base(int value, int base)
{
	char	*basee;
	char	*result;
	int		i;
	int		sign;
	int		min;

	if ((2 <= base && base <= 16))
	{
		min = (value == -2147483648) ? 1 : 0;
		if (value == 0)
			return ("0");
		sign = (value < 0 && base == 10) ? -1 : 1;
		value = (value < 0 && !min) ? -value : value;
		basee = (char*)malloc(sizeof(char) * (base + 1));
		create_base(base, basee);
		i = size_number(value, base);
		if (!(result = (char*)malloc(sizeof(char) * (i + 2))))
			return (0);
		i = to_string(value, result, basee, base);
		i = ft_sign(sign, i, result);
		return (ft_strrev(result, i));
	}
	return (0);
}
