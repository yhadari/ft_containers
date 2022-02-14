// reverse_iterator::base example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "VectorIterator.hpp"

int main () {
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef std::vector<int>::iterator iter_type;
  typedef std::vector<int>::reverse_iterator re_type;

  std::reverse_iterator<iter_type> rev_begin (myvector.begin());
  std::reverse_iterator<iter_type> rev_end (myvector.end());

  std::vector<int>::iterator begin (myvector.begin());
  std::vector<int>::iterator end (myvector.end());

std::cout << "myvector:";
for (re_type it = rev_end; it != rev_begin; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}