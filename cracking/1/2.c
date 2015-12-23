// Implement a function void reverse(char *str) in C or C++ which reverses a null-terminated string.

#include <string.h>
#include <stdio.h>

void		my_swap(char * const a, char * const b)
{
  char		tmp = *a;

  *a = *b;
  *b = tmp;
}

void		reverse(char * const str)
{
  int		i;
  unsigned	len;

  if (!str)
    return ;
  len = strlen(str);
  i = len / 2;
  while (--i > -1)
    {
      my_swap(str + i, str + len - i - 1);
    }
}

int		main(int ac, char **av)
{
  reverse(av[1]);
  printf("%s\n", av[1]);
  return (0);
}
