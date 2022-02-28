#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    {
        ft::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    std::cout << "-------------------------std--------------------------"<<std::endl;
    {
        std::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);
      
        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
      
        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);
      
        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    while (1);
  return 0;
}