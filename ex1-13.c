// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-13. Write a program to print a histogram of the lengths of
// words in its input. It is easy to draw the histogram with the bars
// horizontal; a vertical orientation is more challenging.

#include <stdio.h>

#define MAX_WORD_LENGTH 20 

int main() {
  int word_length_counters[MAX_WORD_LENGTH] = { 0 };
  int i, j;
  int read_char;
  int word_length;  
  int max_counter = 0;
  enum State {
    kWord = 0,
    kBlanks,
  };
  enum State state = kBlanks;

  while ((read_char = getchar()) != EOF) {
    switch (state) {
      case kWord:
        switch (read_char) {
          case ' ':
          case '\t':
          case '\v':
          case '\n':
          case '\r':
            state = kBlanks;
            ++word_length_counters[word_length - 1];
            break;
          default:
            ++word_length;
            break;
        }
        break;
      case kBlanks:
        switch (read_char) {
          case ' ':
          case '\t':
          case '\v':
          case '\n':
          case '\r':
            break;
          default:
            state = kWord;
            word_length = 1;
            break;
        }
        break;
    }
  }
  
  // draw the histogram with the bars horizontally
  printf("Length\twords\n");
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    printf("%d\t", i + 1);
    for (j = 0;
         j < word_length_counters[i];
         ++j) {
      printf("*");
    }
    printf("%d\n", word_length_counters[i]);
  }
  printf("\n\n");
  
  // draw the histogram with a vertical orientation
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    if (word_length_counters[i] > max_counter) {
      max_counter = word_length_counters[i];
    }
  }
  for (j = max_counter; j >= 0; --j) {
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
      if (word_length_counters[i] > j) {
        printf(" * ");
      } else if (word_length_counters[i] == j) {
        printf("%3d", word_length_counters[i]);
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }
  for (i = 0; i < MAX_WORD_LENGTH; ++i) {
    printf("%3d", i + 1);
  }

  return 0;
}
