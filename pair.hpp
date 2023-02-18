/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/26 09:51:35 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PAIR_HPP
# define PAIR_HPP



//Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.
namespace ft
{
    // its a template class
	template <typename type1, typename type2>
    class pair
    {
        typedef type1 first_type;
        typedef type2 second_type;


        first_type  a;
        second_type b;

        //default constructer
        pair(){}
        //copy constructer
        template<class U, class V> pair (const pair<U,V>& pr)
        {
            a = pr.a;
            b = pr.b;
        }
        // initialisition constructor

        pair (const first_type& a, const second_type& b)
        {
                a(a);
                b(b);
        }
        
        //destructur

        ~pair(){}
        //assignement operator:
        pair& operator= (const pair& pr)
        {
            if(&pr == this)
            {
                return (*this);
            }
            a(a);
            b(b);
        }

    };
    template <typename type1, typename type2>
    bool operator == (const pair <type1,type2> &obj1, const pair <type1,type2> &obj2)
    {
        return(obj1.a == obj2.a  && obj1.b == obj2.b);
    }
    template <typename type1, typename type2>
    bool operator != (const pair <type1, type2> &obj1, const pair <type1, type2> &obj2)
    {
        return (obj1.a != obj2.a && obj1.b != obj2.b);
    }
    template<typename type1, typename type2>
    bool operator < (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
    {
        return (obj1.a < obj2.a || obj1.b < obj2.b);
    }
     template<typename type1, typename type2>
    bool operator <= (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
    {
        return !(obj1 < obj2);
    }
     template<typename type1, typename type2>
    bool operator > (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
    {
        return (obj1 < obj2);
    }
    template<typename type1, typename type2>
    bool operator >= (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
    {
        return !(obj1 < obj2);
    }

};


/*******Return value
1) true if both lhs.first == rhs.first and lhs.second == rhs.second, otherwise false
2) !(lhs == rhs)
3) If lhs.first < rhs.first, returns true. Otherwise, if rhs.first < lhs.first, returns false. Otherwise, if lhs.second < rhs.second, returns true. Otherwise, returns false.
4) !(rhs < lhs)
5) rhs < lhs
6) !(lhs < rhs)
7) synth_three_way(lhs.first, rhs.first) if it is not equal to ​0​, otherwise synth_three_way(lhs.second, rhs.second), where synth_three_way is an exposition-only function object performing synthesized three-way comparison.*/
#endif
