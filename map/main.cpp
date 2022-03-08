#include "Bst.hpp"

int main(){
    BstNode<int> *rootPtr = new(BstNode<int>);
    rootPtr->insert(50);
    rootPtr->insert(30);
    rootPtr->insert(20);
    rootPtr->insert(40);
    rootPtr->insert(70);
    rootPtr->insert(60);
    rootPtr->insert(80);
    BstNode<int>::printNode(rootPtr);
    //while (1);
    return 0;
}