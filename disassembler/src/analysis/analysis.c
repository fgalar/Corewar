/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:01:06 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/23 20:29:01 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void	is_op(t_uchar byte, int *i)
{
	(void)i;
	if (1 <= byte && byte <= 16)
	{
		ft_printf(CYAN"%s "E0M, g_w_tab[byte - 1].name);
	}
}

int		disassemble(t_file *file)
{
	int i;

	i = 0;
	while (file->prog_size - i)
	{
		is_op(file->code[i], &i);
		ft_printf("%.2x ", file->code[i]);
		i++;
	}
	ft_printf("\n");
	return (EXIT_SUCCESS);
}
