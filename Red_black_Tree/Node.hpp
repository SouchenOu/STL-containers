/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:12:50 by souchen           #+#    #+#             */
/*   Updated: 2023/02/26 10:12:53 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef NODE_HPP
# define NODE_HPP

# include "Red_black_tree.hpp"
# include "../vector/vector_iterator.hpp"
# include <iostream>
# include <memory>
# include <cmath>
# include <string>
#include "../pair.hpp"
#include "../make_pair.hpp"



template < class T >
    struct Node
    {
        typedef T                           value_type;
        value_type                          data;
        int                                 color;
        Node                                *left;
        Node                                *right;
        Node                                *parent;
        int                                 value_test;

        //default constructer
         Node(void) : data(0),left(0),right(0),color(1),parent(0){};
        
         // constructor with parameter
         Node(value_type const &data, Node *parent, int value_test):value_test(value_test),data(data),parent(parent),left(0),right(0),color(1){}
         
         // copy constuctor
         Node(Node const& obj):color( obj.color),data(obj.data),left(obj.left),right(obj.right),parent(obj.parent), value_test(obj.value_test){}
        
         //assignement operator

         Node& operator = (Node const& obj)
         {
            // if (this == &obj) 
            //     return *this;
            this->color = obj.color;
            this->data = obj.data;
            this->left = obj.left;
            this->right = obj.right;
            this->parent = obj.color;
            this->value_test = obj.value_test;
            return *this;
            
         }
         // destructor

         ~Node(){}

       
    };


// //  template<class T, class Allocator>
// //     ostream& operator<< (ostream& os, const map<T, Allocator> & m)
// //     {
// //         os << m.value_type;
// //         //os << m.Node->root;
// //     }

#endif
