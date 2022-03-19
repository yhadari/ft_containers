#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

typedef struct  s_node {
  int       key;
  s_node    *left;
  s_node    *right;
  int       height;
}               t_node;

int height(t_node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

t_node *newt_node(int key) {
  t_node *node = new t_node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

t_node *rightRotate(t_node *y) {
  t_node *x = y->left;
  t_node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

t_node *leftRotate(t_node *x) {
  t_node *y = x->right;
  t_node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}

void  inorder(t_node *root)
{
    if (root)
    {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

void  preorder(t_node *root)
{
    if(root)
    {
        std::cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void  postorder(t_node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->key << " ";
    }
}

int getBalanceFactor(t_node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

t_node *insertt_node(t_node *node, int key) {
  // Find the correct postion and insert the node
  if (node == NULL)
    return (newt_node(key));
  if (key < node->key)
    node->left = insertt_node(node->left, key);
  else if (key > node->key)
    node->right = insertt_node(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // balance the tree
  node->height = 1 + max(height(node->left), height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

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

#endif