/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:52 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:44:52 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	i;
	unsigned char	*copy;
	unsigned char	*cpsrc;

	copy = (unsigned char*)dst;
	cpsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*(copy + i) = *(cpsrc + i);
		i++;
	}
	dst = (void*)copy;
	return (dst);
}
