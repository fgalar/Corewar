/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:21:14 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/15 14:45:08 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		end_quote(char **cmd, t_file *file, int modif)
{
	int i;
	int line;

	i = 0;
	line = file->line;
	while (ft_itersplit(cmd, i) && *ft_itersplit(cmd, i) != '"')
		i++;
	if (!ft_itersplit(cmd, i))
		return (1);
	if (ft_itersplit(cmd, i + 1) && *ft_itersplit(cmd, i + 1) != '#')
		return (-1 + lexicon_error(cmd, i, "invalid format or quotes", line));
	if (modif)
		file->quotes = 0;
	return (1);
}
