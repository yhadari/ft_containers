#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "../vector/Iterator.hpp"
#include "avl.hpp"

namespace ft{

    template<class T>
    class MapIterator : public iterator<std::bidirectional_iterator_tag, T>{

        t_node _node;
        t_node _root;

        public:

        typedef typename iterator<std::bidirectional_iterator_tag, T>::value_type           value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::difference_type      difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::pointer              pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::reference            reference;
        typedef typename iterator<std::bidirectional_iterator_tag, T>::iterator_category    iterator_category;

        MapIterator(): _node.left(NULL), _node.right(NULL){}
        MapIterator(t_node p): _node(p){}
        MapIterator(MapIterator const& copy): _node(copy._node){}
        MapIterator&     operator=(MapIterator const& it){
            this->_node = it._node;
            return *this;
        }
        // MapIterator&     operator++(){
        //     this->_ptr++;
        //     return *this;
        // }
        // MapIterator      operator++(int){
        //     VectorIterator temp = *this;
        //     ++(*this);
        //     return temp;
        // }
        bool                operator!=(MapIterator const& it) const{
            return  this->_node != it._node;
        }
        reference           operator*() const{
            return  this->_node.key;
        }
        reference           operator*(value_type const& t){
            return (this->_node.key = t);
        }
        pointer             operator->() const{
            return this->_node;
        }
    };
}

#endif