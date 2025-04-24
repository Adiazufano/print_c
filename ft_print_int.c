/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:18:49 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/24 19:37:29 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtprintf.h"

void	ft_print_int(va_list args, int *count, char type)
{
	int		num;
	char	*s;

	num = va_arg(args, int);
	s = ft_itoa(num);
	if (s)
	{
		ft_putstr_fd(s, 1);
		(*count) += ft_strlen(s);
		free(s);
	}
}
