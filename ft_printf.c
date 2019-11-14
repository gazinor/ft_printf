/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:30:51 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/14 05:42:38 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_struct *p)
{
	p->dot = FALSE;
	p->minus = FALSE;
	p->zero = FALSE;
	p->precision = 0;
	p->width = 0;
	p->len = 0;
}

void	ft_init_p(t_struct *p, const char *format)
{
	p->format = NULL;
	p->count = 0;
	p->i = 0;
	p->total = 0;
}

void	ft_look(t_struct *p)
{
	while (++p->i < p->total &&
			(ft_set_find(p->format[p->i]) == 1))
		ft_check_again_xd(p);
	if (p->minus == TRUE)
		p->zero = FALSE;
	if (p->format[p->i] == 'c')
		ft_c(p);
	else if (p->format[p->i] == 's')
		ft_str(p);
	else if (p->format[p->i] == 'd' || p->format[p->i] == 'i')
		ft_num(p);
	else if (p->format[p->i] == 'u')
		ft_num_u(p);
	else if (p->format[p->i] == 'x')
		ft_num_x(p);
	else if (p->format[p->i] == 'X')
		ft_num_x_big(p);
	else if (p->format[p->i] == '%')
		ft_pct(p);
	else if (p->format[p->i] == 'p')
		ft_num_p(p);
}

int		ft_printf(const char *format, ...)
{
	t_struct	p;

	ft_init_p(&p, format);
	p.format = format;
	va_start(p.ap, format);
	while (p.format[p.total])
		++p.total;
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
		{
			ft_reset_flags(&p);
			ft_look(&p);
		}
		else
			ft_putchar(p.format[p.i], &p);
		++p.i;
	}
	va_end(p.ap);
	return (p.count);
}
