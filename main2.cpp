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

//std::cout << "Set***********************\n";

// int main()
// {
//     ft::set<int> setElem1;
//     ft::set<int> setElem4;
//     std::set<int>setTest;
//     ft::set<int> assign_set;
//     std::set<int> set;
// 	ft::set<int>::iterator it1;
//     ft::set<int>::iterator it2;
// 	ft::set<int>::reverse_iterator rev1;
//     std::cout << "inserting 7 elements in set"  << std::endl;
//     for (int i = 0 ; i <= 7 ; i++)
//         setElem1.insert(i);
//     for (int i = 1 ; i <= 10 ; i++)
//         setElem4.insert(i * 100 );
//     for (int i = 1 ; i <= 10 ; i++)
//         setTest.insert(i * 100 );
//     std::cout << "size -->" << setElem1.size() << std::endl;
//     std::cout << "********>Print our set******-->: " <<std::endl;
//     for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
//         std::cout << "Our set-->: "  << *it1  << std::endl;

//     std::cout << "***********************[Set]*******************************\n" << std::endl;
//     std::cout << "----------------------------------------------------------\n";
//     std::cout << "Testing copy constructor, assignement operator and constructer with iterators\n" << std::endl;
//     std::cout << "------>Testing copy constructer<-----\n";
//     ft::set<int> setElem2(setElem1);
//     ft::set<int> setElem3(setElem1.begin(),setElem1.end());


//     std::cout << "********>Print set2<********:\n";
//     for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
//         std::cout << "Set2-->: "  << *it1  << std::endl;
//     std::cout << "*******>Print set3<******:\n";
//     for ( it1 = setElem3.begin() ; it1 != setElem3.end() ; it1++)
//         std::cout << "set3-->: "  << *it1  << std::endl;
    
//     std::cout << "------>Testing assignement operator<-----\n";
//     std::set<int> assignSet;

//     for (int i = 5 ; i < 10 ; i++)
//         assign_set.insert(i * 10);

//     setElem2 = assign_set;
//     std::cout << "assign_set size :" << assign_set.size() << std::endl;
//     std::cout << "set_2  size :" << setElem2.size() << std::endl;

//     std::cout << "********>Print assign_set<******* " << std::endl;
//     for ( it1 = assign_set.begin() ; it1 != assign_set.end() ; it1++)
//         std::cout << "Assign set :: "  << *it1 <<  std::endl;
	
//     std::cout << "********>Print copy_Set<******** " << std::endl;
//     for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
//         std::cout << "copy_set: "  << *it1 <<  std::endl;
//     // breakFunc();
//     std::cout << "------------------------Capacity----------------------------------\n";
//     std::cout << "------------->Testing size(), max_size()<------------\n";

//     std::cout << "Size() :-->" << setElem1.size() << std::endl;
//     std::cout << "Max_size()--->" << setElem1.max_size() << std::endl;
//     // breakFunc();
//     std::cout << "----------------------Modifiers-----------------------------" << std::endl;
//     std::cout << "------------------>testing insert<-------------------" << std::endl;

//     std::cout << "inserting one element in set :" << std::endl;
//     std::cout << "size before insert : " << setElem1.size() << std::endl;
//     setElem1.insert(setElem1.begin(),70);
//     std::cout << "size after insert : " << setElem1.size() << std::endl;
// 	// breakFunc();
//     std::cout << "inserting element that already exists :" << std::endl;
//     setElem1.insert(setElem1.begin(),7);
//     std::cout << "size after insert will not change: " << setElem1.size() << std::endl;
// 	// breakFunc();
//     std::cout << "Inserting range of element that already exist : \n";
//     std::cout << "size before insert : " << setElem1.size() << std::endl;
//     setElem1.insert(setElem1.begin(),setElem1.end());
//     std::cout << "size after insert will not change :" << setElem1.size() << std::endl;
// 	// breakFunc();
//     std::cout << "Inserting our set by using an array of integers\n";
//     int array[] = {500,600,700};
//     setElem1.insert(array,array+3);
//     std::cout << "******>Print our set<*******\n";
//     for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
//         std::cout << "Our set ->"  << *it1 <<  std::endl;
//     // std::cout << "inserting more 1000 elements : " << std::endl;
//     // for (int i = 200 ; i < 1000 ; i++)
//     //     setElem1.insert(i);
//     // std::cout << "******>Print our set<*******\n";
//     // for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
//     //     std::cout << "Our set ->"  << *it1 <<  std::endl;
    
//     // std::cout << "size now-->" << setElem1.size() << std::endl;
    
//     std::cout << "------------------->Testing erasing<-----------------------" << std::endl;
//     setElem1.erase(0);
//     std::cout << "size now : " << setElem1.size() << std::endl;
//     if (setElem1.empty())
//         std::cout << "our set is empty now " << std::endl;
//     else 
//         std::cout << "Our set not empty\n";

//     std::cout << "******>Print our set<*******\n";
//     for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
//         std::cout << "Our set ->"  << *it1 <<  std::endl;
// 	// breakFunc();

//     std::cout << "erasing first 9 elements" << std::endl;
//     for (int i = 0 ; i < 9 ;i++ )
//         setElem1.erase(i);
//     std::cout << "erasing ... " << std::endl;
//     std::cout << "size now " << setElem1.size() << std::endl;
//      std::cout << "******>Print our set<*******\n";
//     for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
//         std::cout << "Our set ->"  << *it1 <<  std::endl;
// 	// breakFunc();
//     // std::cout << "----------------->Testing swap<----------------------------------" << std::endl;
//     // ft::set<int> swap_set;

//     // for (int i = 10 ; i < 100 ; i++)
//     //     swap_set.insert(i);
//     // std::cout << "exchanging content of set with swapSet" << std::endl;
//     // std::cout << "swapSet only has 3 elements" << std::endl;
//     // setElem1.swap(swapSet);
//     // std::cout << "Size of the setElem1 now : " << setElem1.size() <<  std::endl;
// 	// breakFunc();
//     // std::cout << "Checking elements of setElem1 && swap_set :"  << std::endl;
//     //std::cout << "setElem1 elements :\n";
//     // for (it = setElem1.begin() ; it != setElem1.end() ; it++ )
//     //     std::cout << "setElem1 element->" << *it << std::endl;
//     // std::cout << "size of swap_set now :  " << swapSet.size() << std::endl;
//     // std::cout << "swap_set elements : " << std::endl;
//     // for (it = swap_set.begin() ; it != swap_set.end() ; it++ )
//     //     std::cout << "swap_set elements -> " << *it << std::endl;
// 	// breakFunc();
//     // std::cout << "---------------------------------------------------" << std::endl;
    
//     // std::cout << "Clearing elements of swapSet " << std::endl;
//     // swap_set.clear();
//     // std::cout << "clearing ... " << std::endl;
//     // std::cout << "size of swap_set now : " << swap_set.size() << std::endl;
// 	// breakFunc();
//     std::cout << "----------------------Operations-----------------------------" << std::endl;
//     std::cout << "--------------------->Testing Find()<-----------------------------" << std::endl; 
//     std::cout << "Print setElem2 before erasing 60 && 80-->"; 
//     for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
//         std::cout << "Our set ->"  << *it1 <<  std::endl;
//     it2 = setElem2.find(60);
//     std::cout << "Our iterator point -->: " << *it2 << std::endl;
//     setElem2.erase(it2);
//     setElem2.erase(setElem2.find(80));
//     std::cout << "Print setElem2 After erasing 60 && 80-->"; 
//     for ( it1 = setElem2.begin() ; it1 != setElem2.end() ; it1++)
//         std::cout << "Our set ->"  << *it1 <<  std::endl;
// 	// breakFunc();
//     std::cout << "--------------------->Testing count()<------------------------------" << std::endl;
//     if(setElem2.count(3) != 0)
//     {
//         std::cout << "This number is an element in my set\n";
//     }else
//         std::cout << "This number is not an element in my set\n";
    
// 	// breakFunc();
//     std::cout << "-------------------->Testing Lower_bound && Upper_bound<-------------------------------" << std::endl;
//     std::cout << 

//     std::cout << "Our set++++++++++++++++++\n";
//     std::cout << "lower bound of 1 : " << *setElem4.lower_bound(100) << std::endl;
//     std::cout << "lowe bound of 2 : " << *setElem4.lower_bound(200) << std::endl;
//     std::cout << "upper bound of 1 : " << *setElem4.upper_bound(100) << std::endl;
//     std::cout << "upper bound of 2 : " << *setElem4.upper_bound(200) << std::endl;
//     std::cout << "Test set++++++++++++++++++\n";
//     std::cout << "lower bound of 1 : " << *setTest.lower_bound(100) << std::endl;
//     std::cout << "lowe bound of 2 : " << *setTest.lower_bound(200) << std::endl;
//     std::cout << "upper bound of 1 : " << *setTest.upper_bound(100) << std::endl;
//     std::cout << "upper bound of 2 : " << *setTest.upper_bound(200) << std::endl;
    
//     // breakFunc();   
//     std::cout << "-------------------->Testing equal_range()<-------------------------------" << std::endl;  
//      std::cout << "Our set++++++++++++++++++\n";  
//     std::cout << "equal range of 1 first elem : " << *setElem4.equal_range(100).first << std::endl; // lower_bound
//     std::cout <<  "equal range of 1 second elem : " << *setElem4.equal_range(100).second<< std::endl; //upper_bound
//     std::cout <<  "equal range of 1 first elem : " << *setElem4.equal_range(200).first  << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << *setElem4.equal_range(200).second << std::endl;
//     std::cout << "Test set++++++++++++++++++\n";
//     std::cout << "equal range of 1 first elem : " << *setTest.equal_range(100).first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << *setTest.equal_range(100).second<< std::endl;
//     std::cout <<  "equal range of 1 first elem : " << *setTest.equal_range(200).first  << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << *setTest.equal_range(200).second << std::endl;
//     std::cout << "-----------------------Observers:----------------------------" << std::endl;
//     std::cout << "----------------------->Testing key_comp()<-----------------------"<< std::endl;

//     ft::set<int>myset;
//     int height;

//     ft::set<int>::key_compare mycomp = myset.key_comp();

//     for(int k = 0; k <= 5; k++)
//     {
//         myset.insert(k);
//     }
//         height = *myset.rbegin();
//         ft::set<int>::iterator iter;
//         iter = myset.begin();

//         do{
//                 std::cout << "Our elem :->" << *iter<< std::endl;
//         }while(mycomp(*(iter++), height));

//         std::cout << "----------------------->Testing value_comp()<-----------------------"<< std::endl;
//         ft::set<int>::value_compare myvalue = myset.value_comp();
//         ft::set<int>myset2;
//         ft::set<int>::iterator iter2;
//         int height2;
//         for(int m = 0; m <= 5; m++)
//         {
//                 myset2.insert(m);
//         }
//         iter2 = myset2.begin();
//         height2 = *myset2.rbegin();
//         do{
//             std::cout << "Our elem: -->" << *iter2  << std::endl;
//         }while(myvalue((*iter2++),height2));
//     std::cout << "----------------------Allocator-----------------------------" << std::endl;
//     std::cout << "----------------------->Testing get_allocator()<-----------------------"<< std::endl;
//     ft::set<int> myset3;
//     int *arr;

//     // allocate an array of 5 elements using myset's allocator:
//     arr = myset3.get_allocator().allocate(5);

//     for(size_t j = 0; j < 5; j++)
//     {
//         arr[j] = j;
//     }
//     cout << "Print :\n";
//     for (int i=0; i<5; i++) 
//         std::cout << ' ' << arr[i];
//     std::cout << '\n';

//     myset3.get_allocator().deallocate(arr,5);


// }



//std::cout << "Map*************************\n" 



// int main()
// {

//     ft::map<int,char> map1;
//     ft::map<int,char>::iterator it1;
//     std::map<int, char> mapTest2;
// 	ft::map<int,char>::reverse_iterator revIter1;
//     int num = 65;
// //     std::cout << "inserting 7 elements in map"  << std::endl;
//     for (int i = 0 ; i <= 7 ; i++)
//     {
//          map1.insert(ft::pair<int,char>(i,num));
//          mapTest2.insert(std::pair<int,char>(i,num));
//          num++;
//     }
       
//     std::cout << "Printing our map\n";
//     for ( it1 = map1.begin() ; it1 != map1.end() ; it1++)
//         std::cout << "first : "  << it1->first << "   second : " << it1->second << std::endl;

// //     breakFunc();
//     std::cout << "------------------->Constructers<--------------------------------" << std::endl;
//     std::cout << "Testing copy constructor, constructor with iterater and assignement operator" << std::endl;
//     ft::map<int,char> map2(map1);
//     ft::map<int,char> map3(map1.begin(),map1.end());
//     ft::map<int,char> map4(map1.begin(),map1.end());
//     std::map<int, char> mapTest;
//     int nb = 97;

//    ft::map<int,char> assign_map;
//     for (int i = 1 ; i <= 5 ; i++)
//     {
//         //assign_map.insert(ft::make_pair(i,nb));
//         assign_map.insert(ft::pair<int,char>(i,nb));
//         mapTest.insert(std::pair<int, char>(i,nb));
//         nb++;
//     }
        
    
//     map2 = assign_map;
//     std::cout << "Print map2 :\n";
//     for ( it1 = map2.begin() ; it1 != map2.end() ; it1++)
//         std::cout << "first : "  << it1->first << "   second : " << it1->second << std::endl;
//     std::cout << "Print map3 :\n";
//     for ( it1 = map3.begin() ; it1 != map3.end() ; it1++)
//         std::cout << "first : "  << it1->first << "   second : " << it1->second << std::endl;

//     std::cout << "Print map_assign :\n";
//     for ( it1 = assign_map.begin() ; it1 != assign_map.end() ; it1++)
//         std::cout << "first : "  << it1->first << "   second : " << it1->second << std::endl;

//     std::cout << "map1 size now " << map1.size() << std::endl;
//     std::cout << "map2 size now " << map2.size() << std::endl;
//     std::cout << "map3 size now " << map3.size() << std::endl;
//     std::cout << "assign_map size now " << assign_map.size() << std::endl;

// // 	breakFunc();
//     std::cout << 
//     std::cout << "------------------->Iterators<--------------------------------" << std::endl;
//     ft::map<int, char>::iterator ii1;
//     ft::map<int, char>::reverse_iterator rev_ii1;
//     ft::map<int,char>::const_iterator const_iter;
//     ft::map<int, char>::const_reverse_iterator const_rev_iter;
//     std::cout << "--------------------Testing iterator----------------" << std::endl;
//     for(ii1= map2.begin(); ii1 != map2.end() ; ii1++)
//     {
//         std::cout << "First=>" << ii1->first << std::endl;
//         std::cout << "Second=>" << ii1->second << std::endl;
//     }
//     std::cout << "----------Testing Reverse iterator------------------"<< std::endl;
//     for(rev_ii1 = map2.rbegin(); rev_ii1 != map2.rend(); rev_ii1++)
//     {
//         std::cout << "First=> " << rev_ii1->first << std::endl;
//         std::cout << "second=>" << rev_ii1->second << std::endl;
//     }
//     std::cout << "---------Testing const_iterator---------------------" << std::endl;
//     for(const_iter = map2.begin(); const_iter != map2.end(); const_iter++)
//     {
//         std::cout << "First=>" << const_iter->first << std::endl;
//         std::cout << "Second=>" << const_iter->second << std::endl;
//     }
//     std::cout << "-------------Testing const_reverse_iterator--------------------\n";
//     for(const_rev_iter= map2.rbegin(); const_rev_iter != map2.rend(); const_rev_iter++)
//     {
//         std::cout << "First=>" << const_rev_iter->first << std::endl;
//         std::cout << "second=>" << const_rev_iter->second << std::endl;
//     }

//      std::cout << "------------------->Capacity<--------------------------------" << std::endl;
//      std::cout << "-------------------Testing empty()--------------------------------" << std::endl;

//     if(map2.empty() != 0)
//     {
//         std::cout << "Our map is empty\n";
//     }else
//         std::cout << "Our map is not empty\n";
//     std::cout << "-------------------Testing size() && max_size()--------------------------------" << std::endl;

//     std::cout << "Size of our map is :-->" << map2.size() << std::endl;
//     std::cout << "max_Size of our map is :-->" << map2.max_size() << std::endl;
//     std::cout << "------------------->Element access<--------------------------------" << std::endl;
//     std::cout << "-------------------Testing operator[]--------------------------------" << std::endl;

//     map2[11] = 's';
//     mapTest[11] = 's';
//     std::cout << "Print our map after adding 's'-->";
//     for(ii1= map2.begin(); ii1 != map2.end() ; ii1++)
//     {
//         std::cout << "First=>" << ii1->first << std::endl;
//         std::cout << "Second=>" << ii1->second << std::endl;
//     }
//     std::cout << "Accessing element using [] operator : " << std::endl;
//     std::cout << map2[1] << std::endl;
//     std::cout << map2[2] << std::endl;
//     std::cout << map2[3] << std::endl;
    
//     // 	breakFunc();
//     std::cout << "------------------->Modifiers<--------------------------------" << std::endl;
//     std::cout << "---------------------testing insert------------------------ " << std::endl;

//     std::cout << "inserting one element in map" << std::endl;
//     std::cout << "size before insert : " << map2.size() << std::endl;
//     map2.insert(map2.begin(),ft::make_pair(7,'c'));
//     mapTest.insert(mapTest.begin(),std::make_pair(7, 'c'));
//     std::map<int,char>::iterator iterTest;
//     std::cout << "size after insert : " << map2.size() << std::endl;
//     std::cout << "Printing our map\n";
//     for(ii1= map2.begin(); ii1 != map2.end() ; ii1++)
//     {
//         std::cout << "First=>" << ii1->first << std::endl;
//         std::cout << "Second=>" << ii1->second << std::endl;
//     }
//     std::cout << "Printing Testmap\n";
//     for(iterTest= mapTest.begin(); iterTest != mapTest.end() ; iterTest++)
//     {
//         std::cout << "First=>" << iterTest->first << std::endl;
//         std::cout << "Second=>" << iterTest->second << std::endl;
//     }
// // 	breakFunc();
//      std::cout << "inserting elements that already exists in our map" << std::endl;
// // 	breakFunc();
//      std::cout << "size before insert : " << map2.size() << std::endl;
//      map2.insert(map2.begin(),map2.end());
//      std::cout << "size after insert : " << map2.size() << std::endl;
// // 	breakFunc();
//     std::cout << "inserting a range of copyMap" << std::endl;
//     std::cout << "size before insert : " << map2.size() << std::endl;
//     map2.insert(map4.begin(),map4.end());
//     mapTest.insert(mapTest2.begin(),mapTest2.end());
//     std::cout << "size after insert : " << map2.size() << std::endl;
//     std::cout <<"Print our map ***\n";
//     for ( it1 = map2.begin() ; it1 != map2.end() ; it1++)
//     {
//          std::cout << "first : "  << it1->first << std::endl;
//         std::cout<< "second:" << it1->second << std::endl;
//     }
//      std::cout <<"Print mapTest ***\n";
//     for ( iterTest = mapTest.begin() ; iterTest != mapTest.end() ; iterTest++)
//     {
//          std::cout << "first : "  << iterTest->first << std::endl;
//         std::cout<< "second:" << iterTest->second << std::endl;
//     }


// // 	breakFunc();
//     std::cout << "------------------Testing erase()---------------------------------" << std::endl;

//     map2.erase(7);
//     std::cout << "size now : " << map2.size() << std::endl;

// // 	breakFunc();
//     std::cout << "---------------------------------------------------" << std::endl;

//     std::cout << "erasing only first 3 elements" << std::endl;
//     for (int i = 0 ; i < 3 ;i++ )
//         map2.erase(i);
//     std::cout << "erasing ... " << std::endl;
//     std::cout << "size now " << map2.size() << std::endl;
// // 	breakFunc();
// //     std::cout << "--------------------Testing swap()-------------------------------" << std::endl;
// //     ft::map<int,char> swap_map;

// //     for (int i = 1 ; i <= 4 ; i++)
// //         swap_map.insert(std::make_pair(i,i*30));
// //     std::cout << "exchanging content of map with swap_map" << std::endl;
// //     std::cout << "swap_map only has 4 elements" << std::endl;
// //     map2.swap(swapMap);
// //     std::cout << "Size of the map2 now : " << map2.size() <<  std::endl;
// // 	breakFunc();
// //     std::cout << "Checking elements of map2 now:"  << std::endl;
// //     for (it1 = map2.begin() ; it1 != map2.end() ; it++ )
// //         std::cout << "it1-> " << it1->first << std::endl;
// // 	breakFunc();
// //     std::cout << "--------------------Testing clear()-------------------------------" << std::endl;
    
// //     std::cout << "Clearing elements of swap_map " << std::endl;
// //     swap_map.clear();
// //     std::cout << "clearing ... " << std::endl;
// //     std::cout << "size of swap_map now : " << swap_map.size() << std::endl;
// // 	breakFunc();
//     std::cout << "------------------->Operations<--------------------------------" << std::endl;


//     std::cout << "----------------Testing find()-----------------------" << std::endl;
//     it1 = map2.find(5);
//     std::cout << "iterator point : " << it1->first << " && " << it1->second << std::endl;
// // 	breakFunc();
//     std::cout << "-----------------Testing count()----------------------------------" << std::endl;
//     if(map2.count(5) != 0)
//         std::cout << "This element is an elem of my map\n";
//     else
//         std::cout << "This element is not an element of my map\n";
// // 	breakFunc();
//     std::cout << "-----------------Testing lower_bound && upper_bound()------------------------------" << std::endl;
//     std::map<int,char>Test;
//     ft::map<int,char>OurMap;

//     //Ourmap
//     OurMap.insert(ft::pair<int,char>(5,'d'));
//     OurMap.insert(ft::pair<int,char>(6,'m'));
//     OurMap.insert(ft::pair<int,char>(7,'b'));
//     OurMap.insert(ft::pair<int,char>(8,'t'));
//     OurMap.insert(ft::pair<int,char>(9,'k'));
//     OurMap.insert(ft::pair<int,char>(10,'o'));
//     //TestMap
//     Test.insert(std::pair<int,char>(5,'d'));
//     Test.insert(std::pair<int,char>(6,'m'));
//     Test.insert(std::pair<int,char>(7,'b'));
//     Test.insert(std::pair<int,char>(8,'t'));
//     Test.insert(std::pair<int,char>(9,'k'));
//     Test.insert(std::pair<int,char>(10,'o'));

//     std::cout << "Testing Lower_bound and upper_bound of our map " << std::endl;
//     std::cout << "lower bound of 1 : " << OurMap.lower_bound(5)->first << std::endl;
//     std::cout << "lowe bound of 2 : " << OurMap.lower_bound(2)->first << std::endl;
//     std::cout << "upper bound of 1 : " << OurMap.upper_bound(5)->first << std::endl;
//     std::cout << "upper bound of 2 : " << OurMap.upper_bound(2)->first << std::endl;

//     std::cout << "Testing Lower_bound and upper_bound of Test map " << std::endl;
//     std::cout << "lower bound of 1 : " << Test.lower_bound(5)->first << std::endl;
//     std::cout << "lowe bound of 2 : " << Test.lower_bound(2)->first << std::endl;
//     std::cout << "upper bound of 1 : " << Test.upper_bound(5)->first << std::endl;
//     std::cout << "upper bound of 2 : " << Test.upper_bound(2)->first << std::endl;
//     //breakFunc(); 

//     std::cout << "-----------------Testing equal_range() of Ourmap------------------------------" << std::endl;      
//     std::cout << "equal range of 1 first elem : " << OurMap.equal_range(5).first->first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << OurMap.equal_range(5).first->second << std::endl;
//     std::cout <<  "equal range of 1 first elem : " << OurMap.equal_range(2).first->first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << OurMap.equal_range(2).first->second << std::endl;
//     std::cout << "-----------------Testing equal_range() of TestMap------------------------------" << std::endl;      
//     std::cout << "equal range of 1 first elem : " << Test.equal_range(5).first->first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << Test.equal_range(5).first->second << std::endl;
//     std::cout <<  "equal range of 1 first elem : " << Test.equal_range(2).first->first << std::endl;
//     std::cout <<  "equal range of 1 second elem : " << Test.equal_range(2).first->second << std::endl;

// }
int main()
{
	ft::vector<int> vect1;

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
}

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
