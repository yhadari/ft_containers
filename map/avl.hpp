#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include "pair.hpp"
#include "Node.hpp"

namespace ft{

  template < class Key, class T, class Compare, class Alloc >
  class Avl{

    public:
    typedef ft::pair<const Key, T>      value_type;
    typedef ft::Node<value_type>        node_type;
    typedef Alloc                       allocator_pair_type;
    typedef Compare                     campare_type;
    typedef std::allocator<node_type>   allocator_node_type;

    node_type             *_root;
    allocator_pair_type   _pair_allocator;
    allocator_node_type   _node_allocator;
    campare_type          _compare;

    Avl() : _root(NULL){
    }

    Avl&  operator=(const Avl &avl){
      this->_root = avl._root;
			return (*this);
		}

    node_type *NewNode(const value_type& val){
      node_type *ptr;
      ptr = this->_node_allocator.allocate(1);
      ptr->data = this->_pair_allocator.allocate(1);
      this->_pair_allocator.construct(ptr->data, val);
      ptr->left = NULL;
      ptr->right = NULL;
      ptr->height = 1;
      return ptr;
    }

    int Height(node_type *N) {
      if (N == NULL)
        return 0;
      return N->height;
    }

    int max(T a, T b) {
      return (a > b) ? a : b;
    }

    node_type  *rightRotate(node_type *y) {
      node_type *x = y->left;
      node_type *T2 = x->right;
      x->right = y;
      y->left = T2;
      y->height = max(Height(y->left), Height(y->right)) + 1;
      x->height = max(Height(x->left), Height(x->right)) + 1;
      return x;
    }

    node_type  *leftRotate(node_type *x) {
      node_type *y = x->right;
      node_type *T2 = y->left;
      y->left = x;
      x->right = T2;
      x->height = max(Height(x->left), Height(x->right)) + 1;
      y->height = max(Height(y->left), Height(y->right)) + 1;
      return y;
    }

    void  inorder(node_type *root)
    {
      if (root)
      {
        inorder(root->left);
        std::cout << root->data->first << " ";
        inorder(root->right);
      }
    }

    void  preorder(node_type *root)
    {
      if (root)
      {
        std::cout << root->data->first << " ";
        preorder(root->left);
        preorder(root->right);
      }
    }

    void  postorder(node_type *root)
    {
      if (root)
      {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data->first << " ";
      }
    }

    int getBalanceFactor(node_type *N){
      if (N == NULL)
        return 0;
      return Height(N->left) - Height(N->right);
    }

    node_type* findMin(node_type* root)
    {
        while (root->left)
          root = root->left;
        return root;
    }

    node_type* findMax(node_type* root)
    {
        while (root->right)
            root = root->right;
        return root;
    }

    node_type  *insert(node_type *root, const value_type &val) {
      // Find the correct postion and insert the node
      if (root == NULL)
        return (NewNode(val));
      if (this->_compare(val.first, root->data->first))
        root->left = insert(root->left, val);
      else if (!this->_compare(val.first, root->data->first))
        root->right = insert(root->right, val);
      else
        return root;

      // Update the balance factor of each node and
      // balance the tree
      root->height = 1 + max(Height(root->left), Height(root->right));
      int balanceFactor = getBalanceFactor(root);
      if (balanceFactor > 1) {
        if (this->_compare(val.first, root->left->data->first)) {
          return rightRotate(root);
        } else if (!this->_compare(val.first, root->left->data->first)) {
          root->left = leftRotate(root->left);
          return rightRotate(root);
        }
      }
      if (balanceFactor < -1) {
        if (!this->_compare(val.first, root->right->data->first)) {
          return leftRotate(root);
        } else if (this->_compare(val.first, root->right->data->first)) {
          root->right = rightRotate(root->right);
          return leftRotate(root);
        }
      }
      return root;
    }

    node_type *deletet(node_type *root, const value_type &val) {
      // Find the node and delete it
      if (root == NULL)
        return root;
      if (this->_compare(val.first, root->data->first))
        root->left = deletet(root->left, val);
      else if (!this->_compare(val.first, root->data->first))
        root->right = deletet(root->right, val);
      else {
        if ((root->left == NULL) || (root->right == NULL)) {
          node_type *temp = root->left ? root->left : root->right;
          if (temp == NULL) {
            temp = root;
            root = NULL;
          } else
            *root = *temp;
          delete temp;
        } else {
          node_type *temp = findMin(root->right);
          root->data = temp->data;
          root->right = deletet(root->right, *temp->data);
        }
      }

      if (root == NULL)
        return root;

      // Update the balance factor of each node and
      // balance the tree
      root->height = 1 + max(Height(root->left), Height(root->right));
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

    void printTree(node_type *root, std::string indent, bool last) {
      if (root != nullptr) {
        std::cout << indent;
        if (last) {
          std::cout << "R----";
          indent += "   ";
        } else {
          std::cout << "L----";
          indent += "|  ";
        }
        std::cout << root->data->first << std::endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
      }
    }

    node_type* nextNode(node_type* root, node_type* x)
    {
        node_type* succ = NULL;
        if (!root)
            return NULL;
        while (1){
            if (this->_compare(x->data->first, root->data->first)){
                succ = root;
                root = root->left;
            }
            else if (!this->_compare(x->data->first, root->data->first))
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

    node_type*  previousNode(node_type* root, node_type* x)
    {
        node_type* prec = NULL;
        if (!root)
            return NULL;
        while (1){
            if (this->_compare(x->data->first, root->data->first))
                root = root->left;
            else if (!this->_compare(x->data->first, root->data->first)){
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

    bool  operator==(Avl const& avl) const{
      return this->_root == avl._root;
    }

    bool  operator!=(Avl const& avl) const{
      return this->_root != avl._root;
    }

  };
}

#endif