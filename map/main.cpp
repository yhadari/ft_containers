#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>
#include "map.hpp"

int main ()
{  
    {
      ft::map<char,int> mymap;
      char c;

      mymap ['a']=101;
      mymap ['c']=202;
      mymap ['f']=303;

      for (c='a'; c<'h'; c++)
      {
        std::cout << c;
        if (mymap.count(c)>0)
          std::cout << " is an element of mymap.\n";
        else 
          std::cout << " is not an element of mymap.\n";
      }
    }

    {
      std::cout << "-------------------std-----------------\n";
      std::map<char,int> mymap;
      char c;

      mymap ['a']=101;
      mymap ['c']=202;
      mymap ['f']=303;

      for (c='a'; c<'h'; c++)
      {
        std::cout << c;
        if (mymap.count(c)>0)
          std::cout << " is an element of mymap.\n";
        else 
          std::cout << " is not an element of mymap.\n";
      }
    }

  return 0;
}