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
 *	2)Set header : COREWAR_EXEC_MAGIC/on the first 4 octets [ ]
 *				   PLAYER_NAME								[ ]
 *				   COMMENT									[ ]
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
	ft_putchar_fd(nb % (16*16), fd);
}

void	set_prog_head(char *player_name, int fd)
{
	int		i;
	int		magic_nb;

	i = 0;
	magic_nb = COREWAR_EXEC_MAGIC;
	ft_putchar_fd(0x00, fd);                 ///--->ou soustraire a 4 bits le nombre bit total du nombre magic
	ft_puthex_bin(magic_nb, fd);
	while (player_name[i])
		ft_putchar_fd(player_name[i++], fd);
}

int		translate(t_file *file, char *file_name)
{
	t_code	*table;
	int		fd;

	table = file->code_tab;
	if ((fd = compiled_name(file_name)))
		return (0);
	set_prog_head(file->playername, fd);
	while (table)
	{
		ft_printf(BLUE"%s:\n", table->label);
		print_instr(table->instr);
		//print intrinsic instructions (table->instr)
		table = table->next;
	}
	return (0);
}
