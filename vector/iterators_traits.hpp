/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:34:37 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:34:39 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_TRAITS_HPP
# define ITERATORS_TRAITS_HPP


#include "vector_iterator.hpp"
#include "../is_integral.hpp"
#include "../enable_if.hpp"

namespace ft{


// here in template we can write class or typename
	template < class iterator >
	struct iterator_traits
	{
		//	Type to express the result of subtracting one iterator from another
		typedef typename iterator::difference_type			difference_type;
		//The type of the element the iterator can point to.
		typedef typename iterator::value_type				value_type;
		//The type of a pointer to an element the iterator can point to.
		typedef typename iterator::pointer					pointer;
		//The type of a reference to an element the iterator can point to.
		typedef typename iterator::reference				reference;
		/*****The iterator category. It can be one of these:
			input_iterator_tag
			output_iterator_tag
			forward_iterator_tag
			bidirectional_iterator_tag
			random_access_iterator_tag*/
		typedef typename iterator::iterator_category		iterator_category;
	};

	template <class T>
	class iterator_traits<T *>
	{
		typedef ptrdiff_t									difference_type;
		typedef T											value_type;
		typedef T*											pointer;
		typedef T&											reference;
		typedef std::random_access_iterator_tag 			iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t									difference_type;
		typedef T											value_type;
		typedef	const T*									pointer;
		typedef const T&									reference;
		typedef std::random_access_iterator_tag				iterator_category;
	};
	
	// template<typename InputIterator>
	// typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last,
	// 	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	// {
	// 	typename iterator_traits<InputIterator>::difference_type dis = 0;

	// 	while (first != last)
	// 	{	
	// 		 dis++;
	// 		 first++;	
	// 	};
	// 	return dis;
	// }


	

};

#endif
