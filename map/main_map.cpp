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

// int main()
// {
//     std::map<int, int> m;
//     m.insert(std::make_pair(1, 10));
//     m.insert(std::make_pair(2, 10));
//     m.insert(std::make_pair(3, 10));
//     m.insert(std::make_pair(4, 10));
//     std::map<int, int>::iterator it = m.end();
//     std::cout<<it->first;


// }
int main()
{
    ft::map<std::string, char> map1;
    ft::map<std::string, int> map2;
    // std::map<std::string,int> mapTest1;
    std::map<std::string, int> mapTest2;
    ft::map<std::string, int> map3;
    // map1

    map3.insert(ft::pair<std::string,int>("ab",12));
    map3.insert(ft::pair<std::string,int>("bc",13));
    map3.insert(ft::pair<std::string,int>("de",110));
    map3.insert(ft::pair<std::string,int>("ef",210));
    map3.insert(ft::pair<std::string,int>("gh",310));
    map3.insert(ft::pair<std::string,int>("ij",410));
    map3.insert(ft::pair<std::string,int>("kl",510));
    map3["mn"] = 2000;
    // map 2
    map2.insert(ft::pair<std::string,int>("one",12));
    map2.insert(ft::pair<std::string,int>("two",13));
    map2.insert(ft::pair<std::string,int>("three",110));
    map2.insert(ft::pair<std::string,int>("four",210));
    map2.insert(ft::pair<std::string,int>("five",310));
    map2.insert(ft::pair<std::string,int>("twelve",410));
    map2.insert(ft::pair<std::string,int>("eleven",510));
    //map2["six"] = 2000;
    // // map test
    mapTest2.insert(std::pair<std::string,int>("one",12));
    mapTest2.insert(std::pair<std::string,int>("two",13));
    mapTest2.insert(std::pair<std::string,int>("three",110));
    mapTest2.insert(std::pair<std::string,int>("four",210));
    mapTest2.insert(std::pair<std::string,int>("five",310));
    mapTest2.insert(std::pair<std::string,int>("twelve",410));
    mapTest2.insert(std::pair<std::string,int>("eleven",510));

    map3.insert(map2.begin() , map2.find("three"));
    // //mapTest1.insert(mapTest2.begin(), mapTest2.find('e'));



    std::cout << "Printing first map*******\n";
    for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
    {
       
        cout << "First elem -->"<< it1->first << endl;
        cout << "Second element -->" << it1->second << endl;
    }
    // //   std::cout<< "Printing second map*******\n";
    // // // for(ft::map<std::string,int>::iterator it2 = map3.begin();it2 != map3.end(); it2++)
    // // // {
       
    // // //     cout << "First elem -->"<< it2->first << endl;
    // // //     cout << "Second element -->" << it2->second << endl;
    // // // }
    cout << "For testing std::map*************************\n";
    for(std::map<std::string,int>::iterator it3 = mapTest2.begin();it3 != mapTest2.end(); it3++)
    {
        cout << "First elem -->"<< it3->first << endl;
        cout << "Second element -->" << it3->second << endl;
    }

    // std::cout << "*****capacity (empty, size, max_size)************************\n";
    // std::cout << "ft::map************************************************************\n";
    // std::cout << "Check empty function -->"<<map2.empty() << endl;
    // std::cout << "Check size function-->" << map2.size() << endl;
    // std::cout << "Check max_size function-->" << map2.max_size() << endl;
    // std::cout << "std::map***********************************************************\n";
    // std::cout << "Check empty function -->"<<mapTest2.empty() << endl;
    // std::cout << "Check size function-->" << mapTest2.size() << endl;
    // std::cout << "Check max_size function-->" << mapTest2.max_size() << endl;



    // // std::cout << "************Modifiers ***(insert, erase, swap, clear, emplace,emplace_hint)**\n";
    // // std::cout << "erase() function **********************\n";
    // // ft::map<std::string,int>::iterator iter;
    // // std::map<std::string,int>::iterator iter2;
    
    // // iter = map2.find("three");
    // // iter2 =  mapTest2.find("three");
    // // map2.erase(iter);
    // // mapTest2.erase(iter2);
    // // // //map2.erase(iter, map2.end()); 
    // //  std::cout << "Printing first map*******\n";
    // // for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
    // // {
    // //     cout << "First elem -->"<< it1->first << endl;
    // //     cout << "Second element -->" << it1->second << endl;
    // // }
    // // cout << "For testing std::map*************************\n";
    // // for(std::map<std::string,int>::iterator it3 = mapTest2.begin();it3 != mapTest2.end(); it3++)
    // // {
    // //     cout << "First elem -->"<< it3->first << endl;
    // //     cout << "Second element -->" << it3->second << endl;
    // // }
    // // std::cout << "swap function ***********\n";
    // // map2.swap(map1);

    // // std::cout << "clear function***************\n";

    // // map2.clear();
    // // mapTest2.clear();
    // // std::cout << "Printing first map*******\n";
    // // for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
    // // {
    // //     cout << "First elem -->"<< it1->first << endl;
    // //     cout << "Second element -->" << it1->second << endl;
    // // }
    // // cout << "For testing std::map*************************\n";
    // // for(std::map<std::string,int>::iterator it3 = mapTest2.begin();it3 != mapTest2.end(); it3++)
    // // {
    // //     cout << "First elem -->"<< it3->first << endl;
    // //     cout << "Second element -->" << it3->second << endl;
    // // }
    std::cout << "key_compare()*******\n";
    cout << "map_test ********\n";
    std::map<std::string, int>::key_compare mycomp1 = mapTest2.key_comp();

    std::string highest1 = mapTest2.rbegin()->first; // last element
    cout << "height-->" << highest1 << endl;
    std::map<std::string, int>::iterator iter11 = mapTest2.begin(); // first element
    do{
        std::cout << iter11->first << "=>" << iter11->second << endl;

    }while(mycomp1((*iter11++).first, highest1));

    cout << "our map*********\n";
    ft::map<std::string, int>::key_compare mycomp2 = map2.key_comp();

    std::string highest2 = map2.rbegin()->first; // last element
    cout << "height-->" << highest2 << endl;
    ft::map<std::string, int>::iterator iter22 = map2.begin(); // first element
    do{
        std::cout << iter22->first << "=>" << iter22->second << endl;

    }while(mycomp2((*iter22++).first, highest2));
    

    //reverse_iterator
    cout << "reverse iters*****\n";
    ft::map<std::string, int>::reverse_iterator rit;
    std::map<std::string, int>::reverse_iterator rit2;
    //rit = map2.rbegin();
    //cout << "first-->"<< rit->first << endl;
    //std::cout << "rend-->" << map2.rend()->first << std::endl;
    for(rit=map2.rbegin(); rit != map2.rend();++rit)
    {
        
       
        std::cout << rit->first << "=>" << rit->second << endl;
    }
    std::cout << "Test map\n";
    //std::cout << "first-->"<< mapTest2.rbegin()->first << endl;
    for(rit2=mapTest2.rbegin(); rit2!= mapTest2.rend();rit2++)
    {
        //break ;
        std::cout << rit2->first << "=>" << rit2->second << endl;
    }
    // cout << "reverse iters*****\n";
    // ft::map<std::string, int>::iterator rit1;
    // for(rit1=map2.begin(); rit1!= map2.end();rit1++)
    // {
    //     std::cout << rit1->first << "=>" << rit1->second << endl;
    // }

    return 0;

}