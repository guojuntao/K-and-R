// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-22. Write a program to "flod" long input lines into two or
// more shorter lines after the last non-blank character that occurs before the
// n-th column of input. Make sure your program does something intelligent with
// very long lines, and if there are no blanks or tabs before the specified
// column.

#include <stdio.h>
#include <string.h>

// The LINE_LEN don't include '\n'
#define LINE_LEN 20
#define TAB_LEN 8

int main() {
  char short_line[LINE_LEN];    // store the words in this line 
                                // (I can't think a better name).
  int size_on_screen = 0;       // the char's location on screen
  int size_in_memory = 0;       // the char's location in the memory 
                                // of short_line
  int flod_line_location;       // find the location of flod line
  int c;                        // read a character from input store in c 

  while ((c = getchar()) != EOF) {
    switch (size_on_screen) {
      // the short line is full, find flod location and then print
      case (LINE_LEN):
        flod_line_location = LINE_LEN;
        while (flod_line_location > 0 && (short_line[flod_line_location - 1] != ' ' &&
            short_line[flod_line_location - 1] != '\t')) {
          --flod_line_location;
        }
        if (flod_line_location == 0) {
          fwrite(short_line, LINE_LEN, 1, stdout);
          putchar('\n');
          size_in_memory = 0;
          size_on_screen = 0;
          if (c == '\n') {
            break;
          }
        } else {
          //strncpy(tmp, short_line + flod_line_location, LINE_LEN - flod_line_location);
          fwrite(short_line, flod_line_location, 1, stdout);
          putchar('\n');
          strncpy(short_line, short_line + flod_line_location, LINE_LEN - flod_line_location);
          size_in_memory = LINE_LEN - flod_line_location;
          size_on_screen = LINE_LEN - flod_line_location;
        }
        // fall-through

      // the short line is not full, handle the character
      default:
        switch (c) {
          case ('\n'):
            short_line[size_in_memory++] = c;
            fwrite(short_line, size_in_memory, 1, stdout);
            size_in_memory = 0;
            size_on_screen = 0;
            break;
          case ('\t'):
            size_on_screen = (size_on_screen / TAB_LEN + 1) * TAB_LEN;
            if (size_on_screen > LINE_LEN) {
              fwrite(short_line, size_in_memory, 1, stdout);
              putchar('\n');
              short_line[0] = '\t';
              size_in_memory = 1;  
              size_on_screen = TAB_LEN;
            } else {
              short_line[size_in_memory++] = c;
            }
            break;
          default:
            short_line[size_in_memory++] = c;
            ++size_on_screen;
            break;
        }
        break;
    }
  }

  return 0;
}
