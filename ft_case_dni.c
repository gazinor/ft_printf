/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_dni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:58:06 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 22:12:04 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_zero(t_struct *p, int signe)
{
	int		i;

	i = -1;
	while (++i < p->precision - p->len + signe)
		ft_putchar('0', p);
}

void	ft_width_num(t_struct *p, long copy, char c)
{
	int			i;
	long		c_copy;

	i = -1;
	c_copy = copy < 0 ? -copy : copy;
	if (p->minus == TRUE)
	{
		copy < 0 ? ft_putchar('-', p) : 1;
		if (p->precision > p->len)
			ft_display_zero(p, copy < 0 ? 1 : 0);
		if (!(copy == 0 && p->dot == TRUE && p->width != 0))
			ft_putnbr_base((long)c_copy, "0123456789", p);
		else
			p->len = 0;
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
	}
	else
	{
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
		copy < 0 ? ft_putchar('-', p) : 1;
		if (p->precision > p->len)
			ft_display_zero(p, copy < 0 ? 1 : 0);
		if (!(copy == 0 && p->dot == TRUE && p->width != 0))
			ft_putnbr_base((long)c_copy, "0123456789", p);
		else
			ft_putchar(' ', p);
	}
}

void	ft_num(t_struct *p)
{
	long	copy;

	copy = (int)va_arg(p->ap, void *);
	p->len = ft_nbrlen((int)copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	else
		p->precision = 0;
	ft_width_num(p, copy, p->zero == TRUE ? '0' : ' ');
}
