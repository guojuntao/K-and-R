// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
// notations like a-z in the string s1 into equivalent complete list abc...xyz
// in s2. Allow for letters of either case and digits, and be prepared to handle
// cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or tailing - is
// taken literally.

#include <stdio.h>

int expand(s1, s2) {
  int i = 0;
  int j = 0;
  while (s1[i] != '\0') {
    if (s1[i] >= 'a' && s1[i] <= 'z') {
      if (s1[i + 1] == '-' && s1[i + 2] >= 'a' && s1[i + 2] <= 'z' && 
        s1[i] < s1[i + 2]) {
        while (s2[j] < s1[i + 2]) {
          
        }
      }
    }
  }
}
