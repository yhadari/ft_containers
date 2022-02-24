#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    int index = 6;
    {
        ft::vector<int> v1(11, 10);
        ft::vector<int> v2(v1);
        // v2 = v1;
        ft::vector<int>::iterator it2 = v2.begin();
        std::cout << *(it2+1) << std::endl;

        ft::vector<int>::iterator it1 = v1.begin();
        v1.resize(23, -5);
        // v1.reserve(12);
        std::cout << "size: "<< v1.size() << " | Capacity: " << v1.capacity()
            << " | element [" << index << "]= " << v1[index] <<std::endl;
        std::cout << *(it2+1) << std::endl;
    }
    std::cout << "=================================================="<<std::endl;
    {
        std::vector<int> v1(11, 10);
        std::vector<int> v2(v1);
        // v2 = v1;
        std::vector<int>::iterator it2 = v2.begin();
        std::cout << *(it2+1) << std::endl;

        std::vector<int>::iterator it1 = v1.begin();
        v1.resize(23, -5);
        // v1.reserve(12);
        std::cout << "size: "<< v1.size() << " | Capacity: " << v1.capacity()
            << " | element [" << index << "]= " << v1[index] <<std::endl;
        std::cout << *(it2+1) << std::endl;
    }
    while (1);
  return 0;
}