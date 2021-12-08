

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef  struct  s_stack
{
        int      val;
        struct  s_stack *next;
    
}               t_stack;

void bubbleSort(int *arr, int n);


int	ft_atoi(char const *s);