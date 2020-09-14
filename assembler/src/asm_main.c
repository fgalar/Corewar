/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:21:40 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/07 20:53:41 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_file file;

	if (ac != 2)
		return (ft_puterr(ERROR""RED": assembler needs exactly one file!"E0M,
						EXIT_FAILURE));
	else
	{
		file_init(&file);
		if (valid_input(av[1], &file) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
