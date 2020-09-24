/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_codebytes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <fgarault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:45:01 by fgarault          #+#    #+#             */
/*   Updated: 2020/09/24 13:46:09 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

void	collect_magic_bytecode(unsigned char *dest, unsigned int magic_nb)
{
	int		i;

	i = 4;
	while (--i > 0 && magic_nb)
	{
		dest[i] = magic_nb % (16 * 16);
		magic_nb /= (16 * 16);
	}
}

void	get_argument_coding_byte()
{
}

void	collecting_codebytes(t_file *file)
{
	t_code			*tab;
	t_instruction	*ins;

	tab = file->code_tab;
	ins = tab->instr;
	ft_bzero(file->magic_nb, 4);//Can Andre init this in init_struct ? or replace file->code with it
	collect_magic_bytecode(file->magic_nb, COREWAR_EXEC_MAGIC);
	while (tab)
	{
		while (ins)
		{
			get_argument_coding_byte();
			ins = ins->next;
		}
		tab = tab->next;
	}
}
