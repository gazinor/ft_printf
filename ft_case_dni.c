/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_dni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:58:06 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/12 11:09:46 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_zero(t_struct *p)
{
	int		i;

	i = -1;
	while (++i < p->precision - p->len)
	{
		ft_putchar('0');
		++p->count;
	}
}

void	ft_width_num(t_struct *p, int copy, char c)
{
	int		i;

	i = -1;
	if (p->flags['-'] == 1)
	{
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned long long)copy,
				"0123456789", copy < 0 ? -1 : 1);
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
		{
			ft_putchar(c);
			++p->count;
		}
	}
	else
	{
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
		{
			ft_putchar(c);
			++p->count;
		}
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
	if (p->flags['.'] == 1)
		p->flags['0'] = 0;
	ft_width_num(p, copy, p->flags['0'] == 1 ? '0' : ' ');
}
