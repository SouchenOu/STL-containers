#pragma once
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <memory>
#include <exception>
#include <iostream>

namespace ft
{
    template<class T, class alloc = std::allocator<T> >
    class vector
    {
		public:
        typedef     alloc       allocator_type;
        typedef     T           value_type;
        typedef     size_t       size_type;
        typedef const value_type& const_reference;
        typedef value_type& reference;
		typedef ft::My_Iter<value_type> iterator;
		typedef ft::My_Iter<const value_type> const_iterator;
        typedef typename ft::my_Reviter<value_type> reverse_iterator;
        typedef typename ft::my_Reviter<const value_type> const_reverse_iterator;

        static_assert((ft::is_same<typename allocator_type::value_type, value_type>::value), "Error in types: the allocater and the value");
        private:
    }
}
