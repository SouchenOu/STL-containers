/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:20:24 by souchen           #+#    #+#             */
/*   Updated: 2023/02/18 13:20:26 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "iostream"
#include "map.hpp"
#include "../vector/vector_iterator.hpp"
#include "../vector/vector_reverse_iterator.hpp"
#include "map"

using namespace std;

int main()
{
    //std::map<int, char> map1;
    ft::map<char, int> map2;

    //map2['a'] = 1;
    //map2.insert({ 2, 'b'});
    //map1.insert({2, 'b'});
    map2.insert(ft::pair<char,int>('a',12));

    // declare iteretor
    ft::map<char,int>::iterator it;
    //std::map<int,char>::iterator it;

    for(it= map2.begin(); it != map2.end(); it++)
    {
        cout << "here\n" << endl;
        cout << "First ="<< it->first << endl;
        cout << "Second =" << it->second << endl;
    }
cout << "hello" << endl;
return 0;
    // //while()

}