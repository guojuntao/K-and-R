// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-21. Write a program entab that replaces strings of blanks by
// the minimum number of tabs and blanks to achieve the same spacing. Use the
// same tab stops as for detab. When either a tab or a single blank would
// suffice to reach a tab stop, which should be given preference?

#include <stdio.h>

#define TAB_LEN 8
#define BUF_SIZE 4096

// When either a tab or a single blank would suffice to reach a tab stop,
// choose a tab.
int main() {
  int column = 0;
  int blank_len = 0;
  int c;
  int blanks[BUF_SIZE];

  while ((c = getchar()) !=EOF) {
    if (c != ' ') {
      ++column;
      if (blank_len > 0) {
        int start = column - blank_len;
        int fill_len;
        int j;
        while ((fill_len = TAB_LEN - start % TAB_LEN) <= blank_len) {
          putchar('\t');
          blank_len -= fill_len;
          start += fill_len;
        }
        for (j = 0; j < blank_len; ++j) {
          putchar(' ');
        }
        blank_len = 0;
      }
      putchar(c);
      if (c == '\n' || c == '\r') {
        column = 0;
      } 
    } else {
      if (blank_len <= BUF_SIZE) {
        blanks[blank_len++] = c;
      } else {
	printf("The buffer of 4096 Byte is full.");
	return 1;
      }
      ++column;
    }
  }

  return 0;
}
