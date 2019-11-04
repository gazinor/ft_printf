/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:27 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/04 23:24:30 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"

int		ft_check_flags(const char *format, int count, int i)
{
	while (format[i])
	{
		 
	}
	return (i);
}

int		ft_case_all(va_list ap, const char *format, int count)
{
	t_func	f;
	int		i;

	i = 0;
	if (fomat[++i])
	{
		if ((f = g_case[format[i]]) != NULL)
			f(ap, count);
		else
			i += ft_check_flags(format, count, i);
	}
	else
		return (0);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	static int	count = 0;
	int			i;

	i = -1;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i += ft_case_all(ap, format + i, count);
		else
			count += ft_putchar(format[i]);
	}
	va_end(ap);
	return (count);
}
