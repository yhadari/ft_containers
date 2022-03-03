#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/Vector.hpp"

namespace ft{

    template <class T, class Container = ft::vector<T> >
    class stack{

        public:

        typedef T                               value_type;
        typedef Container                       container_type;
        typedef size_t                          size_type;

        explicit    stack(const container_type& ctnr = container_type()): _vector(ctnr){
        }

        size_type           size() const{
            return this->_vector.size();
        }

        bool                empty() const{
            return this->_vector.empty();
        }

        value_type&         top(){
            return this->_vector.back();
        }

        const value_type&   top() const{
            return this->_vector.back();
        }

        void                push(const value_type& val){
            this->_vector.push_back(val);
        }

        void                pop(){
            this->_vector.pop_back();
        }

        private:
        container_type _vector;
    };

    template <class T, class Container>
        bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
            return lhs._vector == rhs._vector;
        }
    template <class T, class Container>
        bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
            return Container::operator!=(lhs, rhs);
        }
    template <class T, class Container>
        bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
            return Container::operator<(lhs, rhs);
        }
    template <class T, class Container>
        bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
            return Container::operator<=(lhs, rhs);
        }
    template <class T, class Container>
        bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
            return Container::operator>(lhs, rhs);
        }
    template <class T, class Container>
        bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs){
            return Container::operator>=(lhs, rhs);
        }
}

#endif