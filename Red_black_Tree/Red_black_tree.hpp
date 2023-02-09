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


    #define red     true
    #define black   false
    
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

                Node *parent_new = NULL;
                Node *Grand_parent = NULL;
                while((new_elem != root) && (new_elem->color == true) && (new_elem->parent->color == true))
                {
                    parent_new = new_elem->parent;
                    Grand_parent = new_elem->parent->parent;
                    ///*********CASE 1******************/
                    // the first case is if parent of the new element is left child of grand_parent
                    if(parent_new == Grand_parent->left)
                    {
                        Node *Uncle = Grand_parent->right;
                        // here we should check two cases 
                        // if the color of uncle is red then recolor 
                        // if the color of uncle is black or if the uncle nexiste pas the do suitable rotation and recolor
                        if(Uncle != NULL &&  Uncle->color == true)
                        {
                            Grand_parent->color = true;
                            parent_new->color = false;
                            Uncle->color = false;
                            new_elem = Grand_parent;
                        }else if(Uncle == NULL || Uncle->color = false)
                        {
                            // then check the position of new element
                            // if our newElem is right elem of the parent of new_elem (that means that we need--> LR rotation)
                            // if our newElem is left elem of the parent of new_elem (that means we need just right rotation (because we have left, left)) 
                            if(new_elem == parent_new->right)
                            {
                                rotateLeft(root,parent_new);
                                new_elem = parent_new;
                                parent_new = new_elem->parent;
                            }
                                rotateRight(root, Grand_parent);
                                //then swap
                                swap(parent_new->color, Grand_parent->color);
                                new_elem = parent_new;
                        }

                    }
                    //**************Case 2****************/

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