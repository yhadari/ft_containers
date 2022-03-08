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

    BstNode*    checkNode(BstNode* &root, BstNode *NewNode){
        if (root->_data < NewNode->_data)
        {
            if (!root->_right && this->_nbNode++)
            {
                root->_right = NewNode;
                return NULL;
            }
            return root->_right;
        }
        else if(root->_data > NewNode->_data)
        {
            if (!root->_left && this->_nbNode++)
            {
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
            BstNode *FinalNode = this;
            NewNode->_data = data;
            while ((FinalNode = checkNode(FinalNode, NewNode)));
        }
    }

    void        findNode(BstNode* &root, BstNode* &rightNode, BstNode* &leftNode, T data){
        if(root)
        {
            findNode(root->_left, rightNode, leftNode, data);
            if (root->_data == data)
            {
                leftNode = root->_left;
                root = root->_right;
            }
            findNode(root->_right, rightNode, leftNode, data);
        }
    }

    void        erase(T data){
        BstNode *leftNode = NULL;
        BstNode *rightNode = NULL;
        BstNode *root = this;
        findNode(root, rightNode, leftNode, data);
        if (leftNode)
        {
            while (rightNode->_left)
                rightNode = rightNode->_left;
            rightNode->_left = leftNode;
        }
        this->_nbNode--;
    }

    static void printNode(BstNode *root){
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