/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_dni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:58:06 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 02:53:19 by glaurent         ###   ########.fr       */
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

void	ft_width_num(t_struct *p, long copy, char c)
{
	int			i;
	long		c_copy;

	i = -1;
	c_copy = copy < 0 ? -copy : copy;
	if (p->minus == TRUE)
	{
		copy < 0 ? ft_putchar('-') : 1;
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((long)c_copy, "0123456789");
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c);
	}
	else
	{
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c);
		copy < 0 ? ft_putchar('-') : 1;
		(p->precision > p->len) ? ft_display_zero(p) : 1;
		ft_putnbr_base((long)c_copy, "0123456789");
	}
}

void	ft_num(t_struct *p)
{
	long	copy;

	copy = (int)va_arg(p->ap, void *);
	p->len = ft_nbrlen((int)copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num(p, copy, p->zero == TRUE ? '0' : ' ');
}
