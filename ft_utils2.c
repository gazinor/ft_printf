/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 01:37:47 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/18 20:12:47 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_find(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' || c == 'x' || c == 'X' ||
			c == 'u' || c == 'p' || c == '%')
		return (0);
	else if (c != 'c' && c != 'd' && c != 'i' && c != 's' && c != 'x' &&
		c != 'X' && c != 'u' && c != 'p' && c != '%' && c != '-' &&
		c != '*' && c != '.' && !(c >= '0' && c <= '9'))
		return (0);
	else if (c == '\0')
		return (-1);
	return (1);
}

void	ft_check_again_xd(t_struct *p)
{
	if (p->format[p->i] == '*')
	{
		if (p->format[p->i - 1] == '.')
		{
			if ((p->precision = (int)va_arg(p->ap, void *)) < 0)
				p->dot = FALSE;
			p->precision = p->precision <= 0 ? -1 : p->precision;
		}
		else if ((p->width = (int)va_arg(p->ap, void *)) < 0)
		{
			p->width = -p->width;
			p->minus = TRUE;
		}
	}
	else if (p->format[p->i] == '-')
		p->minus = TRUE;
	else if (p->format[p->i] == '0')
		p->zero = TRUE;
	else if (p->format[p->i] == '.')
	{
		p->dot = TRUE;
		p->precision = ft_atoi(p);
	}
	else if (p->format[p->i] >= '1' && p->format[p->i] <= '9')
		p->width = ft_atoi(p);
}

int		ft_atoi(t_struct *p)
{
	int nb;

	nb = 0;
	if (p->format[p->i] == '.' && !(p->format[++p->i] >= '0' &&
				p->format[p->i] <= '9'))
	{
		--p->i;
		return (-1);
	}
	while (p->format[p->i] >= '0' && p->format[p->i] <= '9')
	{
		nb = nb * 10 + (p->format[p->i] - '0');
		++p->i;
	}
	--p->i;
	return (nb);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (6);
	while (str[i])
		i++;
	return (i);
}

int		ft_nbrlen(long nb)
{
	int size;

	size = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
		size++;
	while (nb != 0)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
