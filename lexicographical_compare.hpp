/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:18:23 by souchen           #+#    #+#             */
/*   Updated: 2023/02/20 10:18:25 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
    template<class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        while((first1 != last1) && (first2 != last2))
        {
            if(*first1 < *first2)
            {
                return true;
            }else if(*first1 > *first2)
            {
                return false;
            }
            first1++;
            first2++;
        }
        return (first1 == last1) && (first2 != last2);
    }
}

template<class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator1 last2, Compare comp)
{
    while((first1 != last1) && (first2 != last2))
    {
        if(comp(*first1 < *first2))
        {
            return true;
        }else if(comp(*first1 > *first2))
        {
            return false;
        }
    }
    return (first1 == last1) && (first2 != last2);
}

# endif