#include "Vector.hpp"
#include <vector>

int main(){
    ft::vector<int>    my_v(3,4);
	ft::vector<int>::const_iterator my_it;
    my_it = my_v.begin();
    my_it += 1;
    return 0;
}