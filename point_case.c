/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:37 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/07 21:34:15 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

len = ft_strlen(arg);

if (format[i] == '.') // Privilege = 1
{
	precision = ft_atoi(format + i + 1);
	if (precision <= len && type(arg) == char *)
		ft_cut(va_arg(arg, char *), precision);
	else if (precision > len && type(arg) == char *)
		ft_cut(va_arg(arg, char *), len);
	else if (type(arg) == char)
		ft_putchar(va_arg(arg, int));
	else if (precision <= len && type(arg) == int)
		ft_putnbr(va_arg(arg, int));
	else if (precision > len && type(arg) == int)
		ft_fill_with_zeros(va_arg(arg, int), precision, len);
}
else if (format[i] == '-') // Privilege = 2
{

}
else if (format[i] == '0') // Privilege = 3
{
	if (g_flag_charset['.'] == true || g_flag_charset['-'] == true)
		return (0);
	width = ft_atoi(format + i);
	ft_fill_with_zeros
}
