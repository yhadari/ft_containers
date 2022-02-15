#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator_traits.hpp"

template <class Iterator>
class Reverse_iterator{

    public:

    typedef Iterator                                                iterator_type;
    typedef typename Iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef typename Iterator_traits<Iterator>::value_type          value_type;
    typedef typename Iterator_traits<Iterator>::difference_type     difference_type;
    typedef typename Iterator_traits<Iterator>::pointer             pointer;
    typedef typename Iterator_traits<Iterator>::reference           reference;

    Reverse_iterator();
    explicit Reverse_iterator(Iterator iterator) : _iterator(iterator){}
    Reverse_iterator(Reverse_iterator<Iterator> const& copy) : _iterator(copy._iterator){}
    Iterator&           base(){
        return this->_iterator;
    }
    reference           operator*(){
        return *(base()-1);
    }
    Reverse_iterator    operator+(difference_type n){
        return Reverse_iterator(base()-n);
    }

    Reverse_iterator    operator-(difference_type n){
        return Reverse_iterator(base()+n);
    }

    Reverse_iterator&   operator++(){
        return *this = Reverse_iterator(base()-1);
    }

    Reverse_iterator&   operator--(){
        return *this = Reverse_iterator(base()+1);
    }

    Reverse_iterator&   operator+=(difference_type n){
        return *this = Reverse_iterator(base()-n);
    }

    Reverse_iterator&   operator-=(difference_type n){
        return *this = Reverse_iterator(base()+n);
    }
    reference           operator->(){
        return &(operator*());
    }
    private:
    iterator_type _iterator;
};

#endif