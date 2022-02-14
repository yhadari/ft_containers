#ifndef VECTOR_REVERSE_ITERATOR
# define VECTOR_REVERSE_ITERATOR

template <class Iterator>
class Vector_reverse_iterator{

    Iterator _it;
    public:
    Vector_reverse_iterator(){}
    explicit Vector_reverse_iterator(Iterator it) : _it(it){}
    Vector_reverse_iterator(Vector_reverse_iterator<Iterator> const& copy) : _it(copy._it){}
};

#endif