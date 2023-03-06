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

	template <class iterator>

	class reverse_iterator
	{

		private:

			iterator  															_ptr;
		public:

			typedef iterator													iterator_type;
			typedef typename 	iterator_traits<iterator>::iterator_category   iterator_category;
			typedef typename 	iterator_traits<iterator>::value_type			value_type;
			typedef typename	iterator_traits<iterator>::difference_type		difference_type;
			typedef typename	iterator_traits<iterator>::pointer				pointer;
			typedef typename	iterator_traits<iterator>::reference			reference;
		

		//constructers:

		/***default constructers*/

		reverse_iterator():_ptr()
		{}
		/****constructer with parameter*/
		reverse_iterator(iterator_type ptr):_ptr(ptr)
		{}
		/*****copy constructures*/
		template <class Iterator>
			reverse_iterator(const reverse_iterator<Iterator> & iter):_ptr(iter.get_ptr()) {};
		
		/***assignement operator*/
		template <class Iterator>
			reverse_iterator&	operator = (const reverse_iterator<Iterator>& other)
			{
				_ptr = other.get_ptr(); 
				return  *this;		
			};
		/******destructer*/
		~reverse_iterator(){}
		//getter
		iterator_type get_ptr() const
		{
			return _ptr;
		}


		// **********operations
			//difference_type is Alias of one of the fundamental signed integer types.
			// ptrdiff_t
			reverse_iterator operator+(difference_type nb) const
			{
				return reverse_iterator(_ptr - nb);
			}
			//pre increment
			reverse_iterator& operator++()
			{
				_ptr--;
				return *this;
			}
			//post increment
			reverse_iterator operator++(int)
			{
				reverse_iterator temp = *this;
				--_ptr; //--*this
				return (temp);
			}
			reverse_iterator &operator+=(difference_type nb)
			{
				_ptr-=nb;
				return *this;
			}

			reverse_iterator operator-(difference_type nb) const
			{
				return reverse_iterator(_ptr + nb);
			}
			reverse_iterator &operator--()
			{
				++_ptr;
				return *this;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator temp = *this;
				++(_ptr); // or ++(*this)
				return (temp);
			}
			reverse_iterator operator-=(difference_type nb)
			{
				_ptr+=nb;
				return *this;
			}
			reference			operator*() const
			{		
				iterator_type	temp = _ptr;	
				return *(temp--);
			};
			
			pointer operator->() const
			{
				return &(operator*());
			}
			
			reference operator[] (difference_type nb) const
			{
				return get_ptr()[ - nb - 1];

			}

	};



	template <class Iter1, class Iter2>
	bool	operator == ( const reverse_iterator<Iter1>& iter1,const reverse_iterator<Iter2>& iter2 )
	{	
			return  iter1.get_ptr() == iter2.get_ptr();	
	};

	template <class Iter1, class Iter2>
	bool	operator != ( const reverse_iterator<Iter1>& iter1,const reverse_iterator<Iter2>& iter2 )
	{	
		return  iter1.get_ptr() != iter2.get_ptr();
	};

	template <class Iter1, class Iter2>
	bool	operator < ( const reverse_iterator<Iter1>& iter1,const reverse_iterator<Iter2>& iter2 )
	{	
		return  iter1.get_ptr() > iter2.get_ptr();
	};

	template <class Iter1, class Iter2>
	bool	operator <= ( const reverse_iterator<Iter1>& iter1,const reverse_iterator<Iter2>& iter2 ) 
	{	
		return  iter1.get_ptr() >= iter2.get_ptr();
	};

	template <class Iter1, class Iter2>
	bool	operator > ( const reverse_iterator<Iter1>& iter1,const reverse_iterator<Iter2>& iter2 ) 
	{	
		return  iter1.get_ptr() < iter2.get_ptr();
	};

	template <class Iter1, class Iter2>
	bool 	operator >= ( const reverse_iterator<Iter1>& iter1,const reverse_iterator<Iter2>& iter2 )
	{	
		return  iter1.get_ptr() <= iter2.get_ptr();	
		};


	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator - ( const reverse_iterator<Iterator1>& l,const reverse_iterator<Iterator2>& r )
	{		
			return  r.get_ptr() - l.get_ptr(); 
	};

	template <class Iterator>
	reverse_iterator<Iterator>	operator + ( typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& rev_it)
	{		
			return  rev_it + n;	
	};





};

#endif
