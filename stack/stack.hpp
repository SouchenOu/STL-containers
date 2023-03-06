/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:36:07 by souchen           #+#    #+#             */
/*   Updated: 2023/02/22 09:18:42 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "../vector/iterators_traits.hpp"
#include "../vector/vector.hpp"
#include "../vector/vector_iterator.hpp"
#include "../vector/vector_reverse_iterator.hpp"
#include "../lexicographical_compare.hpp"
#include "../make_pair.hpp"
#include "../equal.hpp"

#ifndef STACK_HPP
# define STACK_HPP

namespace ft
{
 template <class T, class Container = ft::vector<T> >
    class stack
    {
            public:
                typedef T               value_type;
                typedef Container       container_type;
                typedef size_t          size_type;
            protected:
                container_type c;
        public:
            //***********************constructers**********************
            explicit stack(const container_type &__c = container_type()):c(__c){} 
        //********************copy constructer************************

        stack(const stack &obj): c(obj.c){}
        // *******************assignement operator********************
        stack &operator=(const stack& obj) 
        {
            c = obj.c;
            return *this;
        }

        bool empty() const
        {
            return c.empty();
        }
        size_type size() const
        {
            return c.size();
        }
        value_type& top()
        {
            return c.back();
        }
        void push(const value_type& val)
        {
            return c.push_back(val);
        }
        void pop()
        {
            c.pop_back();
        }
    };

     template <class T, class Alloc>
      bool operator!=(const stack<T,Alloc>& stk1, const stack<T,Alloc>& stk2)
    {
        return !(stk1 == stk2);
    }
    template <class T, class Alloc>
      bool operator<(const stack<T,Alloc>& stk1, const stack<T,Alloc>& stk2)
    {
        return ft::lexicographical_compare(stk1.begin(), stk1.end(), stk2.begin(), stk2.end());
    }
    template <class T, class Alloc>
      bool operator>(const stack<T,Alloc>& stk2, const stack<T,Alloc>& stk1)
    {
        return ft::lexicographical_compare(stk1.begin(), stk1.end(), stk2.begin(), stk2.end());
    }
    template <class T, class Alloc>
      bool operator<=(const stack<T,Alloc>& stk1, const stack<T,Alloc>& stk2)
    {
        return !(stk2 < stk1);
    }
    template <class T, class Alloc>
      bool operator>=(const stack<T,Alloc>& stk1, const stack<T,Alloc>& stk2)
    {
        return !(stk1 < stk2);
    }
};




#endif