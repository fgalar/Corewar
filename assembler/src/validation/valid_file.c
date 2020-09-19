/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:21:29 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/19 02:14:01 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		valid_input(char *filename, t_file *file)
{
	if (!file_name(filename, ".s"))
		return (EXIT_FAILURE);
	if ((file->fd = open(filename, O_RDONLY) < 0) || read(file->fd, NULL, 0))
	{
		ft_printf_fd(2, ERROR""RED": %s: Cannot open file .s\n"E0M, filename);
		return (EXIT_FAILURE);
	}
	close(file->fd);
	file->name = ft_strdup(filename);
	file->fd = open(filename, O_RDONLY);
	return (EXIT_SUCCESS);
}
