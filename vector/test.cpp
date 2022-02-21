#include "Vector.hpp"
#include "vector"

int main(){

    std::vector<int> p1(10, 10);
    std::vector<int>::iterator itb = p1.begin();
    std::vector<int>::iterator ite = p1.end();
    ft::vector<int>p2(10, 10);
    ft::vector<int>p3(itb, ite);
}