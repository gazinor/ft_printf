/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:13:33 by glaurent          #+#    #+#             */
/*   Updated: 2019/10/31 18:43:44 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

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

#endif
