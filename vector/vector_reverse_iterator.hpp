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

			iterator  			_ptr;
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
		{
		}
		/*****copy constructures*/
		// reverse_iterator(reverse_iterator &obj)
		// {
		// 	_ptr = obj._ptr;
		// }
		template <class Iterator>
			reverse_iterator(const reverse_iterator<Iterator> & iter):_ptr(iter.get_ptr()) {};

		template <class Iterator>
			reverse_iterator&	operator = (const reverse_iterator<Iterator>& other)
			{
				_ptr = other.get_ptr(); 
				return  *this;		
			};
		/******destructer*/
		~reverse_iterator(){}
		/***assignement operator*/
		//getter
		iterator_type get_ptr() const
		{
			return _ptr;
		}

		// reverse_iterator& operator=(reverse_iterator &obj)
		// {
		// 	if(&obj == this)
		// 		return(*this);
		// 	_ptr = obj._ptr;
		// }

		// **********operations
			//difference_type is Alias of one of the fundamental signed integer types.
			// ptrdiff_t
			reverse_iterator operator+(difference_type nb) const
			{
				// _ptr = _ptr - nb;
				// return _ptr;
				return reverse_iterator(_ptr - nb);
				//return *this;
			}
			reverse_iterator& operator++()
			{
				_ptr--;
				return *this;
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--_ptr;
				std::cout << "ptr-->" << _ptr->first << std::endl;
				return (tmp);
			}
			reverse_iterator &operator+=(difference_type nb)
			{
				_ptr-=nb;
				return *this;
			}

			reverse_iterator operator-(difference_type nb) const
			{
				// _ptr = _ptr + nb;
				// return (_ptr);
				return reverse_iterator(_ptr + nb);
			}
			reverse_iterator &operator--()
			{
				++_ptr;
				return *this;
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++(_ptr);
				return (tmp);
			}
			reverse_iterator operator-=(difference_type nb)
			{
				_ptr+=nb;
				return *this;
			}
			// reference operator*(){
			// 	return(*_ptr);
			// }
			reference			operator*() const
			{		
				iterator_type	tmp = _ptr;	
				return *(tmp--);
			};
			
			pointer operator->() const
			{
				//return (_ptr);
				return &(operator*());
			}
			
			reference operator[] (difference_type nb) const
			{
				return get_ptr()[ - nb - 1];

			}
			// equal
			// friend bool  operator == (const reverse_iterator& it1, const reverse_iterator& it2)
			// {
			// 		return (it1._ptr == it2._ptr);
			// }
			// friend bool operator != (const reverse_iterator& it1, const reverse_iterator& it2)
			// {
			// 		return (it1._ptr != it2._ptr);
			// }
			// friend bool operator > (const reverse_iterator& it1, const reverse_iterator& it2)
			// {
			// 	return(it1._ptr > it2._ptr);
			// }
			// friend bool operator >= (const reverse_iterator& it1, const reverse_iterator& it2)
			// {
			// 	return(it1._ptr >= it2._ptr);
			// }
			// friend bool operator < (const reverse_iterator& it1, const reverse_iterator& it2)
			// {
			// 	return(it1._ptr < it2._ptr);
			// }
			// friend bool operator <= (const reverse_iterator& it1, const reverse_iterator& it2)
			// {
			// 	return(it1._ptr <= it2._ptr);
			// }

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
