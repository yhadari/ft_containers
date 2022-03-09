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

    bool        insert(T data)
    {
        if (!this->_nbNode && ++this->_nbNode)
        {
            this->_data = data;
            return true;
        }
        if (this->_data == data)
            return false;
        if (this->_data > data)
        {
            this->_nbNode++;
            if (!this->_left)
                this->_left = new(BstNode<T>);
            return this->_left->insert(data);
        }
        else
        {
            this->_nbNode++;
            if (!this->_right)
                this->_right = new(BstNode<T>);
            return this->_right->insert(data);
        }
    }

    void            erase(T data){
        BstNode *eraseNode = find(data);
        if (eraseNode){
            if (!eraseNode->_left && !eraseNode->_right)
            {
                eraseNode = NULL;
                this->_nbNode--;
            }
        }
    }

    BstNode*        find(T data){
        if (!this->_nbNode)
            return NULL;
        if (this->_data == data)
            return this;
        if (this->_data > data)
        {
            if (this->_left)
                return this->_left->find(data);
            return NULL;
        }
        else
        {
            if (this->_right)
                return this->_right->find(data);
            return NULL;
        }
    }

    int         height()
    {
        if (!this->_nbNode)
            return 0;
        else {
            int lDepth = 0;
            int rDepth = 0;
            if (this->_left)
                lDepth = this->_left->height();
            if (this->_right)
                rDepth = this->_right->height();
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }

    void        printGivenLevel(int level)
    {
        if (!this->_nbNode)
            return;
        if (level == 1)
            std::cout <<"  "<< this->_data;
        else{
            if (this->_left)
                this->_left->printGivenLevel(level - 1);
            if (this->_right)
                this->_right->printGivenLevel(level - 1);
        }
    }

    void        printLevelOrder()
    {
        int h = this->height();
        for (int i = 1; i <= h; i++) {
            this->printGivenLevel(i);
            std::cout <<"\n";
        }
    }

    static void inorder(BstNode *root){
        if (root)
        {
            inorder(root->_left);
            std::cout << root->_data << " ";
            inorder(root->_right);
        }
    }

    static void preorder(BstNode *root){
        if (root)
        {
            std::cout << root->_data << " ";
            preorder(root->_left);
            preorder(root->_right);
        }
    }

    static void postorder(BstNode *root){
        if (root)
        {
            postorder(root->_left);
            postorder(root->_right);
            std::cout << root->_data << " ";
        }
    }
    ~BstNode(){};
};

#endif