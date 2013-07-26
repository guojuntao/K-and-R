// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-17. Write a program to print all input lines that are longer
// than 80 characters.

#include <stdio.h>

#define BUF_SIZE 4096

// TODO: comment it
int GetLine(char line[]);

// TODO: comment it
void ReverseString(char s[], int start, int end);

int main() {
  char line[BUF_SIZE];
  int string_length;

  while ((string_length = GetLine(line)) != 0) {
    if (string_length > 20) {
      printf("%s", line);
    }
  }
  return 0;
}

int GetLine(char s[]) {
  int c;
  int i, j;
  int flag_full_buf = 0;
  enum State {
    kPrintHead = 0,
    kPrintTail,
  };
  // TODO: comment it
  enum State state = kPrintTail;

  for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (j < BUF_SIZE - 2) {
      s[j] = c;
      ++j;
    } else if (state == kPrintTail) {
      if (flag_full_buf == 0) {
        flag_full_buf = 1;
      }
      j %= BUF_SIZE;
      s[j] = c;
      ++j;
    }
  }
  if (c == '\n') {
    s[j] = c;
    ++i;
    ++j;
  }
  s[j] = '\0';

  if (state == kPrintTail && flag_full_buf == 1) {
    ReverseString(s, 0, j + 1);
    ReverseString(s, j + 1, BUF_SIZE);
    ReverseString(s, 0, BUF_SIZE);
  }

  return i;
}

void ReverseString(char *s, int start, int end) {
  char tmp;
  int i = start;
  int j = end - 1;
  while (i < j) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    ++i;
    --j;
  }
}
