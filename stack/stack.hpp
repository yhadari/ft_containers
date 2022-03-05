#ifndef Stack_HPP
# define Stack_HPP

#include "../vector/Vector.hpp"

namespace ft{

    template <class T, class Container = ft::vector<T> >
    class Stack{

        public:

        typedef T                               value_type;
        typedef Container                       container_type;
        typedef size_t                          size_type;

        explicit    Stack(const container_type& ctnr = container_type()): _vector(ctnr){
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

        template <class T1, class Container1>
            friend bool operator==(const Stack<T1,Container1>&, const Stack<T1,Container1>&);

        template <class T1, class Container1>
            friend bool operator!=(const Stack<T1,Container1>&, const Stack<T1,Container1>&);

        template <class T1, class Container1>
            friend bool operator<(const Stack<T1,Container1>&, const Stack<T1,Container1>&);

        template <class T1, class Container1>
            friend bool operator<=(const Stack<T1,Container1>&, const Stack<T1,Container1>&);

        template <class T1, class Container1>
            friend bool operator>(const Stack<T1,Container1>&, const Stack<T1,Container1>&);

        template <class T1, class Container1>
            friend bool operator>=(const Stack<T1,Container1>&, const Stack<T1,Container1>&);

        private:
        container_type _vector;
    };

    template <class T, class Container>
        bool operator==(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
            return lhs._vector == rhs._vector;
        }
    template <class T, class Container>
        bool operator!=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
            return lhs._vector != rhs._vector;
        }
    template <class T, class Container>
        bool operator<(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
            return lhs._vector < rhs._vector;
        }
    template <class T, class Container>
        bool operator<=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
            return lhs._vector <= rhs._vector;
        }
    template <class T, class Container>
        bool operator>(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
            return lhs._vector > rhs._vector;
        }
    template <class T, class Container>
        bool operator>=(const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
            return lhs._vector >= rhs._vector;
        }
}

#endif