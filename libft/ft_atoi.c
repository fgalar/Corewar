/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:32:55 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/21 13:24:12 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_cspecial(const char *c)
{
	int i;

	i = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	return (i);
}

static int	ft_condition(int number, int f, int sign)
{
	return (number == 214748364 && ((f == 8 && sign < 0) ||
									(f == 7 && sign > 0)));
}

int			ft_atoi(const char *str)
{
	int i;
	int number;
	int sign;
	int f;

	number = 0;
	sign = 1;
	i = ft_cspecial(str);
	sign *= (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] <= '9') && (str[i] >= '0'))
	{
		f = ((int)str[i] - '0');
		if (ft_condition(number, f, sign))
		{
			if (f == 8 && sign < 0)
				return (-2147483648);
			return (2147483647);
		}
		number = (number * 10) + f;
		i++;
	}
	return (number * sign);
}
