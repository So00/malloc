#include "header.h"

void    *get_tiny(t_size_list *memory)
{
    t_allocation    *tmp;
    void            *new;

    tmp = memory->small;
    while (tmp->next && tmp->used)
        tmp = tmp->next;
    if (!tmp->used)
    {
        tmp->used = 1;
        return (tmp->data);
    }
    if ((new = mmap(NULL, memory->small_size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
            handle_error("mmap");
    do_header((t_allocation*)new, TINY + sizeof(t_allocation), memory->small_size);
    tmp->next = (t_allocation*)new;
    tmp->next->used = 1;
    return (tmp->next->data);
}

void    *get_medium(t_size_list *memory)
{
    t_allocation    *tmp;
    void            *new;

    tmp = memory->medium;
    while (tmp->next && tmp->used)
        tmp = tmp->next;
    if (!tmp->used)
    {
        tmp->used = 1;
        return (tmp->data);
    }
    if ((new = mmap(NULL, memory->medium_size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
            handle_error("mmap");
    do_header(new, MEDIUM + sizeof(t_allocation), memory->medium_size);
    tmp->next = new;
    tmp->next->used = 1;
    return (tmp->next->data);
}

void    *search_big(t_size_list *memory, size_t size,
    size_t alloc_size, size_t first_size)
{
    void            *new;
    t_allocation    *act;

    act = memory->big;
    while (act->next && (act->used || act->size < size))
        act = act->next;
    if (!act->used && act->size >= size)
    {
        act->used = 1;
        return (act->data);
    }
    if ((new = mmap(NULL, alloc_size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
            handle_error("mmap");
    do_header(new, first_size, alloc_size);
    act->next = new;
    act->next->used = 1;
    return (act->next->data);
}

void    *get_big(t_size_list *memory, size_t size)
{
    t_allocation    *act;
    size_t          alloc_size;
    size_t          first_size;

    alloc_size = create_size(1, size);
    first_size = size + sizeof(t_allocation);
    if (memory->big)
        return (search_big(memory, size, alloc_size, first_size));
    if ((memory->big = mmap(NULL, alloc_size,
        PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)) == MAP_FAILED)
            handle_error("mmap");
    act = (t_allocation*)memory->big;
    do_header(act, first_size, alloc_size);
    act->used = 1;
    return (act->data);
}