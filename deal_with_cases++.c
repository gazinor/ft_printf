/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_cases++.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:49:02 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/04 23:23:56 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"

int main()
{
	int *p;

	printf("\np(%%d) = %d\n", p);
	printf("p(%%p) = %p\n", p);
	ft_putnbr_base(p, "0123456789abcdef", 1);
}
