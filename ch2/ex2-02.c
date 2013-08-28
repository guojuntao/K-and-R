// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-2. Write a loop equivalent to the for loop above without using
// && or ||.

// the for loop above:
// for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
//   s[i] = c;
// }

#include <stdio.h>

int main() {
  int i;
  int c;
  int lim = 80;
  char s[lim];

  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) == '\n') {
      break;
    } else if (c == EOF) {
      break;
    } else {
      s[i] = c;
    }
  }

  return 0;
}
