#include "push_swap.h"




static void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(int *arr, int n)
{
   int i, j;
   int swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = 0;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = 1;
        }
     }
      if (swapped == 0)
        break;
   }
}

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
static int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char const *s)
{
	long			nbr;
	long			sign;
	int				i;
	unsigned long	lon;

	lon = 9223372036854775807;
	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_iswhitespace((int)s[i]) && s[i])
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
		{
			sign = -1;
			nbr = -nbr;
		}
	while (ft_isdigit(s[i]) && s[i])
	{
		if ((unsigned long)nbr > lon / 10 ||
			((unsigned long)nbr == lon / 10 && ((unsigned long)nbr % 10) > 7))
			return (sign > 0 ? -1 : 0);
		nbr = nbr * 10 + (s[i++] - 48);
	}
	return (nbr * sign);
}
