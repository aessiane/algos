#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE	(30)
#define RANGE	(424242)

static void	merge(int * const tab, int left, int middle, int right)
{
  int		tmp[right - left];
  int		i = left, j = middle + 1, k = 0;

  while (i <= middle && j <= right)
    tmp[k++] = (tab[i] < tab[j] ? tab[i++] : tab[j++]);
  while (i <= middle || j <= right)
    tmp[k++] = (i <= middle ? tab[i++] : tab[j++]);
  for (i = 0, j = left; j <= right; ++i, ++j)
    tab[j] = tmp[i];
}

static void	mergeSort(int * const tab, int left, int right)
{
  int		middle;

  if (left < right)
    {
      middle = left + ((right - left) / 2);
      mergeSort(tab, left, middle);
      mergeSort(tab, middle + 1, right);
      merge(tab, left, middle, right);
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
  mergeSort(tab, 0, SIZE - 1);
  printf("After :\n");
  print_tab(tab);
  return (0);
}
