/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:38:48 by ciglesia          #+#    #+#             */
/*   Updated: 2019/07/27 03:41:25 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freesv(char **m, char *end)
{
	int i;

	i = 0;
	while (ft_strcmp(m[i], end) != 0)
	{
		free(m[i]);
		m[i] = NULL;
		i++;
	}
	free(m[i]);
	m[i] = NULL;
	free(m);
	m = NULL;
}
