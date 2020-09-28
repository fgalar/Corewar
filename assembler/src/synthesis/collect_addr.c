/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:43:14 by fgarault          #+#    #+#             */
/*   Updated: 2020/09/28 21:57:43 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label(t_code *code_tab, char *label)
{
	t_code *tab;

	tab = code_tab;
	while (tab)
	{
		if (!ft_strcmp(label, tab->label))
			return (tab->mem_pos);
		tab = tab->next;
	}
	return (-1);
}

void	put_addr(t_args *arg, t_code *tab, int cur_pos)
{
	if (arg->reg)
		arg->hex = itob(arg->hex, arg->reg, arg->arg_size);
	else if (arg->ind)
		arg->hex = itob(arg->hex, ft_atoi(arg->ind), arg->arg_size);
	else if (arg->dir)
	{
		if (arg->dir[1] == LABEL_CHAR)
			arg->hex = itob(arg->hex, (get_label(tab, &arg->dir[2]) - cur_pos),
			arg->arg_size);
		else
			arg->hex = itob(arg->hex, ft_atoi(&arg->dir[1]), arg->arg_size);
	}
}

void	get_addr(t_code *code_tab)
{
	t_code			*tab;
	t_instruction	*instr;
	t_args			*arg;

	tab = code_tab;
	while (tab)
	{
		instr = tab->instr;
		while (instr)
		{
			arg = instr->args;
			while (arg)
			{
				put_addr(arg, code_tab, instr->mem_pos);
				arg = arg->next;
			}
			instr = instr->next;
		}
		tab = tab->next;
	}
}
