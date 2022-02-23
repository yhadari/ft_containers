#include "Vector.hpp"
#include <iostream>
#include <vector>

int main ()
{
  {
        std::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<10; i++) myvector.push_back(i);

        std::cout << "size: " << (int) myvector.size() << '\n';
        std::cout << "capacity: " << (int) myvector.capacity() << '\n';
        myvector.pop_back();
        myvector.pop_back();
        myvector.pop_back();
        std::cout << "size: " << (int) myvector.size() << '\n';
        std::cout << "capacity: " << (int) myvector.capacity() << '\n';
        std::cout << myvector[8] << "|" << myvector[9] << std::endl;
  }
  std::cout << "------------------------------------------------------------------" << std::endl;
  {
      ft::vector<int> myvector;
      // set some content in the vector:
      for (int i=0; i<10; i++) myvector.push_back(i);
      std::cout << "size: " << (int) myvector.size() << '\n';
      std::cout << "capacity: " << (int) myvector.capacity() << '\n';
      myvector.pop_back();
      myvector.pop_back();
      myvector.pop_back();
      std::cout << "size: " << (int) myvector.size() << '\n';
      std::cout << "capacity: " << (int) myvector.capacity() << '\n';
      std::cout << myvector[8] << "|" << myvector[9] << std::endl;
  }
  while (1);
  return 0;
}