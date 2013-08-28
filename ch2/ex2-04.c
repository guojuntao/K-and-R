// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes
// each character in s1 that matches any character in the string s2.

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main() {
  char s1[100], s2[100];
  while (scanf("%s %s", s1, s2) == 2) {
    squeeze(s1, s2);
    printf("%s\n", s1);
  }
  return 0;
}

void squeeze(char s1[], char s2[]) {
  int flag[127] = { 0 };
  int i, j;

  for (i = 0; s2[i] != '\0'; ++i) {
    flag[s2[i]] = 1;
  }
  for (i = 0, j = 0; s1[i] != '\0'; ++i) {
    if (flag[s1[i]] == 0) {
      s1[j] = s1[i];
      ++j;
    }
  }
  s1[j] = '\0';
}     
