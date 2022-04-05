#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
#include "../vector/Reverse_iterator.hpp"
#include "mapIterator.hpp"
#include "../vector/enable_if.hpp"
#include "../vector/is_integral.hpp"
#include "../vector/Vector.hpp"

namespace ft{

    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
    class map{

        public:

        typedef     Key                                                                             key_type;        
        typedef     T                                                                               mapped_type;        
        typedef     typename ft::pair<const key_type, mapped_type>                                  value_type;
        typedef     Compare                                                                         key_compare;
        typedef     Alloc                                                                           allocator_type;
        typedef     typename allocator_type::reference                                              reference;
        typedef     typename allocator_type::const_reference                                        const_reference;
        typedef     typename allocator_type::pointer                                                pointer;
        typedef     typename allocator_type::const_pointer                                          const_pointer;
        typedef     ft::MapIterator<key_type, mapped_type, key_compare, allocator_type>             iterator;
        typedef     ft::MapIterator<const key_type, mapped_type, key_compare, allocator_type>       const_iterator;
        typedef     ft::reverse_iterator<iterator>                                                  reverse_iterator;
        typedef     ft::reverse_iterator<const_iterator>                                            const_reverse_iterator;
        typedef     typename ft::iterator_traits<iterator>::difference_type                         difference_type;
        typedef     size_t                                                                          size_type;
        typedef     ft::Avl<key_type, mapped_type, key_compare, allocator_type>                     avl_type;
        typedef     typename avl_type::node_type                                                    node_type;
        typedef     typename ft::pair<iterator, bool>                                               insert_pare;
        typedef     typename ft::pair<iterator,iterator>                                            equal_range_pair;
        typedef     typename ft::pair<const_iterator,const_iterator>                                const_equal_range_pair;
        typedef     class value_compare : public std::binary_function<value_type, value_type, bool>
                    {
                      friend class  map;
                        protected:
                          Compare comp;
                          value_compare (Compare c) : comp(c){}
                        public:
                          typedef bool result_type;
                          typedef value_type first_argument_type;
                          typedef value_type second_argument_type;
                          bool operator() (const value_type& x, const value_type& y) const
                          {
                            return comp(x.first, y.first);
                          }
                    }value_compare;
                                                                                                                                                 
        private:

        avl_type        _tree;
        size_type       _size;

        public:

        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _size(0){
            this->_tree._pair_allocator = alloc;
            this->_tree._compare = comp;
        }

        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type = InputIterator()): _size(0){
            this->_tree._pair_allocator = alloc;
            this->_tree._compare = comp;
            // while (first != last){
            //     this->_tree._root = this->_tree.insertNode(this->_tree._root, *first++);
            //     this->_size++;
            // }
            insert(first, last);
        }

        map(const map& x){
            *this = x;
        }

        map&    operator=(const map& m){
            this->_tree = m._tree;
            this->_size = m._size;
            return *this;
        }

        ~map(){
            clear();
        }
        
        iterator    begin(){
            return iterator(this->_tree._root, this->_tree.findMin(this->_tree._root));
        }

        const_iterator  begin() const{
            return const_iterator(this->_tree._root, this->_tree.findMin(this->_tree._root));
        }

        iterator    end(){
            return iterator(this->_tree._root, NULL);
        }

        const_iterator  end() const{
            avl_type Node;
            return const_iterator(this->_tree._root, NULL);
        }

        reverse_iterator    rbegin(){
            return reverse_iterator(this->end());
        }

        const_reverse_iterator  rbegin() const{
            return const_reverse_iterator(this->end());
        }

        reverse_iterator    rend(){
            return reverse_iterator(this->begin());
        }

        const_reverse_iterator  rend() const{
            return const_reverse_iterator(this->begin());
        }

        bool    empty() const{
            return this->_size == 0;
        }

        size_type   size() const{
            return this->_size;
        }

        size_type   max_size() const{
            return this->_tree._node_allocator.max_size();
        }

        mapped_type&    operator[](const key_type& k){
            value_type val(k, mapped_type());
            insert_pare it = insert(val);
            return (*it.first).second;
        }

        pair<iterator,bool> insert(const value_type& val){
            bool i = true;
            node_type *node = this->_tree.findNode(this->_tree._root, val.first);
            if (node)
                i = false;
            else
            {
                this->_tree._root = this->_tree.insertNode(this->_tree._root, val);
                node = this->_tree.findNode(this->_tree._root, val.first);
                this->_size++;
            }
            insert_pare ret(iterator(this->_tree._root, node), i);
            return ret;
        }

        iterator    insert(iterator position, const value_type& val){
            (void)position;
            insert_pare i = insert(val);
            return i.first;
        }

        template <class InputIterator>
        void    insert(InputIterator first, InputIterator last){
            while (first != last)
            {
                value_type val((*first).first, (*first).second);
                insert(val);
                first++;
            }
        }

        void    erase(iterator position){
            value_type val((*position).first, (*position).second);
            this->_tree._root = this->_tree.deleteNode(this->_tree._root, val);
            this->_size--;
        }

        size_type   erase(const key_type& k){
            node_type *node = this->_tree.findNode(this->_tree._root, k);
            if (node)
            {
                erase(find(k));
                return 1;
            }
            return 0;
        }

        void    erase(iterator first, iterator last){
            ft::vector<key_type> vector;
            while (first != last)
                vector.push_back((*first++).first);
            typename ft::vector<key_type>::iterator it = vector.begin();
            size_type size = vector.size();
            while (size--)
                erase(*it++);
        }

        void    swap(map& x){
            avl_type temp = this->_tree;
            size_type size  = this->_size;
            this->_tree = x._tree;
            this->_size = x._size;
            x._tree = temp;
            x._size = size;
        }

        void    clear(){
            erase(begin(), end());
        }

        iterator    find(const key_type& k){
            node_type *node = this->_tree.findNode(this->_tree._root, k);
            if(node)
                return iterator(this->_tree._root, node);
            return end();
        }

        const_iterator  find(const key_type& k) const{
            node_type *node = this->_tree.findNode(this->_tree._root, k);
            if (node)
                return const_iterator(this->_tree._root, node);
            return end();
        }

        size_type   count(const key_type& k) const{
            node_type *node = this->_tree.findNode(this->_tree._root, k);
            if (node)
                return 1;
            return 0;
        }

        key_compare key_comp() const{
            return this->_tree._compare;
        }

        value_compare   value_comp() const{
            return (value_compare(key_comp()));
        }

        iterator    lower_bound(const key_type& k){
            node_type *node = this->_tree.upperequalNode(this->_tree._root, k, 1);
            return iterator(this->_tree._root, node);
        }

        const_iterator lower_bound(const key_type& k) const{
            node_type *node = this->_tree.upperequalNode(this->_tree._root, k, 1);
            return const_iterator(this->_tree._root, node);
        }

        iterator    upper_bound(const key_type& k){
            node_type *node = this->_tree.upperequalNode(this->_tree._root, k, 0);
            return iterator(this->_tree._root, node);
        }

        const_iterator  upper_bound(const key_type& k) const{
            node_type *node = this->_tree.upperequalNode(this->_tree._root, k, 0);
            return const_iterator(this->_tree._root, node);
        }

        pair<iterator,iterator> equal_range(const key_type& k){
            equal_range_pair ret(lower_bound(k), upper_bound(k));
            return ret;
        }

        pair<const_iterator,const_iterator> equal_range(const key_type& k) const{
            const_equal_range_pair ret(lower_bound(k), upper_bound(k));
            return ret;
        }

        allocator_type  get_allocator() const{
            return (Alloc(this->_tree._pair_allocator));
        }
    };

    template <class Key, class T, class Compare, class Alloc>
        bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
            if (lhs.size() == rhs.size())
                return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
            else
                return false;
        }
    template <class Key, class T, class Compare, class Alloc>
        bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
            return !operator==(lhs, rhs);
        }
    template <class Key, class T, class Compare, class Alloc>
        bool operator<(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
    template <class Key, class T, class Compare, class Alloc>
        bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
            if (operator==(lhs, rhs) || operator<(lhs, rhs))
                return true;
            return false;
        }
    template <class Key, class T, class Compare, class Alloc>
        bool operator>(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
            return (rhs < lhs);
        }
    template <class Key, class T, class Compare, class Alloc>
        bool operator>= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs){
            if (operator==(lhs, rhs) || operator>(lhs, rhs))
                return true;
            return false;
        }
}

#endif