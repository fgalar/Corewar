/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:58 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:45:00 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ss;
	unsigned char	*sss;

	ss = (unsigned char*)s1;
	sss = (unsigned char*)s2;
	i = 0;
	while (i < n && ss[i] == sss[i])
		i++;
	if (i == n)
		return (0);
	return (ss[i] - sss[i]);
}
