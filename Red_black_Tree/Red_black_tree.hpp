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
# include <string>

# include "Red_black_tree_iter.hpp"
# include "../vector/vector_iterator.hpp"
# include "../vector/vector_reverse_iterator.hpp"
# include "../pair.hpp"
# include "../make_pair.hpp"
# include "../lexicographical_compare.hpp"
# include "../equal.hpp"
# include "../enable_if.hpp"


using namespace std;
namespace ft{


    #define red     1   
    #define black   0

    
    template < class T, class Compare = std::less< T >, class Alloc = std::allocator<T> >
    class Red_black_tree
    {
        public:
            typedef T                                                  value_type;
            typedef Alloc                                              allocator_type;
            typedef Compare                                            value_compare;
            typedef std::size_t                                        size_type;
            typedef Node<value_type>                                   type_name;


             typedef typename allocator_type::pointer                   pointer;
             typedef typename allocator_type::const_pointer             const_pointer;
             typedef typename allocator_type::reference                 reference;
             typedef typename allocator_type::const_reference           const_reference;

             typedef Red_black_tree_iters <T>                           iterator;
             typedef Red_black_tree_iters <const T>                     const_iterator;
             typedef ft::reverse_iterator <iterator>                    reverse_iterator;
             typedef ft::reverse_iterator <const_iterator>              const_reverse_iterator;
             typedef typename Alloc::template rebind< type_name >::other   node_alloc;
            


        public:
            type_name       *root;
            type_name       *TNULL;
            Compare         _comp;
            allocator_type _alloc;
            size_type      NBnode;
            node_alloc      For_allocation_Node;
          
            

        public:
        //********constructers
        //default constructor
            // Red_black_tree(void):TNULL(TNULLNode()),_comp(),_alloc(),NBnode(0){
            //     std::cout << "out here\n";
            // }
            // explicit Red_black_tree(const value_compare& __comp):_comp(__comp){}
            // explicit Red_black_tree(const allocator_type& __a):_alloc(__a){}
            explicit Red_black_tree(const value_compare& __comp, const allocator_type& __a):TNULL(TNULLNode()),_comp(__comp),_alloc(__a),NBnode(0)
            {
                
                
                root = TNULL;
                TNULL->color = 0;
            }
            // copy constructor
            explicit Red_black_tree(Red_black_tree const &tree):TNULL(TNULLNode()),_comp(tree._comp),_alloc(tree._alloc),root(TNULL)
            {     
                    insert(tree.begin(), tree.end());
            }
           
            //Assignement operator
            Red_black_tree& operator=(Red_black_tree const &tree)
            {
                if(this == &tree)
                {
                    return *this;
                }
                _comp = tree._comp;
                _alloc = tree._alloc;
                insert(tree.begin(), tree.end());

            }
            ~Red_black_tree(){ clear(root);}

            //getters
            type_name get_root() const
            {
                return root;
            }
            type_name *TNULLNode()
            {
                type_name *node_new =  For_allocation_Node.allocate(1);
                node_new->color = 0;
                node_new->left = nullptr;
                node_new->right = nullptr;
                node_new->parent = 0;
                node_new->leaf = 0;
                //node_new->data = 0;
                //root=node_new;
                return node_new;
            }
            void clear(type_name *root)
            {
                if(root)
                {
                    clear(root->left);
                    clear(root->right);
                }
                root = TNULL;
            }
            void delete_node(type_name *Node)
            {
                 _alloc.deallocate(Node, 1);
                  For_allocation_Node.dealocate(Node, 1);
                  NBnode--;

            }
            
            //Method 2
            void rotateleft(type_name *node)
            {
                type_name *r = node->right;
                node->right = r->left;
                if(r->left != TNULL)
                {
                    r->left->parent = node;
                }
                r->parent = node->parent;
                if(node->parent == TNULL)
                {
                    this->root = r;
                   
                }
                else if(node == node->parent->left)
                {
                    node->parent->left = r;
                }else if(node == node->parent->right)
                {
                    node->parent->right = r;
                }
                r->left = node;
                node->parent = r;
            }
            void rotateRight(type_name *node)
            {
                type_name *l = node->left;
                node->left = l->right;
                if(l->right != TNULL)
                {
                    l->right->parent = node;
                }
                l->parent = node->parent;
                if(node->parent == nullptr)
                {
                    this->root = l;

                }else if(node == node->parent->right)
                {
                    node->parent->right = l;

                }else if(node == node->parent->left)
                {
                    node->parent->left = l;
                }
                l->right = node;
                node->parent = l;
            }
           //replace function
           // here we didnt just delete (delete_element but we put replace element in delete element place)
            void replace(type_name *elem_del, type_name *elem_rep)
            {
                // if it is a root element 
                if(elem_del->parent == nullptr)
                {
                    root = elem_rep;
                }
                else if(elem_del == elem_del->parent->left)
                {
                    elem_del->parent->left = elem_rep;
                }else
                {
                    elem_del->parent->right = elem_rep;
                }
                
                elem_rep->parent = elem_del->parent;
            }
            /***********the largest element*/
            type_name *max_element(type_name *node)
            {
                while(node->right != NULL)
                {
                    node = node->right;
                }
                return node;
            }

            type_name *min_element(type_name *node)
            {
                while(node->left != NULL)
                {
                    node = node->left;
                }
                return node;
            }

            //delete fix for red black tree
            void deletefix(type_name *node)
            {
                type_name *suibling;
                
                while(node != root && node->color == 0)
                {
                    if(node == node->parent->left)
                    {
                        //his brother
                        suibling = node->parent->right;
                        //**case 1: if the suibling of the node with color red then (1:swap colors of parent and sibling /2: rotate parent in dableBlack direction/3:is still DableBlack exist apply cases again)
                        if(suibling->color == 1)
                        {
                            suibling->color = 0;
                            // if(node->parent->color == 1)
                            //     node->parent->color = 0;
                            // else if(node->parent->color == 0)
                            // {
                            //     node->parent->color = 1;
                            // }
                            node->parent->color = 1;
                            rotateleft(node->parent);
                            suibling = node->parent->right;
                        }
                        //** case 2: if the suibling and his child are black
                        if(suibling->left->color == 0 && suibling->right->color == 0)
                        {
                            suibling->color = 1;
                            node = node->parent;
                        //** case 3: if the suibling is black and the near child is red and the far child is black
                        }else 
                        {
                                if(suibling->right->color == 0)
                                {
                                    suibling->left->color = 0;
                                    suibling->color = 1;
                                    rotateRight(suibling);
                                    suibling = node->parent->right;
                                }
                                //case 4:
                                suibling->color = node->parent->color;
                                node->parent->color = 0;
                                suibling->right->color = 0;
                                rotateleft(node->parent);
                                node = root;
                        }       
                    }
                    else if(node == node->parent->right)
                    {
                        suibling = node->parent->left;
                        if(suibling->color == 1)
                        {
                            suibling->color = 0;
                            //node->color = 0;
                            node->parent->color = 1;
                            rotateRight(node->parent);
                            suibling = node->parent->left;
                        }
                        if(suibling->right->color == 0 && suibling->left->color == 0)
                        {
                            suibling->color = 1;
                            node = node->parent;
                        }else
                        {
                            if(suibling->left->color== 0)
                            {
                                suibling->right->color = 0;
                                suibling->color = 1;
                                rotateleft(suibling);
                                suibling = node->parent->left;
                            }
                            suibling->color = node->parent->color;
                            node->parent->color = 0;
                            suibling->left->color = 0;
                            rotateRight(node->parent);
                            node = root;
                        }
                    }
                }
                node->color = 0;
            }
            //********Delete in red_black_tree********/
            void delete_node(value_type data)
            {
                 deleteNodeHelp(this->root, data);
            }

            void deleteNodeHelp(type_name *node, value_type data)
            {
                type_name *elem_delete = TNULL;
                type_name *x;
                type_name *node_to_delete;
                // search about our delete_elem
                while(node != TNULL)
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
                if(elem_delete == TNULL)
                {
                    cout << "there is no node with this data\n";
                    return ;
                }

                // start instructions to delete 

                /************Here if it is a leaf node or just have one child*/
                // if delete_elem has no right element so we will replace it with his left element
                node_to_delete = elem_delete;
                bool orig_color = node_to_delete->color;
                if(elem_delete->left == TNULL)
                {
                    x = elem_delete->right;
                    replace(elem_delete, elem_delete->right);
                }
                //if our delete_element has no left elem we will replace it by his right element
                else if(elem_delete->right == TNULL)
                {
                    x = elem_delete->left;
                    replace(elem_delete, elem_delete->left);
                }
                
                
                else
                {
                    // i should shoose which path to follow ( right or left) 
                    // i choose to go to the right then search for the smallest element
                    node_to_delete = min_element(elem_delete->right);
                    orig_color = node_to_delete->color;
                    x = node_to_delete->right;


                    if(node_to_delete->parent == elem_delete)
                    {
                        x->parent = node_to_delete;
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
                if(node_to_delete->color == 0)
                {
                    deletefix(x);
                }
                

            }

            type_name *NewNode(value_type const& data, type_name *parent, int leaf)
            {
                type_name  *new_node = For_allocation_Node.allocate(1);
                _alloc.construct(&(new_node->data), data);
                new_node->left = TNULL;
                new_node->right = TNULL;
                new_node->parent = parent;
                new_node->color = 1;
                new_node->leaf = leaf;
                NBnode++;
                return new_node;

            }
           
            //****insert method 2:
            ft::pair<iterator, bool> insert(value_type const& data)
            {
                // type_name *node = new type_name;
                // node->parent = nullptr;
                // node->data = data;
                // node->left = TNULL;
                // node->right = TNULL;
                // node->color = 1;
                //std::cout << data << "\n";
                type_name *y = TNULL;
                type_name *x = root;
                
                // while root exist
                //looking for position of newNode
                while(x != TNULL)
                {
                    y = x;
                    if(data < x->data)
                    {
                        x = x->left;
                    }else if(data > x->data)
                    {
                        x = x->right;
                    }
                    else if(data == x->data)
                    {
                        return ft::make_pair(iterator(x), false);
                    }
                }
                //node->parent = y;
                // our tree is empty
                if(y == TNULL)
                {
                    root = NewNode(data,TNULL,2);
                    root->color = 0;
                    return ft::make_pair(iterator(root),true);
                }
                x = NewNode(data,y,1);
                if(data < y->data)
                {
                    y->left = x;
                }else if(data > y->data)
                {
                    y->right = x;
                }

                if(x->parent == root)
                {
                    return ft::make_pair(iterator(x),true);
                }
                insert_fix(x);
                
                return ft::make_pair(iterator(x),true);

            }
        


            // insert functions
            iterator insert (const_iterator key, const value_type &value)
            {
                (void) key;
                return insert(value).first;

            }
            template<class _InputIterator>
            void insert(_InputIterator first, _InputIterator second)
            {
                while(first != second)
                {
                    insert(*first);
                    first++;
                }
            }
            
            void insert_fix(type_name *node)
            {
                type_name *uncle;
                //until parent color of our node is red 
                while(node->parent->color == 1)
                {
                    // if the parent of our node is the right shild of his parent
                    if(node->parent == node->parent->parent->right)
                    {
                        uncle = node->parent->parent->left;
                        if(uncle->color == 1)
                        {
                            uncle->color = 0;
                            node->parent->color = 0;
                            //condition root
                            node->parent->parent->color = 1;
                            node = node->parent->parent;
                        }else if(uncle->color == 0)
                        {
                            if(node == node->parent->left)
                            {
                                node = node->parent;
                                rotateRight(node);
                            }
                            node->parent->color = 0;
                            node->parent->parent->color = 1;
                            rotateleft(node->parent->parent);
                        }
                    // if the parent of our node is the left child of his parent
                    }else if(node->parent == node->parent->parent->left)
                    {
                        uncle = node->parent->parent->right;

                        if(uncle->color == 1)
                        {
                            uncle->color = 0;
                            node->parent->color = 0;
                            node->parent->parent->color = 1;
                            node = node->parent->parent;
                            
                        }else if(uncle->color == 0)
                        {
                            if(node == node->parent->right)
                            {
                                node = node->parent;
                                rotateleft(node);
                            }
                            node->parent->color = 0;
                            node->parent->parent->color = 1;
                            rotateRight(node->parent->parent);
                        }
                    }

                    if(node == root)
                    {
                        break ;
                    }
                }
                root->color = 0;
            }

          //erase

          size_type erase(value_type const &value)
          {
            type_name *del_node = search(root,value);
            if(del_node)
                delete_node(del_node->data);
            else if(!del_node)
                return 0;
            return 1;
          }
          void erase(iterator first, iterator second)
          {
                while(first != second)
                    erase(*first++);
          }
          
          // find
            iterator find(const value_type& value) const
            {
                type_name *node = search(root, value);
                if(node)
                    return iterator(node);
                return iterater(max_element(root));
            }   

            void printHelper(type_name *root, string txt, int i)
            {
                string color;
                if(root != TNULL)
                {
                    cout << txt;
                    if(i == 1)
                    {
                        cout << "R***";
                        txt = txt + "   ";

                    }else if( i == 0)
                    {
                        cout << "L***";
                        txt = txt + "|   ";
                    }
                    if(root->color == 1)
                    {
                        color = "Red";
                    }else if(root->color == 0)
                    {
                        color = "Black";
                    }
                    cout << root->data << "{" << color << "}" << endl;
                    printHelper(root->left, txt, 0);
                    printHelper(root->right, txt, 1);
                }
            }
            // print our tree
            void printTree()
            {
                if(root)
                {
                    printHelper(root, "", 1);
                }
            
            }

            //Capacity

            bool empty() const
            {
                if(NBnode == 0)
                    return 1;
                else if(NBnode != 0)
                {
                    return 0;
                }

            }
            size_type size()
            {
                return NBnode;
            }
            size_type max_size(){}

            //iterators
            iterator begin()
            {
                type_name *First_elem;
                if(root == TNULL)
                {
                    return iterator(TNULL);
                }
                First_elem = root;
                // std::cout << "testing here\n";
                // std::cout << "data-->"<<First_elem->data << std::endl;
                // std::cout << "his right-->"<<First_elem->right->data << std::endl;
                // std::cout << "his left-->"<<First_elem->right->right->data << std::endl;
                while(First_elem != TNULL && First_elem->left != TNULL)
                {
                    First_elem = First_elem->left;
                }
                return iterator(First_elem);

            }
            const_iterator begin() const
            {
                type_name *First_elem;
                if(root == TNULL)
                {
                    return iterator(TNULL);
                }
                First_elem = root;
                while(First_elem != TNULL && First_elem->left != TNULL)
                {
                    First_elem = First_elem->left;
                }
                return iterator(First_elem);
            }
            iterator end()
            {
                type_name *last_elem;
                if(root == TNULL)
                {
                    return iterator(TNULL);
                }
                last_elem = root;
                while(last_elem != TNULL && last_elem->leaf)
                {
                    last_elem = last_elem->right;
                }
                return iterator(last_elem);
            }
            const_iterator end() const
            {
                type_name *last_elem;
                if(root == TNULL)
                {
                    return iterator(TNULL);
                }
                last_elem = root;
                while(last_elem != TNULL && last_elem->right!= TNULL)
                {
                    last_elem = last_elem->right;
                }
                return iterator(last_elem);
            }
            reverse_iterator rbegin() {
                return reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rbegin() const
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rend() const
            {
                return reverse_iterator(begin());
            }

            //search function
            type_name *search(type_name *node, const value_type& value)
            {
                while(node != TNULL)
                {
                    if(value < node->data)
                    {
                        node = node->left;
                    }else if(value > node->data)
                    {
                        node = node->right;
                    }else
                        return node; 

                }
                return 0;
            }

            // lower_bound && upper_bound
            type_name *lower_bound(const value_type& value)
            {
                type_name *node = root;
                type_name *lower_node = TNULL;
                while(node != TNULL)
                {
                    if(node->data == value)
                    {
                        lower_node = node;
                        node = node->left;
                    }else
                        node = node->right;
                }
                return lower_node;
            }
            type_name *upper_node(const value_type& value)
            {
                type_name *node = root;
                type_name *upper_node = TNULL;

                while(node != TNULL)
                {
                    if(value == node->data)
                    {
                        upper_node = node;
                        node= node->left;
                    }else
                        node = node->right;
                }
                return upper_node;
            }



};

// template<class T, class Allocation>
// ostream& operator<<(ostream& os, const Red_black_tree<T, Allocation>& tree)
// {
//     os << tree.root->data << endl;
// }








}

#endif