/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:35:40 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <algorithm>
# include <iostream>

//using namespace std;
# include "../enable_if.hpp"
# include "vector_iterator.hpp"
# include "vector_reverse_iterator.hpp"
# include "../equal.hpp"

/*enable_if : if we have two oveloaded functions or more the compiler shoose the suitable one
/ for example if we have a function foo() with difference type, the compiler  takes all these functions foo()
with difference argument types and then determine the best one to call it.


** but with functions template it get a little bit more complicated, as function templates are generalizations of functions
in the same way overload resolution rules for function template are generalized overload resolution rules for functions, 
so in order to determine which function to call  compiler performs more steps ...

lets say we call function foo() and then the compiler looks for all variables functions with this name, and thid includes function template 
and the function template is not a function on its own only when we supply a template parameter 
which means a type to it then it becomes a full function, so in the case of overload resolution the  compiler tries to speciales our function template
for the given set of argument types, it preferes more specialized more specific function template 
and then take all this specialised function template and regular functions and picks the best one 
but if no suitable function is found (its not an error --> no error is issued -- SFINAE)

--> we will have essues (error) just if no variable function can be found or two equaly good functions

//allocator : allocator to use for all memory allocations of this container
// what is the difference between size and capacity and max_size
/******
 * size :  This is the number of actual objects held in the vector their storage space when needed or when requested with member resize.
 * 
 * 
 * 
 * 
*/
namespace ft
{
    //template <class Type, class Allocator = std::allocator<Type>>
    template <class T, class Alloc = std::allocator< T > >
    class vector
    {

        private:
   
            T                *_value;
            size_t              _capacity;
            size_t              _current;
            Alloc               _alloc;

        public:
      
            typedef size_t                                          size_type;
            typedef T                                            value_type;
            typedef Alloc                                           allocator_type;
            typedef ptrdiff_t                                       difference_type;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
    
                //**********iterators
            typedef ft::iterator < T >                            iterator; 
            typedef ft::iterator <const T>                          const_iterator;
            typedef ft::reverse_iterator<iterator>                   reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>             const_reverse_iterator;

            vector(){};
            explicit vector(size_type n) : _capacity(n){};

            explicit vector (const allocator_type& alloc) :  _alloc(alloc),_value(NULL),_current(0),_capacity(0){};

            explicit vector (size_type n, const value_type& value ,const allocator_type&  a) : _capacity(n),_alloc(a),_value(NULL),_current(0)
            {
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

            //Input iterators are iterators that can be used in sequential input operations, where each value pointed by the iterator is read only once and then the iterator is incremented.
            template <class InputIterator> 
            vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0): _alloc(alloc), _capacity(0),_current(0),_value(NULL)
            {
                insert(begin(), first, last);	
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
	    	    clear();
			    _alloc.deallocate(_value, _capacity);	
		    }
        
    
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
           
           //Element access *****************
           //element access
            size_type operator[](size_type index)
            {
                if(index >= _current)
                {
                    std::cout << "index out of bound\n" << std::endl;
                    exit(0);
                }
                return _value[index];
            }
            size_type operator[](size_type index) const
            {
                if(index >= _current)
                {
                    std::cout << "index out of bound\n" << std::endl;
                    exit(0);
                }
                return _value[index];
            }
            reference at (size_type n)
            {
                if (n > _current)
                    throw std::out_of_range("vector ");
                return _value[n];
            }

            const_reference at (size_type n) const
            {
                if (n > _current)
                    throw std::out_of_range("vector ");
                return (_value[n]);
            }
            //front
            reference front()
            {
                return _value[0];
            }
            const_reference front() const
            {
                return _value[0];
            }
            reference back()
            {
                return _value[_capacity - 1];
            }
            const_reference back() const
            {
                return _value[_capacity - 1];
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

            
             //***************************Modifiers*/
            template <class InputIterator>
			void		assign( InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0 )
			{
				size_type	n = ft::distance(first, last);

				clear();
				if (n > _capacity)	
                    reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_value + i, *first++);
				_current = n;
			}
            
           
            //Method 2*/
			void		assign( size_type count, const value_type& val )
			{
                //first we remove all old element in our vector then we put val count time
				clear();
				if (count > _capacity)
                {
                    // here i should allocate count space in memory
                    reserve(count);
                   
                }	
				for (size_type i = 0; i < count; i++)	
                    _alloc.construct(_value + i, val);
				_current = count;

			}
            // method 3
            // void assign(size_type count, const size_type& val)
            // {
            //     // count here is the capacity of our vector so i should allocate count space
            //     if(count > _capacity)
            //     {
            //         value_type *_new = _alloc.allocate(count);
            //         for(size_type i = 0; i < count; i++)
            //         {
            //             _alloc.construct(&_new[i], val);
            //             _alloc.destroy(&_value[i]);
            //         }
            //         _alloc.deallocate(_value , _capacity);
            //         _value = _new;
            //         _capacity = count;
            //         _current = count;
            //     }else{
            //         for (size_type i = 0; i < count; i++)	
            //             _alloc.construct(_value + i, val);
			// 	    _current = count;
            //     }
                

            // }


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
			}

			void		pop_back() 						
            {		
                _alloc.destroy(&_value[_current]);
                _current--;		
            }
            
            void		clear()
            {		
                erase(begin(), end()); 							
                
            }


			iterator	insert(iterator position, const value_type& val)
			{
			
                _value[position] = val;
                _current++;
				return begin() + position;
			}
            void insert(iterator position, size_type n, const value_type& val)
            {
                size_type			pos = position - begin();

				if ((_current + n) > _capacity)
					reserve(_current + n);
				for (size_type i = n + _current - 1; i > pos + n - 1; i--)
				{
					_alloc.construct(&_value[i], _value[i - n]);
					_alloc.destroy(&_value[i - n]);
				}
				for (size_type j = pos; j < pos + n; j++)
				{
					_alloc.construct(&_value[j], val);
					_current++;
				}
            }
           template <class InputIterator>
			void	insert( iterator position, InputIterator first, InputIterator last,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				size_type			pos = position - begin();
				size_type			i = ft::distance(first, last);

				if ((_current + i) > _capacity)
					reserve(_current + j);
				for (size_type j = i + _current - 1; j > pos + i - 1; j--)
				{
					_alloc.construct(&_value[j], _value[j - i]);
					_alloc.destroy(&_value[j - i]);
				}
				for (size_type m = pos; m < pos + i; m++)
				{
					_alloc.construct(&_value[m], *first);
					first++;
					_current++;
				}
			}
            iterator				erase( iterator position )
			{
				size_type			value_pos = position - begin();

				_current = _current - 1;
				_alloc.destroy(&_value[val]);
				for (size_type i = value_pos; i < _current; i++)
				{
					_alloc.construct(&_value[i], _value[i + 1]);
					_alloc.destroy(&_value[i + 1]);
				}
				return iterator(&_value[value_pos]);
			}

            iterator	erase( iterator first, iterator last )
			{
				size_type			nb_element = last - first;

				while (first != end() - nb_element)
				{
					*first = first[nb_element];
					first++;
				}
				while (first != end())
				{
					_alloc.destroy(&(*first));
					first++;
				}
				_current -= nb_element;
				return last - nb_element;
			}
            //still swap , emplace and emplace_back
            

            //swap
            template <class T, class Alloc>
            void swap(vector<T, Alloc> vect1, vector<T, Alloc> vect2)
            {
                vect1.swap(vect2);
            }
            void swap(vector& x)
            {
                swap(_alloc,x._alloc);
                swap(_capacity,x._capacity);
                swap(_value, x._value);
                swap(_current,x._current);

            }
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            void clear()
            {
                erase(begin(), end();)
            }

    };

 /*****Non member function :*/

            template <class Type, class Alloc>
	        bool	operator == (const vector<Type,Alloc>& obj1, const vector<Type,Alloc>& obj2)
	        {
		        if (obj1.size() != obj2.size())	
                    return false;
		        return ft::equal(obj1.begin(), obj1.end(), obj2.begin());
	    
            }
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
