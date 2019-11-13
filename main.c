#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	ft_printf("\n------------------------[FAUX PRINTF]--[STRING NULLE]---------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\nfils de pute\n", NULL, NULL, NULL, NULL, NULL);
	   printf("\n------------------------[VRAI PRINTF]--[STRING NULLE]---------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\nfils de pute\n", NULL, NULL, NULL, NULL, NULL);
	ft_printf("\n---------------------------[FAUX PRINTF]--[STRING]------------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\n %012.5s\nfils de pute\n", "ah bah coucou toi, je t'avais pas vu","ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu");
	   printf("\n---------------------------[VRAI PRINTF]--[STRING]------------------------------\n\n      salut %-020s\n %020s\n %-20.s\n %-.s\n %12.5s\n %012.5s\nfils de pute\n", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu","ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu", "ah bah coucou toi, je t'avais pas vu");
	ft_printf("\n-------------------------[FAUX PRINTF]--[CHAR NULLE]----------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", NULL, NULL, NULL, NULL, NULL, NULL);
	   printf("\n-------------------------[VRAI PRINTF]--[CHAR NULLE]----------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", NULL, NULL, NULL, NULL, NULL, NULL);
	ft_printf("\n----------------------------[FAUX PRINTF]--[CHAR]-------------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", 'a', '.', '3', '@', '\n', '\0');
	   printf("\n----------------------------[VRAI PRINTF]--[CHAR]-------------------------------\n\n      salut %-020c\n %020c\n %-20.c\n %-.c\n %12.5c\n %012.5c\nfils de pute\n", 'a', '.', '3', '@', '\n', '\0');
	ft_printf("\n----------------------------[FAUX PRINTF]--[INT]-------------------------------\n\n      salut %-020d\n %020d\n %-20.d\n %-.d\n %12.5d\n %012.5d\nfils d%%e pute\n", 123456789,123456789,123456789,123456789,123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[INT]-------------------------------\n\n      salut %-020d\n %020d\n %-20.d\n %-.d\n %12.5d\n %012.5d\nfils d%%e pute\n", 123456789,123456789,123456789,123456789,123456789,123456789);
	ft_printf("\n----------------------------[FAUX PRINTF]--[INT2]-------------------------------\n\n      salut %-02i\n %02i\n %-2.i\n %-.i\n %5.25i\n %05.25i\nfils de pute\n", 123456789,123456789,123456789,123456789,123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[INT2]-------------------------------\n\n      salut %-02i\n %02i\n %-2.i\n %-.i\n %5.25i\n %05.25i\nfils de pute\n", 123456789,123456789,123456789,123456789,123456789,123456789);
	ft_printf("\n----------------------------[FAUX PRINTF]--[INT3]-------------------------------\n\n      salut %-010i\n %010i\n %-10.i\n %-.i\n %50.25i\n %015.25i\nfils de pute\n", 123456789,123456789,123456789,123456789,123456789,123456789);
	   printf("\n----------------------------[VRAI PRINTF]--[INT3]-------------------------------\n\n      salut %-010i\n %010i\n %-10.i\n %-.i\n %50.25i\n %015.25i\nfils de pute\n", 123456789,123456789,123456789,123456789,123456789,123456789);
	return(0);
}
