/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Red_black_tree_iter.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:33:56 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:33:58 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




namespace ft{

template<typename T>

class Red_black_tree_iters
{
    public:
        typedef T                                   value_type;
        typedef std::ptrdiff_t                      difference_type;
        typedef T*                                  pointer;
        typedef const T*                            const_pointer;
        typedef T&                                  reference;
        typedef const T&                            const_reference;
        typedef std::bidirectional_iterator_tag     iterator_category;

        typedef Red_black_tree_iters< T >           iterator;
        typedef Red_black_tree_iters<const T >      const_iterator;
        typedef Node< T >                           Node_tree;
        typedef Node<const T>                       const_Node_tree;

        





};

};
