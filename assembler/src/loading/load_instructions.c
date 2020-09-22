/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 20:27:27 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/23 00:09:57 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		load_params(char **cmd, int x, int i, t_instruction *instr)
{
	int	valid;
	int type;
	int nargs;

	type = 0;
	nargs = g_op_tab[x].nb_arg;
	while (nargs)
	{
		valid = -1;
		if (ft_itersplit(cmd, i) && *ft_itersplit(cmd, i) == ',')
			i++;
		if ((g_op_tab[x].args[type] & T_REG) == T_REG &&
						(valid = valid_reg(cmd, i)) >= 0)
			instr->reg = ft_atoi(ft_itersplit(cmd, i + 1));
		if (valid == -1 && (g_op_tab[x].args[type] & T_DIR) == T_DIR &&
										(valid = valid_dir(cmd, i)) >= 0)
			instr->dir = ft_strndup(ft_itersplit(cmd, i), valid - i);
		if (valid == -1 && (g_op_tab[x].args[type] & T_IND) == T_IND &&
										(valid = valid_ind(cmd, i)) >= 0)
			instr->ind = ft_strndup(ft_itersplit(cmd, i), valid - i);
		nargs--;
		i = valid;
		type++;
	}
	return (1);
}

int		load_op(char **cmd, int i, int line, t_instruction *instr)
{
	int		x;
	char	*op;

	x = 0;
	if (!ft_itersplit(cmd, i) || *ft_itersplit(cmd, i) == '#')
		return (0);
	while (g_op_tab[x].name)
	{
		op = ft_itersplit(cmd, i);
		if (ft_strcmpn(g_op_tab[x].name, op, ":%") == 0)
		{
			instr->opcode = x + 1;
			instr->nargs = g_op_tab[x].nb_arg;
			load_params(cmd, x, i + ft_strlen(g_op_tab[x].name), instr);
			return (1);
		}
		x++;
	}
	return (-1 + load_error(cmd, i, "unable to load op", line));
}
