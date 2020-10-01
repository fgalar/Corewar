/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:46:06 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/22 02:01:51 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		every_char(char *str, int pos, char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (str[pos] == c[i])
			return (1);
		i++;
	}
	return (0);
}

static int		skip_spaces(char *str, int pos, char *c)
{
	while (str[pos] && every_char(str, pos, c))
		pos++;
	return (pos);
}

static int		ft_count_letters(char *str, int letrs, char *c)
{
	while (str[letrs] && !every_char(str, letrs, c))
		letrs++;
	return (letrs);
}

int				ft_count_words(char *str, int spos, int cont, char *c)
{
	spos = skip_spaces(str, spos, c);
	if (!str[spos])
		return (cont);
	while (str[spos] && !every_char(str, spos, c))
		spos++;
	return (ft_count_words(str, spos, cont + 1, c));
}

char			**ft_decompose(char **tab, char *str, int spos, char *c)
{
	int letrs;
	int i;
	int tpos;

	tpos = 0;
	while (str[spos])
	{
		spos = skip_spaces(str, spos, c);
		if (!str[spos])
			break ;
		letrs = ft_count_letters(str, spos, c);
		if (!(tab[tpos] = (char*)malloc(sizeof(char) * (letrs + 1 - spos))))
			return (0);
		i = 0;
		while (str[spos] && !every_char(str, spos, c))
		{
			tab[tpos][i] = str[spos];
			spos++;
			i++;
		}
		tab[tpos++][i] = '\0';
	}
	tab[tpos] = 0;
	return (tab);
}
