/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 02:53:58 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 03:55:29 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbrlen_base(long nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		size++;
	}
	return (size);
}

void	ft_width_num_p(t_struct *p, long copy, char c)
{
	int		i;

	i = -1;
	write(1, "0x", 2);
	if (p->minus == TRUE)
	{
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned long long)copy, "0123456789abcdef");
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c);
	}
	else
	{
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c);
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned long long)copy, "0123456789abcdef");
	}
}

void	ft_num_p(t_struct *p)
{
	long copy;

	copy = (unsigned long)va_arg(p->ap, void *);
	p->len = ft_nbrlen_base((unsigned long)copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num_p(p, copy, p->zero == TRUE ? '0' : ' ');
}
