#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "Iterator.hpp"

namespace ft{

    template<class T>
    class VectorIterator : public iterator<std::random_access_iterator_tag, T>{
    
        T* _ptr;
    
        public:
    
        typedef typename iterator<std::random_access_iterator_tag, T>::value_type           value_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
        typedef typename iterator<std::random_access_iterator_tag, T>::pointer              pointer;
        typedef typename iterator<std::random_access_iterator_tag, T>::reference            reference;
        typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;
    
        VectorIterator(): _ptr(NULL){}
        VectorIterator(pointer p): _ptr(p){}
        VectorIterator(VectorIterator const& copy): _ptr(copy._ptr){}
        VectorIterator&     operator=(VectorIterator const& it){
            this->_ptr = it._ptr;
            return *this;
        };
        VectorIterator&     operator++(){
            this->_ptr++;
            return *this;
        };
        VectorIterator      operator++(int){
            VectorIterator temp = *this;
            ++(*this);
            return temp;
        };
        VectorIterator&     operator--(){
            this->_ptr--;
            return *this;
        };
        VectorIterator      operator--(int){
            VectorIterator temp = *this;
            --(*this);
            return temp;
        };
        difference_type     operator-(VectorIterator& it){
            difference_type Distance = this->_ptr - it._ptr;
            return Distance;
        };
        VectorIterator      operator+(difference_type value) const{
            return VectorIterator(this->_ptr+value);
        };
        VectorIterator      operator-(difference_type value) const{
            return VectorIterator(this->_ptr-value);
        };
        VectorIterator&     operator+=(difference_type value){
            return *this = VectorIterator(this->_ptr+value);
        };
        VectorIterator&     operator-=(difference_type value){
            return *this = VectorIterator(this->_ptr-value);
        };
        bool                operator==(VectorIterator const& it) const{
            return  this->_ptr == it._ptr;
        }
        bool                operator!=(VectorIterator const& it) const{
            return  this->_ptr != it._ptr;
        }
        bool                operator<(VectorIterator const& it) const{
            return this->_ptr < it._ptr;
        }
        bool                operator>(VectorIterator const& it) const{
            return this->_ptr > it._ptr;
        }
        bool                operator<=(VectorIterator const& it) const{
            return this->_ptr <= it._ptr;
        }
        bool                operator>=(VectorIterator const& it) const{
            return this->_ptr >= it._ptr;
        }
        reference           operator*() const{
            return  *this->_ptr;
        }
        reference           operator*(value_type const& t){
            return (*this->_ptr = t);
        }
        pointer             operator->() const{
            return this->_ptr;
        }
        reference           operator[](difference_type  index) const{
            return *(this->_ptr + index);
        }
        ~VectorIterator(void){};
    };
    
    template<typename T>
    VectorIterator<T>       operator+(typename VectorIterator<T>::difference_type value, VectorIterator<T> iter){
        return iter+value;
    };
}

#endif