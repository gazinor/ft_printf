/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:41:28 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/11 10:28:50 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_struct *p)
{
	int		i;
	char	copy;

	i = -1;
	copy = (char)va_arg(p->ap, void*);
	if (p->flags['-'] == 1)
	{
		ft_putchar(copy ? copy : '\0');
		while (++i < p->width - 1)
		{
			ft_putchar(' ');
			p->count++;
		}
	}
	else
	{
		while (++i < p->width - 1)
		{
			ft_putchar(p->flags['0'] == 1 ? '0' : ' ');
			p->count++;
		}
		ft_putchar(copy ? copy : '\0');
	}
	p->count++;
}
