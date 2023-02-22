/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 09:18:26 by souchen           #+#    #+#             */
/*   Updated: 2023/02/22 09:18:27 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "../Red_black_Tree/Red_black_tree.hpp"
#include "../Red_black_Tree/Red_black_tree_iter.hpp"
#include "../vector/iterators_traits.hpp"
#include "../vector/vector_iterator.hpp"
#include "../vector/vector_reverse_iterator.hpp"
#include "../pair.hpp"
#include "../make_pair.hpp"



#ifndef SET_HPP
#define SET_HPP


namespace ft{
template <class _Key, class _Compare = std::less<_Key>, class _Allocator = std::allocator<_Key> >

class set
{
    public:
        typedef _Key                key_type;
        typedef key_type            value_type;
        typedef _Compare            key_compare;
        typedef key_compare         value_compare;
        typedef _Allocator          allocator_type;
        // typedef value_type&         reference;
        // typedef const value_type&   const_reference;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef             size_t                          size_t;

    private:
            typedef Red_black_tree<value_type, value_compare, allocator_type> _R_B_Ttree;
   
    public:
            typedef typename _R_B_Ttree::iterator                                       iterator;
            typedef typename _R_B_Ttree::const_iterator                                 const_iterator;
            typedef ft::reverse_iterator < iterator >                                   reverse_iterator;
            typedef ft::reverse_iterator < const_iterator >                             const_reverse_iterator;
            typedef typename iterator_traits< iterator >::difference_type               difference_type;


            //*********constructers
            set():_R_B_Ttree(value_compare()){}
            explicit set(const value_compare& __comp):_R_B_Ttree(__comp){}
            explicit set(const value_compare& __comp, const allocator_type& __a):_R_B_Ttree(__comp, __a){}

            template <class _InputIterator>
            set(_InputIterator f,_InputIterator l, const value_compare& _comp = value_compare()):_R_B_Ttree(_comp)
            {
                _R_B_Ttree.insert(f,l);
            }

            //copy constructer
            set(const set& obj): _R_B_Ttree(obj._R_B_Ttree){}

            // Assignement operator

            set& operator=(const set& obj)
            {
                _R_B_Ttree = obj._R_B_Ttree;
                return *this;
            }

            //destructer

            ~set()
            {
                _R_B_Ttree.free();
            }

            //************ Iterators
                iterator begin()
                {
                    return _R_B_Ttree.begin();
                }
                const_iterator begin() const 
                {
                    return _R_B_Ttree.begin();
                }
                iterator end()
                {
                    return _R_B_Ttree.end();
                }
                const_iterator end() const
                {
                    return _R_B_Ttree.end();
                }
                reverse_iterator rbegin()
                {
                    return _R_B_Ttree.rbegin();
                }
                const_reverse_iterator rbegin() const
                {
                    return _R_B_Ttree.rbegin();
                }
                reverse_iterator rend()
                {
                    return _R_B_Ttree.rend();
                }
                const_reverse_iterator rend() const
                {
                    return _R_B_Ttree.rend();
                }



                allocator_type get_allocator() const
                {
                    return _R_B_Ttree._alloc;
                }
                key_compare key_comp() const
                {
                    return _R_B_Ttree.value_comp();
                }
                value_compare value_comp() const{
                    return _R_B_Ttree.value_comp();
                }


                //*******Modifiers
                //insert

                pair<iterator, bool> insert(const value_type& value)
                {
                    return _R_B_Ttree.insert(value);
                }
                iterator insert(const_iterator position, const value_type& value)
                {
                    return _R_B_Ttree.insert(position, value);
                }
                template <class _InputIterator>
                void insert(_InputIterator first, _InputIterator last)
                {
                    return _R_B_Ttree.insert(first,last);
                }

                //erase
                void erase(iterator position)
                {
                    _R_B_Ttree.erase(position);
                }

                size_type erase(const key_type &key)
                {
                    _R_B_Ttree.erase(key);
                }
                void erase(iterator first, iterator last)
                {
                    _R_B_Ttree.erase(first,last);
                }

                       //************ //Capacity
                bool empty() const
                {
                    return _R_B_Ttree.empty();
                }
                size_type size() const
                {
                    return _R_B_Ttree.size();
                }

                size_type max_size() const
                {
                    return _R_B_Ttree.max_size();
                }


                // function find
                iterator find(const key_type& key)
                {
                    return _R_B_Ttree.find(key);
                }

                const_iterator find(const key_type& key) const
                {
                    return _R_B_Ttree.find(key);
                }

                  //count
                size_type count(key_type const& key) const
                {
                    if( (_R_B_Ttree.search(_R_B_Ttree.get_root(), key)) == 0 )
                        return 0;
                    else
                        return 1;
                }

                //lowerBound and upper bound

                iterator lower_bound(key_type const& key)
                {
                    return _R_B_Ttree.lower_bound(key);
                }
                iterator lower_bound(key_type const &key) const
                {
                    return _R_B_Ttree.lower_bound(key);
                }
                //upper_bound

                iterator upper_bound(key_type const &key)
                {
                    return _R_B_Ttree.upper_bound(key);
                }
                iterator upper_bound(key_type const &key) const
                {
                    return _R_B_Ttree.upper_bound(key);
                }

             









};

};

#endif
