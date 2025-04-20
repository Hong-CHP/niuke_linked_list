#include "ft_reverse_ele.h"

t_list  *ft_creat_new_ele(void *data)
{
    t_list  *new_ele;

    new_ele = (t_list *)malloc(sizeof(t_list));
    if (!new_ele)
        return NULL;
    new_ele->data = data;
    new_ele->next = NULL;
    return new_ele;
}

void    ft_add_ele_back(t_list **begin, t_list *ele)
{
    t_list  *curr;

    if (*begin == NULL)
        *begin = ele;
    else
    {
        curr = *begin;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = ele;
    }
    ele->next = NULL;
}

void    ft_reverse_ele(t_list **begin)
{
    t_list *curr;
    t_list  *prev;
    t_list  *next;
    
    if (*begin == NULL)
        return ;
    prev = NULL;
    curr = *begin;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *begin = prev;
}
