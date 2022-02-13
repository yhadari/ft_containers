#include <iostream>     // std::cout
#include <iterator>
#include <vector>
#include "VectorIterator.hpp"

int main () {
    {
        int *p1 = new int[3];
        p1[0] = 10;
        p1[1] = 20;
        p1[2] = 30;

        int *p2 = new int[3];
        p2[0] = 11;
        p2[1] = 21;
        p2[2] = 31;
        VectorIterator<int> i1(p1);
        VectorIterator<int> i2(p2);
        ptrdiff_t d;
        d = i2 - i1;
        std::cout << d << std::endl;
    }

    {
        std::vector<int> p1(3, 10);
        std::vector<int> p2(3, 20);
        std::vector<int>::iterator it1 = p1.begin();
        std::vector<int>::iterator it2 = p2.begin();
        ptrdiff_t d;
        d = it2 - it1;
        std::cout << d << std::endl;
    }
}
