/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:42:18 by ciglesia          #+#    #+#             */
/*   Updated: 2019/08/13 20:42:19 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;
	int		i;

	if (s1 && s2)
	{
		l1 = ft_strlen(s1);
		l2 = ft_strlen(s2);
		if (!(str = ft_strnew(l1 + l2)))
			return (NULL);
		i = 0;
		while (i < l1 + l2)
		{
			if (i < l1)
				str[i] = s1[i];
			else
				str[i] = s2[i - l1];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
