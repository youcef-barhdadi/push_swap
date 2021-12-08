

#include "push_swap.h"



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
    printf("size is %d\n", size);
    /*
    *   5  = 101  =3  this equivlent to divid by 2^i
    *
    */
    while((maxNum >> maxBit) != 0) maxBit++;

    int i = 0;
    int j=0;
    
    while (i < maxBit)
    {
        j =0;
        while (j < size )
        {
            int num = peak(*a);
            if ((num >> i) & 1 == 1)
            {
                // printf("roate a\n");
                rotate_stack(a);
            }else
            {
                // printf("push  to b\n");
                push_from(b, a);
            }
            j++;
        }
        // printf("stack A\n");
        // print_stack_A(*a);
        // printf("stack B\n");
        // print_stack_A(*b);
        

        int    k = stack_size(*b);
        while (k--)
        {
            push_from(a, b);
        }
        i++;
    }
    printf("----------------------------end-----------------------------------\n");
 
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
                printf("%d\n", tab[i-1]);
                i++;
            }
            //ft_memcpy
            memcpy(copy, tab, (argc  -1 ) * sizeof(int));

            bubbleSort(copy, (argc) );
            i = 0;
            int j =0;
            while (i < argc)
            {   
                j =0;
                while (j < argc)
                {
                    if (tab[i] ==  copy[j])
                    {
                        tab[i] = j;
                        // break ; 
                    }
                    j++;
                }
                i++;
            }
            i = 0;
            printf("=====\n");
            while (i < argc-1)
            {
                printf("==>%d\n", tab[i]);
                push(&a, tab[i]);
                i++;
            }
            print_stack_A(a);
            sort(&a, &b, argc -1);    
            print_stack_A(a);
    

            

    }
   

}
