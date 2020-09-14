/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:43:50 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/21 17:06:27 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *str)
{
	int i;

	if (str)
	{
		i = 0;
		while (str[i])
			ft_putchar(str[i++]);
		return (i);
	}
	return (0);
}
