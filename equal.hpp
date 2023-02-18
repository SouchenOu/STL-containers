/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:52:58 by souchen           #+#    #+#             */
/*   Updated: 2023/02/02 17:52:59 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft{

template <class InputIterator1, class InputIterator2>

    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while(first1 != last1)
        {
            if(*first1 != *first2)
            {
                return 0;
            }
            else if(*first1 == *first2)
            {
                first1++;
                first2++;
            }
        }
        return 1;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate> 
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,  BinaryPredicate pre )
    {
            while(first1 != last1)
            {
                if(!pre(*first1,*first2))
                {
                    return 0;
                }
                else if(pre(*first1,*first2))
                {
                    first1++;
                    first2++;
                }
            }
            return 1;
    }

}


# endif

