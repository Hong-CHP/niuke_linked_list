#ifndef FT_REVERSE_ELE_H
# define FT_REVERSE_ELE_H

# include <stdio.h>
# include <stdlib.h>

typedef struct  s_list
{
    void    *data;
    struct s_list   *next;
}               t_list;

t_list  *ft_creat_new_ele(void *data);
void    ft_add_ele_back(t_list **begin, t_list *ele);
void    ft_reverse_ele(t_list **begin);
void    ft_reverse_sublist_ele(t_list **begin, int m, int n);

#endif