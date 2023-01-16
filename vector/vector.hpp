/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/16 11:16:46 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <algorithm>

/*# include "enable_if.hpp"
# include "vector_iterator.hpp"
# include "equal.hpp"*/

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef	T														value_type;
			typedef Alloc													allocator_type;
			typedef size_t													size_type;

			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;

			typedef ft::iterator< T >										iterator;
			typedef ft::iterator< const T >									const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename iterator_traits<iterator>::difference_type		difference_type;
			
			explicit	vector( const allocator_type& alloc = allocator_type() )	:	_alloc(alloc),_capacity(0),_elem(NULL),_size(0){};

			explicit	vector( size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type() )	:	_alloc(alloc),_capacity(0),_elem(NULL),_size(0)		
			{	
							insert(begin(), n, val);	
			};
			
			
			vector( const vector& x )	:	_alloc(x._alloc),_capacity(x._capacity),_elem(_alloc.allocate(x._capacity)),_size(x._size)
			{		
				assign(x.begin(), x.end());		
			};
			
			vector&	operator = (const vector& x)
			{
				if (this != &x) 
					assign(x.begin(), x.end());
				return *this;
			}

			~vector()
			{	
				clear();
				_alloc.deallocate(_elem, _capacity);	
			};
			
			
			template <class InputIterator>
			vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0 )	:_alloc(alloc),
																									_capacity(0),
																									_elem(NULL),
																									_size(0) 	
			{	
				insert(begin(), first, last);	
			};
			
			
			
			
			
				// [	ITERATORS	]
			iterator				begin() 						{		return iterator(_elem); 						};
			const_iterator			begin() const 					{		return const_iterator(_elem);					};
			iterator				end() 							{		return iterator(_elem + _size); 				};
			const_iterator			end() const 					{		return const_iterator(_elem + _size);   		};
			reverse_iterator		rbegin() 						{		return reverse_iterator(end());					};
			const_reverse_iterator	rbegin() const  				{		return const_reverse_iterator(end());			};
			reverse_iterator		rend() 							{		return reverse_iterator(begin());				};
			const_reverse_iterator	rend() const 					{		return const_reverse_iterator(begin());			};

			// [	CAPACITY	]
			size_type				size() const					{		return _size; 									};
			size_type				max_size() const 				{		return _alloc.max_size();						};
			void					resize(size_type n, value_type val = value_type())
			{
				while (n < _size)	pop_back();
				while (n > _size)	push_back(val);
			}
			size_type				capacity() const 				{		return _capacity; 								};
			bool					empty() const					{		return _size == 0; 								};
			void					reserve(size_type n)
			{
				if (n <= _capacity)	return ;
				if (n > max_size())
					throw std::length_error("requested allocation size is greater than max size");
				T	*new_vec = _alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(&new_vec[i], _elem[i]);
					_alloc.destroy(&_elem[i]);
				}
				_alloc.deallocate(_elem, _capacity);
				_elem = new_vec;
				_capacity = n;
			}

			// [	ELEMENT ACCESS		]
			reference				at(size_type n)
			{
				if (n < _size) return _elem[n];
				throw std::out_of_range("element out of range");
			};

			const_reference			at(size_type n) const
			{
				if (n < _size)	return _elem[n];
				throw std::out_of_range("element out of range");
			};

			reference				operator[](size_type n)			{		return _elem[n];								};
			const_reference			operator[](size_type n) const	{		return _elem[n];								};

			reference				front() 						{		return _elem[0];								};
			const_reference 		front() const 					{		return _elem[0];								};

			reference				back()							{		return _elem[_size - 1];						};
			const_reference			back() const					{		return _elem[_size - 1];						};
			
			// [	MODIFIERS	]
			template <class InputIterator>
			void		assign( InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0 )
			{
				size_type	n = ft::distance(first, last);

				clear();
				if (n > _capacity)	reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_elem + i, *first++);
				_size = n;
			};

			void		assign( size_type n, const value_type& val )
			{
				clear();
				if (n > _capacity)	reserve(n);
				for (size_type i = 0; i < n; i++)	_alloc.construct(_elem + i, val);
				_size = n;
			};

			void		push_back(const value_type& val)
			{
				if (_size == _capacity)
					reserve(_new_capacity(_size + 1));
				_alloc.construct(_elem + _size, val);
				_size++;
			};

			void		pop_back() 						{		_alloc.destroy(&_elem[--_size]);		};

			iterator				insert(iterator position, const value_type& val)
			{
				size_type			i = position - begin();

				insert(position, 1, val);
				return begin() + i;
			}

			void					insert(iterator position, size_type n, const value_type& val)
			{
				size_type			i = position - begin();

				if ((_size + n) > _capacity)
					reserve(_new_capacity(_size + n));
				for (size_type j = n + _size - 1; j > i + n - 1; j -= 1)
				{
					_alloc.construct(&_elem[j], _elem[j - n]);
					_alloc.destroy(&_elem[j - n]);
				}
				for (size_type k = i; k < i + n; k++)
				{
					_alloc.construct(&_elem[k], val);
					_size++;
				}
			}

			template <class InputIterator>
			void	insert( iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				size_type			i = position - begin();
				size_type			j = ft::distance(first, last);

				if ((_size + j) > _capacity)
					reserve(_new_capacity(_size + j));
				for (size_type k = j + _size - 1; k > i + j - 1; k -= 1)
				{
					_alloc.construct(&_elem[k], _elem[k - j]);
					_alloc.destroy(&_elem[k - j]);
				}
				for (size_type l = i; l < i + j; l++)
				{
					_alloc.construct(&_elem[l], *first);
					first++;
					_size++;
				}
			}
			
			iterator				erase( iterator position )
			{
				size_type			val = position - begin();

				_size -= 1;
				_alloc.destroy(&_elem[val]);
				for (size_type i = val; i < _size; i++)
				{
					_alloc.construct(&_elem[i], _elem[i + 1]);
					_alloc.destroy(&_elem[i + 1]);
				}
				return iterator(&_elem[val]);
			}

			iterator				erase( iterator first, iterator last )
			{
				size_type			diff = last - first;

				while (first != end() - diff)
				{
					*first = first[diff];
					++first;
				}
				while (first != end())
				{
					_alloc.destroy(&(*first));
					++first;
				}
				_size -= diff;
				return last - diff;
			}



			void					swap(vector& x)
			{
				ft::swap(_alloc, x._alloc);
				ft::swap(_capacity, x._capacity);
				ft::swap(_elem, x._elem);
				ft::swap(_size, x._size);
			}

			void		clear() 						{		erase(begin(), end()); 							};

			// [	ALLOCATOR	] 
			allocator_type get_allocator() const	{		return _alloc;		};

		private:

			size_type		_new_capacity(size_type size)
			{
				size_type			n;

				n = 1;
				while (n < size)	{	n *= 2;	};
				return n;
			}

			allocator_type	_alloc;
			size_type		_capacity;
			value_type		*_elem;
			size_type		_size;
	};

	// [	NON MEMBERS FUNCTION	]
	template <class T, class Alloc>
	bool	operator == (const vector<T,Alloc>& l, const vector<T,Alloc>& r)
	{
		if (l.size() != r.size())	return false;
		return ft::equal(l.begin(), l.end(), r.begin());
	};

	template <class T, class Alloc>
	bool	operator != ( const vector<T,Alloc>& l,
						 const vector<T,Alloc>& r )			{	return !(l == r);		};

	template <class T, class Alloc>
	bool	operator < ( const vector<T,Alloc>& l,
						 const vector<T,Alloc>& r )			{	return ft::lexicographical_compare(l.begin(), l.end(), r.begin(), r.end());		};

	template <class T, class Alloc>
	bool	operator <= ( const vector<T,Alloc>& l,
						 const vector<T,Alloc>& r )			{	return !(r < l);		};

	template <class T, class Alloc>
	bool	operator > ( const vector<T,Alloc>& l,
						 const vector<T,Alloc>& r )			{	return r < l;			};

	template <class T, class Alloc>
	bool	operator >= ( const vector<T,Alloc>& l,
						 const vector<T,Alloc>& r )			{	return !(l < r);		};

	template <class T, class Alloc>
	void	swap(vector<T,Alloc>& x, vector<T,Alloc>& y)	{	x.swap(y);				};
};


#endif
			

