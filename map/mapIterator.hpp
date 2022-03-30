#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "../vector/Iterator.hpp"
#include "avl.hpp"
#include "make_pair.hpp"

namespace ft{

    template<class Key, class T>
    class MapIterator : public iterator<std::bidirectional_iterator_tag, ft::pair<const Key, T> >{

        public:
        typedef ft::pair<const Key, T>                                                          pair;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::value_type            value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::difference_type       difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::pointer               pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::reference             reference;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::iterator_category     iterator_category;
        typedef typename ft::Avl<Key, T>                                                        avl_type;                                                                                                                                   

        private:
        
        avl_type _node;
        avl_type _root;

        public:

        MapIterator(): _node(), _root(){}
        MapIterator(avl_type *root, avl_type *node): _node(*node), _root(*root){}
        MapIterator(const MapIterator& copy): _node(), _root(){
            *this = copy;
        }
        MapIterator&     operator=(MapIterator const& it){
            if (*this == it)
				return (*this);
            this->_node = it._node;
            this->_root = it._root;
            return *this;
        }
        MapIterator&     operator++(){
            this->_node.set_root(this->_root.nextNode(this->_node.get_root()));
            return *this;
        }
        MapIterator      operator++(int){
            MapIterator temp(*this);
            ++(*this);
            return temp;
        }
        MapIterator&     operator--(){
            this->_node.set_root(this->_root.previousNode(this->_node.get_root()));
            return *this;
        }
        MapIterator      operator--(int){
            MapIterator temp(*this);
            --(*this);
            return temp;
        }
        bool                operator==(MapIterator const& it) const{
            return  ((this->_node == it._node) && (this->_root == it._root));
        }
        bool                operator!=(MapIterator const& it) const{
            return  ((this->_node != it._node) || (this->_root != it._root));
        }
        reference        operator*() const{
            return  *(this->_node.get_data());
        }
        reference           operator*(value_type const& t){
            return (this->_node.get_data() = t);
        }
        pointer             operator->() const{
            return this->_node.get_data();
        }
        ~MapIterator(void){};
    };
}

#endif