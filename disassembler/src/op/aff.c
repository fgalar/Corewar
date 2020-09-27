/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:52 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/27 16:59:57 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void							w_aff(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	if (p_acb(acb, 1) == REG && is_reg(file->code, *pos + 2))
	{
		ft_printf("r%d", file->code[*pos + 2]);
	}
	*pos += octal_shift(acb, 4, 1);
}
