/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:34:07 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:34:09 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP




# include <iostream>
# include <memory>
# include <cmath>
namespace ft{


    #define red true
    #define black false
    template < class T >
    struct Node
    {
        typedef T   type_name;
        type_name   data;
        bool        color;
        Node        *left;
        Node        *right;
        Node        *parent;

        //constructer
        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
            parent = NULL;
            this->color = red;
        }
    };
    // class to represent red-black tree
    template < typename T>
    class Red_black_tree
    {
        private:
            Node *root;
        public:
            Red_black_tree()
            {
                root = NULL;
            }
            //Insert binary search tree
            Node *BSTinsert(Node *root, Node *new_elem)
            {
                // if our tree is empty
                if(root == NULL)
                {
                    return new_elem;
                }
                if(new_elem->data < root->data)
                {
                    root->left = BSTinsert(root->left, new_elem);
                    root->left->parent = root;
                }
                else if(new_elem->data > root->data)
                {
                    root->right = BSTinsert(root->right, new_elem);
                    root->right->parent = root;
                }
                return root;
            }
            // balance out binary search tree
            void balance_red_black_tree(Node *&root, Node *&new_elem)
            {
                while((new_elem != root) && (new_elem->color == true) && (new_elem->parent->color == true))
                {
                    // the first case is if parent of the new element is left child of grand_parent
                    if(new_elem->parent == new_elem->parent->parent->left)
                    {
                        Node *Uncle = new_elem->parent->parent->right;
                        // here we should check two cases 
                        // if the color of uncle is red then recolor 
                        // if the clor of uncle is black or if the uncle nexiste pas the do suitable rotation and recolor
                        if(Uncle != NULL &&  Uncle->color == true)
                        {
                            new_elem->parent->parent->color = true;
                            new_elem->parent->color = false;
                            Uncle->color = false;
                            new_elem = new_elem->parent->parent;
                        }else if(Uncle == NULL || Uncle->color = false)
                        {
                            
                        }

                    }

                }
            }
            // Insert function
            void insert(Node <type_name> data)
            {
                Node *new_elem = new Node(data);
                root = BSTinsert(root, new_elem);
                //balance and check if its red_black_tree
                balance_red_black_tree(root,new_elem);
    
            }



};





}

#endif
