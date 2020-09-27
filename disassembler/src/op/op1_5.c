/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1_5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:27:17 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/27 12:07:42 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void							w_live(t_file *file, int *pos)
{
	int live;

	live = reverse_bytes(file->code, *pos + 1, 4);
	ft_printf("%d", live);
	*pos += 5;
}

void							w_ld(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 2);
}

void							w_st(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 2);
}

void							w_add(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 3);
}

void							w_sub(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 3);
}
