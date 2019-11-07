/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:12:17 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/07 20:44:53 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
	printf("%%05d[123456789]    : [%05d]\n", 123456789);
	printf("%%015d[123456789]   : [%015d]\n", 123456789);
	printf("%%05s[salut toi]    : [%05s]\n", "salut toi");
	printf("%%015s[123456789]   : [%015s]\n", "salut toi");
	printf("%%*[016]d[123456789]   : [%*d]\n", 016, 123456789);
	printf("%%016d[123456789]   : [%016d]\n", 123456789);
	printf("%%0016d[123456789]   : [%0016d]\n", 123456789);
	printf("%%*.5d    : [%*.5d]\n", 18, 123456789);
	printf("%%*.40s   : [%*.40s]\n", 50, "salut toi, comment ca va ?");
	printf("%%*.15d   : [%*.15d]\n", 20, 123456789);
	printf("%%-s      : [%-s]\n", "salut toi, comment ca va ?");
	printf("%%-d      : [%-d]\n", 123456789);
	printf("%%-10s    : [%-10s]\n", "salut toi, comment ca va ?");
	printf("%%-5d     : [%-5d]\n", 123456789);
	printf("%%-30s    : [%-30s]\n", "salut toi, comment ca va ?");
	printf("%%-15d    : [%-15d]\n", 123456789);
	printf("%%-10.s   : [%-10.s]\n", "salut toi, comment ca va ?");
	printf("%%-5.d    : [%-5.d]\n", 123456789);
	printf("%%-30.s   : [%-30.s]\n", "salut toi, comment ca va ?");
	printf("%%-15.d   : [%-15.d]\n", 123456789);
	printf("%%-10.5s  : [%-10.5s]\n", "salut toi, comment ca va ?");
	printf("%%-5.3d   : [%-5.3d]\n", 123456789);
	printf("%%.3d     : [%.3d]\n", 123456789);
	printf("%%.0d     : [%.0d]\n", 123456789);
	printf("%%.d      : [%.d]\n", 0);
	printf("%%.5d     : [%.5d]\n", 0);
	printf("%%.0d     : [%.0d]\n", 0);
	printf("%%.c      : [%.c]\n", 'c');
	printf("%%-10.15s : [%-10.15s]\n", "salut toi, comment ca va ?");
	printf("%%-5.8d   : [%-5.8d]\n", 123456789);
	printf("%%-10.30s : [%-10.30s]\n", "salut toi, comment ca va ?");
	printf("%%-5.15d  : [%-5.15d]\n", 123456789);
	printf("%%-30.15s : [%-30.15s]\n", "salut toi, comment ca va ?");
	printf("%%-15.5d  : [%-15.5d]\n", 123456789);
	printf("%%-30.40s : [%-30.40s]\n", "salut toi, comment ca va ?");
	printf("%%-15.20d : [%-15.20d]\n", 123456789);
	printf("%%-40.30s : [%-40.30s]\n", "salut toi, comment ca va ?");
	printf("%%-15.12d : [%-15.12d]\n", 123456789);
}
