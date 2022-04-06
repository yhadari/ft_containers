#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>
#include <vector>
#include "map.hpp"
#include "../vector/Vector.hpp"


#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20 // the ft::map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

int main(){
    /*------------ std::reverse_iterator ---------*/
    std::map<int, char> m;
    for (int i = 0; i < 1e2; i++)
        m.insert(std::make_pair(i, 'A'));

    //std::reverse_iterator<std::map<int, char>::iterator> rit(m.end()), rit_1(--m.end());

    ft::reverse_iterator<std::map<int, char>::iterator> my_rit(m.end()), my_rit1(--m.end());
    /*----------------------------------*/
    // std::cout << "\t\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor "
    //           << "] --------------------]\t\t\033[0m";
    // {
    //     ft::reverse_iterator<std::map<int, char>::iterator> ob(my_rit);
         std::cout << (*my_rit1).first << std::endl;
    //     bool i = *my_rit == *ob;
    // }
    return 0;
}