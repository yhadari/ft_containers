#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator_traits.hpp"

template <class Iterator>
class Reverse_iterator{

    Iterator _it;
    public:

    typedef Iterator                                                iterator_type;
    typedef typename Iterator_traits<Iterator>::iterator_category   iterator_category;
    typedef typename Iterator_traits<Iterator>::value_type          value_type;
    typedef typename Iterator_traits<Iterator>::difference_type     difference_type;
    typedef typename Iterator_traits<Iterator>::pointer             pointer;
    typedef typename Iterator_traits<Iterator>::reference           reference;

    Reverse_iterator();
    Reverse_iterator(Iterator it) : _it(it){}
    Reverse_iterator(Reverse_iterator<Iterator> const& copy) : _it(copy._it){}
};

#endif