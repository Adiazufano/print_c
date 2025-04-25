/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:28:26 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 11:12:56 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

void	ft_print_str(va_list args, int *count);
void	ft_print_char(va_list args, int *count);
void	ft_print_int(va_list args, int *count, char type);
void	ft_unsigned_int(va_list args, int *count);
void	ft_putnbr_hex(unsigned long num, int *count, char type);
void	ft_print_ptr(va_list args, int *count);
int		ft_printf(char const *str, ...);
#endif