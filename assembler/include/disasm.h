/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:46:23 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/23 11:07:59 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H

#include "asm.h"

typedef struct					s_w
{
	char						*name;
	t_uchar						nb_arg;
	t_arg_type					args[3];
	t_uchar						opcode;
	unsigned int				cycle;
	char						*description;
	t_uchar						octal;
	t_uchar						label;
	void						(*f)(t_file *file, int pos);
}								t_w;

int								valid_header(t_file *file);

int								load_exec(t_file *file);

int								disassemble(t_file *file);

void							w_live(t_file *file, int pos);
void							w_ld(t_file *file, int pos);
void							w_st(t_file *file, int pos);
void							w_add(t_file *file, int pos);
void							w_sub(t_file *file, int pos);
void							w_and(t_file *file, int pos);
void							w_or(t_file *file, int pos);
void							w_xor(t_file *file, int pos);
void							w_zjmp(t_file *file, int pos);
void							w_ldi(t_file *file, int pos);
void							w_sti(t_file *file, int pos);
void							w_fork(t_file *file, int pos);
void							w_lld(t_file *file, int pos);
void							w_lldi(t_file *file, int pos);
void							w_lfork(t_file *file, int pos);
void							w_aff(t_file *file, int pos);

extern t_w						g_w_tab[17];

#endif
