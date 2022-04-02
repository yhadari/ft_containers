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

        ft::Avl<int, float, std::less<int>, std::allocator<ft::pair<const int, float> > > tree;

        tree._root = tree.insertNode(tree._root, p1); // create node
        tree._root = tree.insertNode(tree._root, p2); // create node
        tree._root = tree.insertNode(tree._root, p3); // create node
        tree._root = tree.insertNode(tree._root, p4); // create node
        tree._root = tree.insertNode(tree._root, p5); // create node

        // tree->setRoot(tree->deleteNode(tree->getRoot(), p1)); //delete node
        // tree->printTree(tree->getRoot(), "", true);

        ft::MapIterator<int, float>  it(tree._root, tree._root);
        ft::MapIterator<int, float>  it2(tree._root, tree._root);
        it--;
        it2++;
        it2++;
        it2++;
        it2++;
        ft::map<int, float> map(it, it2);
        ft::map<int, float>::reverse_iterator r1 = map.rend();
        std::cout << "rbegin is : "<< (*--r1).first<<std::endl;
        //map.display();
        // while (1);
    }

    std::cout << "------------------------- STD : ---------------------------"<<std::endl;
    {
        std::pair<int, float> p1(1, 5.8);
        std::pair<int, float> p2(2, 10);
        std::pair<int, float> p3(3, 20);
        std::pair<int, float> p4(4, 30);
        std::pair<int, float> p5(5, 40);

        std::map<int, float> map;
        map.insert(p1);
        map.insert(p2);
        map.insert(p3);
        map.insert(p4);
        map.insert(p5);

        std::map<int, float>::reverse_iterator r1 = map.rend();
        std::cout << "rbegin is : "<< (*--r1).first<<std::endl;
    }

    std::cout << "------------------------- END TESTs -----------------------"<<std::endl;
    return (0);                          
}