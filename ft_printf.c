/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:27 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/07 21:34:03 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

			//ft_point_case(format, count);
			//ft_minus_case(format, count);
			//ft_zero_case(format, count);
			//ft_wildcard_case(format, count);

t_f		g_cases[255] =
{
	['c'] = &ft_case_c,
	['s'] = &ft_case_s,
	['d'] = &ft_case_dni,
	['i'] = &ft_case_dni,
	['u'] = &ft_case_u,
	['x'] = &ft_case_x,
	['X'] = &ft_case_X,
	['p'] = &ft_case_p,
	['%'] = &ft_case_percent
};

bool	g_flag_charset[255] =
{
	['.'] = false;
	['-'] = false;
	['*'] = false;
	['0'] = false;
};

char	*ft_define_type(char c)
{
	char	*type;

	if (c == 'c')
		return (type = ft_strdup("char"));
	if (c == 's')
		return (type = ft_strdup("char *"));
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return(type = ft_strdup("int"));
	return (NULL);
}

void	ft_check_flags(const char *format, int i)
{
	while (format[i] && !g_cases[format[i]])
	{
		if (format[i] == '.' || format[i] == '-' ||
			format[i] == '0' || format[i] == '*')
			g_flag_charset[format[i]] = true;
		++i;
	}
	if (g_cases[format[i]] != NULL)
		element.type = ft_define_type(format[i]);
}

void	ft_init_flags(const char *format, int i)
{
	ft_check_flags(format, i);
	while (format[i])
	{
		if (element.width == 0 && format[i] >= '0' && format[i] <= '9')
			element.width = ft_atoi(format + i + 1);
		else if (format[i] == '.')
		{
			element.precision = ft_atoi(format + i + 1);
			break ;
		}
		++i;
	}
}

int		ft_case_all(va_list ap, const char *format, int *count)
{
	t_f		f;
	int		i;

	i = 0;
	if (format[++i])
	{
		if ((f = g_cases[format[i]]) != NULL)
			f(ap, count);
		else
			i += ft_init_flags(format + i, count, 0);
	}
	else
		return (0);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			i;

	i = -1;
	count = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i += ft_case_all(ap, format + i, &count);
		else
			count += ft_putchar(format[i]);
	}
	va_end(ap);
	return (count);
}
