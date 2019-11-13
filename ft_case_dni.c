/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_dni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:58:06 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/13 19:52:47 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_zero(t_struct *p)
{
	int		i;

	i = -1;
	while (++i < p->precision - p->len)
		ft_putchar('0');
}

void	ft_width_num(t_struct *p, int copy, char c)
{
	int		i;

	i = -1;
	if (p->minus == TRUE)
	{
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned long long)copy,
				"0123456789", copy < 0 ? -1 : 1);
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
		ft_putnbr_base((unsigned long long)copy,
				"0123456789", copy < 0 ? -1 : 1);
	}
}

void	ft_num(t_struct *p)
{
	int		copy;

	copy = (int)va_arg(p->ap, void *);
	p->len = ft_nbrlen(copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num(p, copy, p->zero == TRUE ? '0' : ' ');
}
