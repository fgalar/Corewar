/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:52:46 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/22 02:01:17 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char *c)
{
	char	**tab;

	if (s)
	{
		if (!(tab = (char**)malloc(sizeof(char*) *
			(ft_count_words((char*)s, 0, 0, c) + 1))))
			return (NULL);
		return (ft_decompose(tab, (char*)s, 0, c));
	}
	return (NULL);
}
