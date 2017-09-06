// main.cpp
// Rohan Weeden
// Created: August 29, 2017

// Implementation of quicksort algorithm with Lomuto partition scheme
#include <vector>
#include <algorithm>

template <typename T>
int partition(std::vector<T> &A, int lo, int hi) {
  int pivot = A[hi];
  int i = lo - 1;
  for (int j = lo; j < hi; ++j) {
    if (A[j] < pivot) {
      i = i + 1;
      std::swap(A[i], A[j]);
    }
  }
  if (A[hi] < A[i + 1]) {
    std::swap(A[i + 1], A[hi]);
  }
  return i + 1;
}

template <typename T>
void quicksort(std::vector<T> &A, int lo, int hi) {
  if (lo < hi) {
    int p = partition(A, lo, hi);
    quicksort(A, lo, p - 1);
    quicksort(A, p + 1, hi);
  }
}
