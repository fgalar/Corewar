/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:03:41 by ciglesia          #+#    #+#             */
/*   Updated: 2020/08/25 17:32:32 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_max(uintmax_t x, int fd)
{
	if (x >= 10)
		return (ft_putnbr_max(x / 10, fd) + ft_putchar_fd(x % 10 + 48, fd));
	else
		return (ft_putchar_fd(x + 48, fd));
}
