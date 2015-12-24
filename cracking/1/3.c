// Given two strings, write a methodto decide if one is a permutation of the other.

#include <string.h>
#include <stdio.h>

int		checkPermutation(const char * const a, const char * const b)
{
  unsigned	i;
  int		map[256] = {0};

  if (!a || !b)
    return (1);
  else if (strlen(a) != strlen(b))
    return (0);
  for (i = 0; a[i]; ++i)
    ++map[a[i]];
  for (i = 0; b[i]; ++i)
    if (--map[b[i]] == -1)
      return (0);
  return (1);
}

int		main(int ac, char * const * const av)
{
  if (ac == 3)
    printf("%s\n", checkPermutation(av[1], av[2]) ? "PERMUTATION" : "NOT A PERMUTATION");
  return (0);
}
