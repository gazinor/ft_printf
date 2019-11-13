/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:30:51 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/13 19:58:15 by glaurent         ###   ########.fr       */
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
	while (p->i < p->total &&
			(ft_set_find(p->format[p->i]) == 1))
	{
		ft_check_again_xd(p);
		if (p->format[p->i + 1] && p->format[p->i + 1] == '%')
		{
			ft_putchar('%');
			++p->i;
			break ;
		}
		++p->i;
	}
	if (p->minus == TRUE)
		p->zero = FALSE;
	if (p->format[p->i] == 'c')
		ft_c(p);
	if (p->format[p->i] == 's')
		ft_str(p);
	if (p->format[p->i] == 'd' || p->format[p->i] == 'i')
		ft_num(p);
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
		{
			ft_putchar(p.format[p.i]);
			++p.count;
		}
		++p.i;
	}
	va_end(p.ap);
	return (p.count);
}
