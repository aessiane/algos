/*
** Given an image represented by an NxN matrix, where each pixel in the image is
** 4 bytes, write a method to rotate the image by 90 degrees. Can you do this inplace?
*/

#include <stdio.h>

void		rotate(int (*matrix)[5], unsigned n)
{
  unsigned	i;
  unsigned	j;
  int		newmatrix[n][n];

  if (!n || !matrix || !*matrix)
    return ;

  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      newmatrix[j][n - 1 - i] = matrix[i][j];

  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j)
      matrix[i][j] = newmatrix[i][j];
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
    {-1, -2, -3, -4, -5},
    {1, 2, 3, 4, 5},
    {10, 20, 30, 40, 50},
    {100, 200, 300, 400, 500},
    {1000, 2000, 3000, 4000, 5000}
  };

  rotate(tab, sizeof(tab[0]) / sizeof(int));
  myPrintIntTabTab(tab, sizeof(tab[0]) / sizeof(int));
  return (0);
}
