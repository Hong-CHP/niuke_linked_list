#ifndef UNION_H
# define UNION_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
    void *data;
    struct s_list *next;
}               t_list;

void    union_sort_lsts(t_list **l_a, t_list **l_b);

#endif