/*
** Write an algorithm such that if an element in an MxN matrix is 0,
** its entire row and column are set to 0.
*/

#include <string.h>
#include <stdio.h>

void		func(int (*matrix)[5], unsigned M, unsigned N)
{
  int		row[(M / 8) + 1];
  int		col[(N / 32) + 1];

  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  for (unsigned i = 0; i < N; ++i)
    for (unsigned j = 0; j < M; ++j)
      {
	if (matrix[i][j] == 0)
	  {
	    row[j / 32] |= 1 << (j % 32);
	    col[i / 32] |= 1 << (i % 32);
	    break ;
	  }
      }

  for (unsigned i = 0; i < N; ++i)
    for (unsigned j = 0; j < M; ++j)
      {
	if (row[j / 32] & (1 << (j % 32)) ||
	    col[i / 32] & (1 << (i % 32)))
	  matrix[i][j] = 0;
      }
}

void		myPrintIntTabTab(const int (*tab)[5], unsigned n)
{
  for (unsigned i = 0; i < n; ++i)
    {
      for (unsigned j = 0; j < n; ++j)
	printf("%d ", tab[i][j]);
      printf("\n");
    }
}

int		main()
{
  int		tab[5][5] = {
    {-1, -2, -3, -4, 0},
    {1, 2, 3, 4, 5},
    {10, 20, 30, 40, 50},
    {100, 200, 300, 400, 500},
    {1000, 2000, 3000, 4000, 5000}
  };

  func(tab, 5, 5);
  myPrintIntTabTab(tab, sizeof(tab[0]) / sizeof(int));
  return (0);
}
