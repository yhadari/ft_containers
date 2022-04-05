#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>
#include "map.hpp"
#include "../vector/Vector.hpp"

int main ()
{
  ft::map<int, int> m;
  m['a']=100;
  m['b']=200;
  ft::map<int, int>::const_iterator it1 = m.begin();
  std::cout << (*it1).first << std::endl;
  return 0;
}