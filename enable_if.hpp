/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:51:57 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:34:19 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF


/***What is enable if function : it is basically a tool to remove some function template instantiation from the overload resolution  */
namespace ft
{
	template <bool Cond, class T = void>
	//here if it is not true
	struct enable_if{	

	};
	// here if it is true
	template <class T>
		struct enable_if<true, T>
	{ 
		typedef T  type; 
		
	};

};

#endif
