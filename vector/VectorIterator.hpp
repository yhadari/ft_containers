#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "Iterator.hpp"

template<class T>
class VectorIterator : public Iterator<std::random_access_iterator_tag, T>{

    T* _ptr;

    public:

    typedef typename Iterator<std::random_access_iterator_tag, T>::value_type           value_type;
    typedef typename Iterator<std::random_access_iterator_tag, T>::difference_type      difference_type;
    typedef typename Iterator<std::random_access_iterator_tag, T>::pointer              pointer;
    typedef typename Iterator<std::random_access_iterator_tag, T>::reference            reference;
    typedef typename Iterator<std::random_access_iterator_tag, T>::iterator_category    iterator_category;

    VectorIterator(T* p): _ptr(p){}
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
        VectorIterator old_it(*this);
        this->_ptr++;
        return old_it;
    };
    VectorIterator&     operator--(){
        this->_ptr--;
        return *this;
    };
    VectorIterator      operator--(int){
        VectorIterator old_it(*this);
        this->_ptr--;
        return old_it;
    };
    difference_type     operator-(VectorIterator& it){
        difference_type Distance = this->_ptr - it._ptr;
        return Distance;
    };
    VectorIterator      operator+(difference_type value){
        return VectorIterator(this->_ptr+value);
    };
    VectorIterator      operator-(difference_type value){
        return VectorIterator(this->_ptr-value);
    };
    VectorIterator&     operator+=(difference_type value){
        return *this = VectorIterator(this->_ptr+value);
    };
    VectorIterator&     operator-=(difference_type value){
        return *this = VectorIterator(this->_ptr-value);
    };
    bool                operator==(VectorIterator const& it){
        return  this->_ptr == it._ptr;
    }
    bool                operator!=(VectorIterator const& it){
        return  this->_ptr != it._ptr;
    }
    bool                operator<(VectorIterator const& it){
        return this->_ptr < it._ptr;
    }
    bool                operator>(VectorIterator const& it){
        return this->_ptr > it._ptr;
    }
    bool                operator<=(VectorIterator const& it){
        return this->_ptr <= it._ptr;
    }
    bool                operator>=(VectorIterator const& it){
        return this->_ptr >= it._ptr;
    }
    T&                  operator*(){
        return  *this->_ptr;
    }
    T&                  operator*(T const& t){
        return (*this->_ptr = t);
    }
    T&                  operator->(){
        return this->_ptr;
    }
    T&                  operator[](difference_type index){
        return this->_ptr[index];
    }
    ~VectorIterator(void){};
};

template<typename T>
VectorIterator<T>       operator+(typename VectorIterator<T>::difference_type value, VectorIterator<T> it){
    return it+value;
};
#endif