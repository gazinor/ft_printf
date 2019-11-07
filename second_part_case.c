/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:18:13 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/07 17:03:11 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void    ft_case_u(va_list ap, int *count)
{
	ft_putnbr_u(va_arg(ap, unsigned int), count);
}

void    ft_case_x(va_list ap, int *count)
{
	ft_putnbr_base(va_arg(ap, int), "0123456789abcdef", 0, count);
}

void    ft_case_X(va_list ap, int *count)
{
	ft_putnbr_base(va_arg(ap, int), "0123456789ABCDEF", 0, count);
}

void    ft_case_percent(va_list ap, int *count)
{
	write(1, "%", 1);
	++*count;
}
