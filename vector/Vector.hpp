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
            this->_resize = 0;
        }

        explicit vector (size_type n, const value_type& val = value_type(),
                     const allocator_type& alloc = allocator_type()){
                        this->_array = this->_myAllocator.allocate(n);
                        for (size_t i = 0; i < n; i++)
                            this->_myAllocator.construct(this->_array+i, val);
                        this->_size = n;
                        this->_capacity = n;
                        this->_resize = 0;
        }

        template <class InputIterator>
             vector (InputIterator first, InputIterator last,
                     const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()){
                        difference_type distance = last-first;
                        this->_array = this->_myAllocator.allocate(distance);
                        this->_size = distance;
                        this->_capacity = distance;
                        this->_resize = 0;
                        for (size_t i = 0; i < distance; i++)
                            this->_array[i] = *first++;
        }

        vector (const vector& x) : _size(0), _capacity(0), _resize(0){
            *this = x;
        }

        vector& operator=(vector const& x){
            if (!this->_size){
                this->_array = this->_myAllocator.allocate(x._capacity);
                this->_size = x._size;
                this->_capacity = x._capacity;
            }
            for (size_t i = 0; i < x._size; i++)
                this->_array[i] = x._array[i];
            return *this;
        }

        ~vector(){
            this->_myAllocator.deallocate(this->_array, this->_capacity);
            for (size_t i = 0; i < this->_size; i++)
                this->_myAllocator.destroy(this->_array+i);
        }

        iterator                begin(){
            return iterator(this->_array);
        }

        const_iterator          begin() const{
            return const_iterator(this->_array);
        }

        iterator                end(){
            return iterator(this->_array+this->_size);
        }

        const_iterator          end() const{
            return const_iterator(this->_array+this->_size);
        }

        reverse_iterator        rbegin(){
            return reverse_iterator(this->end());
        }

        const_reverse_iterator  rbegin() const{
            return const_reverse_iterator(this->end());
        }

        reverse_iterator        rend(){
            return reverse_iterator(this->begin());
        }

        const_reverse_iterator  rend() const{
            const_reverse_iterator(this->begin());
        }

        size_type               size() const{
            return this->_size;
        }

        size_type               max_size() const{
            return this->_myAllocator.max_size();
        }

        void                    resize(size_type n, value_type val = value_type()){
            if (n < this->_size)
                while (--this->_size > n);
            else
            {
                if (n > this->_capacity*2)
                    this->_resize = n;
                else if (n > this->_capacity)
                    this->_resize = this->_capacity * 2;
                while (n > this->_size)
                    push_back(val);
                this->_resize = 0;
            }
        }

        size_type               capacity() const{
            return this->_capacity;
        }

        bool                    empty() const{
            return this->_size == 0;
        }

        void                    push_back(const value_type& val){
            if (this->_size == 0 && ++this->_capacity)
            {
                this->_myAllocator.deallocate(this->_array, 0);
                this->_array = this->_myAllocator.allocate(this->_capacity);
            }
            else if (this->_size == this->_capacity)
            {
                if (this->_resize == 0)
                    this->_capacity *= 2;
                else
                    this->_capacity = this->_resize;
                this->_tmp = this->_myAllocator.allocate(this->_size);
                for (size_t i = 0; i < this->_size; i++)
                    this->_tmp[i] = this->_array[i];
                this->_myAllocator.deallocate(this->_array, this->_capacity/2);
                this->_array = this->_myAllocator.allocate(this->_capacity);
                for (size_t i = 0; i < this->_size; i++)
                    this->_array[i] = this->_tmp[i];
                this->_myAllocator.deallocate(this->_tmp, this->_size);
            }
            this->_array[this->_size++] = val;   
        }

        void                    pop_back(){
            this->_size--;
        }

        reference               operator[](size_type n){
            return this->_array[n];
        }

        const_reference         operator[](size_type n) const{
            return this->_array[n];
        }

        private:
        T               *_array;
        T               *_tmp;
        allocator_type  _myAllocator;
        size_type       _size;
        size_type       _capacity;
        size_type       _resize;
    };
}
#endif