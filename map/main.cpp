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

        ft::Avl<int, float, std::less<int>, std::allocator<ft::pair<const int, float> > > *tree = 
        new ft::Avl<int, float, std::less<int>, std::allocator<ft::pair<const int, float> > >();

        tree->_root = tree->insert(tree->_root, p1); // create node
        tree->_root = tree->insert(tree->_root, p2); // create node
        tree->_root = tree->insert(tree->_root, p3); // create node
        tree->_root = tree->insert(tree->_root, p4); // create node
        tree->_root = tree->insert(tree->_root, p5); // create node

        // tree->setRoot(tree->deleteNode(tree->getRoot(), p1)); //delete node
        // tree->printTree(tree->getRoot(), "", true);

        ft::MapIterator<int, float>  it(tree);
        ft::MapIterator<int, float>  it2(tree);
        std::cout << "it " << (*it2).first << std::endl;
        it2++;
        std::cout << "it " << (*it2).first << std::endl;
        it2++;
        std::cout << "it " << (*it2).first << std::endl;
        it2++;
        std::cout << "it " << (*it2).first << std::endl;
        it2++;
        //std::cout << "it " << (*it2).first << std::endl;
        ft::map<int, float> map1(it, it2);

        std::cout << "size = " <<map1.size() << std::endl;
        std::cout << "------------------------- Tree : ---------------------------"<<std::endl;
        tree->printTree(tree->_root, "", true);
        std::cout << "------------------------- Map : ---------------------------"<<std::endl;
        map1.display();

    }

    // std::cout << "------------------------- STD : ---------------------------"<<std::endl;
    // {
    //     std::pair<int, float> p1(1, 5.8);
    //     std::pair<int, float> p2(2, 10);
    //     std::pair<int, float> p3(3, 20);

    //     std::map<int, float> map;
    //     map.insert(p1);
    //     map.insert(p2);
    //     map.insert(p3);

    //     std::map<int, float>::iterator it = map.begin();
    //     std::cout << "Iterator = " <<(*it).first << std::endl;
    // }

    // std::cout << "------------------------- END TESTs -----------------------"<<std::endl;
    return (0);                          
}