// Copyright 2013 Juntao Guo (guojuntao1@gmail.com).
//
// K&R Exercise 3-1. Our binary search makes two tests inside the loop, when one
// would suffice (at the price of more tests outside). Write a version with only
// one test inside the loop and measure the difference in run-time.

// Old version in the book
//
// int binsearch(int x, int v[], int n) {
//   int low, high, mid;
//
//   low = 0;
//   high = n - 1;
//   while (low <= high) {
//     mid = (low + high) / 2;
//     if (x < v[mid]) {
//       high = mid - 1;
//     } else if (x > v[mid]) {
//       low = mid + 1;
//     } else {
//       return mid;
//     }
//   }
//   return -1;
// }

// My version
// This function search the element 'x' in the array 'v', the array's length is
// 'n'. Return the location of element 'x'.
int binsearch(int x, int v[], int n) {
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;

  while (low <= high && x != v[mid]) {
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }

  if (x == v[mid]) {
    return mid;
  } else {
    return -1;
  }
}
