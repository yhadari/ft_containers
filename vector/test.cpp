#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    {
        ft::vector<int> myvector;
        ft::vector<int> myvector1;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        std::cout << "1 " << *myvector1.erase (myvector.begin(),myvector.begin()+2) << std::endl;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); ++i)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    std::cout << "=================================================="<<std::endl;
    {
        std::vector<int> myvector;
        std::vector<int> myvector1;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        std::cout << "1 " << *myvector1.erase (myvector.begin(),myvector.begin()+2) << std::endl;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); ++i)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    // while (1);
  return 0;
}