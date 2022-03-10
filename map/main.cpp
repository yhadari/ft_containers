#include "Bst.hpp"

int main(){
    BstNode<int> *rootPtr = new(BstNode<int>);
    rootPtr->insert(50);
    rootPtr->insert(30);
    rootPtr->insert(20);
    rootPtr->insert(40);
    rootPtr->insert(70);
    rootPtr->insert(60);
    rootPtr->erase(20);
    std::cout << "Number Nodes : " << rootPtr->get_nbNode() << std::endl;
    std::cout << "-------------inorder-------------" << std::endl;
    BstNode<int>::inorder(rootPtr);
    std::cout << std::endl << "-------------preorder-------------" << std::endl;
    BstNode<int>::preorder(rootPtr);
    std::cout << std::endl << "-------------postorder-------------" << std::endl;
    BstNode<int>::postorder(rootPtr);
    std::cout << std::endl;
    std::cout << "Height of tree --> " << rootPtr->height() << std::endl;
    rootPtr->printLevelOrder();
    std::cout << std::endl;
    //int i = 50;
    //std::cout << std::endl << i << " --> " << rootPtr->find(i) << std::endl;
    while (1);
    return 0;
}