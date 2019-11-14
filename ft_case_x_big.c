/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_x_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:17:23 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 05:54:40 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_num_x_big(t_struct *p, unsigned int copy, char c)
{
	int		i;
	int		c_copy;

	i = -1;
	if (p->minus == TRUE)
	{
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned int)copy, "0123456789ABCDEF", p);
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
	}
	else
	{
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned int)copy, "0123456789ABCDEF", p);
	}
}

void	ft_num_x_big(t_struct *p)
{
	unsigned int		copy;

	copy = (unsigned int)va_arg(p->ap, void *);
	p->len = ft_nbrlen(copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num_x_big(p, copy, p->zero == TRUE ? '0' : ' ');
}
