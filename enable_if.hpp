/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:51:57 by souchen           #+#    #+#             */
/*   Updated: 2023/01/26 09:51:59 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{
	template <bool Cond, class T = void>
	struct enable_if 					{	};

	template <class T>
	struct enable_if<true, T>			{		typedef T type;		};

	template <class T, T v>
	struct integral_constant
	{
		static const T					value = v;
		T								value_type;
		typedef integral_constant<T, v>	type;
	};

	
};

#endif
