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
    ft::map<std::string, int> map2;
    std::map<std::string,int> mapTest1;
    std::map<std::string, int> mapTest2;
    ft::map<std::string, int> map3;

    //map2['e'] = 1;
    //map2.insert({ 2, 'b'});
    //map1.insert({2, 'b'});
    map2.insert(ft::pair<std::string,int>("one",12));
    map2.insert(ft::pair<std::string,int>("two",13));
    map2.insert(ft::pair<std::string,int>("three",110));
    map2.insert(ft::pair<std::string,int>("four",210));
    // map2.insert(ft::pair<std::string,int>("five",310));
    // map2.insert(ft::pair<std::string,int>("six",410));
    // map test
    mapTest2.insert(std::pair<std::string,int>("one",12));
    mapTest2.insert(std::pair<std::string,int>("two",13));
    mapTest2.insert(std::pair<std::string,int>("three",110));
    mapTest2.insert(std::pair<std::string,int>("four",210));
    // mapTest2.insert(std::pair<std::string,int>("five",310));
    // mapTest2.insert(std::pair<std::string,int>("six",410));

    map3.insert(map2.begin() , map2.find("three"));
    //mapTest1.insert(mapTest2.begin(), mapTest2.find('e'));



    std::cout << "Printing first map*******\n";
    for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
    {
       
        cout << "First elem -->"<< it1->first << endl;
        cout << "Second element -->" << it1->second << endl;
    }
      std::cout<< "Printing second map*******\n";
    for(ft::map<std::string,int>::iterator it2 = map3.begin();it2 != map3.end(); it2++)
    {
       
        cout << "First elem -->"<< it2->first << endl;
        cout << "Second element -->" << it2->second << endl;
    }
    // cout << "For testing std::map*************************\n";
    // for(std::map<char,int>::iterator it2 = mapTest1.begin();it2 != mapTest1.end(); it2++)
    // {
    //     cout << "First elem -->"<< it2->first << endl;
    //     cout << "Second element -->" << it2->second << endl;
    // }

    std::cout << "*****capacity (empty, size, max_size)************************\n";
    std::cout << "ft::map************************************************************\n";
    std::cout << "Check empty function -->"<<map2.empty() << endl;
    std::cout << "Check size function-->" << map2.size() << endl;
    std::cout << "Check max_size function-->" << map2.max_size() << endl;
    std::cout << "std::map***********************************************************\n";
    std::cout << "Check empty function -->"<<mapTest2.empty() << endl;
    std::cout << "Check size function-->" << mapTest2.size() << endl;
    std::cout << "Check max_size function-->" << mapTest2.max_size() << endl;



    std::cout << "************Modifiers ***(insert, erase, swap, clear, emplace,emplace_hint)**\n";
    std::cout << "erase() function **********************\n";
    ft::map<std::string,int>::iterator iter;
    iter = map2.find("three");
    map2.erase(iter, map2.end()); 
     std::cout << "Printing first map*******\n";
    for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
    {
       
        cout << "First elem -->"<< it1->first << endl;
        cout << "Second element -->" << it1->second << endl;
    }
    
    
    return 0;

}