/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_x_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 01:17:23 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/14 11:39:42 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_num_x_big(t_struct *p, unsigned long copy, char c)
{
   int     i;

   i = -1;
   if (p->minus == TRUE)
   {
       if (p->precision > p->len)
           ft_display_zero(p, copy == 0 ? 1 : 0);
       if (copy == 0 && p->dot == TRUE)
           return ;
       ft_putnbr_base((unsigned long)copy, "0123456789ABCDEF", p);
       while (++i < (p->width -
                   (p->precision > p->len ? p->precision : p->len)))
           ft_putchar(c, p);
   }
   else
   {
       while (++i < (p->width + (p->precision == -1 ? 1 : 0) -
                   (p->precision > p->len ? p->precision : p->len)))
           ft_putchar(c, p);
       if (p->precision > p->len)
           ft_display_zero(p, copy == 0 ? 1 : 0);
       if (copy == 0 && p->dot == TRUE)
           return ;
       ft_putnbr_base((unsigned long)copy, "0123456789ABCDEF", p);
   }
}

void	ft_num_x_big(t_struct *p)
{
	unsigned int		copy;

	copy = (unsigned int)va_arg(p->ap, void *);
	p->len = ft_nbrlen_base(copy);
	if (p->dot == TRUE)
		p->zero = FALSE;
	ft_width_num_x_big(p, copy, p->zero == TRUE ? '0' : ' ');
}
