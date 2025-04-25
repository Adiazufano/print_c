/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:24 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 13:43:08 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

// int	main()
// {
// 	//printf("%x", 0);
// 	ft_printf("%X", 0);
// 	return (0);
// }