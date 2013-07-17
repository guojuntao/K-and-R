// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-4. Write a program to print the corresponding Celsius to
// Fahrenheit table.

#include <stdio.h>

#define LOWER -20
#define UPPER 100
#define STEP 10

int main() {
  int celsius;

  for (celsius = LOWER; celsius <= UPPER; celsius += STEP) {
    printf("%3d %6.1f\n", celsius, 9.0 / 5.0 * celsius + 32.0);
  }

  return 0;
}
