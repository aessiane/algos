/*
** 1.c for ok in /Users/abelessiane/prep/algos/cracking/1
**
** Made by Essiane Abel
** Login   <abelessiane@epitech.net>
**
** Started on  Thu Dec 24 19:43:53 2015 Essiane Abel
** Last update Thu Dec 24 19:54:18 2015 Essiane Abel
*/

// Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ?

#define UNIQUE		(1)
#define NOT_UNIQUE	(0)

int		func(char * const str)
{
  char		map[256] = {0};

  if (!str || !(*str))
    return (UNIQUE);
  for (int i = 0; str[i]; ++i)
    {
      if (map[str[i]]++)
	return (NOT_UNIQUE);
    }
  return (UNIQUE);
}

int		main(int ac, char **av)
{
  printf("%s\n", func(av[1]) ? "UNIQUE" : "NOT UNIQUE");
  return (0);
}
