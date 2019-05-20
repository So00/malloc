#ifndef HEADER_H
# define HEADER_H

# include "./ft_printf/includes/ft_printf.h"
# include <stdbool.h>
# include <sys/mman.h>

/**
 * Include for the use of atexit()
**/
# include <stdlib.h>

/**
 * Include for the perror (errno and stdio)
**/
# include <errno.h>
# include <stdio.h>

# define handle_error(msg) \
            { perror(msg); exit(EXIT_FAILURE); }

# define TINY 20
# define MEDIUM 200

typedef struct  s_allocation
{
    size_t                  size;
    bool                    used;
    struct s_allocation     *next;
    void                    *data;
}               t_allocation;

typedef struct  s_size_list
{
    void                    *small;
    size_t                  small_size;
    size_t                  size_tiny_last;
    void                    *medium;
    size_t                  medium_size;
    size_t                  size_medium_last;
    void                    *big;
}               t_size_list;

static t_size_list          g_memory;

void    initialize();
void    *my_malloc(size_t t);
void    *my_realloc(void *ptr, size_t *size);
void    free(void *ptr);
void    *get_tiny(t_size_list *memory);
void    *get_medium(t_size_list *memory);
void    *get_big(t_size_list *memory, size_t size);
void    free_all();
void    give_back(t_allocation *ptr, size_t total_size, size_t last_struct);
void    give_back_big(t_size_list *memory);
int     check_small(void *ptr, t_size_list *memory);
int     check_medium(void *ptr, t_size_list *memory);
int     check_big(void *ptr, t_size_list *memory);
void    do_header(t_allocation *ptr, size_t size,
    size_t total_alloc);
size_t  create_size(int nb_alloc, size_t size_alloc);

#endif