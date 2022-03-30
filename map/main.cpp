#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>

int main() {
std::cout <<"------------------------- FT : ----------------------------"<<std::endl;
    {
        ft::pair<int, float> p1(1, 5.8);
        ft::pair<int, float> p2(2, 10);
        ft::pair<int, float> p3(3, 20);

        ft::Avl<int, float> *tree = new ft::Avl<int, float>();

        tree->set_root(tree->insert(tree->get_root(), p1)); // create node
        tree->set_root(tree->insert(tree->get_root(), p2));
        tree->set_root(tree->insert(tree->get_root(), p3));

        // tree->setRoot(tree->deleteNode(tree->getRoot(), p1)); //delete node
        // tree->printTree(tree->getRoot(), "", true);
        
        ft::MapIterator<int, float> it(tree, tree);
        ft::MapIterator<int, float> it1(tree, tree);

        std::cout << "Iterator = " <<(*it).first << std::endl;
        bool i = it == it1;
        std::cout << i<<std::endl;

        // std::cout << tree->getData()->first << std::endl;
        // while(1);
    }

     std::cout << "------------------------- STD : ---------------------------"<<std::endl;
    {
        std::pair<int, float> p1(1, 5.8);
        std::pair<int, float> p2(2, 10);
        std::pair<int, float> p3(3, 20);

        std::map<int, float> map;
        map.insert(p1);
        map.insert(p2);
        map.insert(p3);

        // tree->setRoot(tree->deleteNode(tree->getRoot(), p1)); //delete node
        // tree->printTree(tree->getRoot(), "", true);
        
        std::map<int, float>::iterator it = map.begin();
        std::map<int, float>::iterator it1 = map.begin();

        std::cout << "Iterator = " <<(*it).first << std::endl;
        bool i = it == it1;
        std::cout << i<<std::endl;

        // std::cout << tree->getData()->first << std::endl;
        // while(1);
    }
}