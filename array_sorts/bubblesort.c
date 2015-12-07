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

static void	bubblesort(int * const tab, int len)
{
  int		sorted = 0;
  int		i;

  --len;
  while (!sorted)
    {
      sorted = 1;
      i = -1;
      while (++i < len)
	if (tab[i] > tab[i + 1])
	  {
	    sorted = 0;
	    swap(tab + i, tab + i + 1);
	  }
    }
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
  bubblesort(tab, SIZE);
  printf("After :\n");
  print_tab(tab);
  return (0);
}
