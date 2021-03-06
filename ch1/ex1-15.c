// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-15. Rewrite the temperature conversion program of Section 1.2
// to use a function for conversion.

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

double FahrToCelsius(int fahr);

int main() {
  int fahr;
  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%3d %6.1f\n", fahr, FahrToCelsius(fahr));
  }
  return 0;
}

double FahrToCelsius(int fahr) {
  return (5.0 / 9.0) * (fahr - 32);
} 
