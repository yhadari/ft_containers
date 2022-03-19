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
            if (*this == it)
				return (*this);
            this->_node = it._node;
            this->_root = it._root;
            return *this;
        }
        MapIterator&     operator++(){
            this->_node = nextNode(this->_root, this->_node);
            return *this;
        }
        MapIterator      operator++(int){
            MapIterator temp = *this;
            ++(*this);
            return temp;
        }
        MapIterator&     operator--(){
            this->_node = previousNode(this->_root, this->_node);
            return *this;
        }
        MapIterator      operator--(int){
            MapIterator temp = *this;
            --(*this);
            return temp;
        }
        bool                operator==(MapIterator const& it) const{
            return  ((this->_node == it._node) && (this->_root == it._root));
        }
        bool                operator!=(MapIterator const& it) const{
            return  ((this->_node != it._node) || (this->_root != it._root));
        }
        reference           operator*() const{
            return  this->_node.key;
        }
        reference           operator*(value_type const& t){
            return (this->_node.key = t);
        }
        pointer             operator->() const{
            return &this->_node->key;
        }

        ~MapIterator(void){};
    };
}

#endif