// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with
// the n bits that begin at position p set to the rightmost n bits of y, leaving
// the other bits unchanged.

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main() {
  unsigned int x;
  int p;
  int n;
  unsigned int y;

  while (scanf("%u %d %d %u", &x, &p, &n, &y) == 4) {
    printf("%u\n", setbits(x, p, n, y));
  }

  return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
  if (p >= sizeof(unsigned int) * 8 || p + 1 - n < 0) {
    // TODO: Error message
  } 
  return x & 
      ((((~(unsigned)0 << n) | y) << (p + 1 - n)) | (~(~(unsigned)0 << n)));
}
