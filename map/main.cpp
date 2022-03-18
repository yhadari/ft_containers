#include "avl.hpp"

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
  std::cout << "After deleting " << std::endl;
  std::cout<<"balance nb : "<<getBalanceFactor(root)<<std::endl;
  printTree(root, "", true);
}