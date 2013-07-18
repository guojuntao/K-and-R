// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-2. Experiment to find out what happens when printf's
// argument string contains \c, where c is some character not listed above.

#include <stdio.h>

int main() {
  printf("Hello,\c world!\n");
  return 0;
}

