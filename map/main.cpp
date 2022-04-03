#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>
#include "map.hpp"

int main ()
{  
  {
    ft::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);
    bar.clear();

    std::cout << "foo contains:\n";
    for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';

  }

  {
    std::cout << "-----------------std---------------\n";
    std::map<char,int> foo,bar;

    foo['x']=100;
    foo['y']=200;

    bar['a']=11;
    bar['b']=22;
    bar['c']=33;

    foo.swap(bar);
    bar.clear();

    std::cout << "foo contains:\n";
    for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';

    std::cout << "bar contains:\n";
    for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';

  }
  return 0;
}