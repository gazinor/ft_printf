#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	char	*txt = "Anticonstitutionnellement";
	ft_printf("\n------------------------[FAUX PRINTF]--[STRING NULLE]---------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\nfils de pute\n", NULL, NULL, NULL, NULL, NULL);
	   printf("\n------------------------[VRAI PRINTF]--[STRING NULLE]---------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\nfils de pute\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("\n---------------------------[FAUX PRINTF]--[STRING]------------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\n %012.5s\nfils de pute\n", "ah bah coucou toi, je t'avais pas vu","ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu");
	   printf("\n---------------------------[VRAI PRINTF]--[STRING]------------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\n %012.5s\nfils de pute\n", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu","ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu");
	ft_printf("\n-------------------------[FAUX PRINTF]--[CHAR NULLE]----------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", NULL, NULL, NULL, NULL, NULL, NULL);
	   printf("\n-------------------------[VRAI PRINTF]--[CHAR NULLE]----------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", NULL, NULL, NULL, NULL, NULL, NULL);
	ft_printf("\n----------------------------[FAUX PRINTF]--[CHAR]-------------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", 'a', '.', '3', '@', '\n', '\0');
	   printf("\n----------------------------[VRAI PRINTF]--[CHAR]-------------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", 'a', '.', '3', '@', '\n', '\0');
	ft_printf("\n----------------------------[FAUX PRINTF]--[INT]-------------------------------\n\n      salut %-020d\n %020d\n %-20.d\n %-.d\n %12.5d\n %012.5d\nfils d%%e pute\n %d", 123456789,123456789,123456789,123456789,123456789,-123456789, 2147483777);
	   printf("\n----------------------------[VRAI PRINTF]--[INT]-------------------------------\n\n      salut %-020d\n %020d\n %-20.d\n %-.d\n %12.5d\n %012.5d\nfils d%%e pute\n%d", 123456789,123456789,123456789,123456789,123456789,-123456789, 2147483777);
	ft_printf("\n----------------------------[FAUX PRINTF]--[INT2]-------------------------------\n\n      salut %-02i\n %02i\n %-2.i\n %-.i\n %5.25i\n %05.25i\nfils de pute\n", 123456789,123456789,123456789,123456789,-123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[INT2]-------------------------------\n\n      salut %-02i\n %02i\n %-2.i\n %-.i\n %5.25i\n %05.25i\nfils de pute\n", 123456789,123456789,123456789,123456789,-123456789,123456789);
	ft_printf("\n----------------------------[FAUX PRINTF]--[INT3]-------------------------------\n\n      salut %-010i\n %010i\n %-10.i\n %-.i\n %50.25i\n %015.25i\nfils de pute\n", 123456789,123456789,123456789,-123456789,123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[INT3]-------------------------------\n\n      salut %-010i\n %010i\n %-10.i\n %-.i\n %50.25i\n %015.25i\nfils de pute\n", 123456789,123456789,123456789,-123456789,123456789,123456789);
	ft_printf("\n----------------------------[FAUX PRINTF]--[UNSIGNED INT]-------------------------------\n\n      salut %-020u\n %020u\n %-20.u\n %-.u\n %12.5u\n %012.5u\nfils d%%e pute\n", 123456789,123456789,123456789,123456789,123456789,-123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[UNSIGNED INT]-------------------------------\n\n      salut %-020u\n %020u\n %-20.u\n %-.u\n %12.5d\n %012.5u\nfils d%%e pute\n", 123456789,123456789,123456789,123456789,123456789,-123456789);
	ft_printf("\n----------------------------[FAUX PRINTF]--[UNSIGNED INT 2]-------------------------------\n\n      salut %-02u\n %02u\n %-2.u\n %-.i\n %5.25u\n %05.25u\nfils de pute\n", 123456789,123456789,123456789,123456789,-123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[UNSIGNED INT 2]-------------------------------\n\n      salut %-02u\n %02u\n %-2.u\n %-.u\n %5.25u\n %05.25u\nfils de pute\n", 123456789,123456789,123456789,123456789,-123456789,123456789);
	ft_printf("\n----------------------------[FAUX PRINTF]--[UNSIGNED INT 3]-------------------------------\n\n      salut %-010u\n %010u\n %-10.u\n %-*.u\n %50.25u\n %015.25u\nfils de pute\n", 123456789,123456789,123456789,2 ,-123456789,123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[UNSIGNED INT 3]-------------------------------\n\n      salut %-010u\n %010u\n %-10.u\n %-*.u\n %50.25u\n %015.25u\nfils de pute\n", 123456789,123456789,123456789, 2, -123456789,123456789,123456789);
ft_printf("|%.*s||%.*s|,|%.*s|,|%.*s|,|%.*s|,|%.*s|\n",0,txt,10,txt,-3,txt,30,txt,-30,txt,-10,txt);
printf("|%.*s||%.*s|,|%.*s|,|%.*s|,|%.*s|,|%.*s|\n",0,txt,10,txt,-3,txt,30,txt,-30,txt,-10,txt);
	   return(0);
}
