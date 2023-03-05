/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 10:29:24 by souchen           #+#    #+#             */
/*   Updated: 2023/03/05 10:29:25 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iostream>
#include "vector/vector.hpp"
#include "map/map.hpp"
#include "set/set.hpp"
#include "stack/stack.hpp"

void   breakFunc()
{
    std::string h;
    while (1)
    {
        getline(std::cin,h);
        if (h.empty())
            break;
    }
}

int main()
{
    ft::set<int> setElem1;
    ft::set<int> setElem4;
    std::set<int>setTest;
    ft::set<int> assign_set;
    std::set<int> set;
	ft::set<int>::iterator it1;
    ft::set<int>::iterator it2;
	ft::set<int>::reverse_iterator rev1;
    std::cout << "inserting 7 elements in set"  << std::endl;
    for (int i = 0 ; i <= 7 ; i++)
        setElem1.insert(i);
    for (int i = 1 ; i <= 10 ; i++)
        setElem4.insert(i * 100 );
    for (int i = 1 ; i <= 10 ; i++)
        setTest.insert(i * 100 );
    std::cout << "size -->" << setElem1.size() << std::endl;
    std::cout << "********>Print our set******-->: " <<std::endl;
    for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
        std::cout << "Our set-->: "  << *it1  << std::endl;

    std::cout << "***********************[Set]*******************************\n" << std::endl;
    std::cout << "----------------------------------------------------------\n";
    std::cout << "Testing copy constructor, assignement operator and constructer with iterators\n" << std::endl;
    std::cout << "------>Testing copy constructer<-----\n";
    ft::set<int> setElem2(setElem1);
    ft::set<int> setElem3(setElem1.begin(),setElem1.end());


    std::cout << "********>Print set2<********:\n";
    for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
        std::cout << "Set2-->: "  << *it1  << std::endl;
    std::cout << "*******>Print set3<******:\n";
    for ( it1 = setElem3.begin() ; it1 != setElem3.end() ; it1++)
        std::cout << "set3-->: "  << *it1  << std::endl;
    
    std::cout << "------>Testing assignement operator<-----\n";
    std::set<int> assignSet;

    for (int i = 5 ; i < 10 ; i++)
        assign_set.insert(i * 10);

    setElem2 = assign_set;
    std::cout << "assign_set size :" << assign_set.size() << std::endl;
    std::cout << "set_2  size :" << setElem2.size() << std::endl;

    std::cout << "********>Print assign_set<******* " << std::endl;
    for ( it1 = assign_set.begin() ; it1 != assign_set.end() ; it1++)
        std::cout << "Assign set :: "  << *it1 <<  std::endl;
	
    std::cout << "********>Print copy_Set<******** " << std::endl;
    for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
        std::cout << "copy_set: "  << *it1 <<  std::endl;
    // breakFunc();
    std::cout << "------------------------Capacity----------------------------------\n";
    std::cout << "------------->Testing size(), max_size()<------------\n";

    std::cout << "Size() :-->" << setElem1.size() << std::endl;
    std::cout << "Max_size()--->" << setElem1.max_size() << std::endl;
    // breakFunc();
    std::cout << "----------------------Modifiers-----------------------------" << std::endl;
    std::cout << "------------------>testing insert<-------------------" << std::endl;

    std::cout << "inserting one element in set :" << std::endl;
    std::cout << "size before insert : " << setElem1.size() << std::endl;
    setElem1.insert(setElem1.begin(),70);
    std::cout << "size after insert : " << setElem1.size() << std::endl;
	// breakFunc();
    std::cout << "inserting element that already exists :" << std::endl;
    setElem1.insert(setElem1.begin(),7);
    std::cout << "size after insert will not change: " << setElem1.size() << std::endl;
	// breakFunc();
    std::cout << "Inserting range of element that already exist : \n";
    std::cout << "size before insert : " << setElem1.size() << std::endl;
    setElem1.insert(setElem1.begin(),setElem1.end());
    std::cout << "size after insert will not change :" << setElem1.size() << std::endl;
	// breakFunc();
    std::cout << "Inserting our set by using an array of integers\n";
    int array[] = {500,600,700};
    setElem1.insert(array,array+3);
    std::cout << "******>Print our set<*******\n";
    for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
        std::cout << "Our set ->"  << *it1 <<  std::endl;
    // std::cout << "inserting more 1000 elements : " << std::endl;
    // for (int i = 200 ; i < 1000 ; i++)
    //     setElem1.insert(i);
    // std::cout << "******>Print our set<*******\n";
    // for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
    //     std::cout << "Our set ->"  << *it1 <<  std::endl;
    
    // std::cout << "size now-->" << setElem1.size() << std::endl;
    
    std::cout << "------------------->Testing erasing<-----------------------" << std::endl;
    setElem1.erase(0);
    std::cout << "size now : " << setElem1.size() << std::endl;
    if (setElem1.empty())
        std::cout << "our set is empty now " << std::endl;
    else 
        std::cout << "Our set not empty\n";

    std::cout << "******>Print our set<*******\n";
    for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
        std::cout << "Our set ->"  << *it1 <<  std::endl;
	// breakFunc();

    std::cout << "erasing first 9 elements" << std::endl;
    for (int i = 0 ; i < 9 ;i++ )
        setElem1.erase(i);
    std::cout << "erasing ... " << std::endl;
    std::cout << "size now " << setElem1.size() << std::endl;
     std::cout << "******>Print our set<*******\n";
    for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
        std::cout << "Our set ->"  << *it1 <<  std::endl;
	// breakFunc();
    // std::cout << "----------------->Testing swap<----------------------------------" << std::endl;
    // ft::set<int> swap_set;

    // for (int i = 10 ; i < 100 ; i++)
    //     swap_set.insert(i);
    // std::cout << "exchanging content of set with swapSet" << std::endl;
    // std::cout << "swapSet only has 3 elements" << std::endl;
    // setElem1.swap(swapSet);
    // std::cout << "Size of the setElem1 now : " << setElem1.size() <<  std::endl;
	// breakFunc();
    // std::cout << "Checking elements of setElem1 && swap_set :"  << std::endl;
    //std::cout << "setElem1 elements :\n";
    // for (it = setElem1.begin() ; it != setElem1.end() ; it++ )
    //     std::cout << "setElem1 element->" << *it << std::endl;
    // std::cout << "size of swap_set now :  " << swapSet.size() << std::endl;
    // std::cout << "swap_set elements : " << std::endl;
    // for (it = swap_set.begin() ; it != swap_set.end() ; it++ )
    //     std::cout << "swap_set elements -> " << *it << std::endl;
	// breakFunc();
    // std::cout << "---------------------------------------------------" << std::endl;
    
    // std::cout << "Clearing elements of swapSet " << std::endl;
    // swap_set.clear();
    // std::cout << "clearing ... " << std::endl;
    // std::cout << "size of swap_set now : " << swap_set.size() << std::endl;
	// breakFunc();
    std::cout << "----------------------Operations-----------------------------" << std::endl;
    std::cout << "--------------------->Testing Find()<-----------------------------" << std::endl; 
    std::cout << "Print setElem2 before erasing 60 && 80-->"; 
    for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
        std::cout << "Our set ->"  << *it1 <<  std::endl;
    it2 = setElem2.find(60);
    std::cout << "Our iterator point -->: " << *it2 << std::endl;
    setElem2.erase(it2);
    setElem2.erase(setElem2.find(80));
    std::cout << "Print setElem2 After erasing 60 && 80-->"; 
    for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
        std::cout << "Our set ->"  << *it1 <<  std::endl;
	// breakFunc();
    std::cout << "--------------------->Testing count()<------------------------------" << std::endl;
    if(setElem2.count(3) != 0)
    {
        std::cout << "This number is an element in my set\n";
    }else
        std::cout << "This number is not an element in my set\n";
    
	// breakFunc();
    std::cout << "-------------------->Testing Lower_bound && Upper_bound<-------------------------------" << std::endl;
    std::cout << 

    std::cout << "Our set++++++++++++++++++\n";
    std::cout << "lower bound of 1 : " << *setElem4.lower_bound(100) << std::endl;
    std::cout << "lowe bound of 2 : " << *setElem4.lower_bound(200) << std::endl;
    std::cout << "upper bound of 1 : " << *setElem4.upper_bound(100) << std::endl;
    std::cout << "upper bound of 2 : " << *setElem4.upper_bound(200) << std::endl;
    std::cout << "Test set++++++++++++++++++\n";
    std::cout << "lower bound of 1 : " << *setTest.lower_bound(100) << std::endl;
    std::cout << "lowe bound of 2 : " << *setTest.lower_bound(200) << std::endl;
    std::cout << "upper bound of 1 : " << *setTest.upper_bound(100) << std::endl;
    std::cout << "upper bound of 2 : " << *setTest.upper_bound(200) << std::endl;
    
    // breakFunc();   
    std::cout << "-------------------->Testing equal_range()<-------------------------------" << std::endl;  
     std::cout << "Our set++++++++++++++++++\n";  
    std::cout << "equal range of 1 first elem : " << *setElem4.equal_range(1).first << std::endl;
    std::cout <<  "equal range of 1 second elem : " << *setElem4.equal_range(1).second<< std::endl;
    std::cout <<  "equal range of 1 first elem : " << *setElem4.equal_range(2).first  << std::endl;
    std::cout <<  "equal range of 1 second elem : " << *setElem4.equal_range(2).second << std::endl;
    std::cout << "Test set++++++++++++++++++\n";
    std::cout << "equal range of 1 first elem : " << *setTest.equal_range(1).first << std::endl;
    std::cout <<  "equal range of 1 second elem : " << *setTest.equal_range(1).second<< std::endl;
    std::cout <<  "equal range of 1 first elem : " << *setTest.equal_range(2).first  << std::endl;
    std::cout <<  "equal range of 1 second elem : " << *setTest.equal_range(2).second << std::endl;
}

// void map_tests()
// {

// 	std::map<int,char> map;
// 	std::map<int,char>::iterator it;
// 	std::map<int,char>::reverse_iterator ir;
//     std::cout << "inserting 7 elements in map"  << std::endl;
//     for (int i = 0 ; i <= 7 ; i++)
//         map.insert(std::make_pair(i,i));
//     std::cout << "map size now " << map.size() << std::endl;
//     std::cout << "map first and second elements : " <<std::endl;
//     for ( it = map.begin() ; it != map.end() ; it++)
//         std::cout << "first : "  << it->first << "   second : " << it->second << std::endl;

//     breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "Testing copy constructor and range iterator" << std::endl;
//     std::map<int,char> copyMap(map);
//     std::map<int,char> rangeMap(map.begin(),map.end());

//     std::map<int,char> assignMap;
//     for (int i = 5 ; i < 55 ; i++)
//         assignMap.insert(std::make_pair(i,i));
    
//     copyMap = assignMap;
//     std::cout << "assignmap size now " << assignMap.size() << std::endl;
//     std::cout << "copyMap size now " << copyMap.size() << std::endl;

// 	breakFunc();
//     std::cout << "element of assignMap " << std::endl;
//     for ( it = assignMap.begin() ; it != assignMap.end() ; it++)
//         std::cout << "first : "  << it->first << "   second : " << it->second << std::endl;
// 	breakFunc();
//     std::cout << "element of copyMap " << std::endl;
//     for ( it = copyMap.begin() ; it != copyMap.end() ; it++)
//         std::cout << "first : "  << it->first << "   second : " << it->second << std::endl;

//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "testing insert " << std::endl;

// 	breakFunc();
//     std::cout << "inserting one element in map" << std::endl;
//     std::cout << "size before insert : " << map.size() << std::endl;
//     map.insert(map.begin(),std::make_pair(7,'c'));
//     std::cout << "size after insert : " << map.size() << std::endl;
// 	breakFunc();
//     std::cout << "inserting range of element that already exists" << std::endl;
// 	breakFunc();
//     std::cout << "size before insert : " << map.size() << std::endl;
//     map.insert(map.begin(),map.end());
//     std::cout << "size after insert : " << map.size() << std::endl;
// 	breakFunc();
//     std::cout << "inserting a range of copyMap" << std::endl;
//     std::cout << "size before insert : " << map.size() << std::endl;
//     map.insert(copyMap.begin(),copyMap.end());
//     std::cout << "size after insert : " << map.size() << std::endl;
// 	breakFunc();
//     for ( it = map.begin() ; it != map.end() ; it++)
//         std::cout << "first : "  << it->first << "   second : " << it->second << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "erasing ..." << std::endl;
//     for (int i = 0 ; i < 100 ; i++)
//         map.erase(i);
//     std::cout << "size now : " << map.size() << std::endl;
//     if (map.empty())
//         std::cout << "map empty now " << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "inserting 100 element  " << std::endl;
//     for (int i = 0 ; i < 100 ; i++)
//         map.insert(std::make_pair(i,i));
//     std::cout << "size now : " << map.size() << std::endl;
//     std::cout << "max size : " << map.max_size() << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "Accessing element using [] operator : " << std::endl;
//     std::cout << map[48] << std::endl;
//     std::cout << map[49] << std::endl;
//     std::cout << map[50] << std::endl;
//     std::cout << map[65] << std::endl;
//     std::cout << map[66] << std::endl;
//     std::cout << map[67] << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "inserting more 100 elements " << std::endl;
//     std::cout << "inserting ..." << std::endl;
//     for (int i = 100 ; i < 200 ; i++)
//         map.insert(std::make_pair(i,i));
// 	breakFunc();
//     std::cout << "size now " << map.size() << std::endl;
//     std::cout << "erasing only first 100 elements" << std::endl;
//     for (int i = 0 ; i < 100 ;i++ )
//         map.erase(i);
//     std::cout << "erasing ... " << std::endl;
//     std::cout << "size now " << map.size() << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::map<int,char> swapMap;

//     for (int i = 0 ; i < 4 ; i++)
//         swapMap.insert(std::make_pair(i,i+46));
//     std::cout << "exchanging content of map with swapMap" << std::endl;
//     std::cout << "swapMap only has 3 elements" << std::endl;
//     map.swap(swapMap);
//     std::cout << "Size of the map now : " << map.size() <<  std::endl;
// 	breakFunc();
//     std::cout << "Checking elements ..."  << std::endl;
//     for (it = map.begin() ; it != map.end() ; it++ )
//         std::cout << "it-> " << it->first << std::endl;
//     std::cout << "swapMap size now :  " << swapMap.size() << std::endl;
//     std::cout << "swapMap elements : " << std::endl;
//     for (it = swapMap.begin() ; it != swapMap.end() ; it++ )
//         std::cout << "it-> " << it->first << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
    
//     std::cout << "Clearing elements of swapMap " << std::endl;
//     swapMap.clear();
//     std::cout << "clearing ... " << std::endl;
//     std::cout << "size of swapMap now : " << swapMap.size() << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "\\* Testing Find memeber function */" << std::endl;
//     std::cout << "finding the element 2" << std::endl;
//     it = map.find(2);
//     std::cout << "element : " << it->first << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "\\* Testing Count memeber function */" << std::endl;
//     std::cout << "finding  many element that have 7" << std::endl;
//     std::cout << "nbr of element : " << map.count(7) << std::endl;
//     std::cout << "finding  many element that have 2" << std::endl;
//     std::cout << "nbr of element : " << map.count(2) << std::endl;
// 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;
//     std::cout << "Testing lower upper and equal bound functions " << std::endl;
//     std::cout << "lower bound of 1 : " << map.lower_bound(1)->first << std::endl;
//     std::cout << "lowe bound of 2 : " << map.lower_bound(2)->first << std::endl;
//     std::cout << "upper bound of 1 : " << map.upper_bound(1)->first << std::endl;
//     std::cout << "upper bound of 2 : " << map.upper_bound(2)->first << std::endl;
//     breakFunc();       
//     std::cout << "equal range of 1 first elem : " << map.equal_range(1).first->first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << map.equal_range(1).first->second << std::endl;
//     std::cout <<  "equal range of 1 first elem : " << map.equal_range(2).first->first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << map.equal_range(2).first->second << std::endl;
// }

// void vec_tests()
// {
// 	std::vector<int> vec;

// 	std::cout << "---------------------------------------------------" << std::endl;
// 	std::cout << "inserting 10 elements in vec " << std::endl;
// 	for (int i = 0 ; i < 10 ; i++)
// 		vec.push_back(i);
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	breakFunc();
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	std::cout << "constructing new vector using copy  constructor " << std::endl;
// 	breakFunc();
// 	std::cout << "constructing ..." << std::endl;
// 	std::vector<int> Copyvec(vec);
// 	std::cout << "size of copyvec: " << Copyvec.size() << "     capacity : " << Copyvec.capacity() << std::endl;
// 	breakFunc();
// 	std::cout << "testing if the two vector are equals or not " << std::endl;
// 	if (Copyvec == vec)
// 		std::cout << "the two vec are equals" << std::endl;
// 	else
// 		std::cout << "the two vectors are not equal" << std::endl;
// 	breakFunc();
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	std::cout << "constructing new vector using assignment operator " << std::endl;
// 	breakFunc();
// 	std::vector<int> Assignvec;
// 	Assignvec = vec;
// 	std::cout << "size of assignvec: " << Assignvec.size() << "     capacity : " << Assignvec.capacity() << std::endl;
// 	breakFunc();
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	std::cout << "constructing a vector using range of iterators, 5 elements from vec" << std::endl;
// 	std::vector<int> iterVec(vec.begin(),vec.begin() + 5);
// 	std::cout << "size of iterVec: " << iterVec.size() << "     capacity : " << iterVec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "testing normal iterators " << std::endl;
// 	breakFunc();
// 	std::vector<int>::iterator it;
// 	it = vec.begin();
// 	std::cout << "iterating through the vector and checking elements " << std::endl;
// 	while (it != vec.end())
// 	{
// 		std::cout << "["  << *it << "]" ;
// 		it++;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "testing reverse iterator ... " << std::endl;
// 	breakFunc();
// 	std::vector<int>::reverse_iterator ir;
// 	for (ir = vec.rbegin() ; ir != vec.rend() ; ir++)
// 		std::cout << "["  << *ir << "]" ;
// 	std::cout << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "resizing vec with a size of 5" << std::endl;
// 	breakFunc();
// 	vec.resize(5);
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "reserving a capacity of 20 to vec" << std::endl;
// 	vec.reserve(20);
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "testing element access operators " << std::endl;
// 	breakFunc();
// 	std::cout << "getting element at index 2 []" << std::endl;
// 	std::cout << "vec[5] : " << vec[2] << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "getting element at index 4 using at" << std::endl;
// 	std::cout << "vec at 4 : " << vec.at(4) << std::endl;
// 	breakFunc();
// 	std::cout << "getting an element out of range " << std::endl;
// 	try {
// 		std::cout << "at(100)" << vec.at(100) << std::endl;
// 	} 
// 	catch (std::out_of_range &e)
// 	{
// 		std::cout << "error : " << e.what() << std::endl;
// 	}
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "testing front  function " << std::endl;
// 	std::cout << "front : " << vec.front() << std::endl;
// 	breakFunc();
// 	std::cout << "testing back  function " << std::endl;
// 	std::cout << "back : " << vec.back() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout <<  "Its time to test assign insert "<< std::endl;
// 	breakFunc();
// 	std::cout << "assigning 5 elements index 5 to 10 " <<std::endl;
// 	vec.assign(Assignvec.begin() + 5 , Assignvec.begin() + 10);
// 	for (it  = vec.begin() ; it != vec.end() ;  it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "assigning 10 elements of value 1337 to the Assignvec " << std::endl;
// 	Assignvec.assign(10,1337);
// 	for (it  = Assignvec.begin() ; it != Assignvec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << Assignvec.size() << "     capacity : " << Assignvec.capacity() 
// 			<< std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "pushing back elements to vec" << std::endl;
// 	breakFunc();
// 	std::cout << "pushing 80 90 and 100 to the end << std::endl" << std::endl;
// 	vec.push_back(80);
// 	vec.push_back(90);
// 	vec.push_back(100);
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	breakFunc();
// 	std::cout << "poping the last two elements from vec " << std::endl;
// 	vec.pop_back();
// 	vec.pop_back();
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "inserting at the begining of vec -1 " << std::endl;
// 	vec.insert(vec.begin(), -1);
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "inserting at postion 3 , 5 elements of value : 42 " << std::endl;
// 	vec.insert(vec.begin(), 5 , 42);
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "inserting at index 2 , 5 element from position 5 to 10 " << std::endl;
// 	vec.insert(vec.begin() + 2, vec.begin() + 5 , vec.begin() + 10);
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "testing Erase function " << std::endl;
// 	breakFunc();
// 	std::cout << "erasing the first element from vec" << std::endl;
// 	vec.erase(vec.begin());
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "erasng from index 4 to index 10 " << std::endl;
// 	vec.erase(vec.begin() + 4,vec.begin() + 10 );
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	std::cout << "size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "---------------------------------------------------" << std::endl;
// 	breakFunc();
// 	std::cout << "testing swap  " << std::endl;

// 	std::vector<int> swapVec;
// 	vec.swap(swapVec);
// 	breakFunc();
// 	std::cout << "vec size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "swapVec size : " << swapVec.size() << "     capacity : " << swapVec.capacity() << std::endl;
// 	breakFunc();
// 	std::cout << "testing element in swapVec" << std::endl;
// 	breakFunc();
// 	for (it  = vec.begin() ; it != vec.end() ;it++){
// 		std::cout << "["  << *it << "]" ;
// 	}
// 	std::cout << std::endl;
// 	breakFunc();
// 	std::cout << "clearing all element of swapVec and vec " << std::endl;
// 	swapVec.clear();
// 	vec.clear();
// 	std::cout << "vec size : " << vec.size() << "     capacity : " << vec.capacity() << std::endl;
// 	std::cout << "swapVec size : " << swapVec.size() << "     capacity : " << swapVec.capacity() << std::endl;
// }

// void stack_tests()
// {
//     std::stack<int> st;
//     std::stack<int> sp;

//     st.push(1);
//     st.push(2);
//     st.push(3);

// 	std::cout << "testing if the stack is empty " << std::endl;
// 	if (sp.empty())
// 		std::cout << "sp is empty" << std::endl;
// 	else
// 		std::cout << "sp is not empty" << std::endl;

// 	breakFunc();
// 	std::cout << "testing if the two stacks are equals or not " << std::endl;
// 	breakFunc();
//     if (st == sp)
//         std::cout << "the two stacks are equals " << std::endl;
//     else if (st != sp )
//         std::cout << "the two stacks are not equals " << std::endl;
// 	breakFunc();
// 	std::cout << "testing who is bigger " << std::endl;
// 	breakFunc();
//     if (st > sp)
//         std::cout << "st bigger tham sp " << std::endl;
//     else if (st < sp )
//         std::cout << "st small than sp " << std::endl;
	
// 	sp.push(1);
//     sp.push(2);
//     sp.push(3);

// 	breakFunc();
// 	std::cout << "top of sp : " << sp.top() << std::endl;
// 	std::cout << "top of st : " << sp.top() << std::endl;

// 	breakFunc();
// 	std::cout << "testing if sp empty " << std::endl;
// 	breakFunc();
// 	if (sp.empty())
// 		std::cout << "sp is empty" << std::endl;
// 	else
// 		std::cout << "sp is not empty" << std::endl;
// 	breakFunc();
// 	std::cout << "testing if the two stacks are equals or not " << std::endl;
// 	breakFunc();
//     if (st == sp)
//         std::cout << "the two stacks are equals " << std::endl;
//     else if (st != sp )
//         std::cout << "the two stacks are not equals " << std::endl;
// 	breakFunc();
// 	std::cout << "testing if one stack is bigger than the other " << std::endl;
// 	breakFunc();
//     if (st > sp)
//         std::cout << "st bigger tham sp " << std::endl;
//     else if (st < sp )
//         std::cout << "st small than sp " << std::endl;
// }

// int main(int argc , char **argv)
// {
//     if (argc  != 2 )
//     {
//         std::cout << "Invalid input" << std::endl;
//         return 1;
//     }
//     std::string a[5] = {"map","vector","stack","set"};
//     void (*ptr[4])() = {map_tests,vec_tests,stack_tests,set_tests};
//     for (int i = 0 ; i < 4 ; i++)
//     {
//         if (argv[1] == a[i])
//         {
//             (*ptr[i])();
//             return 0;
//         }
        
//     }
//     std::cout << "wrong input" << std::endl;
// }
