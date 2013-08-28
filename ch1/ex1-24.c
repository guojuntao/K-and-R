// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 1-24. Write a program to check a C program for rudimentary
// syntax errors like unbalanced parentheses, brackets and braces. Don't forget
// about quotes, both single and double, escape sequences, and comments. (This
// program is hard if you do it in full generality.)

#include <stdio.h>
#include <stdlib.h>

#define STACK_INCREASE_SIZE 100

// Push { [ ( into stack
int PushStack(int symbol);
// When get } ] ), pop stack symbol and check do them match
int PopStackAndCheck(int symbol);
int SkipEscapeCharacter();
int SkipSingleQuote();
int SkipDoubleQuote();
int SkipComment();
int CheckStackEmpty();
int PrintMessage(int result_code);

enum ResultCode {
  kSuccess = 0,
  kBracesError,
  kBracketsError,
  kParenthesesError,
  kStackEmptyError,
  kSingleQuoteError,
  kDoubleQuoteError,
  kGoToCommentError,
  kMatchError,
};

struct SymbolInfo {
  char symbol;
  int occur_line_num;
};

struct InfoStack {
  struct SymbolInfo *base;
  struct SymbolInfo *top;
  int size;
};

int c;  // Read a character from stdin and store in c
int line_num = 1;  // Record the current line when read the program 

// The stack store the infomation about the parentheses, brackets and braces 
struct InfoStack info_stack;  

int main() {
  int result_code = kSuccess;
  info_stack.base = (struct SymbolInfo*)malloc(STACK_INCREASE_SIZE * sizeof
      (struct SymbolInfo));
  info_stack.top = info_stack.base + 1;
  info_stack.size = STACK_INCREASE_SIZE;

  while ((c = getchar()) != EOF) {
    switch (c) {
      // Avoid the \" or \' characters to be treated as the begin of quote
      case '\\':
        result_code = SkipEscapeCharacter();
        break;
      case '{':
      case '[':
      case '(':
        result_code = PushStack(c);
        break;
      case '}':
      case ']':
      case ')':
        result_code = PopStackAndCheck(c);
        break;
      case '\'':
        result_code = SkipSingleQuote();
        break;
      case '\"':
        result_code = SkipDoubleQuote();
        break;
      case '/':
        result_code = SkipComment();
        break;
      case '\n':
        ++line_num;
        break;
      default:
        break;
    }
    if (result_code != kSuccess) {
      PrintMessage(result_code);
      return 0;
    }
  }
  result_code = CheckStackEmpty();
  PrintMessage(result_code);
  return 0;
}

int PushStack(int symbol) {
  if (info_stack.top - info_stack.base >= info_stack.size) {
    info_stack.base =  (struct SymbolInfo*) realloc (info_stack.base,
        (info_stack.size + STACK_INCREASE_SIZE) * sizeof(struct SymbolInfo));
    info_stack.top = info_stack.base + info_stack.size;
    info_stack.size += STACK_INCREASE_SIZE;
  } else {
    info_stack.top->symbol = symbol;
    info_stack.top->occur_line_num = line_num;
    ++info_stack.top;
  }
  return kSuccess;
}

int PopStackAndCheck(int symbol) {
  if (info_stack.top - info_stack.base > 1) {
    --info_stack.top;
    switch (info_stack.top->symbol) {
      case '{':
       if (symbol == '}') {
        break;
       } else {
         return kBracesError;
       }
       break;
      case '[':
       if (symbol == ']') {
        break;
       } else {
         return kBracketsError;
       }
       break;
      case '(':
       if (symbol == ')') {
        break;
       } else {
         return kParenthesesError;
       }
       break;
      default:
       break;
    }
  } else {
    return kStackEmptyError;
  }
  return kSuccess;
}
  
int SkipEscapeCharacter() {
  int number_count;
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
      break;
    case 'x':
      number_count = 0;
      c = getchar();
      while (((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || 
          (c >= 'A' && c <= 'F')) && number_count < 2) {
        ++number_count;
        c = getchar();
      }
      ungetc(c, stdin);
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
      number_count = 1;
      c = getchar();
      while (c >= '0' && c <= '7' && number_count < 3) {
        ++number_count;
        c = getchar();
      }
      ungetc(c, stdin);
      break;
    default:
      // If the program occur undefined character such as \c, doesn't handle
      break;
  }
  return kSuccess;
}

int SkipSingleQuote() {
  c = getchar();
  switch (c) {
    case '\\':
      SkipEscapeCharacter();
      c = getchar();
      if (c != '\'') {
        return kSingleQuoteError;
      }
      break;
    default:
      if ((c = getchar()) != '\'') {
        return kSingleQuoteError;
      }
      break;
  }
  return kSuccess;
}

int SkipDoubleQuote() {
  while((c = getchar()) != '\"') {
    // Avoid the \" characters to be treated as the end of double quote
    // And the program can use '\' to join two physical lines into one logical
    // line 
    if (c == '\\') {
      getchar();
    }
    if (c == '\n') {
      return kDoubleQuoteError;
      break;
    }
  }
  return kSuccess;
}

int SkipComment() {
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
      return kGoToCommentError;
      break;
  }

  switch (comment_state) {
    case kSingleLineComment:
      while ((c = getchar()) != '\n') {
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
  return kSuccess;
} 

int CheckStackEmpty() {
  if (info_stack.top - info_stack.base == 1) {
    return kSuccess;
  } else {
    return kMatchError;
  }
}

int PrintMessage(int result_code) {
  switch (result_code) {
    case kSuccess:
      printf("Congratulations. Your program has no error about unbalanced \
parentheses, brackets and braces.\n");
      break;
    case kBracesError:
       printf("Error. '{' occur in line %d and the next symbol occur in line \
%d are not match.\n", info_stack.top->occur_line_num, line_num); 
      break;
    case kBracketsError:
       printf("Error. '[' occur in line %d and the next symbol occur in line \
%d are not match.\n", info_stack.top->occur_line_num, line_num); 
      break;
    case kParenthesesError:
       printf("Error. '(' occur in line %d and the next symbol occur in line \
%d are not match.\n", info_stack.top->occur_line_num, line_num); 
      break;
    case kStackEmptyError:
      printf("Error. The symbol stack is empty.\n");
      break;
    case kSingleQuoteError:
      printf("Error. The single quote symbols \' are not match int line %d.\
\n", line_num);
      break;
    case kDoubleQuoteError:
      printf("Error. The double quote symbols \" are not match in line %d.\n",
          line_num);
      break;
    case kGoToCommentError:
      printf("Error. The character follow '/' is illegal in line %d.\n",
          line_num);
      break;
    case kMatchError:
      printf("Error. Your program has some errors about unbalanced parentheses,\
 brackets and braces. You can check line %d and its matching symbol.\n",
          (info_stack.top-1)->occur_line_num);
      break;
    default:
      break;
  }
  return 0;
}
