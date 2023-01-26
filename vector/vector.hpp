/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/26 09:51:35 by souchen          ###   ########.fr       */
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



//If allocator_type is an instantiation of the default (allocator) (which has no state), this is not relevant.
namespace ft{
    //template <class Type, class Allocator = std::allocator<Type>>
    template <class Type, class Alloc = std::allocator< Type >>

class vector
{
    /**Typedefs
    const_pointer:	    A type that provides a constant pointer to the type of object managed by the allocator.
    const_reference:	A type that provides a constant reference to type of object managed by the allocator.
    difference_type:	A signed integral type that can represent the difference between values of pointers to the type of object managed by the allocator.
    pointer:	        A type that provides a pointer to the type of object managed by the allocator.
    reference:	        A type that provides a reference to the type of object managed by the allocator.
    size_type:	        An unsigned integral type that can represent the length of any sequence that an object of type allocator can allocate.
    value_type:	        A type that is managed by the allocator.*/

    private:
    // value is the (Type maybe char , int ...) pointer
    // which stores the address of our vector
        Type    *_value;
    // capacity is the total storage
    // capacity of the vector
        size_t  _capacity;
     // current is the number of elements
    // currently present in the vector
        size_t  _current;
        Alloc   _alloc;

    public:
        // //***************** Aliases
        //Member type size_type is an unsigned integral type.
        typedef size_t  size_type;
        typedef Type  value_type;
        typedef Alloc allocator_type;
        typedef ptrdiff_t difference_type;
        //typedef typename iterator_traits<iterator>::difference_type		difference_type;

                    //an allocator defines the following types:
        //typedef typename allocator_type::size_type              size_type;
       // typedef typename allocator_type::difference_type        difference_type;

        typedef typename allocator_type::pointer                ptr;
        typedef typename allocator_type::const_pointer          const_ptr;
        typedef typename allocator_type::reference              ref;
        typedef typename allocator_type::const_reference        const_ref;
    
                //**********iterators
        typedef ft::iterator < Type >                            iterator; 
        typedef ft::iterator <const Type>                        const_iterator;
        typedef ft::reverse_iterator<iterator>                   reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>             const_reverse_iterator;

        /*value_type *value;
        size_type   _capacity;
        size_type   _current;
        allocator_type  alloc;*/

                //********************constructors
        explicit vector (const allocator_type& alloc = allocator_type())
        {
             //alloc	-	allocator to use for all memory allocations of this containe
             //allocate: Used for allocation of memory.
                _alloc(alloc);
             //value	-	the value to initialize elements of the container with
                _value(NULL);
                _current(0);
                _capacity(0);

         }
	        //    vector(size_type __n, const value_type& __x, const allocator_type& __a);
        explicit vector (size_type n, const value_type& value = value_type(),const allocator_type&  a = allocator_type())
        {
                _capacity(n);
                _alloc(a);
                insert(begin(), n, value);


         }
                /***copy constructor***/
        vector (const vector& x)
        {
            _capacity = _capacity.x;
            _current = _current.x;
            _alloc = _alloc.x;
            _value(_alloc.allocate(x._capacity));
            //begin - Input iterator to the initial position range.
            //end -   Input iterator to the final position range.
            // here x element is from begin to end;
                assign(x.begin(), x.end());

        }
        //Assignment operator

        vector&	operator = (const vector& x)
		{
			if (this == &x) 
                return *this;
			assign(x.begin(), x.end());
		}
        // function
        ~vector()
		{
            //The clear() function is used to remove all the elements of the vector container, thus making it size 0.
			clear();
			_alloc.deallocate(_value, _capacity);	
		};
        //Input iterators are iterators that can be used in sequential input operations, where each value pointed by the iterator is read only once and then the iterator is incremented.
        template <class InputIterator> vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
        {
            _alloc(alloc);
            _capacity(0);
            _current(0);
            _value(NULL);
            //the vector::insert() function from the STL in C++ is used to insert elements or values into a vector container. In general, the function returns an iterator pointing to the first of the inserted elements.
            //from the begin of our vector print from the first to the last
            insert(begin(), first, last);	

        }

        vector& operator=(const vector& x);
        //function allocate
        void allocate(size_type capacity) 
        {
            _capacity = capacity;
            _value = std::allocator_traits<allocator_type>::allocate(_alloc, capacity);
        }
        //function dealocate
        void deallocate(size_type capacity) 
        {
            std::allocator_traits<allocator_type>::deallocate(_alloc, _value, capacity);
            _capacity = 0;
            _current = 0;
        }
        void construct(size_type size, const Type& value) 
        {
            _current = size;
            for (size_type index{ 0 }; index < size; ++index)
                std::allocator_traits<allocator_type>::construct(_alloc, _value + index, value);
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

            // Capacity (size, max_size, resize)
            //size	Retourne le nombre d'éléments figurant dans le vecteur.
            //resize	Spécifie une nouvelle taille pour un vecteur.
            //max_size	Retourne la longueur maximale autorisée du vecteur.
            /**First, the size is NOT the same as the capacity. A vector’s size is the number of elements in the vector whereas the capacity is the number of elements for which there is allocated memory.*/
            size_type size() const
            {
                    return _current;
            }
            //The vector::max_size() is a built-in function in C++ STL which returns the maximum number of elements that can be held by the vector container
            size_type max_size() const
            {
                    return _alloc.max_size();
            }
            //capacity
            size_type capacity() const
            {
                return _capacity;
            }
            // function empty
            bool empty() const
            {
                if(_current == 0)
                    return 1;
                else if (_current != 0)
                    return 0;
            }
            //function resize Method 1
            void resize(size_type n, value_type val = value_type())
            {
                while(n < _current)
                {
                    pop_back();
                }
                while(n > _current)
                {
                    push_back(val);
                }
            }
            // function resize method 2
            //resize function using destroy, allocate , deallocate and construct
            //In C++, the operator new allocates memory for an object and then creates an object at that location by calling a constructor. Occasionally, however, it is useful to separate those two operations. [1] If p is a pointer to memory that has been allocated but not initialized, then construct(p, value) creates an object of type T1 at the location pointed to by p. The argument value is passed as an argument to T1's constructor.
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _current)
                {
                    size_type i = n + 1;
                    while (i < _current)
                    {
                        //Pointer to the object to be destroyed.
                        // _alloc : allocator to use for construction
                        _alloc.destroy((_value + i)));
                        i++;
                    }
                    _current = n;
                    return ;
                }
               // Notice that construct() does not allocate space for the element. It should already be available at _value (we allocate space with allocate() function).

                if (n > _current && n < _capacity)
                {
                    size_type i = _current;
                    while (i < n)
                    {
                        //this function provides the automatic fall back to placement new, the member function construct() is an optional Allocator requirement since C++11.
                        _alloc.construct((_value + i), val);
                        i++; 
                    }
                    _current = n;
                    return;
                }
                // we should check first if n is already allocate in memory (if not we should allocate it)
                if (n > _capacity)
                {
                    value_type *tmp = _alloc.allocate(n);
                    size_type i = 0;
                    while(i < _current)
                    {
                        tmp[i] = _value[i];
                        i++;
                    }
                    size_type i = _current;
                    while (i < n)
                    {
                        tmp[i] = val;
                        i++;
                    }
                    _alloc.deallocate(_value, _capacity);
                    _value = tmp;
                    _capacity = n;
                    _current = n;
                    return ;
                }
            }
            // function at()
            //The member function returns a reference to the element of the controlled sequence at position off. If that position is invalid, the function throws an object of class out_of_range.
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
            // function reserve()
            void	reserve(size_type n)
			{
				if (n <= _capacity)	return ;
				if (n > max_size())
					throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                // the capacity should be equal to n (that why we should allocate n place in memory)
				value_type	*_new = _alloc.allocate(n);
				for (size_type i = 0; i < _current; i++)
				{
					_alloc.construct(&_new[i], _value[i]);
					_alloc.destroy(&_value[i]);
				}
				_alloc.deallocate(_value, _capacity);
				_value= _new;
				_capacity = n;
			}

            // function assign
            // there is two differete assign function
            //1: template <class InputIterator>  void assign (InputIterator first, InputIterator last);
            //2: template <class InputIterator>  void assign (InputIterator first, InputIterator last);
            //Method 1
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
			};
            //Method 2
			void		assign( size_type count, const value_type& val )
			{
                //The clear() function is used to remove all the elements of the vector container, thus making it size 0.
				clear();
				if (count > _capacity)
                {
                    reserve(count);
                    //_capacity = count;
                    //** in reserve the capacity will change ant it will be equal to count
                }	
				for (size_type i = 0; i < count; i++)	
                    _alloc.construct(_value + i, val);
				_current = count;

			};
            // method 3
            void assign(size_type count, const Ty& val)
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
            //push_back , pop_back, insert, erase, swap, clear,  get_allocator and operators
            // function push_back


            /**The C++ function std::vector::capacity() returns the size of allocate storage, expressed in terms of elements.

            This capacity is not necessarily equal to the size of vector. It can be equal or greater than vector size.

            The theoretical limit on vector size is given by member max_size.*/
            void		push_back(const value_type& val)
			{
				if (_current == _capacity)
					reserve(_new_capacity(_current + 1));
				_alloc.construct(_value + _current, val);
				_current++;
			};

			void		pop_back() 						
            {		
                _alloc.destroy(&_value[_current]);
                _current--;		
            };
            // function insert
			iterator	insert(iterator position, const value_type& val)
			{
			
                value[position] = val;
                _current++;
                // I should check if the current size is sup than capacity
                //This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
				return begin() + position;
			}
            // erase()
            iterator erase (iterator position)
            {

            }
            /**erase() function is used to remove elements from a container from the specified position or range.*/

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
}

#endif
