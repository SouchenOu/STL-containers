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
/*****NAMESPACE : are used to orgnise code into logical groups especialy when your code base includes multiple libraries*/
/*******WHY WE USE TYPEDEF : WE USE IT FOR ALIASING EXISTING DATATYPES*/
namespace ft
{

		// class iterator
	/***
	 * 
	 * T :Type of elements pointed by the iterator.
		Distance :Type to represent the difference between two iterators.
		Pointer : Type to represent a pointer to an element pointed by the iterator.
		Reference :Type to represent a reference to an element pointed by the iterator.
	*/
	template<typename T>
	class iterator
	{

		private:
		//which points to an element of the Integers container
			T*				_ptr;
		public: 
			typedef 	std::random_access_iterator_tag 	iterator_category;
			typedef 	T									value_type;
			typedef		ptrdiff_t							difference_type;
			typedef		T*									pointer;
			typedef		const T*							const_pointer;
			typedef		T&									reference
			typedef		const T&							const_reference;
			




			//constructures
			//1: Default constructers
			iterator()
			{
				_ptr = 0;
			}
			//2:constructer avec parameters
			iterator(T* it)
			{
				_ptr = ptr;
			}
			//3 copy constructer
			iterator(const iterator &obj)
			{
				_ptr = obj._ptr;
			}
			// Destructure
			~iterator()
			{}

			// operations :
			iterator operator=(iterator &obj)
			{
				if(&obj == this)
					return(*this);
				_ptr = obj._ptr;

			}
			//diffrence_type is Alias of one of the fundamental signed integer types.
			// ptrdiff_t
			iterator operator+(difference_type nb) const
			{
				_ptr = _ptr + nb;
				return _ptr;
				//return *this;
			}
			iterator& operator++()
			{
				_ptr = _ptr + 1;
				return *this;
			}
			iterator& operator++(int)
			{
				iterator tmp;
				tmp = *this;
				(*this) ++;
				return (tmp);
			}
			iterator operator+=(difference_type nb)
			{
				_ptr+=nb;
				return *this;
			}

			iterator operator-(difference_type nb) const
			{
				_ptr = _ptr - nb;
				return (_ptr);
			}
			iterator operator--()
			{
				_ptr = _ptr -1;
				return _ptr;
			}
			iterator operator--(int)
			{
				iterator tmp;
				tmp = *this;
				(*this)--;
				return (tmp);
			}
			iterator operator-=(difference_type nb)
			{
				_ptr-=nb;
				return *this;
			}
			reference operator*(){
				return(*_ptr);
			}
			const_reference operator*() const
			{
				return(*_ptr);
			}
			pointer operator->()
			{
				return (_ptr);
			}
			const_pointer operator->() const
			{
				return (_ptr);
			}
			reference operator[] (difference_type nb)
			{
				return _ptr[nb];

			}
			const_reference operator[](difference_type nb)
			{
				return _ptr[nb];
			}










	};

















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

		
};
	

#endif
