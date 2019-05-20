#include "header.h"

void    give_back(t_allocation *ptr, size_t total_size, size_t last_struct)
{
    t_allocation    *next;

    while (ptr)
    {
        next = (void*)ptr + total_size - last_struct;
        next = next->next;
        munmap(ptr, total_size);
        ptr = next;
    }
}

void    give_back_big(t_size_list *memory)
{
    t_allocation    *act;
    t_allocation    *next;
    size_t          size;

    act = memory->big;
    while (act)
    {
        size = create_size(1, act->size);
        next = (void*)act + size - (sizeof(t_allocation) + act->size
            + size % (TINY + sizeof(t_allocation)));
        next = next->next;
        munmap(act, size);
        act = next;
    }
}

int     check_small(void *ptr, t_size_list *memory)
{
    t_allocation    *next;
    t_allocation    *first;

    first = memory->small;
    while (first)
    {
        if (ptr > (void*)first && ptr < (void*)first + memory->small_size)
        {
            if ((ptr - (void*)first) % (sizeof(t_allocation) + TINY) != sizeof(t_allocation))
                break;
            next = (t_allocation*)(ptr - sizeof(t_allocation));
            next->used = 0;
            return (1);
        }
        next = (void*)first + memory->small_size - memory->size_tiny_last;
        next = next->next;
        first = next;
    }
    return (0);
}

int     check_medium(void *ptr, t_size_list *memory)
{
    t_allocation    *next;
    t_allocation    *first;

    first = memory->medium;
    while (first)
    {
        if (ptr > (void*)first && ptr < (void*)first + memory->medium_size)
        {
            if ((ptr - (void*)first) % (sizeof(t_allocation) + MEDIUM) != sizeof(t_allocation))
                break;
            next = (t_allocation*)(ptr - sizeof(t_allocation));
            next->used = 0;
            return (1);
        }
        next = (void*)first + memory->small_size - memory->size_tiny_last;
        next = next->next;
        first = next;
    }
    return (0);
}

int     check_big(void *ptr, t_size_list *memory)
{
    t_allocation    *act;

    act = memory->big;
    while (act)
    {
        if (act->data == ptr)
        {
            act->used = 0;
            return (1);
        }
        act = act->next;
    }
    return (0);
}