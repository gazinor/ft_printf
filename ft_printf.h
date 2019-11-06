/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:33 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/06 14:18:18 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int n, int *count);
void	ft_putnbr_u(unsigned int n, int *count);
void	ft_putnbr_base(long int n, char *base, int ptr, int *count);
void	ft_case_c(va_list ap, int *count);
void	ft_case_s(va_list ap, int *count);
void	ft_case_p(va_list ap, int *count);
void	ft_case_dni(va_list ap, int *count);
void	ft_case_u(va_list ap, int *count);
void	ft_case_x(va_list ap, int *count);
void	ft_case_X(va_list ap, int *count);
void	ft_case_percent(va_list ap, int *count);
int		ft_case_all(va_list ap, const char *format, int *count);
int		ft_printf(const char *format, ...);

typedef void (*t_f)(va_list, int *);

typedef	struct	s_list t_list;

struct			s_list
{

};


#endif
