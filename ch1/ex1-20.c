// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
// 
// Exercise 1-20. Write a program debtab that replaces tabs in the input with
// the proper number of blanks to space to the next tab stop. Assume a fixed
// set of tab stops, say every n columns. Should n be a variable or a symbolic
// parameter?

#include <stdio.h>

#define TAB_LEN 8

int main() {
  int column = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c != '\t') {
      putchar(c);
      ++column;
      if (c == '\n' || c == '\r') {
        column = 0;
      }
    } else {
      int blank_num = TAB_LEN - (column % TAB_LEN);
      int j;
      for (j = 0; j < blank_num; ++j) {
        putchar(' ');
      }
    }
  }

  return 0;
}
