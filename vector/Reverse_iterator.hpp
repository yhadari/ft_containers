#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "Iterator_traits.hpp"

namespace ft{

    template <class Iterator>
    class reverse_iterator{
    
        public:
    
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iterator>::value_type          value_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::reference           reference;
    
        reverse_iterator(): _iterator(iterator_type()){}
        explicit reverse_iterator(iterator_type iterator) : _iterator(iterator){}
        reverse_iterator(reverse_iterator<Iterator> const& copy) : _iterator(copy._iterator){}
        template <class Iter>
  	   	reverse_iterator& operator= (const reverse_iterator<Iter>& rev_it)
		{
			this->_iterator = rev_it.base();
			return (*this);	  
		}
        iterator_type       base() const{
            return this->_iterator;
        }
        reference           operator*() const{
            iterator_type temp = base();
            return *(--temp);
        }
        reverse_iterator    operator+(difference_type n) const{
            return reverse_iterator(base()-n);
        }
        reverse_iterator    operator-(difference_type n) const{
            return reverse_iterator(base()+n);
        }
        reverse_iterator&   operator++(){
            //return *this = reverse_iterator(base()-1);
            --this->_iterator;
            return (*this);
        }
        reverse_iterator    operator++(int){
            reverse_iterator temp = *this;
            operator++();
            return temp;
        }
        reverse_iterator&   operator--(){
            //return *this = reverse_iterator(base()+1);
            ++this->_iterator;
            return (*this);
        }
        reverse_iterator    operator--(int){
            reverse_iterator temp = *this;
            operator--();
            return temp;
        }
        reverse_iterator&   operator+=(difference_type n){
            return *this = reverse_iterator(base()-n);
        }
        reverse_iterator&   operator-=(difference_type n){
            return *this = reverse_iterator(base()+n);
        }
        pointer             operator->(){
            return &(operator*());
        }
        reference           operator[](difference_type n) const{
            return base()[-n-1];
        }
    
        ~reverse_iterator(void){}
        
        private:
        iterator_type _iterator;
    };
    
    template <class Iterator>
    bool    operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return lhs.base() == rhs.base();
    }
    template <class Iterator>
    bool    operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return lhs.base() != rhs.base();
    }
    template <class Iterator>
    bool    operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return lhs.base() > rhs.base();
    }
    template <class Iterator>
    bool    operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return lhs.base() >= rhs.base();
    }
    template <class Iterator>
    bool    operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return lhs.base() < rhs.base();
    }
    template <class Iterator>
    bool    operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
        return lhs.base() <= rhs.base();
    }
    
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator>& rev_it){
            return rev_it+n;
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>& rhs){
            return rhs.base()-lhs.base();
    }

}

#endif