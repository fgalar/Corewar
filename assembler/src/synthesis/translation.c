/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:12:29 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/24 11:46:17 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_instr(t_instruction *instr)
{
	t_args	*args;
	while (instr)
	{
		ft_printf(GREEN"\t%s "E0M, g_op_tab[instr->opcode - 1].name);
		args = instr->args;
		ft_printf(GREEN"["E0M);
		while (args)
		{
			if (args->reg)
				ft_printf(CYAN"r%d "E0M, args->reg);
			if (args->dir)
				ft_printf(CYAN"%s "E0M, args->dir);
			if (args->ind)
				ft_printf(CYAN"%s "E0M, args->ind);
			args = args->next;
		}
		ft_printf(GREEN"]\n"E0M);
		instr = instr->next;
	}
}

int		translate(t_file *file, int verbosity)
{
	t_code	*table;

	table = file->code_tab;
	while (table)
	{
		if (verbosity)
		{
			ft_printf(BLUE"%s:\n"E0M, table->label);
			print_instr(table->instr);
		}
		table = table->next;
	}
	return (0);
}
