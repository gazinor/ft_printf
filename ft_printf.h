/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaefourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:24:21 by gaefourn          #+#    #+#             */
/*   Updated: 2019/11/18 22:20:16 by gaefourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef struct	s_struct
{
	const char	*format;
	int			count;
	int			width;
	int			precision;
	int			i;
	va_list		ap;
	t_bool		dot;
	t_bool		minus;
	t_bool		zero;
	int			len;
	int			total;
	int			fct;
}				t_struct;

int				ft_set_find(char c);
void			ft_check_again_xd(t_struct *p);
void			ft_putchar(char c, t_struct *p);
void			ft_putstr(char *str, t_struct *p);
int				ft_check_base(char *base);
void			ft_putnbr_base(unsigned long long n, char *base, t_struct *p);
void			ft_look(t_struct *p);
int				ft_atoi(t_struct *p);
void			ft_str(t_struct *p);
char			*ft_dot(t_struct *p, char *copy);
void			ft_less(t_struct *p, char *copy, char c);
void			ft_c(t_struct *p);
int				ft_strlen(char *str);
int				ft_nbrlen(long nb);
int				ft_printf(const char *format, ...);
char			*ft_strndup(char *str, int n);
void			ft_num(t_struct *p);
void			ft_display_zero(t_struct *p, int signe);
void			ft_width_num(t_struct *p, long copy, char c, int i);
void			ft_num_u(t_struct *p);
void			ft_width_num_u(t_struct *p, unsigned int copy, char c, int i);
void			ft_num_x(t_struct *p);
void			ft_width_num_x(t_struct *p, unsigned long copy, char c, int i);
void			ft_num_x_big(t_struct *p);
void			ft_width_num_x_big(
				t_struct *p, unsigned long copy, char c, int i);
void			ft_pct(t_struct *p);
void			ft_width_num_p(t_struct *p, long copy, char c);
void			ft_num_p(t_struct *p);
int				ft_nbrlen_base(long nb);
void			ft_indetermination(t_struct *p);

#endif
