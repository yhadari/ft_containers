// AVL tree implementation in C++

#include <iostream>
using namespace std;

typedef struct  s_node {
  int       key;
  s_node    *left;
  s_node    *right;
  int       height;
}               t_node;

// Calculate height
int height(t_node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

// New node creation
t_node *newt_node(int key) {
  t_node *node = new t_node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
t_node *rightRotate(t_node *y) {
  t_node *x = y->left;
  t_node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;
  return x;
}

// Rotate left
t_node *leftRotate(t_node *x) {
  t_node *y = x->right;
  t_node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(t_node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert a node
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

// t_node with minimum value
t_node *nodeWithMimumValue(t_node *node) {
  t_node *current = node;
  while (current->left != NULL)
    current = current->left;
  return current;
}

// Delete a node
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
      t_node *temp = nodeWithMimumValue(root->right);
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

// Print the tree
void printTree(t_node *root, string indent, bool last) {
  if (root != nullptr) {
    cout << indent;
    if (last) {
      cout << "R----";
      indent += "   ";
    } else {
      cout << "L----";
      indent += "|  ";
    }
    cout << root->key << endl;
    printTree(root->left, indent, false);
    printTree(root->right, indent, true);
  }
}

int main() {
  t_node *root = NULL;
  root = insertt_node(root, 33);
  root = insertt_node(root, 13);
  root = insertt_node(root, 53);
  root = insertt_node(root, 9);
  root = insertt_node(root, 21);
  root = insertt_node(root, 61);
  root = insertt_node(root, 8);
  root = insertt_node(root, 11);
  std::cout<<"balance nb : "<<getBalanceFactor(root)<<std::endl;
  printTree(root, "", true); 
  root = insertt_node(root, 0);
  cout << "After deleting " << endl;
  std::cout<<"balance nb : "<<getBalanceFactor(root)<<std::endl;
  printTree(root, "", true);
}