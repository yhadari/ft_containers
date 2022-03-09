#include "Bst.hpp"

int main(){
    BstNode<int> *rootPtr = new(BstNode<int>);
    rootPtr->insert(8);
    rootPtr->insert(3);
    rootPtr->insert(10);
    rootPtr->insert(6);
    rootPtr->insert(1);
    rootPtr->insert(14);
    rootPtr->insert(7);
    rootPtr->insert(17);
    rootPtr->insert(0);
    std::cout << "number nodes : " << rootPtr->get_nbNode() << std::endl;
    BstNode<int>::printNode(rootPtr);
    int i = 8;
    std::cout << i << " is " << rootPtr->find(i) << std::endl;
    //while (1);
    return 0;
}