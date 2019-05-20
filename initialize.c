#include "header.h"

void    do_header(t_allocation *ptr, size_t size,
    size_t total_alloc)
{
    t_allocation    *tmp;
    t_allocation    *before_tmp;

    tmp = ptr;
    while ((void*)tmp + size < (void*)ptr + total_alloc)
    {
        tmp->size = size - sizeof(t_allocation);
        tmp->data = (void*)tmp + sizeof(t_allocation);
        tmp->next = (void*)tmp + size;
        before_tmp = tmp;
        tmp = tmp->next;
    }
    before_tmp->next = NULL;
}

size_t  create_size(int nb_alloc, size_t size_alloc)
{
    int     i;
    int     page_size;

    i = 0;
    page_size = getpagesize();
    while (page_size * i < nb_alloc * size_alloc)
        i++;
    return (i * page_size);
}

void    initialize(t_size_list *g_memory)
{
   atexit(free_all);
    g_memory->small_size = create_size(100, TINY + sizeof(t_allocation));
    if ((g_memory->small = mmap(NULL, g_memory->small_size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
            handle_error("mmap");
    g_memory->medium_size = create_size(100, MEDIUM + sizeof(t_allocation));
    do_header(g_memory->small, TINY + sizeof(t_allocation), g_memory->small_size);
    g_memory->size_tiny_last = sizeof(t_allocation) + TINY
        + g_memory->small_size % (TINY + sizeof(t_allocation));
    if ((g_memory->medium = mmap(NULL, g_memory->medium_size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
            handle_error("mmap");
    do_header(g_memory->medium, MEDIUM + sizeof(t_allocation), g_memory->medium_size);
    g_memory->size_medium_last = sizeof(t_allocation) + MEDIUM
        + g_memory->medium_size % (MEDIUM + sizeof(t_allocation));
}