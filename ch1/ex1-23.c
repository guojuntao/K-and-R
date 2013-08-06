// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-23. Write a program to remove all comments from a C program.
// Don't forget to handle quoted strings and character constants properly. C
// comments do not nest.

#include <stdio.h>

int main() {
  int c;
  enum CommentState {
    kNormal = 0,
    kQuote,
    kReadyComment,
    kSingleLineComment,
    kMultiLineComment,
    kReadyToEndMultiLineComment,
  };
  enum CommentState comment_state = kNormal;

  while ((c = getchar()) != EOF) {
    switch (comment_state) {
      case kNormal:
        switch (c) {
          case '/':
            comment_state = kReadyComment;
            break;
          // Avoid the \" characters to be treated as the begin of double quote
          case '\\':
            getchar();
            break;
          case '\"':
            comment_state = kQuote;
            break;
          default:
            putchar(c);
            break;
        }
        break;
      case kQuote:
        switch (c) {
          // Avoid the \" characters to be treated as the end of double quote
          case '\\':
            getchar();
            break;
          case '\"':
            comment_state = kNormal;
            break;
          case '\n':
            printf("Error. The quote symbols are not match.\n");
            return 1;
            break;
          default:
            break;
        }
        break;
      case kReadyComment:
        switch (c) {
          case '/':
            comment_state = kSingleLineComment;
            break;
          case '*':
            comment_state = kMultiLineComment;
            break;
          default:
            putchar('/');
            putchar(c);
            comment_state = kNormal;
            break;
        }
        break;
      case kSingleLineComment:
        switch (c) {
          case '\n':
            comment_state = kNormal;
            break;
          default:
            break;
        }
        break;
      case kMultiLineComment:
        switch (c) {
          case '*':
            comment_state = kReadyToEndMultiLineComment;
            break;
          default:
            break;
        }
        break;
      case kReadyToEndMultiLineComment:
        switch (c) {
          case '/':
            comment_state = kNormal;
            break;
          // Avoid **/ to be ignored as the end of multiline comment
          case '*':
            break;
          default:
            comment_state = kMultiLineComment;
            break;
        }
        break;
      default:
        break;
    }
  }
  
  return 0;
}
