/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op6_10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:29:14 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/27 17:06:40 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void							w_and(t_file *file, int *pos)
{
	disect_args(file->code, pos, 0);
}

void							w_or(t_file *file, int *pos)
{
	disect_args(file->code, pos, 0);
}

void							w_xor(t_file *file, int *pos)
{
	disect_args(file->code, pos, 0);
}

void							w_zjmp(t_file *file, int *pos)
{
	int move;

	move = reverse_bytes(file->code, *pos + 1, 2) % IDX_MOD;
	ft_printf("%%%d", move);
	*pos += 3;
}

void							w_ldi(t_file *file, int *pos)
{
	disect_args(file->code, pos, 2);
}
