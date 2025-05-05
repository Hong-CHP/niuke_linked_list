#include "union_sort.h"

void    locate_insert_elem(t_list **head, t_list *node)
{
    t_list *cur;
    t_list *prev;
    t_list *next;

    if (!*head || *(int *)node->data <= *(int *)(*head)->data)
    {
        node->next = *head;
        *head = node;
        return ;
    }
    cur = *head;
    while (cur->next && *(int *)node->data > *(int *)cur->next->data)
    {
        cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
}

void    union_sort_lsts(t_list **l_a, t_list **l_b)
{
    t_list *cur;
    t_list *temp;
    int index;

    cur = *l_b;
    while (cur)
    {
        temp = cur->next;
        locate_insert_elem(l_a, cur);
        cur = temp;    
    }
    *l_b = NULL;
}