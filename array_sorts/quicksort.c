#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE	(30)
#define RANGE	(424242)

static void	swap(int * const a, int * const b)
{
  int		tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

static int	partition(int * const tab, int left, int right)
{
  int		pivot = tab[right];
  int		splitPoint = left - 1;
  int		i;

  i = left;
  while (i < right)
    {
      if (tab[i] <= pivot)
	swap(tab + ++splitPoint, tab + i);
      ++i;
    }
  swap(tab + ++splitPoint, tab + right);
  return (splitPoint);
}

static void	quicksort(int * const tab, int left, int right)
{
  int		splitPoint;

  if (left >= right)
    return ;
  splitPoint = partition(tab, left, right);
  quicksort(tab, left, splitPoint - 1);
  quicksort(tab, splitPoint + 1, right);
}

static void	print_tab(const int * const tab)
{
  for (unsigned i = 0; i < SIZE; ++i)
    printf("%d ", tab[i]);
  printf("\n");
}

int		main()
{
  int		tab[SIZE];

  srand(time(NULL));
  for (unsigned i = 0; i < SIZE; ++i)
    tab[i] = rand() % RANGE;
  printf("Before :\n");
  print_tab(tab);
  quicksort(tab, 0, SIZE - 1);
  printf("After :\n");
  print_tab(tab);
  return (0);
}
