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

    Reverse_iterator(): _iterator(NULL){}
    explicit Reverse_iterator(iterator_type iterator) : _iterator(iterator){}
    Reverse_iterator(Reverse_iterator<Iterator> const& copy) : _iterator(copy._iterator){}
    iterator_type       base() const{
        return this->_iterator;
    }
    reference           operator*() const{
        return *(base()-1);
    }
    Reverse_iterator    operator+(difference_type n) const{
        return Reverse_iterator(base()-n);
    }
    Reverse_iterator    operator-(difference_type n) const{
        return Reverse_iterator(base()+n);
    }
    Reverse_iterator&   operator++(){
        return *this = Reverse_iterator(base()-1);
    }
    Reverse_iterator    operator++(int){
        Reverse_iterator temp = *this;
        operator++();
        return temp;
    }
    Reverse_iterator&   operator--(){
        return *this = Reverse_iterator(base()+1);
    }
    Reverse_iterator    operator--(int){
        Reverse_iterator temp = *this;
        operator--();
        return temp;
    }
    Reverse_iterator&   operator+=(difference_type n){
        return *this = Reverse_iterator(base()-n);
    }
    Reverse_iterator&   operator-=(difference_type n){
        return *this = Reverse_iterator(base()+n);
    }
    pointer             operator->(){
        return &(operator*());
    }
    reference           operator[](difference_type n) const{
        return base()[-n-1];
    }

    ~Reverse_iterator(void){}
    
    private:
    iterator_type _iterator;
};

template <class Iterator>
bool    operator== (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs){
    return lhs.base() == rhs.base();
}
template <class Iterator>
bool    operator!= (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs){
    return lhs.base() != rhs.base();
}
template <class Iterator>
bool    operator< (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs){
    return lhs.base() > rhs.base();
}
template <class Iterator>
bool    operator<= (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs){
    return lhs.base() >= rhs.base();
}
template <class Iterator>
bool    operator> (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs){
    return lhs.base() < rhs.base();
}
template <class Iterator>
bool    operator>= (const Reverse_iterator<Iterator>& lhs, const Reverse_iterator<Iterator>& rhs){
    return lhs.base() <= rhs.base();
}

template <class Iterator>
Reverse_iterator<Iterator> operator+(typename Reverse_iterator<Iterator>::difference_type n,
    const Reverse_iterator<Iterator>& rev_it){
        return rev_it+n;
}
template <class Iterator>
typename Reverse_iterator<Iterator>::difference_type operator-(const Reverse_iterator<Iterator>& lhs,
    const Reverse_iterator<Iterator>& rhs){
        return rhs.base()-lhs.base();
}

#endif