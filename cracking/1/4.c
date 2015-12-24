// Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end of the string to hold
// the additional characters, and that you are given the "true" length of the string.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void		replaceSpaces(char * const str, int trueLen)
{
  const char	*newSpace = "%20";
  int		i;
  int		j;

  if (!str || trueLen < 0)
    return ;
  i = strlen(str);
  j = trueLen;
  while (--i > -1)
    {
      if (str[i] == ' ')
	{
	  j -= 3;
	  strncpy(str + j, newSpace, 3);
	}
      else
	str[--j] = str[i];
    }
}

int		main(int ac, char ** const av)
{
  int		trueLen = 0;
  char		*str;

  if (ac != 2)
    return (1);
  for (int i = 0; av[1][i]; ++i)
    trueLen += (av[1][i] == ' ' ? 3 : 1);
  if ((str = malloc(sizeof(char) * (trueLen + 1))) == NULL)
    return (1);
  memset(str, 0, trueLen + 1);
  strcpy(str, av[1]);
  replaceSpaces(str, trueLen);
  printf("%s\n", str);
  free(str);
  return (0);
}
