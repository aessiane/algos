/*
** Implement a method to perform basic string compression using the counts
** of repeated characters. For example, the string aabcccccaaa would become
** a2blc5a3. If the "compressed" string would not become smaller than the original
** string, your method should return the original string.
*/

#define DIGIT_TO_CHAR(a)	((a) + '0')

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void		unsToChar(char * const str, unsigned count, unsigned * const j)
{
  unsigned	ten = 1;

  while (count / (ten * 10))
    ten *= 10;
  while (ten)
    {
      str[(*j)++] = DIGIT_TO_CHAR((count / ten) % 10);
      ten /= 10;
    }
}

char		*compress(char * const str)
{
  char		*new = NULL;
  unsigned	len;
  unsigned	i = 0;
  unsigned	j = 0;
  unsigned	count;

  if (!str)
    return (NULL);
  len = strlen(str);
  if (!(new = malloc(sizeof(char) * (len + 1))))
    return (NULL);
  memset(new, 0, sizeof(char) * (len + 1));
  while (i < len)
    {
      new[j++] = str[i++];
      count = 1;
      while (str[i] == str[i - 1])
	{
	  ++i;
	  ++count;
	}
      unsToChar(new, count, &j);
      if (j >= len)
	return (str);
    }
  return (new);
}

int		main(int ac, char **av)
{
  if (ac == 2)
    printf("%s\n", compress(av[1]));
}
