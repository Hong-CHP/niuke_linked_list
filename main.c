#include "ft_reverse_ele.h"

int main()
{
    int *a;
    t_list  *head;
    t_list  *ele;
    t_list  *curr;

    head = NULL;
    a = (int *)malloc(sizeof(int));
    if (!a)
        return 1;
    *a = 1;
    ele = ft_creat_new_ele(a);
    printf("%d\n", *(int *)ele->data);
    ft_add_ele_back(&head, ele);
    a = (int *)malloc(sizeof(int));
    if (!a)
        return 1;
    *a = 2;
    ele = ft_creat_new_ele(a);
    ft_add_ele_back(&head, ele);
    a = (int *)malloc(sizeof(int));
    if (!a)
        return 1;
    *a = 3;
    ele = ft_creat_new_ele(a);
    ft_add_ele_back(&head, ele);
    a = (int *)malloc(sizeof(int));
    if (!a)
        return 1;
    *a = 4;
    ele = ft_creat_new_ele(a);
    ft_add_ele_back(&head, ele);
    a = (int *)malloc(sizeof(int));
    if (!a)
        return 1;
    *a = 5;
    ele = ft_creat_new_ele(a);
    ft_add_ele_back(&head, ele);
    curr = head;
    while (curr)
    {
        printf("%d -> ", *(int *)curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    ft_reverse_ele(&head);
    curr = head;
    while (curr)
    {
        printf("%d -> ", *(int *)curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    ft_reverse_sublist_ele(&head, 1, 5);
    curr = head;
    while (curr)
    {
        printf("%d -> ", *(int *)curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    return 0;
}