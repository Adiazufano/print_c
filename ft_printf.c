/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:24 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 09:16:29 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtprintf.h"

static int	ft_handle_format(char type, va_list args, int *count)
{
	if (type == 's')
		ft_print_str(args, count);
	else if (type == 'i' || type == 'd')
		ft_print_int(args, count, type);
	else if (type == 'u')
		ft_unsigned_int(args, count);
	else if (type == 'c')
		ft_print_char(args, count);
	else if (type == 'x' || type == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), count, type);
	else if (type == 'p')
		ft_print_ptr(args, count);
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (!ft_handle_format(str[i], args, &count))
				continue ;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int	x;
	int	*ptr;
	int	i;

	x = 10;
	ptr = &x;
	// Casos de prueba individuales
	ft_printf("String: %s\n", "Hola");
	i = ft_printf("Char: %c\n", 'A');
	ft_printf("Integer: %d\n", 42);
	ft_printf("Unsigned: %u\n", -20);
	ft_printf("Hex (lower): %x\n", 255);
	ft_printf("Hex (upper): %X\n", -255);
	ft_printf("Pointer: %p\n", ptr);
	ft_printf("Literal %%: %%\n");
	// Prueba combinada
	ft_printf("Combinado: %s %d %u %x %p %%\n", "Hola", -123, -456, 255, ptr);
	ft_printf("%i", i);
	return (0);
}
