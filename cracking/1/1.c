// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ?

#include <stdio.h>

#define UNIQUE		(1)
#define NOT_UNIQUE	(0)

int		func(char * const str)
{
  char		map[256] = {0};

  if (!str || !(*str))
    return (UNIQUE);
  for (int i = 0; str[i]; ++i)
    {
      if (map[str[i]])
	return (NOT_UNIQUE);
      map[str[i]] = 1;
    }
  return (UNIQUE);
}

int		main(int ac, char **av)
{
  if (ac != 2)
    return (1);
  printf("%s\n", func(av[1]) ? "UNIQUE" : "NOT UNIQUE");
  return (0);
}
