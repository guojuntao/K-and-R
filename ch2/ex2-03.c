// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-3. Write the function htoi(s), which converts a string of
// hexadecimal digits (including an optional 0x or 0X) into its equivalent
// integer value. The allowable digits are 0 through 9, a through f, and A
// through F.

#include <stdio.h>

int htois(char hex_string[]);

int main() {
  char hex_string[20];
  while (scanf("%s", hex_string) == 1) { 
    printf("%s\t%d\n", hex_string, htois(hex_string));
  }
  return 0;
}

int htois(char hex_string[]) {
  int number = 0;
  int i = 0;

  if (hex_string[i] == '0') {
    ++i;
    if (hex_string[i] == 'x' || hex_string[i] == 'X') {
      ++i;
    } else if (hex_string[i] == '\0') {
      return 0;
    } else {
      return -1;
    }
  }
  while (hex_string[i] != '\0') {
    if (hex_string[i] >= '0' && hex_string[i] <= '9') {
      number = number * 16 + (hex_string[i] - '0');
    } else if (hex_string[i] >= 'a' && hex_string[i] <= 'f') {
      number = number * 16 + (hex_string[i] - 'a' + 10);
    } else if (hex_string[i] >= 'A' && hex_string[i] <= 'F') {
      number = number * 16 + (hex_string[i] - 'A' + 10);
    } else {
      return -1;
    }
    ++i;
  }

  return number;
}
