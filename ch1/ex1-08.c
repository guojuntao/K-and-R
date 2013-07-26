// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-8. Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

int main() {
  int c;
  int blank_count = 0;
  int tab_count = 0;
  int newline_count = 0;

  while ((c = getchar()) != EOF) {
    switch(c) {
      case ' ':
        ++blank_count;
        break;
      case '\t':
        ++tab_count;
        break;
      case '\n':
        ++newline_count;
        break;
      default:
        break;
    }
  }
  printf("blanks:%d tabs:%d newlines:%d\n",
         blank_count,
         tab_count,
         newline_count);

  return 0;
}
