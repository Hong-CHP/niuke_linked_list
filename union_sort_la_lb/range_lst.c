#include "union_sort.h"

void    ft_print_lst(t_list **head)
{
    t_list *cur;

    cur = *head;
    while (cur)
    {
        printf("%d -> ", *(int *)cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void    clear_lst(t_list **head)
{
    t_list *node;
    t_list *next;

    node = *head;
    while (node)
    {
        next = node->next;
        if (node->data)
            free(node->data);
        free(node);
        node = next;
    }
}

t_list *ft_creat_node(void *data)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->data = data;
    node->next = NULL;
    return (node);
}

t_list  *ft_creat_lst(t_list **head, t_list *node)
{
    if(!node)
        return (NULL);
    node->next = *head;
    *head = node;
    return (*head);
}

void    ft_range_lst(int argc, char *argv[])
{
    t_list *l_a;
    t_list *l_b;
    int mid;
    int i;
    int *nb;

    l_a = NULL;
    i = 0;
    mid = (argc + 1)/ 2;
    while (i < mid)
    {
        nb = malloc(sizeof(int));
        if (!nb)
            return ;
        *nb = atoi(argv[i]);
        l_a = ft_creat_lst(&l_a, ft_creat_node(nb));
        i++;
    }
    l_b = NULL;
    while (i < argc)
    {
        nb = malloc(sizeof(int));
        if (!nb)
            return ;
        *nb = atoi(argv[i]);
        l_b = ft_creat_lst(&l_b, ft_creat_node(nb));
        i++;
    }
    ft_print_lst(&l_a);
    ft_print_lst(&l_b);
    union_sort_lsts(&l_a, &l_b);
    ft_print_lst(&l_a);
    clear_lst(&l_a);
    clear_lst(&l_b);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        return (1);
    ft_range_lst(argc - 1, argv + 1);
}