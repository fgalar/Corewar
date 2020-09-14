/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:41:30 by ciglesia          #+#    #+#             */
/*   Updated: 2019/07/26 22:46:06 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_vstrdup(char **m, char *end)
{
	int		i;
	char	**res;

	i = 0;
	while (ft_strcmp(m[i], end) != 0)
		i++;
	if (!(res = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	while (i >= 0)
	{
		res[i] = ft_strdup(m[i]);
		i--;
	}
	return (res);
}
