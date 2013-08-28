// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 2-1. Write a program to determine the ranges of char, short,
// int, and long variables, both signed and unsigned, by printing appropriate
// values from standard headers and by direct computation. Harder if you compute
// them: determine the ranges of the various floating-point types.

#include <stdio.h>
#include <limits.h>
#include <float.h>

void FromStandardHeader() {
  printf("The range of signed char is \t\t%d to %d.\n", SCHAR_MIN, SCHAR_MAX);
  printf("The ragne of unsigned char is \t\t0 to %u.\n", UCHAR_MAX);

  printf("The range of signed short int is \t%d to %d.\n", SHRT_MIN, SHRT_MAX);
  printf("The range of unsigned short int is \t0 to %u.\n", USHRT_MAX);

  printf("The range of signed int is \t\t%d to %d.\n", INT_MIN, INT_MAX);
  printf("The range of unsigned int is \t\t0 to %u.\n", UINT_MAX); 

  printf("The range of signed long int is \t%d to %d.\n", LONG_MIN, LONG_MAX);
  printf("The range of unsigned long int is \t0 to %u.\n", ULONG_MAX);
}

void ByDirectComputation() {
  signed char schar_min = ~(signed char)0 << sizeof(signed char) * 8 - 1; 
  signed char schar_max = (unsigned char)~0 >> 1; 
  unsigned char uchar_max = ~(unsigned char)0;
  signed short shrt_min = ~(signed short)0 << sizeof(signed short) * 8 - 1;
  signed short shrt_max = (unsigned short)~0 >> 1;
  unsigned short ushrt_max = ~(unsigned short)0;
  signed int int_min = ~(signed int)0 << sizeof(signed int) * 8 - 1;
  signed int int_max = (unsigned int)~0 >> 1;
  unsigned int uint_max = ~(unsigned int)0;
  signed long long_min = ~(signed long)0 << sizeof(signed long) * 8 - 1;
  signed long long_max = (unsigned long)~0 >> 1;
  unsigned long ulong_max = ~(unsigned long)0;

  printf("The range of signed char is \t\t%d to %d.\n", schar_min, schar_max);
  printf("The ragne of unsigned char is \t\t0 to %u.\n", uchar_max);

  printf("The range of signed short int is \t%d to %d.\n", shrt_min, shrt_max);
  printf("The range of unsigned short int is \t0 to %u.\n", ushrt_max);

  printf("The range of signed int is \t\t%d to %d.\n", int_min, int_max);
  printf("The range of unsigned int is \t\t0 to %u.\n", uint_max); 

  printf("The range of signed long int is \t%d to %d.\n", long_min, long_max);
  printf("The range of unsigned long int is \t0 to %u.\n", ulong_max);
}

int main() {
  FromStandardHeader();
  printf("\n");
  ByDirectComputation();
  return 0;
}
