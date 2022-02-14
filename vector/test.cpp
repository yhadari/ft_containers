#include <iostream>     // std::cout
#include <iterator>
#include <vector>
#include "VectorIterator.hpp"

int main () {
    {
        int *p1 = new int[4];
        p1[0] = 10;
        p1[1] = 20;
        p1[2] = 30;

        int *p2 = new int[4];
        p2[0] = 11;
        p2[1] = 21;
        p2[2] = 31;
        VectorIterator<int> i1 = p1;
        VectorIterator<int> i2 = p2;
        std::cout << i1[0] << std::endl;
    }

    {
        std::vector<int> p1(4, 10);
        std::vector<int> p2(4, 20);
        std::vector<int>::iterator it1 = p1.begin();
        std::vector<int>::iterator it2 = p2.begin();
        bool i = it1 >= it2;
        std::cout << i << std::endl;
    }
}
