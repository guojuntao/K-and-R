// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-8. Write a function rightrot(x, n) that returns the value of
// the integer x rotated to the right by n bit positions.

#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);

int main() {
  unsigned int x;
  int n;

  while (scanf("%u %d", &x, &n) == 2) {
    printf("%u\n", rightrot(x, n));
  }

  return 0;
}

unsigned int rightrot(unsigned int x, int n) {
  unsigned int tmp;
  tmp = x & ~(~(unsigned int)0 << n);
  x = x >> n;
  tmp = tmp << sizeof(unsigned int) * 8 -n;
  return x | tmp;
}
