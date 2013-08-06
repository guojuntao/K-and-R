// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-18. Write a program to remove trailing blanks and tabs from
// each line of input, and to delete entirely blank lines.

#include <stdio.h>

#define BUF_SIZE 4096

int main() {
  int c;
  int i;
  int flag_empty_line = 1;
  int blank_length = 0;
  int blanks[BUF_SIZE];
  enum State {
    kBlanks,
    kWord,
  };
  enum State state = kBlanks;

  while ((c = getchar()) != EOF) {
    switch (state) {
      case kBlanks:
        switch (c) {
          case ' ':
          case '\t':
          case '\v':
            if (blank_length <= BUF_SIZE) {
              blanks[blank_length++] = c;
            } else {
              printf("The buffer is full.\n");
              return 1;
            }
            break;
          case '\n':
          case '\r':
            if (flag_empty_line == 0) {
              putchar(c);
            }
            flag_empty_line = 1;
            blank_length = 0;
            break;
          default:
            state = kWord;
            if (flag_empty_line == 1) {
              flag_empty_line = 0;
            }
            for (i = 0; i < blank_length; ++i) {
              printf("%c", blanks[i]);
            }
            blank_length = 0;
            putchar(c);
            break;
        }
        break;
      case kWord:
        switch (c) {
          case ' ':
          case '\t':
          case '\v':
            state = kBlanks;
            blanks[blank_length++] = c;
            break;
          case '\n':
          case '\r':
            putchar(c);
            state = kBlanks;
            flag_empty_line = 1;
            blank_length = 0;
            break;
          default:
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
