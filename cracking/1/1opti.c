// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ?

#include <stdio.h>

#define UNIQUE		(1)
#define NOT_UNIQUE	(0)

int		func(char * const str)
{
  int		map[8] = {0};

  if (!str || !(*str))
    return (UNIQUE);
  for (int i = 0; str[i]; ++i)
    {
      if (map[str[i] / 32] & (1 << (str[i] % 32)))
	return (NOT_UNIQUE);
      map[str[i] / 32] |= 1 << (str[i] % 32);
    }
  return (UNIQUE);
}

int		main(int ac, char **av)
{
  printf("%s\n", func(av[1]) ? "UNIQUE" : "NOT UNIQUE");
  return (0);
}
