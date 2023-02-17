/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:35:24 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <algorithm>
# include <iostream>

using namespace std;
# include "../enable_if.hpp"
# include "vector_iterator.hpp"
# include "../equal.hpp"



//allocator : allocator to use for all memory allocations of this container
// what is the difference between size and capacity and max_size
/******
 * size :  This is the number of actual objects held in the vector their storage space when needed or when requested with member resize.
 * 
 * 
 * 
 * 
*/
namespace ft{
    //template <class Type, class Allocator = std::allocator<Type>>
    template <class Type, class Alloc = std::allocator< Type > >
class vector
{

    private:
   
        Type                *_value;
        size_t              _capacity;
        size_t              _current;
        Alloc               _alloc;

    public:
      
        typedef size_t                                          size_type;
        typedef Type                                            value_type;
        typedef Alloc                                           allocator_type;
        typedef ptrdiff_t                                       difference_type;
        typedef typename allocator_type::pointer                ptr;
        typedef typename allocator_type::const_pointer          const_ptr;
        typedef typename allocator_type::reference              ref;
        typedef typename allocator_type::const_reference        const_ref;
    
                //**********iterators
        typedef ft::iterator < Type >                            iterator; 
        typedef ft::iterator <const Type>                        const_iterator;
        typedef ft::reverse_iterator<iterator>                   reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>             const_reverse_iterator;

        vector(){};
        explicit vector(size_type n) : _capacity(n){};

        explicit vector (const allocator_type& alloc) :  _alloc(alloc),_value(NULL),_current(0),_capacity(0){};

        explicit vector (size_type n, const value_type& value ,const allocator_type&  a) : _capacity(n),_alloc(a),_value(NULL),_current(0){
            //inserting value n times to the vector
                insert(begin(), n, value);

         }
                /***copy constructor***/
        vector (const vector& obj)
        {
            _capacity   = obj._capacity;
            _current    = obj._current;
            _alloc      = obj._alloc;
            _value = _alloc.allocate(obj._capacity);

            // assign all element of our new obj to our existent obj
            //from begin to end
            assign(obj.begin(), obj.end());
        }
        //Assignment operator

        vector&	operator = (const vector& obj)
		{
			if (this == &obj) 
                return *this;
			assign(obj.begin(), obj.end());
		}
        ~vector()
		{
	    	//clear();
			_alloc.deallocate(_value, _capacity);	
		};
        //Input iterators are iterators that can be used in sequential input operations, where each value pointed by the iterator is read only once and then the iterator is incremented.
        // template <class InputIterator> 
        // vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type()): _alloc(alloc), _capacity(0),_current(0),_value(NULL)
        //     insert(begin(), first, last);	
        // };

        // size_type operator[](int index)
        // {
        //     if(index >= _current)
        //     {
        //         std::cout << "index out of bound\n" << std::endl;
        //         exit(0);
        //     }
        //     return _value[index];
        // }
        //function allocate
        // void allocate(size_type capacity) 
        // {
        //     _capacity = capacity;
        //     _value = std::allocator_traits<allocator_type>::allocate(_alloc, capacity);
        // };

        // //function dealocate
        // void deallocate(size_type capacity) 
        // {
        //     std::allocator_traits<allocator_type>::deallocate(_alloc, _value, capacity);
        //     _capacity = 0;
        //     _current = 0;
        // }

        // void construct(size_type size, const Type& value) 
        // {
        //     _current = size;
        //     for (size_type index = 0 ; index < size; ++index)
        //         std::allocator_traits<allocator_type>::construct(_alloc, _value + index, value);
        // }
            
            
            //implement iterators
            iterator begin()
            {
                 return iterator(_value);
            }
            const_iterator begin() const
            {
                return const_iterator(_value);
            }
            iterator end()
            {
                 return iterator(_value + _current);
            }
            const_iterator end() const
            {
                return const_iterator(_value + _current);
            }

            //implement reverse iterators
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const
            {
                return reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
            const_reverse_iterator rend() const
            {
                return reverse_iterator(begin());
            }

            
            
            size_type size() const
            {
                return _current;
            }


            size_type max_size() const
            {
                    return _alloc.max_size();
            }


            size_type capacity() const
            {
                return _capacity;
            }


            bool empty() const
            {
                if(_current == 0)
                    return 1;
                else if (_current != 0)
                    return 0;
            }


            // void resize(size_type n, value_type val = value_type())
            // {
            //     while(n < _current)
            //     {
            //         pop_back();
            //     }
            //     while(n > _current)
            //     {
            //         push_back(val);
            //     }
            // }
          
          // i still have a problem here in capacity au cas ou (n > _capacity)
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _current)
                {
                    size_type i = n + 1;
                    while (_current > i)
                    {
                        _alloc.destroy((_value + _current));
                        _current--;
                    }
                    _current = n;
                    return ;
                }

                if (n > _current && n < _capacity)
                {
                    size_type j = _current + 1;
                    while (j < n)
                    {
                        _alloc.construct((_value + j), val);
                        j++; 
                    }
                    _current = n;
                    return;
                }
                if (n > _capacity)
                {
                    value_type *tmp = _alloc.allocate(n);
                    size_type k = 0;
                    while(k < _current)
                    {
                        tmp[k] = _value[k];
                        k++;
                    }
                    k = _current;
                    while (k < n)
                    {
                        tmp[k] = val;
                        k++;
                    }
                    _alloc.deallocate(_value, _capacity);
                    _value = tmp;
                    _capacity = _capacity * 2 ;
                    _current = n;
                    return ;
                }
            }
           
           
            ref at (size_type n)
            {
                if (n > _current)
                    throw std::out_of_range("vector ");
                return _value[n];
            }

            const_ref at (size_type n) const
            {
                if (n > _current)
                    throw std::out_of_range("vector ");
                return (_value[n]);
            }

            // function reserve()
            void	reserve(size_type n)
			{
				if (n <= _capacity)
                {
                    return ;
                }
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                // the capacity should be equal to n (that why we should allocate n place in memory)
				value_type	*_new = _alloc.allocate(n);
				for (size_type i = 0; i < _current; i++)
				{
					//_alloc.construct(&_new[i], _value[i]);
                    _new[i] = _value[i];
					//_alloc.destroy(&_value[i]);
				}
				//_alloc.deallocate(_value, _capacity);
				_value= _new;
				_capacity = n;
			}

            
            
            /*template <class InputIterator>
			void		assign( InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0 )
			{
				size_type	n = ft::distance(first, last);

				clear();
				if (n > _capacity)	
                    reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_value + i, *first++);
				_current = n;
			};*/

            //Method 2*/
			void		assign( size_type count, const value_type& val )
			{

				clear();
				if (count > _capacity)
                {
                    reserve(count);
                   
                }	
				for (size_type i = 0; i < count; i++)	
                    _alloc.construct(_value + i, val);
				_current = count;

			};
            // method 3
            void assign(size_type count, const size_type& val)
            {
                // count here is the capacity of our vector so i should allocate count space
                if(count > _capacity)
                {
                    value_type *_new = _alloc.allocate(count);
                    for(size_type i = 0; i < count; i++)
                    {
                        _alloc.construct(&_new[i], val);
                        _alloc.destroy(&_value[i]);
                    }
                    _alloc.deallocate(_value , _capacity);
                    _value = _new;
                    _capacity = count;
                    _current = count;
                }else{
                    for (size_type i = 0; i < count; i++)	
                        _alloc.construct(_value + i, val);
				    _current = count;
                }
                

            }
            void		clear()
            {		
                erase(begin(), end()); 							
                
            };


            void		push_back(const value_type& val)
			{
                size_type new_capacity;
                new_capacity = 1;
				if (_current == _capacity)
                {
                    while(new_capacity < _current + 1)
                    {
                        new_capacity = new_capacity * 2;
                    }
                    reserve(new_capacity);
                }
				//_alloc.construct(_value + _current, val);
                _value[_current] = val;
				_current++;
			};

			void		pop_back() 						
            {		
                _alloc.destroy(&_value[_current]);
                _current--;		
            };
            
			iterator	insert(iterator position, const value_type& val)
			{
			
                _value[position] = val;
                _current++;
				return begin() + position;
			}
            // erase()
            /*iterator erase (iterator position)
            {

            }*/

            iterator	erase( iterator first, iterator last )
			{
				size_type			nb_element = last - first;

				while (first != end() - nb_element)
				{
					*first = first[nb_element];
					++first;
				}
				while (first != end())
				{
					_alloc.destroy(&(*first));
					++first;
				}
				_current -= nb_element;
				return last - nb_element;
			}

};


 /*****Non member function :*/


            template <class Type, class Alloc>
            bool operator !=(const vector<Type, Alloc> &obj1, const vector<Type, Alloc> &obj2)
            {
                    return(obj1 != obj2);
            }
            
            template <class Type, class Alloc>
            bool operator > (const vector<Type, Alloc> &obj1, const vector<Type, Alloc> &obj2)
            {
                    return(obj1 > obj2);
            }
            
            template <class Type, class Alloc>
            bool operator >= (const vector<Type,Alloc> &obj1, const vector<Type, Alloc> &obj2)
            {
                return (obj1 >= obj2);
            }

            template <class Type, class Alloc>
            bool operator < (const vector<Type,Alloc> &obj1, const vector<Type, Alloc> &obj2)
            {
                return (obj1 < obj2);
            }

            template <class Type, class Alloc>
            bool operator <= (const vector<Type, Alloc> &obj1, const vector<Type,Alloc> &obj2)
            {
                return (obj1 <= obj2);
            }
};

#endif
