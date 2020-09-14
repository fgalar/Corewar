/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:41:13 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:41:14 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		e;
	char	*last;

	i = 0;
	e = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			e = 1;
			last = (char*)(s + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char*)(s + i));
	if (e)
		return (last);
	return (NULL);
}
