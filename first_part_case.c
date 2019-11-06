/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:18:00 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/06 14:15:12 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	ft_case_c(va_list ap, int *count)
{
	*count += ft_putchar(va_arg(ap, int));
}

void	ft_case_s(va_list ap, int *count)
{
	*count += ft_putstr(va_arg(ap, char *));
}

void	ft_case_p(va_list ap, int *count)
{
	ft_putnbr_base(va_arg(ap, long int), "0123456789abcdef", 1, count);
}

void	ft_case_dni(va_list ap, int *count)
{
	ft_putnbr(va_arg(ap, int), count);
}
