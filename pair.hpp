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


// #ifndef PAIR_HPP
// # define PAIR_HPP



// //Maps are associative containers that store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have same key values.
// namespace ft
// {
//     // its a template class
// 	template <typename type1, typename type2>
//     class pair
//     {
//         public:
//             typedef type1 first_type;
//             typedef type2 second_type;


//             first_type  first;
//             second_type second;

//             pair() : first(),second(){};
        
//             //copy constructer
//             template<class U, class V> 
//             pair (const pair< U,V >& pr): first(pr.first), second(pr.second){};
        
//             // initialisition constructor

//             pair (const first_type& a, const second_type& b):first(a),second(b){};
       
        
//             //destructur

//             ~pair(){}
//             //assignement operator:
//             pair& operator = (pair const& pr)
//             {
//                 if ( this != &pr )	{	first = pr.first; second = pr.second;		}
// 				return *this;
//             }

//     };
//     template <class type1, class type2>
//     pair<type1,type2> make_pair (type1 a, type2 b)
//     {
//             return (pair<type1,type2>(a,b));
//     }
//     template <typename type1, typename type2>
//     bool operator == (const pair <type1,type2> &obj1, const pair <type1,type2> &obj2)
//     {
//         return(obj1.first == obj2.first  && obj1.second == obj2.second);
//     }
//     template <typename type1, typename type2>
//     bool operator != (const pair <type1, type2> &obj1, const pair <type1, type2> &obj2)
//     {
//         return (obj1.first != obj2.first && obj1.second != obj2.second);
//     }
//     template<typename type1, typename type2>
//     bool operator < (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
//     {
//         return (obj1.first < obj2.first || obj1.second < obj2.second);
//     }
//      template<typename type1, typename type2>
//     bool operator <= (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
//     {
//         return !(obj1 < obj2);
//     }
//      template<typename type1, typename type2>
//     bool operator > (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
//     {
//         return (obj1 < obj2);
//     }
//     template<typename type1, typename type2>
//     bool operator >= (const pair <type1,type2> &obj1, const pair <type1, type2> &obj2)
//     {
//         return !(obj1 < obj2);
//     }

// };


// /*******Return value
// 1) true if both lhs.first == rhs.first and lhs.second == rhs.second, otherwise false
// 2) !(lhs == rhs)
// 3) If lhs.first < rhs.first, returns true. Otherwise, if rhs.first < lhs.first, returns false. Otherwise, if lhs.second < rhs.second, returns true. Otherwise, returns false.
// 4) !(rhs < lhs)
// 5) rhs < lhs
// 6) !(lhs < rhs)
// 7) synth_three_way(lhs.first, rhs.first) if it is not equal to ​0​, otherwise synth_three_way(lhs.second, rhs.second), where synth_three_way is an exposition-only function object performing synthesized three-way comparison.*/
// #endif


#ifndef PAIR_HPP
# define PAIR_HPP

#include "iostream"
using namespace std;

namespace ft
{
	template < typename T1, typename T2 >
	class pair
	{
		public: 
			typedef T1	first_type;
			typedef T2	second_type;

			T1				first;
			T2			second;

			pair()	:	first(),
						second()	{};
					
			template < class U1, class U2 >
			pair(const pair< U1,U2 > & p):	first(p.first),
											second(p.second) {};

			pair(T1 const & a, T2 const & b):	first(a),second(b) {}

			pair&		operator = ( pair const& p )
			{
				first = p.first;
                second = p.second;
				return *this;
			}
			~pair() {};
	};

	template < typename T1, typename T2 >
	pair< T1, T2 > make_pair ( T1 x, T2 y )										{	return pair< T1, T2 >( x, y );	}

	template < typename T1, typename T2 >
	bool	operator == ( const pair< T1, T2 > & l, const pair< T1, T2 > & r )	{ return l.first == r.first && l.second == r.second; }

	template < typename T1, typename T2 >
	bool	operator != ( const pair< T1, T2 > & l, const pair< T1, T2 > & r )	{ return !(l == r); }

	template < typename T1, typename T2 >
	bool	operator < ( const pair< T1, T2 > & l, const pair< T1, T2 > & r )	{ return l.first < r.first || (!(r.first < l.first) && l.second < r.second); }

	template < typename T1, typename T2 >
	bool	operator <= ( const pair< T1, T2 > & l, const pair< T1, T2 > & r )	{ return !(r < l); }

	template < typename T1, typename T2 >
	bool	operator > ( const pair< T1, T2 > & l, const pair< T1, T2 > & r )	{ return r < l; }

	template < typename T1, typename T2 >
	bool	operator >= ( const pair< T1, T2 > & l, const pair< T1, T2 > & r )	{ return !(l < r); }
    template < typename T1, typename T2 >
	ostream	& operator << (ostream &out, const pair<T1,T2> &p)
    {
        out << p.first << std::endl;
        out << p.second << std::endl;
        return out;
    }
};

#endif

