// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-17. Write a program to print all input lines that are longer
// than 80 characters.

#include <stdio.h>

#define BUF_SIZE 81

int main() {
  int c;
  int i = 0;
  int flag_input_tmp = 0;
  char tmp[BUF_SIZE] = {'\0'};

  while ((c = getchar()) != EOF) {
    if ((c != '\n' && c != '\r') && i < BUF_SIZE - 1) {
     tmp[i++] = c;
    } else if ((c == '\n' || c == '\r') && i < BUF_SIZE - 1) {
      i = 0;
    } else {
      if (flag_input_tmp == 0) {
        printf("%s", tmp);
        flag_input_tmp = 1;
      }
      putchar(c);
      if (c == '\n' || c == '\t') {
        i = 0;
        flag_input_tmp = 0;
      }
    }
  }

  return 0;
}
