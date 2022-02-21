#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "VectorIterator.hpp"
#include "Reverse_iterator.hpp"
#include "enable_if.hpp"

namespace ft{

    template < class T, class Alloc = std::allocator<T> >
    class vector{
    
        T *_array;
    
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

        explicit vector(const allocator_type& alloc = allocator_type()){
            allocator_type allocat(alloc);
            this->_array = allocat.allocate(0);
        }
        explicit vector (size_type n, const value_type& val = value_type(),
                     const allocator_type& alloc = allocator_type()){
                         std::cout << "1" << std::endl;
                     }
        template <class InputIterator>
             vector (InputIterator first, InputIterator last,
                     const allocator_type& alloc = allocator_type(), typename enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
                        std::cout << "2" << std::endl;
                     }
    };
}
#endif