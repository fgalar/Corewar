/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:41:27 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:41:28 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*fresh;
	unsigned int	i;

	i = 0;
	if (!(fresh = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
		fresh[i++] = '\0';
	return (fresh);
}
