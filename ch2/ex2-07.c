// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// k&R Exercise 2-7. Write a function invert(x, p, n) that returns x with the n
// bits that begin at position p inverted (i.e., 1 changed into 0 and vice
// verse), leaving the others unchanged.

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main() {
  unsigned int x;
  int p;
  int n;

  while (scanf("%u %d %d", &x, &p, &n) == 3) {
    printf("%u\n", invert(x, p, n));
  }
  
  return 0;
}

unsigned int invert(unsigned int x, int p, int n) {
  if (p >= sizeof(unsigned int) * 8 || p + 1 - n < 0) {
    // TODO: Error message
  } 
  return x ^ (~(~(unsigned)0 << n) << (p + 1 - n));
}
