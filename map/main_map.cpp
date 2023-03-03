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


// #include "iostream"
// #include "map.hpp"
// #include "../vector/vector_iterator.hpp"
// #include "../vector/vector_reverse_iterator.hpp"
// #include "map"

// using namespace std;


// int main()
// {
//     ft::map<std::string, char> map1;
//     ft::map<std::string, int> map2;
//     // std::map<std::string,int> mapTest1;
//     std::map<std::string, int> mapTest2;
//     ft::map<std::string, int> map3;
//     ft::map<std::string, int>::iterator i1;
//     // map1

//     map3.insert(ft::pair<std::string,int>("ab",12));
//     map3.insert(ft::pair<std::string,int>("bc",13));
//     map3.insert(ft::pair<std::string,int>("de",110));
//     map3.insert(ft::pair<std::string,int>("ef",210));
//     map3.insert(ft::pair<std::string,int>("gh",310));
//     map3.insert(ft::pair<std::string,int>("ij",410));
//     map3.insert(ft::pair<std::string,int>("kl",510));
//     map3["mn"] = 2000;
//     // map 2
//     map2.insert(ft::pair<std::string,int>("one",12));
//     map2.insert(ft::pair<std::string,int>("two",13));
//     map2.insert(ft::pair<std::string,int>("three",110));
//     map2.insert(ft::pair<std::string,int>("four",210));
//     map2.insert(ft::pair<std::string,int>("five",310));
//     map2.insert(ft::pair<std::string,int>("twelve",410));
//     map2.insert(ft::pair<std::string,int>("eleven",510));
//     map2["six"] = 2000;
//     //map2.insert({"seven", 700});
//     i1 = map2.find("three");
//     map2.insert(i1,ft::pair<std::string,int>("seventeen",120)); // should work..
//     // // map test
//     mapTest2.insert(std::pair<std::string,int>("one",12));
//     mapTest2.insert(std::pair<std::string,int>("two",13));
//     mapTest2.insert(std::pair<std::string,int>("three",110));
//     mapTest2.insert(std::pair<std::string,int>("four",210));
//     mapTest2.insert(std::pair<std::string,int>("five",310));
//     mapTest2.insert(std::pair<std::string,int>("twelve",410));
//     mapTest2.insert(std::pair<std::string,int>("eleven",510));
//     mapTest2["six"] = 2000;
//     map3.insert(map2.begin() , map2.find("three"));
//     // //mapTest1.insert(mapTest2.begin(), mapTest2.find('e'));



//     std::cout << "Printing first map*******\n";
//     for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
//     {
       
//         cout << "First elem -->"<< it1->first << endl;
//         cout << "Second element -->" << it1->second << endl;
//     }
//     // //   std::cout<< "Printing second map*******\n";
//     // // // for(ft::map<std::string,int>::iterator it2 = map3.begin();it2 != map3.end(); it2++)
//     // // // {
       
//     // // //     cout << "First elem -->"<< it2->first << endl;
//     // // //     cout << "Second element -->" << it2->second << endl;
//     // // // }
//     cout << "For testing std::map*************************\n";
//     for(std::map<std::string,int>::iterator it3 = mapTest2.begin();it3 != mapTest2.end(); it3++)
//     {
//         cout << "First elem -->"<< it3->first << endl;
//         cout << "Second element -->" << it3->second << endl;
//     }

//     std::cout << "*****capacity (empty, size, max_size)************************\n";
//     std::cout << "ft::map************************************************************\n";
//     std::cout << "Check empty function -->"<<map2.empty() << endl;
//     std::cout << "Check size function-->" << map2.size() << endl;
//     std::cout << "Check max_size function-->" << map2.max_size() << endl;
//     std::cout << "std::map***********************************************************\n";
//     std::cout << "Check empty function -->"<<mapTest2.empty() << endl;
//     std::cout << "Check size function-->" << mapTest2.size() << endl;
//     std::cout << "Check max_size function-->" << mapTest2.max_size() << endl;



//     std::cout << "************Modifiers ***(insert, erase, swap, clear, emplace,emplace_hint)**\n";
//     std::cout << "erase() function **********************\n";
//     ft::map<std::string,int>::iterator iter;
//     std::map<std::string,int>::iterator iter2;
    
//     iter = map2.find("three");
//     iter2 =  mapTest2.find("three");
//     map2.erase(iter);
//     mapTest2.erase(iter2);
//     // //map2.erase(iter, map2.end()); 
//      std::cout << "Printing first map*******\n";
//     for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
//     {
//         cout << "First elem -->"<< it1->first << endl;
//         cout << "Second element -->" << it1->second << endl;
//     }
//     cout << "For testing std::map*************************\n";
//     for(std::map<std::string,int>::iterator it3 = mapTest2.begin();it3 != mapTest2.end(); it3++)
//     {
//         cout << "First elem -->"<< it3->first << endl;
//         cout << "Second element -->" << it3->second << endl;
//     }
//     // std::cout << "swap function ***********\n";
//     // map2.swap(map1);

//     // std::cout << "clear function***************\n";

//     // map2.clear();
//     // mapTest2.clear();
//     // std::cout << "Printing first map*******\n";
//     // for(ft::map<std::string,int>::iterator it1 = map2.begin();it1 != map2.end(); it1++)
//     // {
//     //     cout << "First elem -->"<< it1->first << endl;
//     //     cout << "Second element -->" << it1->second << endl;
//     // }
//     // cout << "For testing std::map*************************\n";
//     // for(std::map<std::string,int>::iterator it3 = mapTest2.begin();it3 != mapTest2.end(); it3++)
//     // {
//     //     cout << "First elem -->"<< it3->first << endl;
//     //     cout << "Second element -->" << it3->second << endl;
//     // }
//     std::cout << "key_compare()****&& value_compare()***\n";
//     cout << "map_test key_compare()********\n";
//     std::map<std::string, int>::key_compare mycomp1 = mapTest2.key_comp();

//     std::string highest1 = mapTest2.rbegin()->first; // last element
//     std::map<std::string, int>::iterator iter11 = mapTest2.begin(); // first element
//     do{
//         std::cout << iter11->first << "=>" << iter11->second << endl;

//     }while(mycomp1((*iter11++).first, highest1));

//     cout << "our map*****key_compare()****\n";
//     ft::map<std::string, int>::key_compare mycomp2 = map2.key_comp();

//     std::string highest2 = map2.rbegin()->first; // last element
//     ft::map<std::string, int>::iterator iter22 = map2.begin(); // first element
//     do{
//         std::cout << iter22->first << "=>" << iter22->second << endl;

//     }while(mycomp2((*iter22++).first, highest2));
    
//     std::cout << "map_test value_compare()*******\n";
//     std::pair<std::string, int> heigh = *mapTest2.rbegin();
//     std::map<std::string, int>::iterator itTest = mapTest2.begin();

//     do{
//         std::cout << itTest->first << "=>" << itTest->second << endl;
//     }while(mapTest2.value_comp()(*itTest++, heigh));

//     std::cout << "our map value_compare()*******\n";
//     ft::pair<std::string, int> heigh1 = *map2.rbegin();
//     ft::map<std::string, int>::iterator Test = map2.begin();

//     do{
//         std::cout << Test->first << "=>" << Test->second << endl;
//     }while(map2.value_comp()(*Test++, heigh1));


//     //reverse_iterator
//     cout << "reverse iters*****\n";
//     ft::map<std::string, int>::reverse_iterator rit;
//     std::map<std::string, int>::reverse_iterator rit2;
//     //rit = map2.rbegin();
//     //cout << "first-->"<< rit->first << endl;
//     //std::cout << "rend-->" << map2.rend()->first << std::endl;
//     for(rit=map2.rbegin(); rit != map2.rend();++rit)
//     {
//         std::cout << rit->first << "=>" << rit->second << endl;
//     }
//     std::cout << "Test map\n";
//     //std::cout << "first-->"<< mapTest2.rbegin()->first << endl;
//     for(rit2=mapTest2.rbegin(); rit2!= mapTest2.rend();rit2++)
//     {
//         //break ;
//         std::cout << rit2->first << "=>" << rit2->second << endl;
//     }

//     // cout << "reverse iters*****\n";
//     // ft::map<std::string, int>::iterator rit1;
//     // for(rit1=map2.begin(); rit1!= map2.end();rit1++)
//     // {
//     //     std::cout << rit1->first << "=>" << rit1->second << endl;
//     // }
//     cout<< "const iters*****\n";
//     ft::map<std::string, int>::const_iterator rit3;
//     std::map<std::string, int>::const_iterator rit4;
//     std::cout << "our map*******\n";
//     for(rit3 = map2.cbegin(); rit3 != map2.cend(); rit3++)
//     {
//         std::cout << rit3->first << "=>" << rit3->second << std::endl;
//     }
//     std::cout << "Test map***\n";
//     for(rit4 = mapTest2.cbegin(); rit4 != mapTest2.cend(); rit4++)
//     {
//         std::cout << rit4->first << "=>" << rit4->second << std::endl;
//     }

//     cout << "const reverse iters***\n";

//     std::map<std::string, int>::const_reverse_iterator iter33;
//     ft::map<std::string, int>::const_reverse_iterator iter44;
//        std::cout << "our map*******\n";
//     for(iter44 = map2.crbegin(); iter44 != map2.crend(); iter44++)
//     {
//         std::cout << iter44->first << "=>" << iter44->second << std::endl;
//     }
//     std::cout << "Test map***\n";
//     for(iter33 = mapTest2.crbegin(); iter33 != mapTest2.crend(); iter33++)
//     {
//         std::cout << iter33->first << "=>" << iter33->second << std::endl;
//     }



//     //lower_bound and upper_bound

//     std::cout << "map_test-->Lower_bound*****&& upper_bound**** \n";

//     // std::map<std::string, int>::iterator itlow,itup;

//     // itlow = mapTest2.lower_bound("three");
//     // itup = mapTest2.upper_bound("five");

//     // mapTest2.erase(itlow,itup);

//     // i should check here again --> still have a problem
//     cout << "For testing std::map*************************\n";
//     std::cout << "upper_bound()******\n";
//     std::cout << "First-->"<<map2.upper_bound("three")->first << "  Second-->" << map2.upper_bound("three")->second << endl;
//     std::cout << "lower_bound()********\n";
//     std::cout << "First-->"<<map2.lower_bound("three")->first << "  Second-->" << map2.lower_bound("three")->second << endl;


//     return 0;

// }