#include "Vector.hpp"

int main(){
    ft::vector<std::string>    ft_v1(10, "string1");
    ft::vector<std::string>    ft_v2(20, "string2");
    ft_v1 = ft_v2;
    
    return 0;
}