// CopyRight 2013 Juntao Guo (guojuntao1@gmail.com).
// 
// K&R Exercise 1-12. Write a program that prints its input one word per line.

#include <stdio.h>

int main() {
  int c;
  enum State {
    kWord = 0,
    kBlanks,
  };
  enum State state = kBlanks;

  while ((c = getchar()) != EOF) {
    switch (state) {
      case kWord:
        if (c != ' ' && c != '\t' && c != '\n') {
          putchar(c);
        } else {
          state = kBlanks;
          putchar('\n');
        }
        break;
      case kBlanks:
        if (c != ' ' && c != '\t' && c != '\n') {
          state = kWord;
          putchar(c);
        }
        break;
      default:
        break;
    }
  }

  return 0;
}
