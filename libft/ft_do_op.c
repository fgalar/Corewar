/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:39:02 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:39:03 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ccmpr(char *s1, char s2)
{
	return (*s1 == s2);
}

static int	exion(char *n1, char *n2)
{
	if (ft_atoi(n1) == -2147483648 || ft_atoi(n2) == -2147483648)
	{
		if (ft_atoi(n1) == -1 || ft_atoi(n2) == -1)
			return (1);
	}
	return (0);
}

int			ft_do_op(int ac, char **av)
{
	int nbr;

	if (ac == 4)
	{
		if (ccmpr(av[2], '+'))
			nbr = ft_atoi(av[1]) + ft_atoi(av[3]);
		else if (ccmpr(av[2], '-'))
			nbr = ft_atoi(av[1]) - ft_atoi(av[3]);
		else if (ccmpr(av[2], '*'))
		{
			if (!exion(av[1], av[3]))
				nbr = ft_atoi(av[1]) * ft_atoi(av[3]);
			else
				ft_putstr("2147483648");
		}
		else if (ccmpr(av[2], '/') && (ft_atoi(av[3]) != 0))
			nbr = ft_atoi(av[1]) / ft_atoi(av[3]);
		else if (ccmpr(av[2], '%'))
			nbr = ft_atoi(av[1]) % ft_atoi(av[3]);
		if (!exion(av[1], av[3]) && (ft_atoi(av[3]) != 0))
			ft_putnbr(nbr);
	}
	ft_putstr("\n");
	return (0);
}
