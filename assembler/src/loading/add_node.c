/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:59:54 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/15 20:04:03 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	add_label(t_file *file, char *label)
{
	unsigned int	i;
	t_code			*new;
	t_code			*aux;

	i = 0;
	while (label[i] && label[i] != ':')
		i++;
	new = new_label();
	new->label = ft_strndup(label, i);
	aux = file->code_tab;
	if (!aux)
		file->code_tab = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;

	}
}

void	add_instruction(t_file *file, char **cmd, int i)
{
	(void)file;
	if (ft_itersplit(cmd, i))
		ft_printf("OPCODE: %s\n", ft_itersplit(cmd, i));
}
