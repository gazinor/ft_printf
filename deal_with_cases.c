/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:31:48 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/04 23:22:54 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		;
	write(1, str, i);
	return (i);
}

int		ft_putnbr(int n)
{
	unsigned int	nb;
	static int		count = 0;

	nb = (n < 0 ? -n : n);
	if (n < 0)
	{
		write(1, "-", 1);
		++count;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
	++count;
	return (count);
}

int		ft_putnbr_u(unsigned int n)
{
	static int		count = 0;
	
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n % 10 + '0');
	++count;
	return (count);
}

int		ft_putnbr_base(int n, char *base, int ptr)
{
	unsigned long int	nb;
	int					base_len;
	static int			count = 0;

	(ptr == 1) ? write(1, "0x", 2) : 1;
	base_len = 0;
	while (base[base_len])
		++base_len;
	nb = (n < 0 ? -n : n);
	if (n < 0)
	{
		write(1, "-", 1);
		++count;
	}
	if (nb > base_len - 1)
	{
		ft_putnbr_base(nb / base_len, base, 0);
		ft_putchar(base[nb % base_len]);
	}
	else
		ft_putchar(base[nb % base_len]);
	++count;
	return (count);
}
