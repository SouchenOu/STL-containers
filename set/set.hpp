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
#include "../Red_black_Tree/Node.hpp"
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
        typedef             size_t                          size_type;

    private:
            typedef Red_black_tree<value_type, value_compare, allocator_type> _R_B_Ttree;

   
    public:
            typedef typename _R_B_Ttree::iterator                                       iterator;
            typedef typename _R_B_Ttree::const_iterator                                 const_iterator;
            typedef ft::reverse_iterator < iterator >                                   reverse_iterator;
            typedef ft::reverse_iterator < const_iterator >                             const_reverse_iterator;
            typedef typename iterator_traits< iterator >::difference_type               difference_type;
    private:
        _R_B_Ttree              Ttree;
        value_compare              _compare;
        allocator_type           _alloc;
    public:
            //*********constructers
            //set():Ttree(value_compare()){}
            //explicit set(const value_compare& __comp):Ttree(__comp){}
            explicit set(const value_compare& __comp = value_compare(), const allocator_type& __a = allocator_type()):Ttree(__comp, __a),_compare(__comp),_alloc(__a){}

            template <class _InputIterator>
            set(_InputIterator f,_InputIterator l, const value_compare& _comp = value_compare(), const allocator_type& alloc = allocator_type()):Ttree(_comp, alloc)
            {
                Ttree.insert(f,l);
            }

            //copy constructer
            set(const set& obj): Ttree(obj.Ttree)
            {
                *this = obj;
            }

            // Assignement operator

            set& operator=(const set& obj)
            {
                //Ttree.free();
                Ttree = obj.Ttree;
                return *this;
            }

            //destructer

            ~set()
            {
            }

            //************ Iterators
                iterator begin()
                {
                    return Ttree.begin();
                }
                const_iterator cbegin() const 
                {
                    return Ttree.begin();
                }
                iterator end()
                {
                    return Ttree.end();
                }
                const_iterator cend() const
                {
                    return Ttree.end();
                }
                reverse_iterator rbegin()
                {
                    return Ttree.rbegin();
                }
                const_reverse_iterator crbegin() const
                {
                    return Ttree.rbegin();
                }
                reverse_iterator rend()
                {
                    return Ttree.rend();
                }
                const_reverse_iterator crend() const
                {
                    return Ttree.rend();
                }



                allocator_type get_allocator() const
                {
                    return Ttree._alloc;
                }
                key_compare key_comp() const
                {
                    return Ttree.value_comp();
                }
                value_compare value_comp() const{
                    return Ttree.value_comp();
                }


                //*******Modifiers
                //insert

                pair<iterator, bool> insert(const value_type& value)
                {
                    return Ttree.insert(value);
                }
                iterator insert(iterator position, const value_type& value)
                {
                    return Ttree.insert(position, value);
                }
                template <class _InputIterator>
                void insert(_InputIterator first, _InputIterator last)
                {
                    return Ttree.insert(first,last);
                }

                //erase
                void erase(iterator position)
                {
                    Ttree.erase(*position);
                }

                size_type erase(const key_type &key)
                {
                    return Ttree.erase(key);
                }
                void erase(iterator first, iterator last)
                {

                    Ttree.erase(first,last);
                }

                       //************ //Capacity
                bool empty() const
                {
                    return Ttree.empty();
                }
                size_type size() const
                {
                    return Ttree.size();
                }

                size_type max_size() const
                {
                    return Ttree.max_size();
                }


                // function find
                iterator find(const key_type& key)
                {
                    return Ttree.find(key);
                }

                const_iterator find(const key_type& key) const
                {
                    return Ttree.find(key);
                }

                  //count
                size_type count(key_type const& key)
                {
                    if( (Ttree.search(Ttree.get_root(), key)) == 0 )
                        return 0;
                    else
                        return 1;
                }
                //clear
                void clear()
                {	
                    Ttree.clear();
                }
                //swap

                // void swap(set& s)
                // {
                //      Ttree.swap(s.Ttree);
                // }
    
                //lowerBound and upper bound

                iterator lower_bound(key_type const& key)
                {
                    return Ttree.lower_bound(key);
                }
                iterator lower_bound(key_type const &key) const
                {
                    return Ttree.lower_bound(key);
                }
                //upper_bound

                iterator upper_bound(key_type const &key)
                {
                    return Ttree.upper_bound(key);
                }
                iterator upper_bound(key_type const &key) const
                {
                    return Ttree.upper_bound(key);
                }

                //equal_range()
      
                ft::pair<iterator,iterator> equal_range (const key_type& k)
                {
                    iterator iter = iterator(Ttree.find(k));
                        if (iter == this->end())
                            return ft::make_pair(iter, iter);
                        else
                            return ft::make_pair(iter++, iter);
                }
                ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
                {
                    const_iterator iter = const_iterator(Ttree.find(k));
                        if (iter == this->end())
                            return ft::make_pair(iter, iter);
                        else
                            return ft::make_pair(iter, ++iter);
                }

             









};

};

#endif
