#include "stack.hpp"
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>   

int main ()
{
  ft::stack<int> foo;   // three ints with a value of 100
  ft::stack<int> bar;   // two ints with a value of 200

  foo.push(1);
  foo.push(2);
  foo.push(3);
  foo.push(4);
  foo.push(5);
  bar.push(6);
  bar.push(7);
  if (foo==bar) std::cout << "foo and bar are equal\n";

  return 0;
}