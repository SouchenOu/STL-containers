/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:35:55 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iterator>
# include <algorithm>


#include "../Red_black_Tree/Red_black_tree.hpp"
#include "../Red_black_Tree/Red_black_tree_iter.hpp"
#include "../pair.hpp"
#include "../vector/vector_iterator.hpp"
#include "../vector/vector_reverse_iterator.hpp"


namespace ft
{
    template<class Key, class T, class Compare = std::less< Key>,class Allocator = std::allocator<std::pair<const Key,T>>>
    class map
    {
        public:
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef ft::pair<const Key_type,mapped_type>                        value_type;
            typedef Compare                                                     key_compare;
            typedef Allocator                                                   allocator_type;
            typedef value_type&                                                 reference;
            typedef const value_type&                                           const_reference;
            //Member class: i declared it here because if i put our class directly here we told me that 
            // value_type is undefined 
            class                                                                value_compare;
        
            typedef typename allocator_type::pointer                             pointer;
            typedef typename allocator_type::const_pointer                       const_pointer;
            typedef typename allocator_type::size_type                           size_type;
            typedef typename iterator_traits<iterator>::difference_type          difference_type

            // typedef typename allocator_type::reference                            reference;
            // typedef typename allocator_type::const_reference                      const_reference;
        private:
            typedef Red_black_tree<value_type, value_compare, allocator_type>                     Ttree;

        public:
            typedef typename Red_black_tree::iterator                              iterator;
            typedef typename Red_black_tree::const_iterator                        const_iterator;
            typedef ft::reverse_iterator <iterator>                                reverse_iterator;
            typedef ft::reverse_iterator <const_iterator>                          const_reverse_iterator;


            typedef Node <value_type>                                               Node;

        private:

            Ttree                       _R_B_Ttree;
            key_compare                 _compare;
            allocator_type              _alloc;

        // Member classes
        public:
            class value_compare
            {
                friend class map;
                protected:
                    key_compare comp;
                    value_compare(key_compare c)
                    {
                        comp(c);
                    }
                public:
                    bool operator()(const value_type& __x, const value_type& __y)const
                    {
                        return comp(__x.first, __y.first);
                    }
            };    
            // ***********Member functions:

            // constructers:
            //default constructer
            //map(){}
            //constructer with parameters
            explicit map(const key_compare & __comp = key_compare(), const allocator_type& __a  = allocator_type())
            {
                    _compare(__comp);
                    _alloc(__a);
                    _R_B_Ttree(__comp);
            }
            
            // copy constructer

            map(map const & obj)
            {
                 _R_B_Ttree(obj._R_B_Ttree);
                 _compare(obj._compare);
                 _alloc(obj._alloc);
            }

            // template <class _InputIterator>
            map(_InputIterator _first, _InputIterator _last, const key_compare& _comp = key_compare())
            {
                    _R_B_Ttree(_comp);
                    insert(_first, _last);
            }
            template <class _InputIterator>
            map(_InputIterator _first, _InputIterator _last, const key_compare& _comp = key_compare(), const allocator_type& __alloc = allocator_type())
            {
                _R_B_Ttree(_comp);
                _alloc(__alloc);
                _R_B_Ttree.insert(_first,_last);
            }
            // //Assignement operator

            map& operator=(const map& obj)
            {
                _R_B_Ttree(obj._R_B_Ttree);
                if(this != &obj)
                {
                    _R_B_Ttree(obj._R_B_Ttree);
                    _compare = obj._compare;
                    _alloc = obj._alloc;
                }
                return *this;
            }
            ~map(){}

            allocator_type get_allocator() const
            {
                return _R_B_Ttree._alloc;
            }

            //Element access
            // mapped_type& operator[](const key_type& )
            // {
            //     // Overloading [] operator to access elements in array style
            // }
            mapped_type& 	operator[] ( const key_type& key )
            {	
                return (*(insert(ft::make_pair( key, mapped_type() )).first)).second;			
            };


            //*******Modifiers
            // ft::pair<iterator, bool> insert (value_type const &_value)
            // {
            //         return _R_B_Ttree.insert(_value);
            // }
            iterator insert(const_iterator __pos, value_type &value)
            {
                return _R_B_Ttree.insert(__pos, value);
            }
            // template <class _InputIterator>
            // void insert(_InputIterator first, _InputIterator last)
            // {
            //     R_B_Ttree.insert(first, last);
            // }


                //************ Iterators
                iterator begin()
                {
                    return _R_B_Ttree.begin();
                }
                const_iterator cbegin() const 
                {
                    return _R_B_Ttree.cbegin();
                }
                iterator cend()
                {
                    return _R_B_Ttree.cend();
                }
                const_iterator end()
                {
                    return _R_B_Ttree.end();
                }
                reverse_iterator rbegin()
                {
                    return _R_B_Ttree.rbegin();
                }
                reverse_iterator rend()
                {
                    return _R_B_Ttree.rend();
                }



            //************ //Capacity
            // bool empty() const
            // {
            //     return _R_B_Ttree.empty();
            // }
            // size_type size() const{
            //     return _R_B_Ttree.size();
            // }

            // szie_type max_size() const{
            //     return _R_B_Ttree.max_size();
            // }

            





        

    };
			 		 
	
}

#endif



