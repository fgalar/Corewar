/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:39:58 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:40:00 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_letter(char c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

static void		caser(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_letter(str[i]))
		{
			if ('a' <= str[i] && str[i] <= 'z')
			{
				ft_putchar(str[i] - 32);
			}
			else
			{
				ft_putchar(str[i] + 32);
			}
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int				ft_ulstr(char *str)
{
	caser(str);
	ft_putchar('\n');
	return (0);
}
