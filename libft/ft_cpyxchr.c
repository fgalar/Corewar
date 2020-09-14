/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyxchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:42:38 by ciglesia          #+#    #+#             */
/*   Updated: 2019/07/26 22:45:15 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cpyxchr(char *str, char *dst, char c, int n)
{
	int i;

	i = n;
	while (str[i - n] && dst[i])
	{
		if (str[i - n] != c)
			dst[i] = str[i - n];
		i++;
	}
	return (dst);
}
