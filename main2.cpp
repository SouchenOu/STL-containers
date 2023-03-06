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


// #include <vector>
// #include <map>
// #include <stack>
// #include <set>
// #include <iostream>
// #include "vector/vector.hpp"
// #include "map/map.hpp"
// #include "set/set.hpp"
// #include "stack/stack.hpp"


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



//     std::cout << "-------------------------------------------------------------------------\n";
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
//     std::cout << "------------->Testing assignement operator<--------------\n";
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


//     std::cout << "---------------------------Capacity----------------------------------\n";


//     std::cout << "------------->Testing size(), max_size()<------------\n";

//     std::cout << "Size() :-->" << setElem1.size() << std::endl;
//     std::cout << "Max_size()--->" << setElem1.max_size() << std::endl;





//     std::cout << "----------------------Modifiers-----------------------------" << std::endl;
//     std::cout << "------------------>testing insert<-------------------" << std::endl;

//     std::cout << "inserting one element in set :" << std::endl;
//     std::cout << "size before insert : " << setElem1.size() << std::endl;
//     setElem1.insert(setElem1.begin(),70);
//     std::cout << "size after insert : " << setElem1.size() << std::endl;
//     std::cout << "inserting element that already exists :" << std::endl;
//     setElem1.insert(setElem1.begin(),7);
//     std::cout << "size after insert will not change: " << setElem1.size() << std::endl;
//     std::cout << "Inserting range of element that already exist : \n";
//     std::cout << "size before insert : " << setElem1.size() << std::endl;
//     setElem1.insert(setElem1.begin(),setElem1.end());
//     std::cout << "size after insert will not change :" << setElem1.size() << std::endl;
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

//     std::cout << "erasing first 9 elements" << std::endl;
//     for (int i = 0 ; i < 9 ;i++ )
//         setElem1.erase(i);
//     std::cout << "erasing ... " << std::endl;
//     std::cout << "size now " << setElem1.size() << std::endl;
//      std::cout << "******>Print our set<*******\n";
//     for ( it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++)
//         std::cout << "Our set ->"  << *it1 <<  std::endl;
//     std::cout << "------------------->Testing swap<----------------------------------" << std::endl;
//     ft::set<int> swap_set;

//     for (int i = 10 ; i < 20 ; i++)
//         swap_set.insert(i);

//     std::cout << "setElem1 before extchange his element with swap_set:\n";
//     for (it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++ )
//         std::cout << "setElem1 element->" << *it1 << std::endl;
//     std::cout<< "swap_set before extchange his element with setElem1\n";
//     for (it1 = swap_set.begin() ; it1 != swap_set.end() ; it1++ )
//         std::cout << "swap_set elements -> " << *it1 << std::endl;
//     setElem1.swap(swap_set);
//     std::cout << "Size of the setElem1 now : " << setElem1.size() <<  std::endl;
//     std::cout << "Checking elements of setElem1 && swap_set :"  << std::endl;
//     std::cout << "setElem1 elements after extchanging his element with swap_element :\n";
//     for (it1 = setElem1.begin() ; it1 != setElem1.end() ; it1++ )
//         std::cout << "setElem1 element->" << *it1 << std::endl;
//     std::cout << "size of swap_set now :  " << swap_set.size() << std::endl;
//     std::cout << "swap_set elements after extchanging his element with set_element : " << std::endl;
//     for (it1 = swap_set.begin() ; it1 != swap_set.end() ; it1++ )
//         std::cout << "swap_set elements -> " << *it1 << std::endl;
//     std::cout << "---------------------Testing clear()---------------------------------" << std::endl;
    
//     std::cout << "Clearing elements of swap_set " << std::endl;
//     swap_set.clear();
//     std::cout << "size of swap_set now : " << swap_set.size() << std::endl;




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
//     std::cout << "--------------------->Testing count()<------------------------------" << std::endl;
//     if(setElem2.count(3) != 0)
//     {
//         std::cout << "This number is an element in my set\n";
//     }else
//         std::cout << "This number is not an element in my set\n";
    
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
//      std::cout << "inserting elements that already exists in our map" << std::endl;
//      std::cout << "size before insert : " << map2.size() << std::endl;
//      map2.insert(map2.begin(),map2.end());
//      std::cout << "size after insert : " << map2.size() << std::endl;
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




//     std::cout << "------------------Testing erase()---------------------------------" << std::endl;

//     map2.erase(7);
//     std::cout << "size now : " << map2.size() << std::endl;

//     std::cout << "-----------------------------------------------------------------" << std::endl;

//     std::cout << "erasing only first 3 elements" << std::endl;
//     for (int i = 0 ; i < 3 ;i++ )
//         map2.erase(i);
//     std::cout << "erasing ... " << std::endl;
//     std::cout << "size now " << map2.size() << std::endl;


//     std::cout << "--------------------Testing swap()-------------------------------" << std::endl;
//     ft::map<int,char> swap_map;
//     int n= 65;
//     for (int i = 1 ; i <= 4 ; i++)
//     {
//          swap_map.insert(ft::make_pair(i,n));
//          n++;
//     }
       
//     std::cout<< "Checking map_swap before swaping his element with map2\n";
//     for (it1 = swap_map.begin() ; it1 != swap_map.end() ; it1++ )
//     {
//         std::cout << "it1-> " << it1->first << std::endl;
//         std::cout<< "it2->" << it1->second << std::endl;
//     }
//     std::cout << "Checking map2 before swaping his element with swap_map\n";
//     for (it1 = map2.begin() ; it1 != map2.end() ; it1++ )
//     {
//         std::cout << "it1-> " << it1->first << std::endl;
//         std::cout<< "it2->" << it1->second << std::endl;

//     }
//     map2.swap(swap_map);
//     std::cout << "Size of the map2 now : " << map2.size() <<  std::endl;
//     std::cout << "Checking elements of map2 now:"  << std::endl;
//     std::cout << "exchanging content of map with swap_map" << std::endl;
//     std::cout<< "Checking map_swap after swaping his element with map2\n";
//     for (it1 = swap_map.begin() ; it1 != swap_map.end() ; it1++ )
//     {
//         std::cout << "it1-> " << it1->first << std::endl;
//         std::cout<< "it2->" << it1->second << std::endl;
//     }
//     std::cout << "Checking map2 after swaping his element with swap_map\n";
//     for (it1 = map2.begin() ; it1 != map2.end() ; it1++ )
//     {
//         std::cout << "it1-> " << it1->first << std::endl;
//         std::cout<< "it2->" << it1->second << std::endl;

//     }

//     std::cout << "--------------------Testing clear()-------------------------------" << std::endl;
    
//     std::cout << "Clearing elements of swap_map " << std::endl;
//     swap_map.clear();
//     std::cout << "size of swap_map now : " << swap_map.size() << std::endl;




//     std::cout << "------------------->Operations<--------------------------------" << std::endl;


//     std::cout << "----------------Testing find()-----------------------" << std::endl;
//     it1 = map2.find(5);
//     std::cout << "iterator point : " << it1->first << " && " << it1->second << std::endl;


//     std::cout << "-----------------Testing count()----------------------------------" << std::endl;
//     if(map2.count(5) != 0)
//         std::cout << "This element is an elem of my map\n";
//     else
//         std::cout << "This element is not an element of my map\n";


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
