#include "ft_reverse_ele.h"

//in this problem, the record of initial places before move is essential
//need pay attention to the if (head->data == m), if m or n is not in the list, if n is before m
//is_head = 1 if m is data of head
//curr is for moving on linked list
//next is for recording the curr->next before movement
//prev is for identifying the place of the first one of list after move
//temp is for remerbering the ele before m for relink the reversed sublist
//last is for recording the place of the sublist's end in case of revers. 
void    ft_reverse_sublist_ele(t_list **begin, int m, int n)
{
    int is_head;
    t_list  *curr;
    t_list  *next;
    t_list  *prev;
    t_list  *temp;
    t_list  *last;

    is_head = 0;
    if (!*begin)
        return ;
    curr = *begin;
    if (*(int *)curr->data == m)
        is_head = 1;
    while (curr && *(int *)curr->data != m)
    {
        temp = curr;
        if (*(int *)curr->data == n)
            return ;
        if (curr->next == NULL && *(int *)curr->data != m)
            return ;
        curr = curr->next;
    }
    prev = *begin;
    while (prev && *(int *)prev->data != n)
    {
        if (prev->next == NULL && *(int *)prev->data != n)
            return ;
        prev = prev->next;
    }
    prev = prev->next;
    last = prev;
    while (curr != last)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    if (is_head)
        *begin = prev;
    else
        temp->next = prev;
}