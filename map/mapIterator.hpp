#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "../vector/Iterator.hpp"
#include "avl.hpp"

namespace ft{

    template<class T>
    class MapIterator : public iterator<std::bidirectional_iterator_tag, T>{

        t_node node;

        public:

        typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type           value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type      difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer              pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::reference            reference;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category    iterator_category;
    };
}

#endif