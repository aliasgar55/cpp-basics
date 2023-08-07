#include "timer.h"
#include <iostream>

int main() {
  {
    Timer timer;
    // using a 2d array
    int **a2d = new int *[50000];

    for (int i = 0; i < 50000; i++) {
      a2d[i] = new int[5];
    }
    // assigning value to the array
    for (int i = 0; i < 50000; i++) {
      for (int j = 0; j < 5; j++) {
        a2d[i][j] = 2;
      }
    }
    // accesing the value from the array and prinint it
    for (int i = 0; i < 50000; i++) {
      for (int j = 0; j < 5; j++) {
        int a = a2d[i][j];
      }
      // std::cout << std::endl;
    }
  }
  {
    Timer timer;
    int *a2d_fast = new int[50000 * 5];
    // assigning value to the array
    for (int i = 0; i < 50000; i++) {
      for (int j = 0; j < 5; j++) {
        a2d_fast[i * 5 + j] = 2;
      }
    }
    for (int i = 0; i < 50000; i++) {
      for (int j = 0; j < 5; j++) {
        int a = a2d_fast[i * 5 + j];
      }
      // std::cout << std::endl;
    }
  }
}
