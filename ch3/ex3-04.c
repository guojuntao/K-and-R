// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-4. In a two's complement number representation, our version of
// itoa does not handle the largest negative number, that is the value of n
// equal to -(2 ^ (wordsize - 1)). Explain why not. Modify it to print that
// value correctly, regardless of the machine on which it runs.

#include <limits.h>

// Old version in the book
// void itoa (int n, char s[]) {
//   int i, sign;
//   if ((sign = n) < 0) {
//     n = -n;
//   }
//   i = 0;
//   do {
//     s[i++] = n % 10 + '0';
//   } while ((n /= 10) > 0);
//   if (sign < 0) {
//     s[i++] = '-';
//   }
//   s[i] = '\0';
//   reverse(s);
// }

// My version
// This function convers an integer 'n' into the string 's' 
void itoa (int n, char s[]) {
  int i, sign;
  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;
  // If the value of n equal to -(2 ^ (wordsie - 1))
  if (n == -n) {
    s[i++] = INT_MAX % 10 + '0' + 1;
    n = INT_MAX / 10;
  }
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
