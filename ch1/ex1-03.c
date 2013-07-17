// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-3. Modify the temperature conversion program to print a
// heading above the table.

#include <stdio.h>

int main() {
  double fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("fahr  celsius\n");
  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%4.0f   %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
