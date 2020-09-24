/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:12:29 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/24 13:29:43 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_instr(t_instruction *instr)
{
	while (instr)
	{
		ft_printf(GREEN"\t%s "E0M, g_op_tab[instr->opcode - 1].name);
		ft_printf(CYAN"[r%d, %s, %s]\n"E0M, instr->reg, instr->dir, instr->ind);
		instr = instr->next;
	}
}

int		translate(t_file *file, int verbosity)
{
	t_code	*table;

	table = file->code_tab;
	collecting_codebytes(file);
	while (table)
	{
		if (verbosity)
		{
			ft_printf(BLUE"%s:\n", table->label);
			print_instr(table->instr);
		}
		table = table->next;
	}
	//writing_exec(file);
	return (0);
}
