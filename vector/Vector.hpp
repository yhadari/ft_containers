#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "VectorIterator.hpp"
#include "Reverse_iterator.hpp"

template < class T, class Alloc = std::allocator<T> >
class Vector{

    public:

    typedef             T                                               value_type;
    typedef             Alloc                                           allocator_type;
    typedef typename    allocator_type::reference                       reference;
    typedef typename    allocator_type::const_reference                 const_reference;
    typedef typename    allocator_type::pointer                         pointer;
    typedef typename    allocator_type::const_pointer                   const_pointer;
    typedef             ft::VectorIterator<T>                           iterator;
    typedef             const   iterator                                const_iterator;
    typedef             ft::reverse_iterator<iterator>                  reverse_iterator;
    typedef             ft::reverse_iterator<const_iterator>            const_reverse_iterator;
    typedef typename    ft::iterator_traits<iterator>::difference_type  difference_type;
    typedef             size_t                                          size_type;
};

#endif