/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:22:47 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 10:11:42 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_ptr(va_list args, int *count)
{
	long	num;

	if (!args || !count)
		return ;
	num = va_arg(args, unsigned long);
	if (num == 0)
	{
		ft_putstr_fd("0x0", 1);
		(*count) += 3;
		return ;
	}
	ft_putstr_fd("0x", 1);
	(*count) += 2;
	ft_putnbr_hex(num, count, 'p');
}
