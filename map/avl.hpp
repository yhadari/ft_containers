#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "pair.hpp"

template < class Key, class T, class Compare, class Alloc >
class Node{

  public:
  typedef ft::pair<Key, T>                                value_type;
  typedef Alloc                                           allocator_type;
  typedef std::allocator<Node<Key, T, Compare, Alloc > >  other_allocator;

  private:
    value_type      *data;
    allocator_type  myalocator;
    other_allocator nodeAllocator;
    Node            *left;
    Node            *right;
    int             height;

  public:
  
  Node(const value_type& val){
    Node *node = this->nodeAllocator.allocate(1);
    node->data = this->myalocator.allocate(1);
    this->myalocator.construct(node->data, val);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
  }

  int Height() {
    if (!this->data)
      return 0;
    return this->height;
  }

  int max(T a, T b) {
    return (a > b) ? a : b;
  }

  Node  *rightRotate() {
    Node *x = this->left;
    Node *T2 = x->right;
    x->right = this;
    this->left = T2;
    this->height = max(height(this->left), height(this->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
  }

  Node  *leftRotate() {
    Node *y = this->right;
    Node *T2 = y->left;
    y->left = this;
    this->right = T2;
    this->height = max(height(this->left), height(this->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
  }

  void  inorder()
  {
    if (this->data)
    {
      inorder(this->left);
      std::cout << this->key << " ";
      inorder(this->right);
    }
  }

  void  preorder()
  {
    if (this->data)
    {
      std::cout << this->key << " ";
      preorder(this->left);
      preorder(this->right);
    }
  }

  void  postorder()
  {
    if (this->data)
    {
      postorder(this->left);
      postorder(this->right);
      std::cout << this->key << " ";
    }
  }

  int getBalanceFactor(){
    if (!this->data)
      return 0;
    return height(this->left) - height(this->right);
  }

  Node  *insert(value_type &val) {
    // Find the correct postion and insert the node
    if (!this->data)
      return (Node(val));
    if (val->first < this->data->first)
      this->left = this->left->insert(val);
    else if (val->first > this->data->first)
      this->right = this->right->insert(val);
    else
      return this;

    // Update the balance factor of each node and
    // balance the tree
    this->height = 1 + max(height(this->left), height(this->right));
    int balanceFactor = this->getBalanceFactor;
    if (balanceFactor > 1) {
      if (val->first < this->left->data->first) {
        return this->rightRotate();
      } else if (val->first > this->left->data->first) {
        this->left = this->left->leftRotate();
        return this->rightRotate();
      }
    }
    if (balanceFactor < -1) {
      if (val->first > this->right->data->first) {
        return this->leftRotate();
      } else if (val->first < this->right->data->first) {
        this->right = this->right->rightRotate();
        return this->leftRotate();
      }
    }
    return this;
  }

};

 
/*

  t_node* findMin(t_node* root)
  {
      while (root->left)
        root = root->left;
      return root;
  }

  t_node* findMax(t_node* root)
  {
      while (root->right)
          root = root->right;
      return root;
  }

  t_node *deletet_node(t_node *root, int key) {
    // Find the node and delete it
    if (root == NULL)
      return root;
    if (key < root->key)
      root->left = deletet_node(root->left, key);
    else if (key > root->key)
      root->right = deletet_node(root->right, key);
    else {
      if ((root->left == NULL) || (root->right == NULL)) {
        t_node *temp = root->left ? root->left : root->right;
        if (temp == NULL) {
          temp = root;
          root = NULL;
        } else
          *root = *temp;
        free(temp);
      } else {
        t_node *temp = findMin(root->right);
        root->key = temp->key;
        root->right = deletet_node(root->right, temp->key);
      }
    }

    if (root == NULL)
      return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left), height(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1) {
      if (getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
      } else {
        root->left = leftRotate(root->left);
        return rightRotate(root);
      }
    }
    if (balanceFactor < -1) {
      if (getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
      } else {
        root->right = rightRotate(root->right);
        return leftRotate(root);
      }
    }
    return root;
  }

  void printTree(t_node *root, std::string indent, bool last) {
    if (root != nullptr) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L----";
        indent += "|  ";
      }
      std::cout << root->key << std::endl;
      printTree(root->left, indent, false);
      printTree(root->right, indent, true);
    }
  }

  t_node* nextNode(t_node* root, t_node* x)
  {
      t_node* succ = NULL;
      if (!root)
          return NULL;
      while (1){
          if (x->key < root->key){
              succ = root;
              root = root->left;
          }
          else if (x->key > root->key)
              root = root->right;
          else {
              if (root->right)
                  succ = findMin(root->right);
              break;
          }
          if (!root)
            return succ;
      }
      return succ;
  }

  t_node* previousNode(t_node* root, t_node* x)
  {
      t_node* prec = NULL;
      if (!root)
          return NULL;
      while (1){
          if (x->key < root->key)
              root = root->left;
          else if (x->key > root->key){
              prec = root;
              root = root->right;
          }
          else {
              if (root->left)
                  prec = findMax(root->left);
              break;
          }
          if (!root)
            return prec;
      }
      return prec;
  }
*/
#endif