/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:33 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/04 22:26:52 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_base(int n, char *base, int ptr);
void	ft_case_c(va_list ap, int count);
void	ft_case_s(va_list ap, int count);
void	ft_case_p(va_list ap, int count);
void	ft_case_dni(va_list ap, int count);
void	ft_case_u(va_list ap, int count);
void	ft_case_x(va_list ap, int count);
void	ft_case_X(va_list ap, int count);
void	ft_case_percent(va_list ap, int count);
int		ft_case_all(va_list ap, const char *format, int count);
int		ft_printf(const char *format, ...);

typedef void (*t_f)(va_list, int);

t_f	g_case[255] =
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
/*
   typedef enum	e_case
   {
   CHAR = 0,
   STRING,
   INT,
   INT2,
   UNSIGNED_INT,
   HEX,
   UNSIGNED_HEX,
   ADDRESS,
   STOP
   }				t_case;

   typedef	struct	s_list t_list;

   struct			s_list
   {
   char		c;
   int			(*f)(va_list);
   t_case		next;
   };
   */

#endif
