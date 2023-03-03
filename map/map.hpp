/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:16:42 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:35:55 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iterator>
# include <algorithm>


# include "../Red_black_Tree/Red_black_tree.hpp"
# include "../Red_black_Tree/Node.hpp"
# include "../vector/vector_iterator.hpp"
# include "../vector/vector_reverse_iterator.hpp"
# include "../make_pair.hpp"
# include "../equal.hpp"
# include "../lexicographical_compare.hpp"

#include "../pair.hpp"

/*template <class T> struct less;
Function object class for less-than inequality comparison*/

/*Binary function object class whose call returns whether the its first argument compares less than the second 
(as returned by operator <).

Generically, function objects are instances of a class with member function 
operator() defined. This member function allows the object to be used with the same syntax 
as a function call.

It is defined with the same behavior as:

C++11
template <class T> struct less : binary_function <T,T,bool> 
{
  bool operator() (const T& x, const T& y) const {return x<y;
}
};*/

namespace ft
{
    template<class Key, class T, class Compare = std::less< Key>,class Allocator = std::allocator<ft::pair<const Key,T > > >
    class map
    {
        public:
            typedef Key                                                         key_type;
            typedef T                                                           mapped_type;
            typedef ft::pair<const Key,T>                                       value_type;
            //key_compare : defaults to: less<key_type>
            typedef Compare                                                     key_compare;
            typedef Allocator                                                   allocator_type;
            // typedef value_type&                                                 reference;
            // typedef const value_type&                                           const_reference;
            //Member class: i declared it here because if i put our class directly here we told me that 
            // value_type is undefined 
            class                                                                value_compare;
        
            typedef typename allocator_type::pointer                             pointer;
            typedef typename allocator_type::const_pointer                       const_pointer;
            typedef typename allocator_type::size_type                           size_type;

            // typedef typename allocator_type::reference                            reference;
            // typedef typename allocator_type::const_reference                      const_reference;
        private:
            typedef Red_black_tree<value_type, value_compare, allocator_type>                     Ttree;

        public:
            typedef typename Ttree::iterator                                            iterator;
            typedef typename Ttree::const_iterator                                      const_iterator;
            typedef ft::reverse_iterator < iterator >                                   reverse_iterator;
            typedef ft::reverse_iterator < const_iterator >                             const_reverse_iterator;
            typedef typename iterator_traits< iterator >::difference_type               difference_type;



            typedef Node <value_type>                                                    Node;

        private:

            Ttree                       _R_B_Ttree;
            key_compare                 _compare;
            allocator_type              _alloc;

        // Member classes
        public:
            class value_compare
            {
                friend class map;
                protected:
                    key_compare comp;
                    value_compare(key_compare c): comp(c){}
                    
                public:
                /*bool operator() (const T& x, const T& y)
                Member function returning whether the first argument compares less than the second (x<y).*/
                    bool operator()(const value_type& __x, const value_type& __y)const
                    {
                        return comp(__x.first, __y.first);
                    }
            };    
            // ***********Member functions:

            // constructers:
            //default constructer
            //map(){}
            //constructer with parameters
            explicit map(const key_compare & __comp = key_compare(), const allocator_type& __a  = allocator_type()):_R_B_Ttree(__comp,__a),_compare(__comp),_alloc(__a){};
            
            // copy constructer

            map(map const & obj):_R_B_Ttree(obj._R_B_Ttree),_compare(obj._compare),_alloc(obj._alloc)
            {};
            

            // template <class _InputIterator>
            // map(_InputIterator _first, _InputIterator _last, key_compare const & _comp = key_compare()): _R_B_Ttree(_comp),_compare(_comp)
            // {
            //         _R_B_Ttree.insert(_first, _last);
            // }
            template <class _InputIterator>
            map(_InputIterator first, _InputIterator last,key_compare const& comp = key_compare(),  allocator_type const& alloc = allocator_type()):_R_B_Ttree(comp,alloc),_compare(comp)
            {
                _R_B_Ttree.insert(first,last);
            }
            // //Assignement operator

            map& operator= (const map& obj)
            {
                if(this != &obj)
                {
                    _R_B_Ttree = obj._R_B_Ttree;
                    _compare = obj._compare;
                    _alloc = obj._alloc;
                }
                return *this;
            }
            ~map(){}

            allocator_type get_allocator() const
            {
                return _R_B_Ttree._alloc;
            }
            value_type get_key(const key_type &k)
            {
                return ft::make_pair(k, mapped_type());
            }

            //Element access
            // mapped_type& operator[](const key_type& )
            // {
            //     // Overloading [] operator to access elements in array style
            // }
            // mapped_type& 	operator[] ( const key_type& k )
            // {	
            //     return (*(insert(ft::make_pair( k, mapped_type() )).first)).second;			
            // }
            mapped_type& 	operator[] ( const key_type& k )
            {	
                return (*(insert(ft::make_pair( k, mapped_type() )).first)).second;	
            };
            // //************ Iterators
                iterator begin()
                {
                    return _R_B_Ttree.begin();
                }
                const_iterator cbegin() const 
                {
                    return _R_B_Ttree.begin();
                }
                iterator end()
                {
                    return _R_B_Ttree.end();
                }
                const_iterator cend() const
                {
                    return _R_B_Ttree.end();
                }
                reverse_iterator rbegin()
                {
                    return _R_B_Ttree.rbegin();
                }
                const_reverse_iterator crbegin() const
                {
                    return _R_B_Ttree.rbegin();
                }
                reverse_iterator rend()
                {
                    return _R_B_Ttree.rend();
                }
                const_reverse_iterator crend() const
                {
                    return _R_B_Ttree.rend();
                }


            //*******Modifiers
            //insert
            ft::pair<iterator, bool> insert (value_type const&_value)
            {
                //cout << _value.first << endl;
                    return _R_B_Ttree.insert(_value);
            }
            iterator insert(iterator __pos, const value_type &value)
            {
                return _R_B_Ttree.insert(__pos, value);
            }
            template <class _InputIterator>
            void insert(_InputIterator first, _InputIterator last)
            {
                _R_B_Ttree.insert(first, last);
            }

           
            void erase(iterator position)
            {
                _R_B_Ttree.erase((position.get_node()));
            }

            size_type erase(const key_type &key)
            {
                return _R_B_Ttree.erase(get_key(key));
            }
            void erase(iterator first, iterator last)
            {

                _R_B_Ttree.erase(first,last);
            }

            // function find
            iterator find(const key_type& key)
            {
                return _R_B_Ttree.find(get_key(key));
            }

            const_iterator find(const key_type& key) const
            {
                return _R_B_Ttree.find(get_key(key));
            }


            //lowerBound and upper bound

            iterator lower_bound(key_type const& key)
            {
                return _R_B_Ttree.lower_bound(get_key(key));
            }
            iterator lower_bound(key_type const &key) const
            {
                return _R_B_Ttree.lower_bound(get_key(key));
            }
            //upper_bound

            iterator upper_bound(key_type const &key)
            {
                return _R_B_Ttree.upper_bound(get_key(key));
            }
            iterator upper_bound(key_type const &key) const
            {
                return _R_B_Ttree.upper_bound(get_key(key));
            }



            //count
            size_type count(key_type const& key) const
            {
                if( (_R_B_Ttree.search(_R_B_Ttree.get_root(), key)) == 0 )
                    return 0;
                else
                    return 1;
            }
             

            //************ //Capacity
            bool empty() const
            {
                return _R_B_Ttree.empty();
            }
            size_type size() const{
                return _R_B_Ttree.size();
            }

            size_type max_size() const{
                return _R_B_Ttree.max_size();
            }
                // doesnt work
            // void swap(map& m)
		    // {	
			// 	_R_B_Ttree.swap(m._R_B_Ttree);						
			// };
            void clear()
            {	
                _R_B_Ttree.clear(_R_B_Ttree.get_root());
            }
            
            ////Observers:
            //key_compare()
            key_compare 	key_comp() const
            {
                	return this->_compare;
                    
            };//value_compare()
			value_compare 				value_comp() const
            {	
                return value_compare(this->_compare);
            };

            // at()

            // mapped_type& at (const key_type& k)
            // {
            //     // if(count(k) == 0)
            //     //     throw std::out_of_range("map ");
            //     // else 
            //     //     return 
            //         Node *node;
            //         node = _R_B_Ttree.search(_R_B_Ttree.get_root(), k);
            //         if(node != NULL)
            //         {
            //             return node->data;
            //         }else
            //             throw std::out_of_range("map ");
            // }
            // // const mapped_type& at (const key_type& k) const
            // // {
            // //     _R_B_Ttree.at(k);
            // // }
            // mapped_type& at(const key_type& k)
            // {
            //     _R_B_Ttree.at(k);
            // }

            
    };
    // No member function

    template <class T, class Allocator>

    bool operator == (const map<T, Allocator>& obj1, const map<T, Allocator>& obj2)
    {
        if(obj1.size() != obj2.size())
        {
            return false;
        }else if(obj1.size() == obj2.size())
        {
            return ft::equal(obj1.begin(), obj1.end(), obj2.begin());
        }
        
    }
    template <class T, class Allocator>
    bool operator != (const map< T, Allocator> &obj1, const map<T, Allocator> & obj2)
    {
        return (obj1 != obj2 );
    }

    template <class T, class Allocator>
    bool operator < (const map<T, Allocator> &obj1, const map <T, Allocator> &obj2)
    {
        return ft::lexicographical_compare(obj1.begin(), obj1.end(), obj2.begin(), obj2.end());
    }
    template <class T, class Allocator>
    bool operator <= (const map<T, Allocator> &obj1, const map <T, Allocator> &obj2)
    {
        return !(obj1 < obj2);
    }
    template <class T, class Allocator>
    bool operator > (const map<T, Allocator> &obj1, const map <T, Allocator> &obj2)
    {
        return (obj1 < obj2);
    }
    template <class T, class Allocator>
    bool operator >= (const map<T, Allocator> &obj1, const map <T, Allocator> &obj2)
    {
        return !(obj1 < obj2);
    };


    // swap doesnt work..
    // template <class T, class Alloc>
	// void	swap(map< T, Alloc >& map1, map< T, Alloc >& map2) 
	// {	
	// 	map1.swap(map2);			
	// }

    
    // template<class T, class Allocator>
    // ostream& operator<< (ostream& os, const map<T, Allocator> & m)
    // {
    //     os << m.value_type;
    //     //os << m.Node->root;
    // }


			 		 
	
};

#endif



