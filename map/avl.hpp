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
    node_type             *_ptr;
    allocator_pair_type   _pair_allocator;
    allocator_node_type   _node_allocator;
    campare_type          _compare;

    Avl(): _root(NULL), _ptr(NULL){
    }

    ~Avl(){
    }

    Avl&          operator=(const Avl &tree)
		{
			this->_root = tree._root;
			this->_ptr = tree._ptr;
			return (*this);
		}

    node_type*    NewNode(const value_type& val){
      node_type *node;
      node = this->_node_allocator.allocate(1);
      node->data = this->_pair_allocator.allocate(1);
      this->_pair_allocator.construct(node->data, val);
      node->left = NULL;
      node->right = NULL;
      node->height = 1;
      return node;
    }

    int           Height(node_type *N) {
      if (N == NULL)
        return 0;
      return N->height;
    }

    int           max(int a, int b) {
      return (a > b) ? a : b;
    }

    node_type*    rightRotate(node_type *y) {
      node_type *x = y->left;
      node_type *T2 = x->right;
      x->right = y;
      y->left = T2;
      y->height = max(Height(y->left), Height(y->right)) + 1;
      x->height = max(Height(x->left), Height(x->right)) + 1;
      return x;
    }

    node_type*    leftRotate(node_type *x) {
      node_type *y = x->right;
      node_type *T2 = y->left;
      y->left = x;
      x->right = T2;
      x->height = max(Height(x->left), Height(x->right)) + 1;
      y->height = max(Height(y->left), Height(y->right)) + 1;
      return y;
    }

    int           getBalanceFactor(node_type *N){
      if (N == NULL)
        return 0;
      return Height(N->left) - Height(N->right);
    }

    node_type*    findMin(node_type* root) const
    {
        while (root && root->left)
          root = root->left;
        return root;
    }

    node_type*    findMax(node_type* root) const
    {
        while (root && root->right)
            root = root->right;
        return root;
    }

    node_type*    insertNode(node_type *root, const value_type &val) {
      if (root == NULL)
        return (NewNode(val));
      if (this->_compare(val.first, root->data->first))
        root->left = insertNode(root->left, val);
      else if (this->_compare(root->data->first, val.first))
        root->right = insertNode(root->right, val);
      else
        return root;

      root->height = 1 + max(Height(root->left), Height(root->right));
      int balanceFactor = getBalanceFactor(root);

      if (balanceFactor > 1)
      {
        if (this->_compare(val.first, root->left->data->first))
          return rightRotate(root);
        else if (this->_compare(root->left->data->first, val.first))
        {
          root->left = leftRotate(root->left);
          return rightRotate(root);
        }
      }

      if (balanceFactor < -1)
      {
        if (this->_compare(root->right->data->first, val.first))
          return leftRotate(root);
        else if (this->_compare(val.first, root->right->data->first))
        {
          root->right = rightRotate(root->right);
          return leftRotate(root);
        }
      }
      return root;
    }

    node_type*    deleteNode(node_type *root, const value_type &val) {
      if (root == NULL)
        return root;
      if (this->_compare(val.first, root->data->first))
        root->left = deleteNode(root->left, val);
      else if (this->_compare(root->data->first, val.first))
        root->right = deleteNode(root->right, val);
      else
      {
        if ((root->left == NULL) || (root->right == NULL))
        {
          node_type *temp = root->left ? root->left : root->right;
          if (temp == NULL)
          {
            temp = root;
            root = NULL;
          }
          else{
            root->left = temp->left;
            root->right = temp->right;
            root->height = temp->height;
            this->_pair_allocator.destroy(root->data);
            this->_pair_allocator.construct(root->data, *temp->data);
          }
          this->_pair_allocator.deallocate(temp->data, 1);
          this->_node_allocator.deallocate(temp, 1);
        } 
        else 
        {
          node_type *temp = findMin(root->right);
          this->_pair_allocator.destroy(root->data);
          this->_pair_allocator.construct(root->data, *temp->data);
          root->right = deleteNode(root->right, *temp->data);
        }
      }
      if (root == NULL)
        return root;

      root->height = 1 + max(Height(root->left), Height(root->right));
      int balanceFactor = getBalanceFactor(root);

      if (balanceFactor > 1)
      {
        if (getBalanceFactor(root->left) >= 0)
          return rightRotate(root);
        else 
        {
          root->left = leftRotate(root->left);
          return rightRotate(root);
        }
      }

      if (balanceFactor < -1)
      {
        if (getBalanceFactor(root->right) <= 0)
          return leftRotate(root);
        else
        {
          root->right = rightRotate(root->right);
          return leftRotate(root);
        }
      }
      return root;
    }

    node_type*    nextNode(node_type* root, node_type* x) const
    {
        node_type* succ = NULL;
        if (!root)
            return NULL;
        while (1){
            if (this->_compare(x->data->first, root->data->first)){
                succ = root;
                root = root->left;
            }
            else if (this->_compare(root->data->first, x->data->first))
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

    node_type*    previousNode(node_type* root, node_type* x) const
    {
        node_type* prec = NULL;
        if (!root)
            return NULL;
        while (1){
            if (this->_compare(x->data->first, root->data->first))
                root = root->left;
            else if (this->_compare(root->data->first, x->data->first)){
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

	  node_type*    findNode(node_type *root, const Key &key) const
		{
			if (!root)
				return NULL;
			if (this->_compare(root->data->first, key))
				return (findNode(root->right, key));
			else if (this->_compare(key, root->data->first))
				return (findNode(root->left, key));
			return root;
		}

    node_type*    upperNode(node_type *root, Key key) const
    {
      if (root)
      {
        if(root->data->first > key && (!root->left || findMax(root->left)->data->first <= key))
          return root;
        else{
          if (root->data->first <= key){
            node_type *found_node = upperNode(root->right, key);
            return found_node;
          }
          else{
            node_type *found_node = upperNode(root->left, key);
            return found_node;
          }
        }
      }
      else
        return NULL;
    }

    void          printTree(node_type *root, std::string indent, bool last) {
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

    bool          operator==(Avl const& avl) const{
      return ((this->_root == avl._root) && (this->_ptr == avl._ptr));
    }

    bool          operator!=(Avl const& avl) const{
      return ((this->_root != avl._root) || (this->_ptr != avl._ptr));
    }

  };
}

#endif