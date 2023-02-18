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
    std::map<int, char> map1;
    ft::map<int, char> map2;

    map2[1] = 'a';
    map2.insert( 2, 'b');
    map1.insert({2, 'b'});

    // declare iteretor
    ft::map<int,char>::iterator it;
    std::map<int,char>::iterator it;

    for(it== map1.begin(); it != map1.end(); it++)
    {
        cout << "First ="<< it.first() << endl;
        cout << "Second =" << it.second() << endl;
    }


    //while()

}