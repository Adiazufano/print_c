/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:20:07 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/24 19:37:09 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtprintf.h"

void	ft_unsigned_int(va_list args, int *count)
{
	unsigned int	num;
	char			*str;

	num = va_arg(args, unsigned int);
	str = ft_itoa(num);
	if (str)
	{
		ft_putstr_fd(str, 1);
		(*count) += ft_strlen(str);
		free(str);
	}
}
