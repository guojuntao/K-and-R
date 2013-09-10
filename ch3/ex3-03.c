// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-3. Write a function expand(s1, s2) that expands shorthand
// notations like a-z in the string s1 into equivalent complete list abc...xyz
// in s2. Allow for letters of either case and digits, and be prepared to handle
// cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or tailing - is
// taken literally.

#include <assert.h>
#include <string.h>

#define BUFSIZE 40

// This function expands shorthand notations in the string src into equivalent
// complete list in string dest.
// Return the string dest's length.
int expand(char dest[], int dest_limit, char src[], int src_length);

int main() { 
  char dest[BUFSIZE];
  expand(dest, BUFSIZE, "a-z", strlen("a-z"));
  assert(!strcmp(dest, "abcdefghijklmnopqrstuvwxyz"));
  expand(dest, BUFSIZE, "-0-9-", strlen("-0-9-"));
  assert(!strcmp(dest, "-0123456789-"));
  expand(dest, BUFSIZE, "a-g0-9", strlen("a-g0-9"));
  assert(!strcmp(dest, "abcdefg0123456789"));
  return 0;
}

int expand(char dest[], int dest_limit, char src[], int src_length) {
  int i = 0;
  int j = 0;
  while (src[i] != '\0' && i < src_length) {
    if (src[i] != '-') {
      if (src[i + 1] != '\0' && i + 1 < src_length && src[i + 1] == '-') {
        if (src[i + 2] != '\0' && i + 2 < src_length) {
          char c; // c is an temp character.
          c = src[i];
          while (c < src[i + 2]) {
            dest[j++] = c;
            if (j == dest_limit) {
              return j;
            }
            c = c + 1;
          }
          i = i + 2;
        } else { // Handle a tailing '-'
          dest[j++] = src[i];
          if (j == dest_limit) {
            return j;
          }
          dest[j++] = src[i + 1];
          dest[j] = '\0';
          return j;
        }
      } else { // Handle a character close to another character
        dest[j++] = src[i];
        if (j == dest_limit) {
          return j;
        }
        ++i;
      }
    } else {  // Handle a leading '-'
      dest[j++] = src[i];
      if (j == dest_limit) {
        return j;
      }
      ++i;
    }
  }
  dest[j] = '\0';
  return j;
}
