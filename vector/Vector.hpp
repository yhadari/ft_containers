#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "VectorIterator.hpp"
#include "Reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft{

    template < class T, class Alloc = std::allocator<T> >
    class vector{
    
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
            this->_array = this->_myAllocator.allocate(0);
            this->_size = 0;
            this->_capacity = 0;
        }
        explicit vector (size_type n, const value_type& val = value_type(),
                     const allocator_type& alloc = allocator_type()){
                        this->_array = this->_myAllocator.allocate(n);
                        for (size_t i = 0; i < n; i++)
                            this->_myAllocator.construct(this->_array+i, val);
                        this->_size = n;
                        this->_capacity = n;
        }
        template <class InputIterator>
             vector (InputIterator first, InputIterator last,
                     const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
                        difference_type distance = last-first;
                        this->_array = this->_myAllocator.allocate(distance);
                        this->_size = distance;
                        this->_capacity = distance;
                        for (size_t i = 0; i < distance; i++)
                            this->_array[i] = *first++;
        }
        vector (const vector& x) : _size(0), _capacity(0){
            *this = x;
        }
        vector& operator=(vector const& x){
            if (!this->_size)
                this->_array = this->_myAllocator.allocate(x._size);
            for (size_t i = 0; i < x._size; i++)
                this->_array[i] = x._array[i];
            return *this;
        }
        ~vector(){
            for (size_t i = 0; i < this->_size; i++)
                this->_myAllocator.destroy(this->_array+i);
            this->_myAllocator.deallocate(this->_array, this->_size);
        }

        private:
        T               *_array;
        allocator_type  _myAllocator;
        difference_type _size;
        difference_type _capacity;
    };
}
#endif