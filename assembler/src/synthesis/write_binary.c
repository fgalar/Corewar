/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:48:19 by fgarault          #+#    #+#             */
/*   Updated: 2020/09/24 17:35:22 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		compiled_name(t_file *file)
{
	int		i;
	char	*name;
	int		fd;

	i = 0;
	fd = 0;
	if (!(name = ft_strnew(ft_strlen(file->name))))
		return (-1);
	while (file->name[i] != '.')
	{
		name[i] = file->name[i];
		i++;
	}
	ft_strcat(name, ".corbis");
	ft_bzero(file->name, sizeof(PROG_NAME_LENGTH));
	file->name = name;
	if ((fd = open(file->name, O_RDWR | O_CREAT, 00666)) == -1)
		return (-1);
	return (fd);
}

static int		write_header(t_file *file, int fd)
{
	write(fd, file->magic_nb, 4);
	write(fd, file->playername, PROG_NAME_LENGTH);
	write(fd, file->comment, COMMENT_LENGTH);
	return (0);
}

int		writing_exec(t_file *file)
{
	int		fd;

	if ((fd = compiled_name(file)) < 0)
	{
		ft_printf_fd(2, "Failed to create %s", file->name);
		return (EXIT_FAILURE);
	}
	if (!write_header(file, fd))
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}
