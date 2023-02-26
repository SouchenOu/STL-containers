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
    std::map<char,int> mapTest;

    //map2['e'] = 1;
    //map2.insert({ 2, 'b'});
    //map1.insert({2, 'b'});
    map2.insert(ft::pair<char,int>('b',12));
    map2.insert(ft::pair<char,int>('d',13));
    map2.insert(ft::pair<char,int>('c',110));
    //std::pair<std::map<char, int>::iterator,bool> ret;
    //ret = map2.insert(ft::pair<char,int>('z', 500));
    // if(ret.second == false)
    // {
    //     std::cout << ret.first->second<< "\n";
    // }
    //mapTest.insert(ft::pair<char,int>('b',12));

    // declare iteretor
    // ft::map<char,int>::iterator it = map2.begin();
    //std::map<int,char>::iterator it;

    // while(it != map2.end())
    // {
    //     cout << "here\n" << endl; 
    //     cout << "First ="<< it->first << endl;
    //     cout << "Second =" << it->second << endl;
    //     it++;
    // }
    // for(std::map<char,int>::iterator it2 = mapTest.begin();it2 != mapTest.end(); it2++)
    // {
    //     cout << "I enter here\n";
    //     cout << "First elem -->"<< it2->first << endl;
    //     cout << "Second element -->" << it2->second << endl;
    // }
    for(ft::map<char,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
    {
       
        cout << "First elem -->"<< it1->first << endl;
        cout << "Second element -->" << it1->second << endl;
    }
        return 0;

}