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

namespace ft
{
	template < typename T1, typename T2 >
	class pair
	{
		public: 
			typedef T1	first_type;
			typedef T2	second_type;

			first_type				first;
			second_type			second;

			pair()	:	first(),
						second()	{};
					
			template < typename U, typename V >
			pair(const pair< U,V > & p):	first(p.first),
											second(p.second) {};

			pair(const first_type & a, const second_type & b):	first(a),
																second(b) {}

			pair&		operator = ( pair const& p )
			{
				if ( this != &p )	{	first = p.first; second = p.second;		}
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
};

#endif
