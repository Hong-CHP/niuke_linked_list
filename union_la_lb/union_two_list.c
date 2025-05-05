#include "union.h"
void    clear_list(t_list *head)
{
    t_list *cur;
    t_list *next;

    cur = head;
    while (cur)
    {
        next = cur->next;
        if (cur->data)
            free(cur->data);
        free(cur);
        cur = next;
    }
}

t_list *ft_creat_ele(void *data)
{
    t_list *ele;

    ele = malloc(sizeof(t_list));
    if (!ele)
        return (NULL);
    ele->data = data;
    ele->next = NULL;
    return (ele);
}

t_list    *init_list(t_list *l_a)
{
    l_a = malloc(sizeof(t_list));
    if (!l_a)
        return (NULL);
    (l_a)->next = NULL;
    return (l_a);
}

void    ft_add_list_front(t_list *head, t_list *node)
{
    node->next = head->next;
    head->next = node;
}

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
//     const unsigned char *p1;
//     const unsigned char *p2;

//     p1 = (const unsigned char)s1;
//     p2 = (const unsigned char)s2;
//     if (n = 0)
//         return (0);
//     while (n > 0)
//     {
//         if (*p1 != *p2)
//             return ((unsigned char)*p1 - (unsigned char)*p2);
//         p1++;
//         p2++;
//         n--;
//     }
//     return (0);
// }

int locate_ele(t_list *l_a, void *data)
{
    t_list *cur;

    if (!l_a)
        return (0);
    cur = l_a->next;
    while (cur)
    {
        if (*(int *)cur->data == *(int *)data)
        {
        //    printf("find_repeat");
            return (1);
        }
        cur = cur->next;
    }
    return (0);
}

t_list *ft_union_two_list(t_list *l_a, t_list *l_b)
{
    t_list *cur_b;
    t_list *cur_a;
    t_list *temp;

    cur_b = l_b->next;
    while (cur_b)
    {
        if (!locate_ele(l_a, cur_b->data))
        {
            temp = cur_b->next;
            ft_add_list_front(l_a, cur_b);
            cur_b = temp;
        }
        else        
            cur_b = cur_b->next;
    }
    return (l_a);
}

int main(int argc, char *argv[])
{
    int i = 1;
    int *a;
    t_list *l_a;
    t_list *l_b;
    t_list *node;
    t_list *cur;
    int mid;

    mid = (argc - 1) / 2; 
    l_a = init_list(l_a);
    l_b = init_list(l_b);
    if (argc < 2)
        return (1);
    while (i <= mid)
    {
        a = malloc(sizeof(int));
        if (!a)
            return (1);
        *a = atoi(argv[i]);
        node = ft_creat_ele(a);
        ft_add_list_front(l_a, node);
        i++;
    }
    while (i < argc)
    {
        a = malloc(sizeof(int));
        if (!a)
            return (1);
        *a = atoi(argv[i]);
        node = ft_creat_ele(a);
        ft_add_list_front(l_b, node);
        i++;
    }
    cur = l_a->next;
    while (cur)
    {
        printf("%d -> ", *(int *)cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
    cur = l_b->next;
    while (cur)
    {
        printf("%d -> ", *(int *)cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
    ft_union_two_list(l_a, l_b);
    cur = l_a->next;
    printf(">>union: ");
    while (cur)
    {
        printf("%d -> ", *(int *)cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
    free(l_a);
    free(l_b);
}