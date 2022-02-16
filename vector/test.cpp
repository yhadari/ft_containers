// reverse_iterator::base example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include "VectorIterator.hpp"

int main () {

  std::vector<int> v;
  v.push_back(10);
  v.push_back(11);
  v.push_back(12);
  v.push_back(13);
  v.push_back(14);
  std::vector<int>::iterator it_b = v.begin();
  std::vector<int>::iterator it_e = v.end();
  std::vector<int>::reverse_iterator r_it_b = v.rbegin();
  std::vector<int>::reverse_iterator r_it_e = v.rend();

  std::cout << r_it_e[-1] << std::endl;
  return 0;
}