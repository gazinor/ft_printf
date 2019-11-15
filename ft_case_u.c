/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 09:58:06 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/15 00:17:22 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_num_u(t_struct *p, unsigned int copy, char c)
{
	int		i;

	i = -1;
	if (p->minus == TRUE)
	{
		if (p->precision > p->len)
			ft_display_zero(p, copy == 0 ? 1 : 0);
		if (copy == 0 && p->dot == TRUE)
			return ;
		ft_putnbr_base((unsigned int)copy, "0123456789", p);
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
	}
	else
	{
		while (++i < (p->width -
					(p->precision > p->len ? p->precision : p->len)))
			ft_putchar(c, p);
		if (p->precision > p->len)
			ft_display_zero(p, copy == 0 ? 1 : 0);
		if (copy == 0 && p->dot == TRUE)
			return ;
		ft_putnbr_base((unsigned int)copy, "0123456789", p);
	}
}

void	ft_num_u(t_struct *p)
{
	unsigned int	copy;

	copy = (unsigned int)va_arg(p->ap, void *);
	p->len = ft_nbrlen(copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	else
		p->precision = 0;
	ft_width_num_u(p, copy, p->zero == TRUE ? '0' : ' ');
}
