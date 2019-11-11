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
	return(0);
}
