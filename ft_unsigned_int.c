/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:20:07 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 10:12:10 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_unsigned(unsigned int nbr)
{
	char				*str;
	int					i;
	unsigned int		nb;

	i = 1;
	nb = nbr;
	if (!nbr)
		return (NULL);
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i)
	{
		str[--i] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
	printf("%i", i);
	return (str);
}

void	ft_unsigned_int(va_list args, int *count)
{
	unsigned int		num;
	unsigned int		result;
	char				*s;

	num = (unsigned int) va_arg(args, unsigned int);
	s = ft_itoa_unsigned(num);
	if (!args || !count)
		return ;
	if (s)
	{
		ft_putstr_fd(s, 1);
		(*count) += ft_strlen(s);
		free(s);
	}
}
