// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-18. Write a program to remove trailing blanks and tabs from
// each line of input, and to delete entirely blank lines.

#include <stdio.h>

#define BUF_SIZE 4096

// TODO: comment it. Change program structure
int HandleLine();

int main() {
  while (HandleLine() != 0) {
  }
  return 0;
}

int HandleLine() {
  int c;
  int i;
  int flag_empty_line = 1;
  int blanks_length = 0;
  int blanks[BUF_SIZE];
  enum State {
    kBlanks,
    kWord
  };
  enum State state = kBlanks;

  while ((c = getchar()) != EOF && c != '\n') {
    switch (state) {
      case kBlanks:
        switch (c) {
          case ' ':
          case '\t':
          case '\v':
            if (blanks_length <= BUF_SIZE) {
              blanks[blanks_length++] = c;
            }
            // TODO: Handle error
            break;
          default:
            state = kWord;
            if (flag_empty_line == 1) {
              flag_empty_line = 0;
            }
            for (i = 0; i < blanks_length; ++i) {
              printf("%c", blanks[i]);
            }
            blanks_length = 0;
            putchar(c);
            break;
        }
        break;
      case kWord:
        switch (c) {
          case ' ':
          case '\n':
          case '\v':
            state = kBlanks;
            blanks[blanks_length++] = c;
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
  if (c != EOF) {
    if (flag_empty_line == 0) {
      putchar(c);
    }
    return 1;
  } else {
    return 0;
  }
}
