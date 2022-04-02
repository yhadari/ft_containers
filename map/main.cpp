#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>
#include "map.hpp"

int main ()
{
  {
    ft::map<char,int> mymap;

    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    ft::map<char,int>::iterator it = mymap.begin();
    ft::map<char,int>::iterator it2;
    it2 = mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
    std::cout << "it: " << (*it2).first << std::endl;

    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';

  }
  {
      std::map<char,int> mymap;

    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );

    std::map<char,int>::iterator it = mymap.begin();
    std::map<char,int>::iterator it2;
    it2 = mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting
    std::cout << "it: " << (*it2).first << std::endl;

    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  }
    return 0;
}