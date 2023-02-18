/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_black_tree_iter.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:33:56 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:33:58 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_ITER_HPP
# define RED_BLACK_TREE_ITER_HPP

# include "Red_black_tree.hpp"
# include <iostream>
# include <memory>
# include <cmath>
# include <string>

namespace ft{

template < class T >
    struct Node
    {
        typedef T                           value_type;
        value_type                          data;
        int                                 color;
        Node                                *left;
        Node                                *right;
        Node                                *parent;

        //default constructer
         Node(){
            this->data = 0;
            this->left = nullptr;
            this->right =nullptr;
            this->color = 1;//(with red color)
         }
         // constructor with parameter
         Node(value_type const &data, Node *parent)
         {
            this->data(data);
            parent(parent);
            left(0);
            right(0);
            color(1);
         }
         // copy constuctor
         Node(Node const& obj)
         {
            this->color = obj->color;
            this->data = obj->data;
            this->left = obj->left;
            this->right = obj->right;
            this->parent = obj->parent;
         }
         //assignement operator

         Node& operator = (Node const& obj)
         {
            if (this == &obj) 
                return *this;
            this->color = obj->color;
            this->data = obj->data;
            this->left = obj->left;
            this->right = obj->right;
            this->parent = obj->parent;
            
         }
         // destructor

         ~Node(){}

       
    };

template<typename T>
class Red_black_tree_iters
{
    
    public:
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef std::bidirectional_iterator_tag     iterator_category;

        typedef Red_black_tree_iters< T >           iterator;
        typedef Red_black_tree_iters<const T >      const_iterator;
        typedef Node< T >                           Node_tree;
        typedef Node<const T>                       const_Node_tree;

        // ***********constructers
        // default constructers

        Red_black_tree_iters()
        {
            _Node =  NULL;
        }
        // copy constructer
        Red_black_tree_iters(Node_tree &obj)
        {
            _Node = obj;
        }

        Red_black_tree_iters(Red_black_tree_iters const& obj)
        {
            _Node = obj._Node;
        }
        // Assignement operator
        Red_black_tree_iters&  operator = (Red_black_tree_iters const& obj)
        {
            if (this == &obj) 
                return *this;
            _Node = obj._Node;
        }

        //Comparison Operators
        bool operator == (Red_black_tree_iters const& obj)
        {
            return _Node == obj._Node;
        }
        bool operator != (Red_black_tree_iters const & obj)
        {
            return _Node != obj._Node;
        }
        bool operator > (Red_black_tree_iters const &obj)
        {
            return _Node > obj._Node;
        }
        bool operator >= (Red_black_tree_iters const &obj)
        {
            return _Node >= obj._Node;
        }
        bool operator < (Red_black_tree_iters const &obj)
        {
            return _Node < obj._Node;
        }
        bool operator <= (Red_black_tree_iters const &obj)
        {
            return _Node <= obj._Node;
        }

        // Arithmetic operator

        Red_black_tree_iters &operator ++ () 
        {

            if(_Node == nullptr)
            {
                _Node = Red_black_tree->root;
                if(_Node == nullptr)
                {
                   return *this;
                }
                // move to the smallest value in the tree,
                // which is the first node inorder
                while(_Node->left != nullptr)
                {
                    _Node = _Node->left;
                }

            }
            else
                if(_Node->right != NULL)
                {
                    _Node = _Node->right;
                    while(_Node && _Node->left)
                    {
                        _Node = _Node->parent;
                    }
            }
            else if(_Node->right == NULL)
            {
                // have already processed the left subtree, and
                // there is no right subtree. move up the tree,
                // looking for a parent for which nodePtr is a left child,
                // stopping if the parent becomes NULL. a non-NULL parent
                // is the successor. if parent is NULL, the original node
                // was the last node inorder, and its successor
                // is the end of the list
                Node_tree OurNode = _Node;
                _Node = _Node->parent;
                while(_Node != TNULL && _Node->right == OurNode)
                {
                    OurNode = _Node;
                    _Node = _Node->parent;
                }
            }
            return *this;

        }
        Red_black_tree_iters &operator-- ()
        {
            if(_Node == nullptr)
            {
                _Node = Red_black_tree->root;
                if(_Node == nullptr)
                {
                    return *this;
                }
                // move to the smallest value in the tree,
                // which is the first node inorder
                while(_Node->right != nullptr)
                {
                    _Node = _Node->right;
                }

            }
            else
                if(_Node->left)
                {
                    _Node = _Node->left;
                    while(_Node && _Node->right)
                    {
                        _Node = _Node->parent;
                    }
            }
            else if(!_Node->left)
            {
                Node_tree OurNode = _Node;;
                _Node = _Node->parent;
                while(_Node && _Node->left == OurNode)
                {
                    OurNode = _Node;
                    _Node = _Node->parent;
                }
            }
            return *this;
        }

        private:
            Node_tree*                                   _Node;




};

};

#endif
