/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:20:58 by souchen           #+#    #+#             */
/*   Updated: 2023/02/22 09:18:32 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "set.hpp"
// #include "iostream"
// #include "set"
// int main()
// {
//     std::set<int> myset;
//     ft::set<int> set1;
//     ft::set<int>::iterator it1;
//     ft::pair<ft::set<int>::iterator, bool> ret; 


//     std::cout << "*************************************************************\n";
//     std::cout << "********** Testing insert() *********\n";
//     for(int i=1; i<= 5; i++)
//     {
//         set1.insert(i*10);
//     }
//     std::cout << "inserting from 10 to 50\n";
//     for(it1 = set1.begin(); it1 != set1.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }

//     ret = set1.insert(20);

//     if(ret.second == false)
//     {
//         it1 = ret.first;
//     }

//     std::cout << "try to modifier the value\n";
//     set1.insert(it1, 25);
//     // set1.insert(it1, 24);
//     // set1.insert(it1, 26);
//     for(it1 = set1.begin(); it1 != set1.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }

//     // int array[] = {5,10,15};
//     // set1.insert(array, array+3);
//     // std::cout << "our set after putting another three value\n";
//     // for(it1 = set1.begin(); it1 != set1.end(); it1++)
//     // {
//     //     std::cout << *it1 << std::endl;
//     // }

//     // insert map by using two iters

//     ft::set<int>::iterator it2;
//     ft::set<int> set2;
//     it2=set1.find(24);
//     set2.insert(it2, set1.end());

//     std::cout << "printing second set\n";
//     for(it1 = set2.begin(); it1 != set2.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }

//     std::cout << "*************************************************************\n";
//     std::cout << "************* testing erase()**********\n ";

//     // ft::set<int>::iterator it3;
//     // it3 = set1.begin();

//     // it3++;
//     // set1.erase(it3);
//     // std::cout << "printing our set after remove an element that it3 point in it\n";

//     // for(it1 = set1.begin(); it1 != set1.end(); it1++)
//     // {
//     //     std::cout << *it1 << std::endl;
//     // }
//     // ft::set<int>::iterator it4;
//     // it4 = set2.begin();
//     // it4++;
//     // set2.erase(it4,set2.end());
//     // std::cout << "Printing after remove from the second element to the end\n";
//     // for(it1 = set2.begin(); it1 != set2.end(); it1++)
//     // {
//     //     std::cout << *it1 << std::endl;
//     // }

//     set1.erase(26);
//     std::cout << "printing set after removing 26 element\n ";
//     for(it1 = set1.begin(); it1 != set1.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }

//     std::cout << "*************************************************************\n";
//     std::cout << "********testing find()********\n";

//     ft::set<int>::iterator it5;
//     it5=set1.find(25);

//     set1.erase(it5);
//     std::cout << "Printing our map after removing 20\n";
//     for(it1 = set1.begin(); it1 != set1.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }


//     std::cout << "*************************************************************\n";
//     std::cout << "*******Testing count()********\n";

//     for(int j = 1; j < 10; j++)
//     {
//         if(set1.count(j * 10) != 0)
//             cout << "is an element of myset\n";
//         else
//         {
//             cout << "is not an element of my set\n";
//         }

//     }
//     std::cout << "*************************************************************\n";
//     std::cout << "******Testing size(), max_size() and empty()*******\n";

//     if(set1.empty() == 0)
//     {
//         std::cout << "Our set is not empty\n";
//     }else
//         std::cout << "Our set is empty\n";

//     std::cout << "Size of our set is :-->" << set1.size() << endl;
//     std::cout << "Max size of our set is:-->" << set1.max_size() << endl;

//     std::cout << "*************************************************************\n";
//     std::cout << "*************Testing clear()*********\n";
//     //sigfault with negative numbers 
//     // tring to insert 0
//     // boucle infini 
//     set2.insert(1);
//     set2.insert(2);
//     set2.insert(3);
//     set2.insert(55);
//     set2.insert(10);
//     std::cout << "printing second set befaure clear()\n";
//     for(it1 = set2.begin(); it1 != set2.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }
//     set2.clear();
//     set2.insert(1101);
//     set2.insert(2003);
//     std::cout << "printing second set after clear()\n";
//     for(it1 = set2.begin(); it1 != set2.end(); it1++)
//     {
//         std::cout << *it1 << std::endl;
//     }

//     // std::cout << "****** Swap() *********\n";

//     // ft::set<int>setTest1;
//     // ft::set<int>setTest2;
//     // ft::set<int>::iterator ii1;

//     // setTest1.insert(100);
//     // setTest1.insert(200);
//     // setTest1.insert(300);
//     // setTest1.insert(400);
//     // setTest1.insert(500);
//     // setTest2.insert(1000);
//     // setTest2.insert(2000);
//     // setTest2.insert(3000);
//     // setTest2.insert(4000);
//     // setTest2.insert(5000);

//     // setTest1.swap(setTest2);

//     // std::cout << "Print SetTest1***\n";
//     // for(ii1 = setTest1.begin(); ii1!= setTest1.end(); ii1++)
//     // {
//     //     std::cout << *ii1 << std::endl;
//     // }
//     // std::cout << "Print setTest2**\n";
//     // for(ii1 = setTest2.begin(); ii1!= setTest2.end(); ii1++)
//     // {
//     //     std::cout << *ii1 << std::endl;
//     // }

//     std::cout << "Lower bound()*******&& upper_bound()****\n";

//     std::set<int> set3;
//     std::set<int>::iterator iter1;
//     std::set<int>::iterator iter2;
//     for(int i = 1; i < 10; i++)
//     {
//         set3.insert(i * 10);
//     }
//     iter1 = set3.lower_bound(30);
//     iter2 = set3.upper_bound(30);
//     std::cout << "lower_bound(30)-->" << *iter1 << endl;
//     std::cout << "upper_bound(30)-->"<< *iter2 << endl;
    
//     std::cout << "*******equal_range()***\n";

//     ft::set<int> myset;

//     for(int k = 1; k <=5 ; k++)
//     {
//         myset.insert(k * 10);
//     }

//     ft::pair<ft::set<int>::iterator,ft::set<int>::iterator> ret;
//     ft::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ret1;

//     // there is a problem here
//     ret1 = myset.equal_range(30);


// }