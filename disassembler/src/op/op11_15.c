/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op11_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:23 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/27 11:36:52 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void							w_sti(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 2, 3);
}

void							w_fork(t_file *file, int *pos)
{
	(void)file;
	*pos += 3;
}

void							w_lld(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 4, 2);
}

void							w_lldi(t_file *file, int *pos)
{
	t_uchar	acb;

	acb = file->code[*pos + 1];
	*pos += octal_shift(acb, 2, 3);
}

void							w_lfork(t_file *file, int *pos)
{
	(void)file;
	*pos += 3;
}
