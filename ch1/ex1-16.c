// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-16. Revise the main routine of the longest-line program so
// it will correctly print the length of arbitrarily long input lines, and as
// much as possible of the text.

#include <stdio.h>
#include <string.h>

#define BUF_SIZE 4096

// TODO: comment it
int GetLine(char line[]);

// TODO: comment it
void ReverseString(char s[], int start, int end);

int main() {
  int string_length;
  char line[BUF_SIZE];
  char longest_line[BUF_SIZE];
  int max_string_length = 0;

  while ((string_length = GetLine(line)) > 0) {
    if (string_length > max_string_length) {
      max_string_length = string_length;
      if (max_string_length >= BUF_SIZE) {
        memcpy(longest_line, line, BUF_SIZE);
      } else {
        memcpy(longest_line, line, max_string_length + 1);
      }
    }
  }
  if (max_string_length > 0) {
    printf("The longest line length is %d : %s",
        max_string_length, longest_line);
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
  }
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
