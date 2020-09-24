/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_codebytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:45:01 by fgarault          #+#    #+#             */
/*   Updated: 2020/09/24 19:12:27 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

void	translate_to_bytecode(unsigned char *dest, unsigned int nb, size_t size)
{
	while (--size > 0 && nb)
	{
		dest[size] = nb % (16 * 16);
		nb /= (16 * 16);
	}
}

char	get_argument_coding_byte(t_instruction *instruction)
{
	t_args	*argument;
	int		i;
	int		acb;

	argument = instruction->args;
	i = 7;
	acb = 0;
	while (argument)
	{
		if (argument->reg && i--)
			acb += ft_power(2, i);
		else if (argument->dir && i--)
			acb += ft_power(2, i + 1);
		else if (argument->ind && i--)
			acb += ft_power(2, i + 1) + ft_power(2, i);
		i--;
		argument = argument->next;
	}
	return (acb);
}
int		is_bigger_arg(t_instruction *instr)
{
	char *op;

	op = g_op_tab[instr->opcode - 1].name;
	if (!ft_strcmp("and", op) || !ft_strcmp("or", op) || !ft_strcmp("xor", op))
		return (1);
	return (0);
}

int		get_sizeof(t_instruction *instruction)
{
	t_args	*argument;
	int		total;

	argument = instruction->args;
	total = 0;
	while (argument)
	{
		if (argument->reg)
			argument->size = 1;
		else if (argument->ind)
			argument->size = 2;
		else if (argument->dir)
		{
			if (is_bigger_arg(instruction))
				argument->size = 4;
			else
				argument->size = 2;
		}
		total += argument->size;
		argument = argument->next;	
	}
	return (total);
}

void	collecting_codebytes(t_file *file)
{
	t_code			*tab;
	t_instruction	*ins;

	tab = file->code_tab;
	ins = tab->instr;
	ft_bzero(file->magic_nb, 4);//Can Andre init this in init_struct ? or replace file->code with it
	translate_to_bytecode(file->magic_nb, COREWAR_EXEC_MAGIC, 4);
	while (tab)
	{

		while (ins)
		{
			ins->acb = get_argument_coding_byte(ins);
			ins->size = get_sizeof(ins);
			ft_printf("%d\n", ins->size);
			ins = ins->next;
		}
		tab = tab->next;
	}
	writing_exec(file);
}
