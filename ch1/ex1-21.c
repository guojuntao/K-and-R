// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-21. Write a program entab that replaces strings of blanks by
// the minimum number of tabs and blanks to achieve the same spacing. Use the
// same tab stops as for detab. When either a tab or a single blank would
// suffice to reach a tab stop, which should be given preference?

#include <stdio.h>

#define TAB_LEN 8

// When either a tab or a single blank would suffice to reach a tab stop, choose
// a blank.
int main() {
  int column = 0;
  int space_counter = 0;
  int c;

  while ((c = getchar()) !=EOF) {
    if (c != ' ') {
      if (c == '\t') {
        putchar(c);
        space_counter = 0;
        column = (column / TAB_LEN + 1) * TAB_LEN; 
      } else {
        int i;
        for (i = 0; i < space_counter; ++i) {
          putchar(' ');
        }
        putchar(c);
        space_counter = 0;
        ++column;
        if (c == '\n') {
          column = 0;
        }
      }
    } else {
      ++space_counter;
      ++column;
      if (column % TAB_LEN == 0) {
        if (space_counter == 1) {
          putchar(' ');
        } else {
          putchar('\t');
        }
        space_counter = 0;
      }
    }
  } 
  return 0;
}
