// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-5. Write the function itob(n, s, b) that converts the integer
// n into a base b character representation in the string s. In particular,
// itob(n, s, 16) formats n as a hexadecimal integer in s.

#include <assert.h>
#include <string.h>

void itob(int number, char *string, int base);

int main() {
  char string[100];
  itob(0, string, 10);
  assert(0 == strcmp(string, "0"));
  itob(31, string, 16);
  assert(0 == strcmp(string, "1f"));
  itob(32, string, 2);
  assert(0 == strcmp(string, "100000"));
  return 0;
}

void itob(int number, char *string, int base) {
  int i, string_length = 0;
  char c;
  if (0 == number) {
    string[string_length++] = '0';
  }
  while (number != 0) {
    if (base <= 10 || (number % base) <= 9) {
      string[string_length++] = number % base - 0 + '0';
    } else {
      string[string_length++] = number % base - 10 + 'a';
    }
    number /= base;
  }
  string[string_length] = '\0';

  for (i = 0; i < string_length / 2; ++i) {
    c = string[i];
    string[i] = string[string_length - 1 - i];
    string[string_length - 1 - i] = c;
  }
}
