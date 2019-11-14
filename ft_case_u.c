/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:58:06 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 01:53:11 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_num_u(t_struct *p, int copy, char c)
{
	int		i;
	int		c_copy;

	i = -1;
	if (p->minus == TRUE)
	{
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((unsigned int)copy,
				"0123456789");
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
		ft_putnbr_base((unsigned int)copy,
				"0123456789");
	}
}

void	ft_num_u(t_struct *p)
{
	unsigned int	copy;

	copy = (unsigned int)va_arg(p->ap, void *);
	p->len = ft_nbrlen(copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num_u(p, copy, p->zero == TRUE ? '0' : ' ');
}
