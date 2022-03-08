#ifndef BST_HPP
#define BST_HPP

#include <iostream>
template<class T>
class BstNode{

    T           _data;
    BstNode*    _left;
    BstNode*    _right;
    int         _nbNode;

    public:
    BstNode() : _left(NULL), _right(NULL), _nbNode(0){};
    T           get_data(){return this->_data;};
    BstNode*    get_left(){return this->_left;};
    BstNode*    get_right(){return this->_right;};
    int         get_nbNode(){return this->_nbNode;};
    BstNode*    checkNode(BstNode* root, BstNode *NewNode){
        if (root->_data < NewNode->_data)
        {
            if (!root->_right)
            {
                this->_nbNode++;
                root->_right = NewNode;
                return NULL;
            }
            return root->_right;
        }
        else if(root->_data > NewNode->_data)
        {
            if (!root->_left)
            {
                this->_nbNode++;
                root->_left = NewNode;
                return NULL;
            }
            return root->_left;
        }
        return NULL;
    }
    void        insert(T data){
        if (!this->_nbNode)
        {
            this->_data = data;
            this->_nbNode++;
        }
        else
        {
            BstNode *NewNode = new(BstNode<T>);
            BstNode *FinalNode = new(BstNode<T>);
            NewNode->_data = data;
            FinalNode = this;
            while ((FinalNode = checkNode(FinalNode, NewNode)));
        }
    }
    static  void    printNode(BstNode *root){
        if (root)
        {
            printNode(root->_left);
            std::cout << root->_data << std::endl;
            printNode(root->_right);
        }
    }
    ~BstNode(){};
};

#endif