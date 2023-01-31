/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:34:30 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:34:32 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP


#include <limits>

namespace ft
{
    template <class T> struct is_integral
    {
            typedef     T   value_type;

            //The value of std::numeric_limits<T>::is_integer is true for all integer arithmetic types T and false otherwise. This constant is meaningful for all specializations.
            static const bool val_bool = std::numeric_limits<value_type>::is_integer;
    };

    template<typename T, typename U>
        struct is_same 
    {
            static const bool val_bool = false; 
    };
    template<typename T> struct is_same<T,T>
    {
            static const bool val_bool = true; 
    };
}

#endif
