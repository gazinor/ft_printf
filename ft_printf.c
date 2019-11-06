/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:27 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/06 15:25:44 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
/*
int		ft_check_flags(const char *format, int *count, int i)
{
	while (format[i])
	{
		 if (format[i] == '.')
			ft_point_case(format, count);
		 if (format[i] == '-')
		 	ft_minus_case(format, count);
		 if (format[i] == '0')
		 	ft_zero_case(format, count);
		 if (format[i] == '*')
		 	ft_wildcard_case(format, count);
	}
	return (i);
}
*/
t_f g_cases[255] =
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

int		ft_case_all(va_list ap, const char *format, int *count)
{
	t_f		f;
	int		i;

	i = 0;
	if (format[++i])
	{
		if ((f = g_cases[format[i]]) != NULL)
			f(ap, count);
//		else
//			i += ft_check_flags(format + i, count, 0);
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

int main()
{
	int p = 123;
	int ret1;
	int ret2;

//	ret1 =    printf("\n---VRAI PRINTF :\n%d\n%u\n%u\n%d\n%x\n%X\n%d", 741, 852, 963, 789, 123, 546, 0x456545);
//	ret2 = ft_printf("\n---FAUX PRINTF :\n%d\n%u\n%u\n%d\n%x\n%X\n%d", 741, 852, 963, 789, 123, 546, 0x456545);
//	printf("\nret1 = %d\nret2 = %d\n", ret1, ret2);
	printf("%-.22s\n", "salut comment ca va ?");
	return (0);
}
