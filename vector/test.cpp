// reverse_iterator::base example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "VectorIterator.hpp"

int main () {

  std::vector<int> v(10,10);
  int *p = new int[4];
  p[0] = 10;
  p[0] = 11;
  p[0] = 12;
  p[0] = 13;
  VectorIterator<int>::Iterator i = p;
  return 0;
}