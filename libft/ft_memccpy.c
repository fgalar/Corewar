/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:45:09 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:45:09 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
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
		if (*(cpsrc + i) == (unsigned char)c)
			return ((void*)(copy + i + 1));
		i++;
	}
	return (NULL);
}
