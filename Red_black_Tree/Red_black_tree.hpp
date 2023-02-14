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
            Node *BSTinsert(Node <type_name> *root, Node <type_name> *new_elem)
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
            //******************** rotations 
            // left rotation
            void rotationleft(Node <type_name> &8roor, Node <type_name> *&elem)
            {
                Node *elem_right = elem->right;
                elem->right = elem_right->left;

                if(elem->right != NULL)
                {
                    root = elem_right;
                }else if(elem == elem->parent->left)
                {
                    elem->parent->left = elem_right;
                }else {
                    elem->parent->right = elem->right;
                }
                elem_right->left = elem;
                elem->parent = elem_right;
            }
            // right rotation

            void rotateRight(Node <type_name> *&root, Node <type_name> *&elem)
            {
                Node *elem_left = elem->left;
                elem->left = elem_left->right;
                if(elem->left != NULL)
                {
                    elem->left->parent = elem;
                }
                elem_left->parent = elem->parent;
                if(elem->parent == NULL)
                {
                    root = elem_left;
                }else if(elem == elem->parent->left)
                {
                    elem->parent->left = elem_left;
                }else
                    elem->parent->right = elem_left;

                elem_left->right = elem;
                elem->parent = elem_left;
            }
           //replace function
           // here we didnt just delete (delete_element but we put replace element in delete element place)
            void replace(Node elem_del, Node elem_rep)
            {
                // if it is a root element 
                if(elem_del->parent == NULL)
                {
                    root = elem_rep;
                }
                else if(elem_del == elem_del->parent->left)
                {
                    elem_del->parent->left = elem_rep;
                }else if(elem_del == elem_del->parent->right)
                {
                    elem_del->parent->right = elem_rep;
                }
                elem_rep->parent = elem_del->parent;

            }
            /***********the largest element*/
            Node max_element(Node node)
            {
                while(node->right != NULL)
                {
                    node = node->right;
                }
                return node;
            }

            Node min_element(Node node)
            {
                while(node->left != NULL)
                {
                    node = node->left;
                }
                return node;
            }


            //********Delete in red_black_tree********/
            void delete_node(type_name data)
            {
                 deleteNodeHelp(this->root, data);
            }

            void deleteNodeHelp(Node node, type_name data)
            {
                Node elem_delete = NULL;
                Node x;
                Node node_to_delete;
                // serch about our delete_elem
                while(node != NULL)
                {
                    if(node->data == data)
                    {
                        elem_delete = node;
                    }
                    if(node->data <= data)
                    {
                        node = node->right;
                    }
                    else {
                        node = node->left;
                    }
                }
                if(elem_delete == NULL)
                {
                    cout << "there is no node with this data\n";
                    return ;
                }

                // start instructions to delete 

                /************Hre if it is a leaf node or just have one child*/
                // if delete_elem has no right element so we will replace it with his left element
                node_to_delete = elem_delete;
                if(elem_delete->right == NULL)
                {
                    x = elem_delete->left;
                    replace(elem_delete, elem_delete->left);
                // if our delete_element has no left elem we will replace it by his right element
                }else if(elem_delete->left == NULL)
                {
                    x = elem_delete->right;
                    replace(elem_delete, elem_delete->right);
                }
                // sinon if it hase two shild
                else if(elem_delete->left != NULL && elem_delete->right != NULL)
                {
                    // i choose to go to the left then search for the largest element
                    node_to_delete = min_element(elem_delete->right);

                    if(node_to_delete->parent == elem_delete)
                    {
                        x = large_elem->right;
                    }
                    else if(node_to_delete->parent != elem_delete) 
                    {
                        replace(node_to_delete, node_to_delete->right);
                        node_to_delete->right = elem_delete->right;
                        node_to_delete->right->parent = node_to_delete;

                    }
                    replace(elem_delete, node_to_delete);
                    node_to_delete->left = elem_delete->left;
                    node_to_delete->left->parent = node_to_delete;
                    node_to_delete->color = elem_delete->color;
                }
                delete elem_delete;
                if(node_to_delete->color == false)
                {
                    deleteFix(x);
                }

            }

            // delete fix for red black tree
            
            
            // balance out binary search tree
            void balance_red_black_tree(Node <type_name> *&root, Node<type_name> *&new_elem)
            {
                Node *parent_new = NULL;
                Node *Grand_parent = NULL;
                while((new_elem != root) && (new_elem->color == true) && (new_elem->parent->color == true))
                {
                    parent_new = new_elem->parent;
                    Grand_parent = new_elem->parent->parent;
                    ///*********CASE 1****************=**/
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
                    //if parent of our new element is right child of grand parent
                    else{
                        Node *Uncle = Grand_parent->left;
                        if((Uncle != NULL) && Uncle->color = true)
                        {
                            Grand_parent->color = true;
                            parent->new = false;
                            Uncle->color = false;
                            new_elem = Grand_parent;
                        }else if(Uncle == NULL || Uncle->color = false)
                        {
                            // here again we will have two cases 
                            // if our rotation is(right, left) then we should applicate (RL) rotation

                            if(new_elem = parent_new->left)
                            {
                                rotateRight(root, parent_new);
                                new_elem = parent_new;
                                parent_new = new_elem->parent;
                            }
                            // if our rotation is (right, right) then we should applicate just (L) rotation
                            rotateLeft(root, Grand_parent);
                            //then swap
                            swap(parent_new->color, Grand_parent->color);
                            new_elem = parent_new;
                        }
                    }
                    root->color = false;

                }
            }
            // Insert function
            void insert(type_name data)
            {
                Node *new_elem = new Node(data);
                root = BSTinsert(root, new_elem);
                //balance and check if its red_black_tree
                balance_red_black_tree(root,new_elem);
    
            }



};





}

#endif