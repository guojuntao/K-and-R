// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-19. Write a function reverse(s) that reverses the character
// string s. Use it to write a program that reverses its input a line at a
// time.

#include <stdio.h>

#define BUF_SIZE 4096 

// Read a line from standard input and store it in the string line[BUF_SIZE],
// return the length of the line.
int GetLine(char s[]);

// Reverse string s[] from the location start to end: s[start, end).
void StringReverse(char s[], int start, int end);

int main() {
  int string_length;
  char line[BUF_SIZE];

  while ((string_length = GetLine(line)) != 0) {
    StringReverse(line, 0, string_length);
    printf("%s", line);
  }
  return 0;
}

int GetLine(char s[]) {
  int c;
  int i;

  for (i = 0; (c = getchar()) != EOF && c != '\n' && i < BUF_SIZE - 2; ++i) {
    s[i] = c;
  }
  if (c != EOF) {
    s[i] = '\n';
    ++i;
  }
  s[i] = '\0';
  return i;
}

void StringReverse(char s[], int start, int end) {
  int i = start;
  int j = end - 1;
  char tmp;

  while (i < j) {
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    ++i;
    --j;
  }
}
