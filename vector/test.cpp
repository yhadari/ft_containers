#include "Vector.hpp"
#include <iostream>
#include <vector>

int main()
{
    int index = 0;
    std::cout << "\n<----------< My ft::Vector >----------->\n" << std::endl;
    {
        ft::vector<int> v1(11, 10);
        ft::vector<int> v2(v1);
        // v2 = v1;
        ft::vector<int>::iterator it2 = v2.begin();
        std::cout << *(it2+1) << std::endl;

        ft::vector<int>::iterator it1 = v1.begin();
        v1.resize(230, -5);
        // v1.reserve(12);
        std::cout << "size: "<< v1.size() << " | Capacity: " << v1.capacity()
            << " | element [" << index << "]= " << v1[index] <<std::endl;
        std::cout << *(it2+1) << std::endl;
    }

    std::cout << "\n<--------< Original STD Tests >------->\n" << std::endl;
    {
        std::vector<int> v1(11, 10);
        std::vector<int> v2(v1);
        // v2 = v1;
        std::vector<int>::iterator it2 = v2.begin();
        std::cout << *(it2+1) << std::endl;

        std::vector<int>::iterator it1 = v1.begin();
        v1.resize(230, -5);
        // v1.reserve(12);
        std::cout << "size: "<< v1.size() << " | Capacity: " << v1.capacity() 
            << " | element [" << index << "]= " << v1[index] <<std::endl;
        std::cout << *(it2+1) << std::endl;

    }
    std::cout << "\n<------------< End Tests >------------>" << std::endl;
    // system("leaks Containers");
    while(1);
    return (0);
}