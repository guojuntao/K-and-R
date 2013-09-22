// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-6. Write a version of itoa that accepts three arguments
// instead of two. The third argument is a minimum field width; the converted
// number must be padded with blanks on the left if necessary to make it wide
// enough.

#include <assert.h>
#include <string.h>

void itoa(int number, char *string, int min_field_width);

int main() {
  char string[32];
  itoa(123, string, 10);
  assert(0 == strcmp(string, "       123"));
  itoa(12345, string, 4);
  assert(0 == strcmp(string, "12345"));
  return 0;
}

void itoa(int number, char *string, int min_field_width) {
  int i, string_length = 0;
  char c;
  if (0 == number) {
    string[string_length++] = '0';
  }
  while (0 != number) {
    string[string_length++] = number % 10 - 0 + '0';
    number /= 10;
  }
  while (string_length < min_field_width) {
    string[string_length++] = ' ';
  }
  string[string_length] = '\0';
  for (i = 0; i < string_length / 2; ++i) {
    c = string[i];
    string[i] = string[string_length - 1 - i];
    string[string_length - 1 - i] = c;
  }
}
