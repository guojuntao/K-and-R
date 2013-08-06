// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-24. Write a program to check a C program for rudimentary
// syntax errors like unbalanced parentheses, brackets and braces. Don't forget
// about quotes, both single and double, escape sequences, and comments. (This
// program is hard if you do it in full generality.)

#include <stdio.h>
#include <stdlib.h>

#define STACK_INCREASE_SIZE 100

void PushStack(int symbol);
void PopStackAndCheak(int symbol);
// Skip the Escape Character and return the character followed the escape
// character
int  SkipEscapeCharacter();
void SkipSingleQuote();
void SkipDoubleQuote();
void SkipComment();
void CheckStackEmpty();

struct MatchSymbolInfo {
  char symbol;
  int occur_line_num;
};

struct InfoStack {
  struct MatchSymbolInfo *base;
  struct MatchSymbolInfo *top;
  int size;
};

int c; // Read a character from stdin and store in c
int line_num = 1;  // Record the current line when read the program 
struct InfoStack info_stack;  // The stack store the infomation about the
                              // parentheses, brackets and braces 

int main() {
  info_stack.base = (struct InfoStack *)malloc(STACK_INCREASE_SIZE * sizeof
      (struct InfoStack));
  info_stack.top = info_stack.base + 1;
  info_stack.size = STACK_INCREASE_SIZE;

  while ((c = getchar()) != EOF) {
    switch (c) {
      // Avoid the \" or \'characters to be treated as the begin of quote
      // If the program occurs \{, it will not be treated as an error.  
      case '\\':
        c = SkipEscapeCharacter();
        // fall-through
      case '{':
      case '[':
      case '(':
        PushStack(c);
        break;
      case '}':
      case ']':
      case ')':
        PopStackAndCheak(c);
        break;
      case '\'':
        SkipSingleQuote();
        break;
      case '\"':
        SkipDoubleQuote();
        break;
      case '/':
        SkipComment();
        break;
      case '\n':
        ++line_num;
        break;
      default:
        break;
    }
  }
  CheckStackEmpty();

  return 0;
}


void PushStack(int symbol) {
  if (info_stack.top - info_stack.base >= info_stack.size) {
    info_stack.base =  (struct InfoStack *) realloc (info_stack.base,
        (info_stack.size + STACK_INCREASE_SIZE) * sizeof(struct InfoStack));
    info_stack.top = info_stack.base + info_stack.size;
    info_stack.size += STACK_INCREASE_SIZE;
  } else {
    info_stack.top->symbol = symbol;
    info_stack.top->occur_line_num = line_num;
    ++info_stack.top;
  }
}

void PopStackAndCheak(int symbol) {
  if (info_stack.top - info_stack.base > 1) {
    --info_stack.top;
    switch (info_stack.top->symbol) {
      case '{':
       if (symbol == '}') {
        break;
       } else {
         printf("Error. '{' occur in line %d and %c occur in line %d are not \
             match.\n", info_stack.top->occur_line_num, symbol, line_num); 
         exit(1);
       }
       break;
      case '[':
       if (symbol == ']') {
        break;
       } else {
         printf("Error. '[' occur in line %d and %c occur in line %d are not \
             match.\n", info_stack.top->occur_line_num, symbol, line_num); 
         exit(2);
       }
       break;
      case '(':
       if (symbol == ')') {
        break;
       } else {
         printf("Error. '(' occur in line %d and %c occur in line %d are not \
             match.\n", info_stack.top->occur_line_num, symbol, line_num); 
         exit(3);
       }
       break;
      default:
       break;
    }
  } else {
    printf("Error. The symbol stack is empty.\n");
    exit(4);
  }
}
  

int SkipEscapeCharacter() {
  int num;
  c = getchar();
  switch (c) {
    case 'a':
    case 'b':
    case 'f':
    case 'n':
    case 'r':
    case 't':
    case 'v':
    case '\\':
    case '\?':
    case '\'':
    case '\"':
      c = getchar();
      break;
    case 'x':
      num = 0;
      c = getchar();
      while (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || 
          (c >= 'A' && c <= 'F')) && num < 2) {
        ++num;
        c = getchar();
      }
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      num = 1;
      c = getchar();
      while (c >= '0' && c <= '9' && num < 3) {
        ++num;
        c = getchar();
      }
      break;
    default:
      c = getchar();
      break;
  }
  return c;
}

void SkipSingleQuote() {
  c = getchar();
  switch (c) {
    case '\\':
      c = SkipEscapeCharacter();
      if (c != '\'') {
        printf("Error. The single quote symbols \' are not match int line %d.\
            \n", line_num);
        exit(5);
      }
      break;
    default:
      if ((c = getchar()) != '\'') {
        printf("Error. The single quote symbols \' are not match int line %d.\
            \n", line_num);
        exit(5);
      }
      break;
  }
}

void SkipDoubleQuote() {
  while((c = getchar()) != '\"') {
    // Avoid the \" characters to be treated as the end of double quote
    if (c == '\\') {
      getchar();
    }
    if (c == '\n') {
      printf("Error. The double quote symbols \" are not match in line %d.\n",
          line_num);
      exit(6);
      break;
    }
  }
}

void SkipComment() {
  enum CommentState {
    kSingleLineComment = 0,
    kMultiLineComment,
  } comment_state;

  c = getchar();
  switch (c) {
    case '/':
      comment_state = kSingleLineComment;
      break;
    case '*':
      comment_state = kMultiLineComment;
      break;
    default:
      printf("Error. The character follow '/' is illegal in line %d.\n",
          line_num);
      exit(7);
      break;
  }

  switch (comment_state) {
    case kSingleLineComment:
      while (c = getchar() != '\n') {
      }
      ++line_num;
      break;
    case kMultiLineComment:
      c = getchar();
      while (c != '*' && (c = getchar()) != '/') {
        if (c == '\n') {
          ++line_num;
        }
      }
      break;
    default:
      break;
  }
} 

void CheckStackEmpty() {
  if (info_stack.top - info_stack.base == 1) {
    printf("Congratulations. Your program has no error about unbalanced \
        parentheses, brackets and braces.\n");
  } else {
    printf("Error. Your program has some errors about unbalanced parentheses, \
        brackets and braces. You can check line %d and its matching symbol.\n",
        (info_stack.top-1)->occur_line_num);
  }
}
