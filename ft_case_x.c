/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:34:22 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 10:56:55 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_num_x(t_struct *p, unsigned int copy, char c)
{
	int		i;

	i = -1;
	if (p->minus == TRUE)
	{
		if (p->precision > p->len)
			ft_display_zero(p, copy == 0 ? 1 : 0);
		if (copy == 0 && p->dot == TRUE)
			return ;
		ft_putnbr_base((unsigned int)copy, "0123456789abcdef", p);
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
	}
	else
	{
		while (++i < (p->width + (p->precision == -1 ? 1 : 0) -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
		if (p->precision > p->len)
			ft_display_zero(p, copy == 0 ? 1 : 0);
		if (copy == 0 && p->dot == TRUE)
			return ;
		ft_putnbr_base((unsigned int)copy, "0123456789abcdef", p);
	}
}

void	ft_num_x(t_struct *p)
{
	unsigned int copy;

	copy = (unsigned int)va_arg(p->ap, void *);
	p->len = ft_nbrlen_base(copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num_x(p, copy, p->zero == TRUE ? '0' : ' ');
}
