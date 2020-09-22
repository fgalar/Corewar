/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 22:21:40 by ciglesia          #+#    #+#             */
/*   Updated: 2020/09/22 13:01:35 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	t_file	file;

	if (ac != 2 && (ac == 3 && ft_strcmp(av[1], "-v") != 0))
		return (ft_puterr(ERROR""RED": assembler needs exactly one file!"E0M,
						EXIT_FAILURE));
	else if (ac == 2 || (ac == 3 && ft_strcmp(av[1], "-v") == 0))
	{
		file_init(&file);
		if (valid_input((ac == 2) ? av[1] : av[2], &file) == EXIT_FAILURE)
			return (EXIT_FAILURE + file_destructor(&file));
		if (verify_code(&file, NULL, 0, 0) == EXIT_FAILURE)
			return (EXIT_FAILURE + file_destructor(&file));
		translate(&file, (ac == 3) ? ft_strcmp(av[1], "-v") == 0 : 0);
		file_destructor(&file);
	}
	return (EXIT_SUCCESS);
}
