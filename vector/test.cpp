#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    {
        ft::vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
          myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    std::cout << "=================================================="<<std::endl;
    {
        std::vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
          myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
//   while (1);
  return 0;
}