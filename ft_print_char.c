/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:17:43 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 10:12:58 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_char(va_list args, int *count)
{
	char	c;

	c = (char) va_arg(args, int);
	if (!args || !count)
		return ;
	ft_putchar_fd(c, 1);
	(*count)++;
}
