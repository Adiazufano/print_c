/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:24 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/23 17:19:43 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtprintf.h"

void	ft_print_str(char const *str, va_list args)
{
	char	*s;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 's')
		{
			s = va_arg(args, char *);
			ft_putstr_fd(s, 1);
		}
		i++;
	}
}
void	ft_print_char(char const *str, va_list args)
{
	char	c;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'c')
		{
			c = va_arg(args, char);
			ft_putchar_fd(c, 1);
		}
		i++;
	}
}
void	ft_print_int(char const *str, va_list args)
{
	int	num;
	int	i;
	char	*s;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'i')
		{
			num = va_arg(args, int);
			s = ft_itoa(num);
			ft_putstr_fd(s, 1);
			free(s);
		}
		i++;
	}
}
void	ft_unsigned_int(char const *str, va_list args)
{
	int	num;
	int	i;
	char	*s;

	i = 0;
	num = va_arg(args, int);
	if (num < 0)
		num = -num;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == 'u')
		{
			s = ft_itoa(num);
			ft_putstr_fd(s, 1);
			free(s);
		}
		i++;
	}
}
void	ft_print_porcentaje(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar_fd('%', 1);
		i++;
	}
}
void	ft_print_hexadecima(va_list args, char type)
{
	int	num;
	int i;
	char	hex[9];

	num = va_arg(args, unsigned int);
	i = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return;
	}
	while (num > 0)
	{
		if (num % 16 < 10)
			hex[i] = (num % 16) + '0';
		else if (type == 'x')
			hex[i] = (num % 16) - 10 + 'a';
		else if	(type == 'X')
			hex[i] = (num % 16) - 10 + 'A';
		num /= 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(hex[i], 1);
	
}

void	ft_print_ptr(va_list args)
{
	long	num;
	long i;
	char	hex[17];

	num = va_arg(args, unsigned long);
	i = 0;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return;
	}
	while (num > 0)
	{
		if (num % 16 < 10)
			hex[i] = (num % 16) + '0';
		else
			hex[i] = (num % 16) - 10 + 'a';
		num /= 16;
		i++;
	}
	ft_putstr_fd("0x",1);
	while (--i >= 0)
		ft_putchar_fd(hex[i], 1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	va_start(args, str);
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_print_str(str, args);
			if (str[i] == 'i')
				ft_print_int(str,args);
			if (str[i] == 'c')
				ft_print_char(str, args);
			if (str[i] == 'u')
				ft_unsigned_int(str, args);
			if (str[i] == '%')
				ft_print_porcentaje(str);
			if (str[i] == 'x')
				ft_print_hexadecima(args, 'x');
			if (str[i] == 'X')
				ft_print_hexadecima(args, 'X');
			if (str[i] == 'p')
				ft_print_ptr(args);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main()
{
	int x = 10;
	int *ptr = &x;
	ft_printf("Hola %s que tal %i kdkkhadk %c tengo :%u años? %% %x %X", "Alberto", 3, 'k', -20, 255, 25);
	ft_printf("\n%p\n",&ptr);
	return(0);
}