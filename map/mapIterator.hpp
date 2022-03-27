#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "../vector/Iterator.hpp"
#include "avl.hpp"

namespace ft{

    template<class pair>
    class MapIterator : public iterator<std::bidirectional_iterator_tag, pair>{

        public:

        typedef typename iterator<std::bidirectional_iterator_tag, pair>::value_type            value_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::difference_type       difference_type;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::pointer               pointer;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::reference             reference;
        typedef typename iterator<std::bidirectional_iterator_tag, pair>::iterator_category     iterator_category;
        typedef typename ft::Avl<typename pair::first_type, typename pair::second_type>         avl_type;                                                                     

        private:
        
        avl_type *_node;
        avl_type *_root;

        public:

        MapIterator(): _node(NULL), _root(NULL){}
        MapIterator(avl_type *root, avl_type *node): _node(node), _root(root){}
        MapIterator(MapIterator const& copy){
            *this = copy;
        }
        MapIterator&     operator=(MapIterator const& it){
            this->_node = it._node;
            this->_root = it._root;
            return *this;
        }
        MapIterator&     operator++(){
            this->_node->set_root(this->_root->nextNode(this->_node->get_root()));
            return *this;
        }
        MapIterator      operator++(int){
            MapIterator temp = *this;
            ++(*this);
            return temp;
        }
        MapIterator&     operator--(){
            this->_node->set_root(this->_root->previousNode(this->_node->get_root()));
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
        typename pair::second_type   operator*() const{
            return  this->_node->get_data().second;
        }
        reference           operator*(value_type const& t){
            return (this->_node->key = t);
        }
        pointer             operator->() const{
            return &this->_node->key;
        }
        ~MapIterator(void){};
    };
}

#endif