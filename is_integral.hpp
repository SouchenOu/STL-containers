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

//Checks whether T is an integral type. Provides the member constant value which is equal to true, if T is the type bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, or any implementation-defined extended integer types, including any signed, unsigned, and cv-qualified variants. Otherwise, value is equal to false.
/*std::is_integer<T> does not exist.
That being said, std::numeric_limits<T>::is_integer does exist.*/

// numeric_limits : Provides information about the properties of arithmetic types (either integral or floating-point) in the specific platform for which the library compiles.

// There is difference between is_integer and is_integral (is not the same ishould change it )
namespace ft
{
    template <class T> 
    struct is_integral
    {
            typedef     T   value_type;

            //The value of std::numeric_limits<T>::is_integer is true for all integer arithmetic types T and false otherwise. This constant is meaningful for all specializations.
            static const bool val_bool = std::numeric_limits<value_type>::is_integer;
            //exp std::cout << "Maximum value for int: " << std::numeric_limits<int>::max() << '\n';
                //std::cout << "int is signed: " << std::numeric_limits<int>::is_signed << '\n';
    };

   
}

#endif
