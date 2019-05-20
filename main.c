#include "header.h"

int main(void)
{
    char    *str = 0;

    str = malloc(20);
    ft_printf("Adress of str(TINY) : %p\n", str);
    ft_printf("Begin of while with free\n");
    for (int i = 0; i < 200; i++)
    {
        free(str);
        str=malloc(20);
    }
    ft_printf("Adress of str(TINY) : %p\n\n", str);
    free(str);

    str = malloc(200);
    ft_printf("Adress of str(MEDIUM) : %p\n", str);
    ft_printf("Begin of while with free\n");
    for (int i = 0; i < 200; i++)
    {
        free(str);
        str=malloc(200);
    }
    ft_printf("Adress of str(MEDIUM) : %p\n\n", str);
    free(str);

    str = malloc(2000);
    ft_printf("Adress of str(BIG) : %p\n", str);
    ft_printf("Begin of while with free\n");
    for (int i = 0; i < 200; i++)
    {
        free(str);
        str=malloc(2000);
    }
    ft_printf("Adress of str(BIG) : %p\n\n", str);
    free(str);
}