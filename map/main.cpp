#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>
#include "map.hpp"

int main()
{
    std::cout <<"------------------------- FT : ----------------------------"<<std::endl;
    {
        ft::pair<int, float> p1(1, 5.8);
        ft::pair<int, float> p2(2, 10);
        ft::pair<int, float> p3(3, 20);
        ft::pair<int, float> p4(4, 30);
        ft::pair<int, float> p5(5, 40);

        ft::map<int, float> map;
        ft::pair<ft::map<int, float>::iterator, bool> i;
        i = map.insert(p1);
        std::cout << "i is: " << i.second << std::endl;
        i = map.insert(p1);
        std::cout << "i is: " << i.second << std::endl;
        map.insert(p2);
        map.insert(p3);
        map.insert(p4);
        map.insert(p5);
        map[6] = 100;

        ft::map<int, float>::iterator t1 = map.begin();
        ft::map<int, float>::iterator t2 = map.end();
        ft::map<int, float>::reverse_iterator r1 = map.rbegin();
        ft::map<int, float>::reverse_iterator r2 = map.rend();
        std::cout << "begin is : "<< (*t1).first<<std::endl;
        std::cout << "end is : "<< (*--t2).first<<std::endl;
        std::cout << "s is : "<< (*t2).second<<std::endl;
        std::cout << "rbegin is : "<< (*r1).first<<std::endl;
        std::cout << "rend is : "<< (*--r2).first<<std::endl;
        std::cout << map.empty()<<std::endl;
        std::cout << map.max_size()<<std::endl;
        std::cout << map.size()<<std::endl;
    }

    std::cout << "------------------------- STD : ---------------------------"<<std::endl;
    {
        std::pair<int, float> p1(1, 5.8);
        std::pair<int, float> p2(2, 10);
        std::pair<int, float> p3(3, 20);
        std::pair<int, float> p4(4, 30);
        std::pair<int, float> p5(5, 40);

        std::map<int, float> map;
        std::pair<std::map<int, float>::iterator, bool> i;
        i = map.insert(p1);
        std::cout << "i is: " << i.second << std::endl;
        i = map.insert(p1);
        std::cout << "i is: " << i.second << std::endl;
        map.insert(p2);
        map.insert(p3);
        map.insert(p4);
        map.insert(p5);
        map[6] = 100;

        std::map<int, float>::iterator t1 = map.begin();
        std::map<int, float>::iterator t2 = map.end();
        std::map<int, float>::reverse_iterator r1 = map.rbegin();
        std::map<int, float>::reverse_iterator r2 = map.rend();
        std::cout << "begin is : "<< (*t1).first<<std::endl;
        std::cout << "end is : "<< (*--t2).first<<std::endl;
        std::cout << "s is : "<< (*t2).second<<std::endl;
        std::cout << "rbegin is : "<< (*r1).first<<std::endl;
        std::cout << "rend is : "<< (*--r2).first<<std::endl;
        std::cout << map.empty()<<std::endl;
        std::cout << map.max_size()<<std::endl;
        std::cout << map.size()<<std::endl;
    }

    std::cout << "------------------------- END TESTs -----------------------"<<std::endl;
    return (0);                          
}