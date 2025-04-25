/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:15:46 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 10:12:32 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_str(va_list args, int *count)
{
	char	*s;
	int		i;

	i = 0;
	s = va_arg(args, char *);
	if (!args || !count)
		return ;
	ft_putstr_fd(s, 1);
	(*count) += ft_strlen(s);
}
