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
    rootPtr->insert(13);
    rootPtr->insert(4);
    rootPtr->insert(3);
    rootPtr->erase(10);
    std::cout << "number nodes : " << rootPtr->get_nbNode() << std::endl;
    BstNode<int>::printNode(rootPtr);
    //while (1);
    return 0;
}