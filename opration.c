

#include "push_swap.h"

#include <limits.h>

void    push(t_stack **s, int val)
{
    t_stack *new = malloc(sizeof(t_stack));
    bzero(new, sizeof(t_stack));
    // check maloc
    if (new)
    {
        new->val = val;
        new->next = *s;
        *s = new;
    }
}
int     pop(t_stack **s)
{
    t_stack *tmp;
    
    if (s && *s)
    {
        tmp = *s;
        *s = (*s)->next;
        int val = tmp->val;
        free(tmp);
        tmp = NULL;
        return val;
    }
    return 0;
}


int peak(t_stack *s)
{
    if (s)
        return s->val;
    return 0;
}
/// 

void swap(t_stack *s)
{
    t_stack *second;

    if (s == NULL)
        return ;
    second = s->next;
    if(second == NULL)
        return ;
    
    int tmp = s->val;
    s->val = second->val;
    second->val = tmp;
}

/*
    this function take tow stack (A,B) and take pop elment from B and push it to A
*/
void push_from(t_stack **a, t_stack **b)
{
    push(a, pop(b));
}


void    rotate_stack(t_stack **s)
{
    t_stack *tmp;

    tmp = *s;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    // *s is the first elment and tmp is last one , we will make *s the last 
    tmp->next = *s;
    *s = (*s)->next;
    tmp->next->next = NULL;
    // we must remove the first one
}


void revers_rotate(t_stack **s)
{
    t_stack *last;
    t_stack *before_last;


    last = *s;
    while (last->next)
    {   
        before_last = last;
        last = last->next;
    }
    last->next = *s;
    *s = last;
    before_last->next = NULL;
}


void print_stack_A(t_stack *s)
{
    t_stack  *tmp;

    tmp = s;
    while(tmp)
    {
        printf("|\t%d\t|\n", tmp->val);
        tmp = tmp->next;
    }
}
int findSmall(t_stack *a, int *index)
{
    int min = 0XFFFFFFF;
    t_stack *s = a;

    *index =0;
    int  i = 0;

    while (s)
    {
        /* code */
        if (min > s->val)
        {
            min = s->val;
            *index = i;
        } 
        s = s->next;
        i++;
    }
    return min;
    
}


int stack_size(t_stack *s)
{
    t_stack  *tmp;
    int i;

    i = 0;
    tmp = s;
    while(tmp)
    {
            i++;
        tmp = tmp->next;
    }

        

    return i;
}

void sort(t_stack **a, t_stack **b, int size)
{
    int maxNum = size;
    int maxBit = 0;
    // printf("size is %d\n", size);
    /*
    *   5  = 101  =3  this equivlent to divid by 2^i
    *
    */
    while((maxNum >> maxBit) != 0) ++maxBit;
// while ((max_num >> max_bits) != 0) ++max_bits;

    int i = 0;
    int j=0;
    
    while (i <= maxBit +2)
    {
        j =0;
        while (j < size )
        {
            int num = peak(*a);
            if ((num >> i) & 1 == 1)
            {
                // printf("roate a\n");
                 printf("ra\n");

                rotate_stack(a);
            }else
            {
                // printf("push  to b\n");
                            printf("pb\n");

                push_from(b, a);
            }
            j++;
        }
        // printf("stack A\n");
        // print_stack_A(*a);
        // printf("stack B\n");
        // print_stack_A(*b);
        

        int    k = stack_size(*b);
        while (k)
        {
            push_from(a, b);
            printf("pa\n");
            k--;
        }
        i++;
    }
 
}
// 16 1 2 888 33


int checkIsNotSorted(int *t, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i+1; j < size; j++)
        {   
            if (t[i] > t[j])
                return 1;
        }
    }
    return (0);
}

int checkDuplicated(int *t,  int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i+1; j < size; j++)
        {   
            if (t[i] == t[j])
                return 1;
        }
    }
    return 0;
    
}

void sort_three(t_stack  **a, t_stack **b)
{
    int val0 = (*a)->val;
    int val1 = (*a)->next->val;
    int val2 = (*a)->next->next->val;
    if (val0 > val1 && val1 < val2 && val0 < val2)
    {
        swap(*a);
        printf("sa\n");
    }
    else if (val0 > val1 && val1 > val2)
    {
        swap(*a);
        revers_rotate(a);
        printf("sa\nrra\n");
    }
    else if (val0 > val1 && val1 < val2 && val0 > val2)
    { 
        rotate_stack(a);
         printf("ra\n");
    }
    else if (val0 < val1 && val0 < val2 && val1 > val2 )
    {
        swap(*a);
        rotate_stack(a);
        printf("sa\nra\n");
    }
    else if (val2 < val1 && val1 > val0)
    {
        revers_rotate(a);
        printf("rra\n");
    }
}

void sort_five(t_stack **a, t_stack **b)
{
    int i = 0;
    int index = 0;
    int size = 5;
    while (i < 2)
    {
        int small = findSmall(*a, &index);
        if(index == 0)
        {
            printf("pb\n");
            push_from(b, a);
        }
        else if(index > (size - i) / 2)
        {
            while (peak(*a) != small)
            {
                printf("rra\n");
                revers_rotate(a);
            }
            printf("pb\n");
            push_from(b, a);
        }
        else
        {
            while (peak(*a) != small)
            {
                printf("ra\n");
                rotate_stack(a);
            }
            printf("pb\n");
            push_from(b, a);
        }
        i++;
    }
    sort_three(a, b);
    // swap(*b);

    push_from(a, b);
    push_from(a, b);
    // rotate_stack(a);
    // rotate_stack(a);
    printf("pa\npa\n");
    // print_stack_A(*a);
}

int main(int argc , char **argv)
{

    int *tab;
    int *copy;
    int i = 1;
    t_stack *a = NULL;
    t_stack *b = NULL;
 
    if (argc > 2 )
    {
            tab = malloc(sizeof(int) * argc );
            copy = malloc(sizeof(int) * argc );

            while (i <argc )
            {
                tab[i-1] = ft_atoi(argv[i]);
                // printf("argvv   ==== %d || %s\n", tab[i-1], argv[i]);
                i++;
            }
            if (checkDuplicated(tab, argc-1) == 1)
            {
                printf("is duplicated\n");
                return 1;
            }
            if (checkIsNotSorted(tab, argc-1) == 0)
            {
                printf("error is sorted\n");
                return 1;
            }
                        i =  argc-2;
            while (i >= 0)
            {
                push(&a, tab[i]);
                i--;
            }
            if (argc == 4)
            {
            
                sort_three(&a, &b);
                return 1;
            }
            if (argc == 6)
            {
                sort_five(&a, &b);
                return 6;
            }
            //ft_memcpy
            memcpy(copy, tab, (argc  -1 ) * sizeof(int));
            bubbleSort(copy, argc -1 );
            i = 0;
            int j =0;

            // index
            while (i < argc)
            {   
                j =0;
                while (j < argc)
                {
                    if (tab[i] ==  copy[j])
                    {
                        tab[i] = j;
                        break ; 
                    }
                    j++;
                }
                i++;
            }

            i =  argc-2;
            while (i >= 0)
            {
                push(&a, tab[i]);
                i--;
            }
            sort(&a, &b, argc -1);    
         
        
            

    }
   

}
