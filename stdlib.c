#include "header.h"

void    *malloc(size_t t)
{
    if (g_memory.small == NULL)
        initialize(&g_memory);
    if (t <= TINY)
        return (get_tiny(&g_memory));
    else if (t <= MEDIUM)
        return (get_medium(&g_memory));
    else
        return (get_big(&g_memory, t));
}

void    *my_realloc(void *ptr, size_t *size)
{

}

void    free(void *ptr)
{
    if (ptr)
    {
        if (check_small(ptr, &g_memory))
            return;
        else if (check_medium(ptr, &g_memory))
            return ;
        check_big(ptr, &g_memory);
    }
}

void    free_all()
{
    give_back(g_memory.small, g_memory.small_size, g_memory.size_tiny_last);
    give_back(g_memory.medium, g_memory.medium_size, g_memory.size_medium_last);
}

void    show_mem_alloc()
{

}