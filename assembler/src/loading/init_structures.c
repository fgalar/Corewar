/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:49:08 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/22 14:44:09 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			file_init(t_file *file, char *name)
{
	file->fd = -1;
	file->line = 0;
	file->quotes = 0;
	file->name = NULL;
	file->code_tab = NULL;
	file->name = ft_strdup(name);
	ft_memset(file->comment, 0, COMMENT_LENGTH);
	ft_memset(file->playername, 0, PROG_NAME_LENGTH);
	ft_memset(file->code, 0, CHAMP_MAX_SIZE);
}

t_code			*new_label(void)
{
	t_code *new;

	if (!(new = (t_code*)malloc(sizeof(t_code))))
		return (NULL);
	new->label = NULL;
	new->instr = NULL;
	new->next = NULL;
	return (new);
}

t_instruction	*new_instruction(void)
{
	t_instruction	*new;

	if (!(new = (t_instruction*)malloc(sizeof(t_instruction))))
		return (NULL);
	new->opcode = 0;
	new->acb = 0;
	new->reg = 0;
	new->dir = NULL;
	new->ind = NULL;
	new->next = NULL;
	return (new);
}

void			free_instructions(t_instruction *instr)
{
	t_instruction *aux;

	while (instr)
	{
		if (instr->dir)
			free(instr->dir);
		if (instr->ind)
			free(instr->ind);
		aux = instr->next;
		free(instr);
		instr = aux;
	}
}

int				file_destructor(t_file *file)
{
	t_code	*table;
	t_code	*tabaux;

	if (file->name)
		free(file->name);
	if (file->code_tab)
	{
		table = file->code_tab;
		while (table)
		{
			if (table->instr)
				free_instructions(table->instr);
			if (table->label)
				free(table->label);
			tabaux = table->next;
			free(table);
			table = tabaux;
		}
	}
	return (0);
}
