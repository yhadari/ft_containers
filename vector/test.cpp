#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    {
        ft::vector<int>v1(6, 10);
        std::cout << v1[0] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
        ft::vector<int>::iterator it = v1.begin();
        std::cout << *v1.insert(it+3, 11) << std::endl;
        std::cout << v1[0] << std::endl;
        std::cout << v1[2] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
    }
    std::cout << "=================================================="<<std::endl;
    {
        std::vector<int>v1(6, 10);
        std::cout << v1[0] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
        std::vector<int>::iterator it = v1.begin();
        std::cout << *v1.insert(it+3, 11) << std::endl;
        std::cout << v1[0] << std::endl;
        std::cout << v1[2] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
    }
    // while (1);
  return 0;
}