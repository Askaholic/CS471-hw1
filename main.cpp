// main.cpp
// Rohan Weeden
// Created: August 29, 2017

// Test cases for quicksort algorithm
#include <vector>
#include <iostream>
#include "quicksort.hpp"

template <typename T>
void printVector(std::vector<T> &);

template <typename T>
bool isSorted(std::vector<T> &);

int main(int argc, char const *argv[]) {
  std::vector<std::vector<int>> tests {
    {10, 50, 100, -30, -70, 1000, -1234},
    {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 5, 6, 7},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, 0},
    {0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {17673, 36802, -2086, 66159, -73747, 80703, -19613},
    {10, 5, -10, -20}
  };
  for (int c = 0; c < tests.size(); c++) {
    std::vector<int> &v = tests[c];
    printVector(v);
    quicksort(v, 0, v.size() - 1);
    printVector(v);
    std::cout << ((isSorted(v)) ? ("OK") : ("FAILED")) << std::endl;
    std::cout << "----------------------\n\n";
  }
  return 0;
}

template <typename T>
void printVector(std::vector<T> &v) {
  std::cout << "[";
  for(int c = 0; c < v.size(); c++) {
    if (c != 0) {
      std::cout << ",";
    }
    std::cout << v[c];
  }
  std::cout << "]" << std::endl;
}

template <typename T>
bool isSorted(std::vector<T> &v) {
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] > v[i + 1]) {
      return false;
    }
  }
  return true;
}
