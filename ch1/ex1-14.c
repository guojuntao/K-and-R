// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-14. Write a program to print a histogram of the frequencies
// of different characters in its input.

#include <stdio.h>

// Frequency statistics only 26 letters
#define CHAR_NUM 26

int main() {
  int i, j;
  int read_char;
  int char_counters[CHAR_NUM] = { 0 };
  int char_frequency[CHAR_NUM];
  int all_char_counter = 0;

  while ((read_char = getchar()) != EOF) {
    if (read_char >= 'a' && read_char <= 'z') {
      ++char_counters[read_char - 'a'];
    } else if (read_char >= 'A' && read_char <= 'Z') {
      ++char_counters[read_char - 'A'];
    }
  }

  for (i = 0; i < CHAR_NUM; ++i) {
    all_char_counter += char_counters[i];
  }
  for (i = 0; i < CHAR_NUM; ++i) {
    char_frequency[i] = char_counters[i] * 100 
                                / all_char_counter;
  }

  printf("character frequency\n");
  for (i = 0; i < CHAR_NUM; ++i) {
    printf("%c         ", 'a' + i); 
    for (j = 0; j < char_frequency[i]; ++j) {
      printf("*");
    }
    printf("%d%%\n", char_frequency[i]);
  }

  return 0;
}
