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


namespace ft
{
    template<class Key, class T, class Compare = std::less< Key>,class Allocator = std::allocator<std::pair<const Key,T>>>
    class map
    {
        public:
            typedef T                                           mapped_type;
            typedef Key                                         key_type;
            typedef std::pair<const Key, T>                     value_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            typedef size_t                                      size_type;
        
        
        
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename  allocator_type::pointer                   pointer;
            typedef typename  allocator_type::const_pointer             const_pointer;
    
            typedef typename Red_black_tree::iterator             iterator;
            typedef typename Red_black_tree::const_iterator       const_iterator;

            typedef Node <value_type>               Node;

        private:

            Red_black_tree              _tree;
            key_compare                 _compare;
            allocator_type              _alloc;

        // Member classes

        class value_compare
        {
            friend class map;
            protected:
                key_compare comp;
            value_compare(key_compare c)
            {
                comp(c);
            }
            bool operator()(const value_type& __x, const value_type& __y)const
            {
                return comp(__x.first, __y.first);
            }
        }        
            // Member functions:

            // constructers:
            map(){}
            explicit map(const key_compare & __comp, const allocator_type& __a)
            {
                    _compare(comp);
                    _alloc(a);
            }


    };
			 		 
	
}

#endif



