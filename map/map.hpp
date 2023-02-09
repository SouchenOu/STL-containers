/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:35:55 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iterator>
# include <algorithm>


namespace ft
{
    template<class Key, class T, class Compare = std::less< Key>,class Allocator = std::allocator<std::pair<const Key,T>>>
    class map
    {
        public:
            typedef T                               mapped_type;
            typedef Key                             key_type;
            typedef std::pair<const Key, T>         value_type;
            typedef Compare                         key_compare;
            typedef Allocator                       allocator_type;
        
        
        
        typedef typename allocator_type::reference                  reference;
        typedef typename allocator_type::const_reference            const_reference;
        typedef typename  allocator_type::pointer                   pointer;
        typedef typename  allocator_type::const_pointer             const_pointer;
        

    };
			 		 
	
}

#endif



