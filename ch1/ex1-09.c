// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
// 
// K&R Exercise 1-9. Write a program to copy its input to its output, replacing
// each string of one or more blanks by a single blank.

#include <stdio.h>

int main() {
  int c;
  enum State {
    kRegular = 0,
    kInsideSpaces,
  };
  enum State state = kRegular;

  while ((c = getchar()) != EOF) {
    switch (state) {
      case kRegular:
        switch (c) {
          case ' ':
            state = kInsideSpaces;
            // fall-through
          default:
            putchar(c);
        }
        break;
      case kInsideSpaces:
        switch (c) {
          case ' ':
            break;
          default:
            state = kRegular;
            putchar(c);
            break;
        }
        break;
      default:
        break;
    }
  }
  return 0;
}
