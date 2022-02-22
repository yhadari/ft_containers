#include "Vector.hpp"
#include "vector"

int main(){

    ft::vector<int>p1(10, 10);
    ft::vector<int>::reverse_iterator it = p1.rend();
    std::cout << *(it+1) << std::endl;
}