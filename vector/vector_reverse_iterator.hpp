/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:15:44 by souchen           #+#    #+#             */
/*   Updated: 2023/02/02 16:15:45 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP


#include "iterators_traits.hpp"

namespace ft{

    //reverse iterator

	template <class U>

	class reverse_iterator
	{

		private:

			U  _ptr;
		public:

			typedef U													iterator_type;
			typedef typename 	iterator_traits<U>::iterator_category   iterator_category;
			typedef typename 	iterator_traits<U>::value_type			value_type;
			typedef typename	iterator_traits<U>::difference_type		difference_type;
			typedef typename	iterator_traits<U>::pointer				pointer;
			typedef typename	iterator_traits<U>::reference			reference;
		

		//constructers:

		/***default constructers*/

		reverse_iterator()
		{
			return _ptr;
		}
		/****constructer with parameter*/
		reverse_iterator(iterator_type ptr)
		{
			_ptr = ptr;
		}
		/*****copy constructures*/
		reverse_iterator(reverse_iterator &obj)
		{
			_ptr = obj._ptr;
		}
		/******destructer*/
		~reverse_iterator(){}
		/***assignement operator*/

		reverse_iterator& operator=(reverse_iterator &obj)
		{
			if(&obj == this)
				return(*this);
			_ptr = obj._ptr;
		}

		// **********operations
			//difference_type is Alias of one of the fundamental signed integer types.
			// ptrdiff_t
			reverse_iterator operator+(difference_type nb) const
			{
				_ptr = _ptr - nb;
				return _ptr;
				//return *this;
			}
			reverse_iterator& operator++()
			{
				_ptr = _ptr - 1;
				return *this;
			}
			reverse_iterator& operator++(int)
			{
				reverse_iterator tmp;
				tmp = *this;
				(*this) --;
				return (tmp);
			}
			reverse_iterator operator+=(difference_type nb)
			{
				_ptr-=nb;
				return *this;
			}

			reverse_iterator operator-(difference_type nb) const
			{
				_ptr = _ptr + nb;
				return (_ptr);
			}
			reverse_iterator operator--()
			{
				_ptr = _ptr + 1;
				return _ptr;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp;
				tmp = *this;
				(*this)++;
				return (tmp);
			}
			reverse_iterator operator-=(difference_type nb)
			{
				_ptr+=nb;
				return *this;
			}
			reference operator*(){
				return(*_ptr);
			}
			
			pointer operator->()
			{
				return (_ptr);
			}
			
			reference operator[] (difference_type nb)
			{
				return _ptr[ - nb - 1];

			}
			// equal
			friend bool  operator == (const reverse_iterator& it1, const reverse_iterator& it2)
			{
					return (it1._ptr == it2._ptr);
			}
			friend bool operator != (const reverse_iterator& it1, const reverse_iterator& it2)
			{
					return (it1._ptr != it2._ptr);
			}
			friend bool operator > (const reverse_iterator& it1, const reverse_iterator& it2)
			{
				return(it1.ptr > it2._ptr);
			}
			friend bool operator >= (const reverse_iterator& it1, const reverse_iterator& it2)
			{
				return(it1.ptr >= it2._ptr);
			}
			friend bool operator < (const reverse_iterator& it1, const reverse_iterator& it2)
			{
				return(it1.ptr < it2._ptr);
			}
			friend bool operator <= (const reverse_iterator& it1, const reverse_iterator& it2)
			{
				return(it1.ptr <= it2._ptr);
			}

	};


};

#endif
