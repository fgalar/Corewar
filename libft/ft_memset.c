/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:44:40 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:44:40 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	*copy;

	copy = (unsigned char*)b;
	i = 0;
	while (i < len)
		*(copy + (i++)) = (unsigned char)c;
	b = (void*)copy;
	return (b);
}
