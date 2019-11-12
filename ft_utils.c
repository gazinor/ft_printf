/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:13:17 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/12 10:35:57 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (str[i])
		i++;
	write(1, str, i);
}

int		ft_check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (!base || !base[i])
		return (0);
	while (base[i])
	{
		j = i + 1;
		if ((base[i] >= '0' && base[i] <= '9') ||( base[i] >= 'a' &&
		base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))
		{
			while (base[j++])
				if (base[i] == base[j])
					return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_putnbr_base(unsigned long long n, char *base, int signe)
{
	unsigned long long nb;
	int		i;

	nb = n;
	i = 0;
	if (ft_check_base(base) == 0)
		return ;
	while(base[i])
		i++;
	if (signe == -1)
		ft_putchar('-');
	if (nb > i)
	{
		ft_putnbr_base(nb / i, base, 1);
		ft_putnbr_base(nb % i, base, 1);
	}
	else
		ft_putchar(base[nb]);
}
