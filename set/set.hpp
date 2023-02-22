/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:18:26 by souchen           #+#    #+#             */
/*   Updated: 2023/02/22 09:18:27 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "../Red_black_Tree/Red_black_tree.hpp"
#include "../Red_black_Tree/Red_black_tree_iter.hpp"
#include "../vector/iterators_traits.hpp"
#include "../vector/vector_iterator.hpp"
#include "../vector/vector_reverse_iterator.hpp"
#include "../pair.hpp"
#include "../make_pair.hpp"



#ifndef SET_HPP
#define SET_HPP


namespace ft{
template <class _Key, class _Compare = std::less<_Key>, class _Allocator = std::allocator<_Key> >

class set
{
    public:
        typedef _Key                key_type;
        typedef key_type            value_type;
        typedef _Compare            key_compare;
        typedef key_compare         value_compare;
        typedef _Allocator          allocator_type;
        // typedef value_type&         reference;
        // typedef const value_type&   const_reference;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef             size_t                          size_t;

    private:
            typedef Red_black_tree<value_type, value_compare, allocator_type> _R_B_Ttree;
   
    public:
            typedef typename _R_B_Ttree::iterator                                       iterator;
            typedef typename _R_B_Ttree::const_iterator                                 const_iterator;
            typedef ft::reverse_iterator < iterator >                                   reverse_iterator;
            typedef ft::reverse_iterator < const_iterator >                             const_reverse_iterator;
            typedef typename iterator_traits< iterator >::difference_type               difference_type;

    set():_R_B_Ttree(value_compare());



};

};

#endif
