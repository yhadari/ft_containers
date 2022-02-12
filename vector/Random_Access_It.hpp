#ifndef RANDOM_ACCESS_IT_HPP
# define RANDOM_ACCESS_IT_HPP

#include "Iterator.hpp"

template<class T>
class Random_Access_It : public Iterator<std::random_access_iterator_tag, T>{

    T* _ptr;

    public:
    Random_Access_It(T* p): _ptr(p){}
    Random_Access_It(Random_Access_It const& copy){*this = copy;};
    Random_Access_It&   operator=(Random_Access_It const& it){this->_ptr = it._ptr;};
    bool                operator==(Random_Access_It const& it){
        return  this->_ptr == it._ptr ? true : false;
    }  
    ~Random_Access_It(void){};    

};

#endif