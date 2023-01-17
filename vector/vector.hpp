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
# include <algorithm>
# include <iterator>



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

    //typedef size_t  size_type;
    typedef Type  value_type;
    typedef Alloc allocator_type;
    //typedef ptrdiff_t difference_type;
    //typedef typename iterator_traits<iterator>::difference_type		difference_type;

    //an allocator defines the following types:
    typedef typename allocator_type::size_type        size_type;
    typedef typename allocator_type::difference_type       difference_type;

    typedef typename allocator_type::pointer          ptr;
    typedef typename allocator_type::const_pointer     const_ptr;
    typedef typename allocator_type::reference       ref;
    typedef typename allocator_type::const_reference const_ref;
    
    //iterators
    typedef ft::iterator < Type >                       iterator; 
    typedef ft::iterator <const Type>                   const_iterator;
    typedef ft::reverse_iterator<iterator>              reverce_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_iterator;


    //********************constructors
    explicit vector (const allocator_type& alloc = allocator_type())
    {
        //alloc	-	allocator to use for all memory allocations of this containe
        _alloc(alloc);
        //value	-	the value to initialize elements of the container with
        _value(NULL);

    }
	//    vector(size_type __n, const value_type& __x, const allocator_type& __a);
    explicit vector (size_type n, const value_type& value = value_type(),const allocator_type&  a = allocator_type());
    /***copy constructor***/
    vector (const vector& x);
    ~vector();
    vector& operator=(const vector& x);


    //implement iterators
    iterator begin()
    {
        return iterator(_value);
    }
    const_iterator begin() const
    {
        return const_iterator(elem);
    }
    iterator end()
    {
        return iterator(elem);
    }





    

};
}

#endif