// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-2. Write a function escape(s, t) that converts characters like
// newline and tab into visible escape sequences like \n and \t as it copies the
// string t to s. Use a switch. Write a function for the other direction as
// well, converting escape sequences into the real characters.

#include <assert.h>
#include <stdio.h>
#include <string.h>

int escape(char dest[], char src[]);
int real(char dest[], char src[]);

int main() {
  char escape_string[40] = "first\\nsecond\\tthird";
  char real_string[40] = "first\nsecond\tthird";
  char compare_string[40];
  escape(compare_string, real_string);
  assert(!strcmp(escape_string, compare_string));
  real(compare_string, escape_string);
  assert(!strcmp(real_string, compare_string));
  return 0;
}

int escape(char dest[], char src[]) {
  int i = 0;
  int j = 0;
  while (src[i] != '\0') {
    switch (src[i]) {
      case '\t':
        dest[j++] = '\\';
        dest[j++] = 't';
        break;
      case '\n':
        dest[j++] = '\\';
        dest[j++] = 'n';
        break;
      default:
        dest[j++] = src[i];
        break;
    }
    ++i;
  }
  dest[j] = '\0';
  return j;
}

int real(char dest[], char src[]) {
  int i = 0;
  int j = 0;
  while (src[i] != '\0') {
    switch (src[i]) {
      case '\\':
        switch (src[i + 1]) {
          case 't':
            dest[j++] = '\t';
            ++i;
            break;
          case 'n':
            dest[j++] = '\n';
            ++i;
            break;
          default:
            dest[j++] = '\\';
            break;
        }
        break;
      default:
        dest[j++] = src[i];
        break;
    }
    ++i;
  }
  dest[j] = '\0';
  return j;
}
