// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-5. Write the function any(s1, s2), which returns the first
// location in the string s1 where any character from the string s2 occurs, or
// -1 if s1 contains no characters from s2. (The standard library function
// strpbrk does the same job but returns a pointer to the location.)

#include <stdio.h>

int any(char s1[], char s2[]);

int main() {
  char s1[100], s2[100];
  while (scanf("%s %s", s1, s2) == 2) {
    printf("%d\n", any(s1, s2));
  }
  return 0;
}

int any(char s1[], char s2[]) {
  int flag[127] = { 0 };
  int i;

  for (i = 0; s2[i] != '\0'; ++i) {
    flag[s2[i]] = 1;
  }
  for (i = 0; s1[i] != '\0'; ++i) {
    if (flag[s1[i]] == 1) {
      return i;
    }
  }
  return -1;
}
