/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op6_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:29:14 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/27 11:33:25 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void							w_and(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 3);
}

void							w_or(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 3);
}

void							w_xor(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 3);
}

void							w_zjmp(t_file *file, int *pos)
{
	(void)file;
	*pos += 3;
}

void							w_ldi(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 2, 3);
}
