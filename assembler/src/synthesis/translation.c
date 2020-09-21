/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:12:29 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/16 12:29:44 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

/**************************************************************
 * 	1)Creating file											[X]
 *	2)Set header : COREWAR_EXEC_MAGIC/on the first 4 octets	[X]
 *				   PLAYER_NAME								[X]
 *				   PROG_SIZE / 8 octets						[ ]
 *				   COMMENT									[X]
 */

void	print_instr(t_instruction *instr)
{
	while (instr)
	{
		ft_printf(GREEN"\t%s "E0M, g_op_tab[instr->opcode - 1].name);
		ft_printf(CYAN"[r%d, %s, %s]\n"E0M, instr->reg, instr->dir, instr->ind);
		instr = instr->next;
	}
}

int		compiled_name(char *file_name)
{
	int		i;
	char	*name;
	int		fd;

	i = 0;
	fd = 0;
	if (!(name = ft_strnew(ft_strlen(file_name))))
		return (-1);
	while (file_name[i + 1])
	{
		name[i] = file_name[i];
		i++;
	}
	ft_strcat(name, "corbis");
	if ((fd = open(name, O_RDWR | O_CREAT, 00666)) == -1)
		return (-1);
	return (fd);
}

void 	ft_puthex_bin(int nb, int fd)
{
	if (nb >= (16 * 16))
		ft_puthex_bin(nb / (16 * 16), fd);
	ft_printf_fd(fd, "%c", nb % (16*16));
}

void	set_prog_head(t_file *file, int fd)
{
	int		i;
	int		magic_nb;
	int		null_bits;

	i = 0;
	magic_nb = COREWAR_EXEC_MAGIC;
	null_bits = 4;
	while (magic_nb && null_bits--)
		magic_nb /= (16 * 16);
	while (null_bits--)
		ft_printf_fd(fd, "%c", 0x00);
	ft_puthex_bin(COREWAR_EXEC_MAGIC, fd);
	while (file->playername[i])
		ft_printf_fd(fd, "%c", file->playername[i++]);
	while (i <= PROG_NAME_LENGTH)
	{
		ft_printf_fd(fd, "%c", 0x00);
		i++;
	}
	while (file->comment[i])
		ft_printf_fd(fd, "%c", file->comment[i++]);
}

int		translate(t_file *file, int verbosity)
{
	t_code	*table;

	int		fd;
	table = file->code_tab;
	if ((fd = compiled_name(file->name)))
		return (0);
	set_prog_head(file, fd);
	while (table)
	{
		if (verbosity)
		{
			ft_printf(BLUE"%s:\n", table->label);
			print_instr(table->instr);
		//print intrinsic instructions (table->instr)
		}
		table = table->next;
	}
	return (0);
}
