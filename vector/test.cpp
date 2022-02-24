#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    {
        ft::vector<int> myvector(10, 10);
        std::cout << myvector[0] << std::endl;
        std::cout << myvector.size() << std::endl;
        std::cout << myvector.capacity() << std::endl;
        myvector.assign(6, 6);
        std::cout << myvector[0] << std::endl;
        std::cout << myvector.size() << std::endl;
        std::cout << myvector.capacity() << std::endl;
    }
    std::cout << "=================================================="<<std::endl;
    {
        std::vector<int> myvector(10, 10);
        std::cout << myvector[0] << std::endl;
        std::cout << myvector.size() << std::endl;
        std::cout << myvector.capacity() << std::endl;
        myvector.assign(6, 6);
        std::cout << myvector[0] << std::endl;
        std::cout << myvector.size() << std::endl;
        std::cout << myvector.capacity() << std::endl;
    }
//   while (1);
  return 0;
}