// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-2. Write a function escape(s, t) that converts characters like
// newline and tab into visible escape sequences like \n and \t as it copies the
// string t to s. Use a switch. Write a function for the other direction as
// well, converting escape sequences into the unescape characters.

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 40 

// This function converts characters like newline and tab into visible escape
// sequences as it copies the string src to dest.
// Return the string dest's length.
int Escape(char dest[], int dest_limit, char src[], int src_length);
// This function converts escape sequences into the unescape characters as it
// copies the string src to dest.
// Return the string dest's length.
int Unescape(char dest[], int dest_limit, char src[], int src_length);

int main() {
  char escape_string[BUFSIZE] = "first\\nsecond\\tthird";
  char unescape_string[BUFSIZE] = "first\nsecond\tthird";
  char compare_string[BUFSIZE];
  Escape(compare_string, BUFSIZE, unescape_string, BUFSIZE);
  assert(!strcmp(escape_string, compare_string));
  Unescape(compare_string, BUFSIZE, escape_string, BUFSIZE);
  assert(!strcmp(unescape_string, compare_string));
  return 0;
}

int Escape(char dest[], int dest_limit, char src[], int src_length) {
  int i = 0;
  int j = 0;
  while (src[i] != '\0' && i < src_length) {
    switch (src[i]) {
      case '\t':
        dest[j++] = '\\';
        if (j == dest_limit) {
          return j;
        }
        dest[j++] = 't';
        if (j == dest_limit) {
          return j;
        }
        break;
      case '\n':
        dest[j++] = '\\';
        if (j == dest_limit) {
          return j;
        }
        dest[j++] = 'n';
        if (j == dest_limit) {
          return j;
        }
        break;
      default:
        dest[j++] = src[i];
        if (j == dest_limit) {
          return j;
        }
        break;
    }
    ++i;
  }
  dest[j] = '\0';
  return j;
}

int Unescape(char dest[], int dest_limit, char src[], int src_length) {
  int i = 0;
  int j = 0;
  while (src[i] != '\0' && i < src_length) {
    switch (src[i]) {
      case '\\':
        if (src[i + 1] != '\0' && i + 1 < src_length) {
          switch (src[i + 1]) {
            case 't':
              dest[j++] = '\t';
              if (j == dest_limit) {
                return j;
              }
              ++i;
              break;
            case 'n':
              dest[j++] = '\n';
              if (j == dest_limit) {
                return j;
              }
              ++i;
              break;
            default:
              dest[j++] = '\\';
              if (j == dest_limit) {
                return j;
              }
              break;
          }
        }
        break;
      default:
        dest[j++] = src[i];
        if (j == dest_limit) {
          return j;
        }
        break;
    }
    ++i;
  }
  dest[j] = '\0';
  return j;
}
