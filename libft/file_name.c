/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 22:07:39 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/22 02:01:33 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		file_name(char *file, char *end)
{
	unsigned int	e;
	int				i;

	i = 0;
	e = ft_strlen(end);
	if (ft_strlen(file) < e)
	{
		ft_printf_fd(2, ERROR": %s: Not a %s file\n", file, end);
		return (0);
	}
	while (file[i + e])
		i++;
	if (ft_strcmp(&file[i], end) != 0)
	{
		ft_printf_fd(2, ERROR": %s: Not a %s file\n", file, end);
		return (0);
	}
	return (1);
}
