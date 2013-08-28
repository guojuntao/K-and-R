// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-10. Rewrite the function lower, which converts upper case
// letters to lower case, with a conditional expression instead of if-else.

#include <stdio.h>

int lower(int c);

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    printf("%c\n", lower(c));
  }
  return 0;
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}
