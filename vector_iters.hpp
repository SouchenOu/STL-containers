/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:51:19 by souchen           #+#    #+#             */
/*   Updated: 2023/01/26 09:51:21 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <vector>
# include <cstddef>
# include <iterator>
//# include "enable_if.hpp"


/*****The iterator_traits class template comes with a default definition that obtains these types from the iterator type itself (see below). It is also specialized for pointers (T*) and pointers to const (const T*).****/
namespace ft
{
	template < class iterator >
	struct iterator_traits
	{
		//	Type to express the result of subtracting one iterator from another
		typedef typename iterator::difference_type		difference_type;
		//The type of the element the iterator can point to.
		typedef typename iterator::value_type			value_type;
		//The type of a pointer to an element the iterator can point to.
		typedef typename iterator::pointer				pointer;
		//The type of a reference to an element the iterator can point to.
		typedef typename iterator::reference			reference;
		/*****The iterator category. It can be one of these:
			input_iterator_tag
			output_iterator_tag
			forward_iterator_tag
			bidirectional_iterator_tag
			random_access_iterator_tag*/
		typedef typename iterator::iterator_category	iterator_category;
	};

		
};
	// class iterator

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	/***
	 * 
	 * T :Type of elements pointed by the iterator.
		Distance :Type to represent the difference between two iterators.
		Pointer : Type to represent a pointer to an element pointed by the iterator.
		Reference :Type to represent a reference to an element pointed by the iterator.
	*/
	struct iterator{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

#endif
