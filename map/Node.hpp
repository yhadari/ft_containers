#ifndef NODE_HPP
#define NODE_HPP

namespace ft{

    template <class pair>
    struct Node
    {
        typedef pair    value_type;
        
        Node        *right;
        Node        *left;
        value_type  *data;
        int         height;
    };  
}

#endif