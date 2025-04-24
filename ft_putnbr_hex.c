/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:21:30 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:55 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtprintf.h"

void	ft_putnbr_hex(unsigned long num, int *count, char type)
{
	char	*base;

	if (num >= 16)
		ft_putnbr_hex(num / 16, count, type);
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	ft_putchar_fd(base[num % 16], 1);
	(*count)++;
}
