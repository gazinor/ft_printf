/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:30:51 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/12 16:18:14 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_fct(pointe fct[100])
{
	fct['c'] = &ft_c;
	fct['s'] = &ft_str;
	fct['d'] = &ft_num;
	fct['i'] = &ft_num;
//	fct['x'] = &ft_base;
//	fct['p'] = &ft_base;
//	fct['X'] = &ft_base;
}

void	ft_reset_flags(t_struct *p)
{
	p->flags['-'] = 0;
	p->flags['.'] = 0;
	p->flags['0'] = 0;
	p->precision = 0;
	p->width = 0;
	p->len = 0;
}

void	ft_init_p(t_struct *p, const char *format, pointe fct[100])
{
	p->format = NULL;
	p->count = 0;
	p->i = 0;
	p->total = 0;
	ft_init_fct(fct);
}


int	ft_printf(const char *format, ...)
{
	t_struct	p;
	pointe		fct[100];

	ft_init_p(&p, format, fct);
	p.format = format;
	va_start(p.ap, format);
	while (p.format[p.total])
		++p.total;
	while (p.format[p.i])
	{
		if (p.format[p.i] == '%')
		{
			ft_reset_flags(&p);
			ft_look(&p, fct);
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
