/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iters.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:51:19 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:35:30 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <vector>
# include <cstddef>
# include <iterator>
#include "iterators_traits.hpp"



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
			T*												_ptr;
		public: 
			typedef 	std::random_access_iterator_tag 	iterator_category;
			typedef 	T									value_type;
			typedef		ptrdiff_t							difference_type;
			typedef		T*									pointer;
			typedef		const T*							const_pointer;
			typedef		T&									reference;
			typedef		const T&							const_reference;
			

			//constructures
			//1: Default constructers
			iterator()
			{
				_ptr = 0;
			}
			//2:constructer avec parameters
			iterator(T* ptr)
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
			iterator operator=(const iterator &obj)
			{
				
				_ptr = obj._ptr;
				return *this;

			}
			//getter
			pointer get_ptr() const
			{
				return _ptr;
			}
			//diffrence_type is Alias of one of the fundamental signed integer types.
			// ptrdiff_t
			iterator operator+(difference_type nb) const
			{
				// _ptr = _ptr + nb;
				// return _ptr;
				return iterator(_ptr + nb);
				//return *this;
			}
			iterator& operator++()
			{
				_ptr = _ptr + 1;
				return *this;
			}
			iterator operator++(int)
			{
				iterator (tmp) = *this;
				//tmp = *this;
				_ptr = _ptr + 1;
				return tmp;
			}
			iterator operator+=(difference_type nb)
			{
				_ptr+=nb;
				return *this;
			}

			iterator operator-(difference_type nb) const
			{
				// _ptr = _ptr - nb;
				// return (_ptr);
				return iterator(_ptr - nb);
			}
			iterator operator--()
			{
				_ptr = _ptr -1;
				return *this;
			}
			iterator operator--(int)
			{
				iterator (tmp);
				// tmp = *this;
				// (*this)--;
				_ptr--;
				return tmp;
			}
			iterator operator-=(difference_type nb)
			{
				_ptr-=nb;
				return *this;
			}

			/***The .* operator is used to dereference pointers to class members. The first operand must be of class type. If the type of the first operand is class type T, or is a class that has been derived from class type T, the second operand must be a pointer to a member of a class type T.
			The ->* operator is also used to dereference pointers to class members. The first operand must be a pointer to a class type. If the type of the first operand is a pointer to class type T, or is a pointer to a class derived from class type T, the second operand must be a pointer to a member of class type T.*/
			reference operator*(){
				return(*_ptr);
			}
			const_reference operator*() const
			{
				return(*_ptr);
			}
			pointer operator->()
			{
				return &(operator*());
			}
			const_pointer operator->() const
			{
				//return (_ptr);
				return &(operator*());
			}
			reference operator[] (difference_type nb)
			{
				return _ptr[nb];

			}
			const_reference operator[](difference_type nb) const
			{
				return _ptr[nb];
			}
			// equal
			friend bool  operator == (const iterator& it1, const iterator& it2)
			{
					return (it1._ptr == it2._ptr);
			}
			friend bool operator != (const iterator& it1, const iterator& it2)
			{
					return (it1._ptr != it2._ptr);
			}
			friend bool operator > (const iterator& it1, const iterator& it2)
			{
				return(it1.ptr > it2._ptr);
			}
			friend bool operator >= (const iterator& it1, const iterator& it2)
			{
				return(it1.ptr >= it2._ptr);
			}
			friend bool operator < (const iterator& it1, const iterator& it2)
			{
				return(it1.ptr < it2._ptr);
			}
			friend bool operator <= (const iterator& it1, const iterator& it2)
			{
				return(it1.ptr <= it2._ptr);
			}

	};
	template <class Iterator1, class Iterator2>
	typename iterator<Iterator1>::difference_type operator - ( const iterator<Iterator1>& obj1, const iterator<Iterator2>& obj2 )
	{		
		return  obj1.get_ptr() - obj2.get_ptr(); 
	}
	template<typename InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type dis = 0;

		while (first != last)
		{	
			 dis++;
			 first++;	
		};
		return dis;
	}

	

};


#endif
