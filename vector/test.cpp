#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
    int i = 3;
    {
        ft::vector<int>v1(6, 10);
        ft::vector<int>v2(8, 5);
        ft::vector<int>::iterator it_b = v2.begin();
        ft::vector<int>::iterator it_e = v2.end();
        std::cout << v1[0] << std::endl;
        std::cout << v1[1] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
        ft::vector<int>::iterator it = v1.begin();
        v1.insert(it+i, it_b, it_e);
        std::cout << v1[0] << std::endl;
        std::cout << v1[1] << std::endl;
        std::cout << v1[2] << std::endl;
        std::cout << v1[3] << std::endl;
        std::cout << v1[4] << std::endl;
        std::cout << v1[5] << std::endl;
        std::cout << v1[6] << std::endl;
        std::cout << v1[7] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
    }
    std::cout << "=================================================="<<std::endl;
    {
        std::vector<int>v1(6, 10);
        std::vector<int>v2(8, 5);
        std::vector<int>::iterator it_b = v2.begin();
        std::vector<int>::iterator it_e = v2.end();
        std::cout << v1[0] << std::endl;
        std::cout << v1[1] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
        std::vector<int>::iterator it = v1.begin();
        v1.insert(it+i, it_b, it_e);
        std::cout << v1[0] << std::endl;
        std::cout << v1[1] << std::endl;
        std::cout << v1[2] << std::endl;
        std::cout << v1[3] << std::endl;
        std::cout << v1[4] << std::endl;
        std::cout << v1[5] << std::endl;
        std::cout << v1[6] << std::endl;
        std::cout << v1[7] << std::endl;
        std::cout << v1.size() << std::endl;
        std::cout << v1.capacity() << std::endl;
    }
    // while (1);
  return 0;
}