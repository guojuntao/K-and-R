// Copyright Juntao Guo(guojuntao1@gmail.com).
//
// K&R Exercise 4-1. Write the funtion strrindex(s, t), which returns the
// position of the rightmost occurrence of t in s, or -1 if there is none.

#include <assert.h>
#include <string.h>

#define BUFSIZE 100

int strrindex(char *string, char *pattern);

int main() {
  char string[BUFSIZE], pattern[BUFSIZE];
  strcpy(string, "guojuntaoguojuntao");
  strcpy(pattern, "guo");
  assert(9 == strrindex(string, pattern));
  strcpy(string, "guojuntaoguojuntao");
  strcpy(pattern, "gou");
  assert(-1 == strrindex(string, pattern));
  strcpy(string, "aaaaaaaaa");
  strcpy(pattern, "aaaa");
  assert(5 == strrindex(string, pattern));
  return 0;
}

// KMP algorithm
int strrindex(char *string, char *pattern) {
  int i, j, rightmost = -1;
  int next[BUFSIZE] = { 0 };
  for (i = 1; pattern[i] != '\0'; ++i) {
    if (pattern[i] == pattern[next[i - 1]]) {
      next[i] = next[i - 1] + 1;
    } else {
      next[i] = 0;
    }
  }
  i = 0;
  j = 0;
  while (string[i] != '\0') {
    if (pattern[j] == string[i]) {
      ++i;
      ++j;
    } else {
      if (j != 0) {
        j = next[j - 1];
      } else {
        ++i;
      }
    }
    if (pattern[j] == '\0') {
      rightmost = i - j;
      i = rightmost + 1;
      j = 0;
    }
  }
  return rightmost;
}
