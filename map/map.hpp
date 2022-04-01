#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
#include "../vector/Reverse_iterator.hpp"
#include "mapIterator.hpp"
#include "../vector/enable_if.hpp"
#include "../vector/is_integral.hpp"

namespace ft{

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map{

        public:

        typedef     Key                                                                             key_type;        
        typedef     T                                                                               mapped_type;        
        typedef     typename ft::pair<const key_type, mapped_type>                                  value_type;        
        typedef     Compare                                                                         key_compare;
        typedef     Alloc                                                                           allocator_type;
        typedef     typename allocator_type::reference                                              reference;
        typedef     typename allocator_type::const_reference                                        const_reference;
        typedef     typename allocator_type::pointer                                                pointer;
        typedef     typename allocator_type::const_pointer                                          const_pointer;
        typedef     ft::MapIterator<key_type, mapped_type, key_compare, allocator_type>             iterator;
        typedef     ft::MapIterator<const key_type, mapped_type, key_compare, allocator_type>       const_iterator;
        typedef     ft::reverse_iterator<iterator>                                                  reverse_iterator;
        typedef     ft::reverse_iterator<const_iterator>                                            const_reverse_iterator;
        typedef     typename ft::iterator_traits<iterator>::difference_type                         difference_type;
        typedef     size_t                                                                          size_type;
        typedef     ft::Avl<key_type, mapped_type, key_compare, allocator_type>                     avl_type;

        private:

        avl_type        _tree;
        size_type       _size;

        public:

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _size(0){
            this->_tree._pair_allocator = alloc;
            this->_tree._compare = comp;
        }

        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()): _size(0){
            this->_tree._pair_allocator = alloc;
            this->_tree._compare = comp;
            while (first != last){
                this->_tree._root = this->_tree.insertNode(this->_tree._root, *first++);
                this->_size++;
            }
        }

        map (const map& x){
            *this = x;
        }

        map&    operator=(const map& m){
            this->_tree = m._tree;
            this->_size = m._size;
            return *this;
        }

        size_type size() const{
            return this->_size;
        }

        ~map(){
            this->_size = 0;
        }
        
        iterator begin(){
            this->_tree._ptr = this->_tree.findMin(this->_tree._root);
            return iterator(this->_tree._root, this->_tree._ptr);
        }

        const_iterator begin() const{
            this->_tree._ptr = this->_tree.findMin(this->_tree._root);
            return const_iterator(this->_tree._root, this->_tree._ptr);
        }

        iterator end(){
            this->_tree._ptr = this->_tree.findMax(this->_tree._root);
            iterator it = iterator(this->_tree._root, this->_tree._ptr);
            return it;
        }

        const_iterator end() const{
            this->_tree._ptr = this->_tree.findMax(this->_tree._root);
            const_iterator it = const_iterator(this->_tree._root, this->_tree._ptr);
            return it;
        }

        void    display(){
            this->_tree.printTree(this->_tree._root, "", true);
        }
    };
}

#endif