/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:20:07 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/25 13:45:55 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	counter(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_unsigned(unsigned int nbr)
{
	char				*str;
	int					i;
	unsigned int		nb;

	nb = nbr;
	i = counter(nb);
	if (nb == 0)
		return (ft_strdup("0"));
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
}

void	ft_unsigned_int(va_list args, int *count)
{
	unsigned int		num;
	char				*s;

	num = va_arg(args, unsigned int);
	s = ft_itoa_unsigned(num);
	if (s)
	{
		ft_putstr_fd(s, 1);
		(*count) += ft_strlen(s);
		free(s);
	}
}
