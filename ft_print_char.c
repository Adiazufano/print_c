/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:17:43 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/24 19:38:08 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtprintf.h"

void	ft_print_char(va_list args, int *count)
{
	char	c;

	c = (char) va_arg(args, int);
	ft_putchar_fd(c, 1);
	(*count)++;
}
