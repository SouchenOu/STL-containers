#ifndef RBTREE_HPP
# define RBTREE_HPP

# include <iostream>
# include <memory>
# include <cmath>

# include "enable_if.hpp"
# include "vector_iterator.hpp"
# include "RBTree_iterator.hpp"
# include "equal.hpp"
# include "pair.hpp"

template < class T, class Compare = std::less< T >, class Alloc = std::allocator<T> >
class RBTree
{
    public:
        // VAR TYPES
        typedef T												            value_type;
        typedef Alloc   										            allocator_type;                // container allocator
        typedef Compare                                                     value_compare;                     
        typedef typename allocator_type::pointer				            pointer;
        typedef typename allocator_type::const_pointer			            const_pointer;
        typedef typename allocator_type::reference				            reference;
        typedef typename allocator_type::const_reference		            const_reference;
        typedef treeIterator< T >									        iterator;
        typedef treeIterator< const T >								        const_iterator;
        typedef ft::reverse_iterator< iterator >				            reverse_iterator;
        typedef ft::reverse_iterator< const_iterator >			            const_reverse_iterator;
        typedef std::size_t										            size_type;
        typedef node< value_type >                                          treeNode;
        typedef typename Alloc::template rebind< treeNode >::other	        node_allocator;             // container's element allocator 
    
    private:
        // TREE ELEMENTS
        treeNode                    *NIL;
        treeNode                    *_root;
        size_type                   _height;
        Compare                     _comp;
        node_allocator              _node_alloc;
        allocator_type              _alloc;

    public:
        // CONSTRUCTORS
        explicit RBTree( const value_compare &comp,
                         const allocator_type &alloc )  :   NIL(nilNode()),
                                                            _height(0),
                                                            _comp(comp),
                                                            _alloc(alloc)           {     NIL->color = BLACK; _root = NIL;       };

        RBTree( RBTree const &t ) : NIL(nilNode()),
                                    _root(NIL),                                    
                                    _comp(t._comp),
                                    _alloc(t._alloc)                                {       insert(t.begin(), t.end());          };

        RBTree& operator = ( const RBTree &t )
        {
            if ( this != &t )
            {
                clear(_root);
                insert(t.begin(), t.end());
                _comp = t._comp;
                _alloc = t._alloc;
            }
            return *this;
        };

        ~RBTree( void )                                                             {       clear(_root); delnilNode(NIL);      };

        // [INSERT] ( + newNode() )
        treeNode                    *nilNode( void )
        {
            treeNode    *nilnode = _node_alloc.allocate(1);
            nilnode->left  = NIL;
            nilnode->right = NIL;
            nilnode->parent = 0;
            nilnode->color = BLACK;
            nilnode->leaf = 0;
			return nilnode;
        };


        allocator_type	get_allocator( void ) const					{	return _alloc;	        };

        treeNode*	search(treeNode* to_find, const value_type& val) const
        {
            while (to_find != NIL) 
            {
                if (_comp(val, to_find->value))              	to_find = to_find->left;
                else if (_comp(to_find->value, val))         	to_find = to_find->right;
                else					                        return to_find;
            }
            return 0;
        }

        ft::pair< iterator, bool>    insert( value_type const& value )
        {
            if (_root == NIL) { _root = newNode( value, NIL, 2 );
                                _root->color = BLACK;
                                return ft::make_pair(iterator(_root), true); }
            treeNode    *parent = NIL;
            treeNode    *curr = _root;
            while (curr != NIL)
            { 
                parent = curr;
                if (_comp(value, curr->value))              
                    curr = curr->left;
                else if (_comp(curr->value, value))
                    curr = curr->right;
                else                                        
                    return ft::make_pair(iterator(curr), false);                         
            }
            curr = newNode( value, parent, 1 );
            if (_comp(value, parent->value))             parent->left = curr;
            else                                         parent->right = curr;
            curr->left->parent  = curr;
            curr->right->parent = curr;
            rebalanceTree4insert(curr);
            return ft::make_pair(iterator(curr), true);
        };

        iterator 				insert(iterator position, const value_type& value)      {       return insert(value).first; (void)position;                     };
		
        template <class InputIterator>
	    void					insert(InputIterator first, InputIterator last)         {       while (first != last)   { insert(*first); first++; }            }; 

        // [ERASE] ( + delNode() )
        size_type 				erase(value_type const &val)
        {
            	treeNode	*to_del = search(_root, val);
		        if (!to_del)
                    return 0;
		        erase(to_del);
		        return 1;
        }

        void 				erase(treeNode *node)
        {
                treeNode    *to_del = node;
                treeNode    *to_fix;
                int originColor = node->color;
                if (node->left == NIL)
                {
                    to_fix = node->right;
                    transplantNode(node, node->right);
                }
                else if (node->right == NIL)
                {
                    to_fix = node->left;
                    transplantNode(node, node->left);
                }
                else
                {
                    to_del = min(node->right); //min
                    originColor = to_del->color;
                    to_fix = to_del->right;
                    if (to_del->parent == node) to_fix->parent = to_del; // to check
                    else
                    {
                        transplantNode(to_del, to_del->right);
                        to_del->right = node->right;
                        to_del->right->parent = to_del;
                    }
                    transplantNode(node, to_del);
                    to_del->left = node->left;
                    to_del->left->parent = to_del;
                    to_del->color = node->color;
                }
                if (originColor == BLACK)
                    rebalanceTree4erase(to_fix);
                delNode(node);
        };
		void 					erase(iterator first, iterator last)                    {       while (first != last)   erase(*first++);	        };

        // [FIND] + search

        iterator    find(const value_type& val) const
        {
            treeNode*	node = search(_root, val);
            if (node)
                return iterator(node);
            return iterator(max(_root));
        }

        // CLEAR
        // clear the tree in postorder trasversal (left, right, root)
        void        clear(treeNode *root)
        {
        	if (root && root->leaf)
            {
                clear(root->left);
                clear(root->right);
                delNode(root);
            }
            _root = NIL;            
        }
        
        // capacity
        bool        empty( void ) const             {       return _height == 0;                     };
        size_type   size( void )  const             {       return _height;                          };
	    size_type	max_size() const	            {       return _node_alloc.max_size();           };

        // iterators
        iterator				begin( void )
        {
            if (_root == NIL)		return iterator(NIL);
            treeNode* first = _root;
            while (first && first->left != NIL) { first = first->left; }
            return iterator(first);
        }
        const_iterator			begin( void ) const
        {
            if (_root == NIL || !_root)  return iterator(NIL);
            treeNode* first = _root;
            while (first && first->left != NIL) first = first->left;
            return iterator(first);
        }
        iterator				end()				{       return iterator(max(_root));                    }
        const_iterator			end() const			{       return iterator(max(_root));                    }
        reverse_iterator		rbegin()			{       return reverse_iterator(end());                 }
        const_reverse_iterator	rbegin() const		{       return reverse_iterator(end());                 }
        reverse_iterator		rend()				{       return reverse_iterator(begin());               }
        const_reverse_iterator	rend() const		{       return reverse_iterator(begin());               }

        void	swap( RBTree &t ) {
			ft::swap(NIL, t.NIL);
			ft::swap(_root, t._root);
			ft::swap(_alloc, t._alloc);
			ft::swap(_node_alloc, t._node_alloc);
			ft::swap(_comp, t._comp);
			ft::swap(_height, t._height);
		}

            treeNode* lower_bound (const value_type& value) const
        {
            treeNode*	node = _root;
            treeNode*	lower = NIL;
        
            while (node != NIL)
            {
                if (!_comp(node->value, value))
                    {       lower = node; node = node->left;        }
                else         node = node->right;
            }
            return lower;
        };

        treeNode* upper_bound (const value_type& value) const
        {
            treeNode*	node = _root;
            treeNode*	upper = NIL;
        
            while (node != NIL)
            {
                if (_comp(value, node->value))
                    {       upper = node; node = node->left;        }
                else        node = node->right;
            }
            return upper;
        };

        treeNode    *get_root()    const                         {           return _root;      };

    private:
        treeNode                    *newNode( value_type const& value, treeNode *parent, int leaf )
        {
            treeNode    *newnode = _node_alloc.allocate(1);
            _alloc.construct(&(newnode->value), value);
            newnode->left  = NIL;
            newnode->right = NIL;
            newnode->parent = parent;
            newnode->color = RED;
            newnode->leaf = leaf;
            _height++;
			return newnode;
        };

        void        delNode(treeNode *node)
        {              
            _alloc.destroy(&(node->value));  
            _node_alloc.deallocate(node, 1); 
            _height--;
        }

        void        delnilNode(treeNode *node)
        {              
            _node_alloc.deallocate(node, 1); 
            _height--; 
        }

        // min, max
        treeNode    *min(treeNode* node) const      {       while (node->left != NIL)       {   node = node->left;      }    return node;        };
        treeNode    *max(treeNode* node) const      {       while (node && node->leaf)      {   node = node->right;     }    return node;        };

        // debugging
        void inorder(treeNode* root)
        {
            if (root != NIL)
            {
                inorder(root->left);
                std::cout << root->value.second << " ";
                inorder(root->right);          
            }
        };

        void    leftRotate(treeNode    *node)
        {
            treeNode    *tmp = node->right;
            node->right = tmp->left;
            if (tmp->left != NIL)
                tmp->left->parent = node;
            tmp->parent = node->parent;
            if (node->parent == NIL)
                _root = tmp;
            else if (node == node->parent->left)
                node->parent->left = tmp;
            else
                node->parent->right = tmp;
            tmp->left = node;
            node->parent = tmp;
        }

        void    rightRotate(treeNode *node)
        {
            treeNode    *tmp = node->left;
            node->left = tmp->right;
            if (tmp->right != NIL)
                tmp->right->parent = node;
            tmp->parent = node->parent;
            if (node->parent == NIL)
                _root = tmp;
            else if (node == node->parent->right)
                node->parent->right = tmp;
            else
                node->parent->left = tmp;
            tmp->right = node;
            node->parent = tmp;
        }

        void        recolorNode(treeNode *node)                     {          node->color == RED ? node->color = BLACK : node->color = RED;                        };        
        void        transplantNode(treeNode *a, treeNode *b)
        {
            if (a->parent == NIL)       _root = b;
            else if (a == a->parent->left)  a->parent->left = b;
            else                            a->parent->right = b;
            b->parent = a->parent;
        };

        treeNode	*replaceNode(treeNode *node)
            {
                if (!node || (!node->left && !node->right))         return 0;
                if (node->left && node->right)  			return successor(node->right);
            if (node->right)  return node->left;
                return node->right;
            };
        // find first node which has no left child
        treeNode    *successor(treeNode *n)                             {          treeNode *tmp = n; while (tmp->left != NULL) tmp = tmp->left;   return tmp;          };
  
        void    rebalanceTree4insert(treeNode *node)
        {
            while (node != _root && node->parent->color == RED)
            {
                treeNode    *grandmaNode = node->parent->parent;
                if (node->parent == grandmaNode->right)
                {
                    treeNode    *uncleNode = grandmaNode->left;
                    if (uncleNode->color == RED)
                    {
                        uncleNode->color = BLACK;
                        node->parent->color = BLACK;
                        grandmaNode->color = RED;
                        node = grandmaNode;
                    }
                    else
                    {
                        if (node == node->parent->left)
                        {
                            node = node->parent;
                            rightRotate(node);
                        }
                        node->parent->color = BLACK;
                        grandmaNode->color = RED;
                        leftRotate(grandmaNode);
                    }
                }
                else
                {
                    treeNode    *uncleNode = grandmaNode->right;
                    if (uncleNode->color == RED)
                    {
                        uncleNode->color = BLACK;
                        node->parent->color = BLACK;
                        grandmaNode->color = RED;
                        node = grandmaNode;
                    }
                    else
                    {
                        if (node == node->parent->right)
                        {
                            node = node->parent;
                            leftRotate(node);
                        }
                        node->parent->color = BLACK;
                        grandmaNode->color = RED;
                        rightRotate(grandmaNode);
                    }
                }                
            }
            _root->color = BLACK;
        };

        void    rebalanceTree4erase(treeNode *node)
        {
            while (node != _root && node->color == BLACK)
            {
                if( node == node->parent->left)
                {
                    treeNode *sibling = node->parent->right;
                    if (sibling->color == RED)
                    {
                        recolorNode(sibling); //b
                        node->parent->color = RED; 
                        leftRotate(node->parent);
                        sibling = node->parent->right;
                    }
                    if (sibling->left->color == BLACK && sibling->right->color == BLACK)
                    {
                        sibling->color = RED;
                        node = node->parent;
                    }
                    else
                    {
                        if (sibling->right->color == BLACK)
                        {
                            sibling->left->color = BLACK;
                            sibling->color = RED;
                            rightRotate(sibling);
                            sibling = node->parent->right;
                        }
                        sibling->color = node->parent->color;
                        node->parent->color = BLACK;
                        sibling->right->color = BLACK;
                        leftRotate(node->parent);
                        node = _root;
                    }
                }
                else
                {
                    treeNode *sibling = node->parent->left;
                    if (sibling->color == RED)
                    {
                        recolorNode(sibling);
                        node->parent->color = RED;
                        rightRotate(node->parent);
                        sibling = node->parent->left;
                    }
                    if (sibling->right->color == BLACK && sibling->left->color == BLACK)
                    {
                        sibling->color = RED;
                        node = node->parent;
                    }
                    else 
                    {
                        if (sibling->left->color == BLACK)
                        {
                            sibling->right->color = BLACK;
                            sibling->color = RED;
                            leftRotate(sibling);
                            sibling = node->parent->left;
                        }
                        sibling->color = node->parent->color;
                        node->parent->color = BLACK;
                        sibling->left->color = BLACK;
                        rightRotate(node->parent);
                        node = _root;
                    }
                }
            }
            node->color = BLACK;
        };
};

#endif
