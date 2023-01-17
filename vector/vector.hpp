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




namespace ft{
    template <class Type, class Allocator = std::allocator<Type>>
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

    //an allocator defines the following types:
    typedef typename Allocator::pointer          ptr;
    typedef typename Allocator::cont_pointer     const_ptr;
    typedef typename Allocator::reference       ref;
    typedef typename Allocator::const_reference const_ref;
    
    //iterators


    

};
}

#endif