#include <stdio.h>
#include "src/ft_printf.h"


int    main(void)
{
    int        c, b;

    char    *str = "cause";
    char    *str2 = "cause";
    int        i = -30;
    int        y = 69;
    int        *ptr = &i;
    int a = -30;

    int *ptr2  = &a;

    int x = 69;
    c = printf("I like turtles %s %d%%\nError %cdata at %p -> %x %X\nPwease wait %i%u seconds.. %s\n\n", str, y, '\0', ptr, i, -i, -y, -y, (char *) 0);
    b = ft_printf("I like turtles %s %d%%\nError %cdata at %p -> %x %X\nPwease wait %i%u seconds.. %s\n\n", str2, y, '\0', ptr2, a, -a, -x, -x, (char *) 0);

    printf("Comparaisons: [%d] VS [%d]", c, b);
    return (0);
}