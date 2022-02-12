#ifndef RANDOM_ACCESS_IT_HPP
# define RANDOM_ACCESS_IT_HPP

#include "Iterator.hpp"

template<class T>
class Random_Access_It : public Iterator<std::random_access_iterator_tag, T>{

    T* _ptr;

    typedef typename Iterator<std::random_access_iterator_tag, T>::value_type value_type;
    typedef typename Iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
    typedef typename Iterator<std::random_access_iterator_tag, T>::Pointer Pointer;
    typedef typename Iterator<std::random_access_iterator_tag, T>::Reference Reference;
    typedef typename Iterator<std::random_access_iterator_tag, T>::iterator_category iterator_category;

    public:
    Random_Access_It(T* p): _ptr(p){}
    Random_Access_It(Random_Access_It const& copy): _ptr(copy._ptr){}
    Random_Access_It&   operator=(Random_Access_It const& it){
        this->_ptr = it._ptr;
    };
    Random_Access_It&   operator++(){
        this->_ptr++;
        return *this;
    };
    Random_Access_It&   operator++(int){
        Random_Access_It old_ptr(*this);
        this->_ptr++;
        return old_ptr;
    };
    Random_Access_It&   operator--(){
        this->_ptr--;
        return *this;
    };
    Random_Access_It&   operator--(int){
        Random_Access_It old_ptr(*this);
        this->_ptr--;
        return old_ptr;
    };
    Random_Access_It&   operator-(Random_Access_It const& it){
        this->_ptr -= it._ptr;
        return *this;
    };
    Random_Access_It&   operator+(difference_type& value){
        Random_Access_It new_ptr(*this+value);
        return new_ptr;
    };
    Random_Access_It&   operator-(difference_type const& value){
        Random_Access_It new_ptr(*this-value);
        return new_ptr;
    };
    bool                operator==(Random_Access_It const& it){
        return  this->_ptr == it._ptr ? true : false;
    }
    bool                operator!=(Random_Access_It const& it){
        return  !operator==(it);
    }
    T&                  operator*(){
        return  *this->_ptr;
    }
    T&                  operator->(){
        return this->_ptr;
    }
    T&                  operator*(T const& t){
        return (*this->_ptr = t);
    }   
    ~Random_Access_It(void){};
};

#endif