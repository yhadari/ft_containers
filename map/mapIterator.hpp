#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "../vector/Iterator.hpp"
#include "avl.hpp"
#include "make_pair.hpp"

namespace ft{

    template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class MapIterator : public iterator<std::bidirectional_iterator_tag, ft::pair<const Key, T> >{

        public:
        typedef ft::pair<const Key, T>                                                          pair;
        typedef ft::Node<pair>                                                                  node_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::value_type            value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::difference_type       difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::pointer               pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::reference             reference;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::iterator_category     iterator_category;
        typedef typename ft::Avl<Key, T, Compare, Alloc>                                        avl_type;    
                                                                                                                                       
        private:
        avl_type _tree;

        public:
        MapIterator(): _tree(){}
        MapIterator(node_type *root, node_type *ptr): _tree(){
                this->_tree._root = root;
                this->_tree._ptr = ptr;
        }
        MapIterator(const MapIterator& copy){
            *this = copy;
        }
        MapIterator&     operator=(MapIterator const& it){
            if (*this == it)
				return (*this);
            this->_tree = it._tree;
            return *this;
        }
        MapIterator&     operator++(){
            this->_tree._ptr = this->_tree.nextNode(this->_tree._root, this->_tree._ptr);
            return *this;
        }
        MapIterator      operator++(int){
            MapIterator temp(*this);
            ++(*this);
            return temp;
        }
        MapIterator&     operator--(){
            if (!this->_tree._ptr)
                this->_tree._ptr = this->_tree.findMax(this->_tree._root);
            else
                this->_tree._ptr = this->_tree.previousNode(this->_tree._root, this->_tree._ptr);
            return *this;
        }
        MapIterator      operator--(int){
            MapIterator temp(*this);
            --(*this);
            return temp;
        }
        MapIterator    operator+(difference_type n) const{
            MapIterator it(*this);
            while (n--)
                it++;
            return it;
        }
        MapIterator    operator-(difference_type n) const{
            MapIterator it(*this);
            while (n--)
                it--;
            return it;
        }
        bool                operator==(MapIterator const& it) const{
            return  this->_tree == it._tree;
        }
        bool                operator!=(MapIterator const& it) const{
            return  this->_tree != it._tree;
        }
        reference        operator*() const{
            return  *(this->_tree._ptr->data);
        }
        reference           operator*(value_type const& t){
            return (this->_tree._ptr->data = t);
        }
        pointer             operator->() const{
            return this->_tree._ptr->data;
        }
        ~MapIterator(void){};
    };
}

#endif