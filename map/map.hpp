#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
#include "../vector/Reverse_iterator.hpp"
#include "mapIterator.hpp"

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

        avl_type        _root;
        avl_type        _ptr;
        size_type       _size;

        public:

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(), _ptr(), _size(0){
            this->_root._pair_allocator = alloc;
            this->_root._pair_allocator = alloc;
            this->_ptr._compare = comp;
            this->_ptr._compare = comp;
        }
        // template <class InputIterator>
        //     map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        //     const allocator_type& alloc = allocator_type()){

        //     }
    };
}

#endif