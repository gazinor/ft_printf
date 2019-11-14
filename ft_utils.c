/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:13:17 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/14 03:58:15 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

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

void	ft_putnbr_base(unsigned long long n, char *base)
{
	int					i;

	i = 0;
	while (base[i])
		i++;
	if (n >= i)
	{
		ft_putnbr_base(n / i, base);
		ft_putnbr_base(n % i, base);
	}
	else
		ft_putchar(base[n]);
}
