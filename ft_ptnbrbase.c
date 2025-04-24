/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptnbrbase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldiaz-u <aldiaz-u@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:27:16 by aldiaz-u          #+#    #+#             */
/*   Updated: 2025/04/24 19:38:41 by aldiaz-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count_digits(int nbr, int base_len)
{
	int	count;

	count = 1;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr > 0)
	{
		count++;
		nbr /= base_len;
	}
	return (count);
}

static void	check_base(int base_len, char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base_len < 2)
		return ;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return ;
			j++;
		}
		i++;
	}
}

void	ft_putnbrbase(int nbr, char *base)
{
	int		base_len;
	long	num;

	base_len = ft_strlen(base);
	num = nbr;
	check_base(base_len, base);
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num >= base_len)
		ft_putnbrbase(num / base_len, base);
	ft_putchar_fd(base[num % base_len], 1);
}
