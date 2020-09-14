/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:43:06 by ciglesia          #+#    #+#             */
/*   Updated: 2019/07/26 22:47:45 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillstr(char c, int q)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = ft_strnew(q)))
		return (NULL);
	while (i < q)
		str[i++] = c;
	return (str);
}
