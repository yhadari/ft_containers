#include "avl.hpp"
#include "mapIterator.hpp"
#include <map>

int main() {
  ft::Avl<int, int> *avl = new ft::Avl<int, int>();
  ft::pair<int, int> p(10, 100);
  ft::pair<int, int> p1(11, 200);
  ft::pair<int, int> p2(12, 300);
  ft::pair<int, int> p3(13, 400);

  avl->set_root(avl->insert(avl->get_root(), p));
  avl->set_root(avl->insert(avl->get_root(), p1));
  avl->set_root(avl->insert(avl->get_root(), p2));
  avl->set_root(avl->insert(avl->get_root(), p3));

  ft::MapIterator<int, int> it(avl, avl);
  ft::MapIterator<int, int> it1;
  std::cout << (*it).second << std::endl;
  it1 = it++;
  std::cout << (*it).second << std::endl;
  std::cout << (*it1).second << std::endl;
  // avl->printTree(avl->get_root(), "", true);
  // avl->set_root(avl->deletet(avl->get_root(), p2));
  // avl->set_root(avl->deletet(avl->get_root(), p));

  return 0;
}
