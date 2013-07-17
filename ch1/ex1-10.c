// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-10. Write a program to copy its input to its output, replacing
// each tab by \t, each backspace by \b, and each backslash by \\. This makes 
// tabs and backspaces visible in an unambiguous way.

#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    switch(c) {
      case '\t':
        printf("\\t");
        break;
      case '\b':
        printf("\\b");
        break;
      case '\\':
        printf("\\\\");
        break;
      case '\n':
	printf("\\n");
	break;
      default:
        putchar(c);
        break;
    }
  }

  return 0;
}
