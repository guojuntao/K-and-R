// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-16. Revise the main routine of the longest-line program so
// it will correctly print the length of arbitrarily long input lines, and as
// much as possible of the text.

#include <stdio.h>

#define MAX_LINE 1000

int get_line(char line[]);

int main() {
  char line[MAX_LINE];

  while (get_line(line) > 0) {
    printf("%s", line);
  }

  return 0;
}

int get_line(char s[]) {
  int c;
  int i;

  for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}
