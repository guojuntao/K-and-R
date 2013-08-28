// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-9. In a two's complement number system, x &= (x - 1) deletes
// the rightmost 1-bit in x. Explain why. Use this observation to write a faster
// version of bitcount.

#include <stdio.h>

int bitcount(unsigned int x);

int main() {
  unsigned int x;
  while (scanf("%u", &x) == 1) {
    printf("%d\n", bitcount(x));
  }
  return 0;
}

int bitcount(unsigned int x) {
  int counter = 0;
  while (x != 0) {
    x &= (x - 1);
    ++counter;
  }
  return counter;
}
