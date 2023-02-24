/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:34:46 by souchen           #+#    #+#             */
/*   Updated: 2023/01/31 11:34:53 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "vector_iterator.hpp"
# include "vector_reverse_iterator.hpp"
#include <iostream>
#include <string>
#include <vector>

//using namespace std;

// int main() 
// {
    
//     ft::vector<int> vect1;
//     std::vector<int> vectTest1;

//     ft::vector<int> vect2;
//     std::vector<int> vect3;

//     vect2.push_back(100);
//     vect2.push_back(200);
//     vect2.push_back(300);
//     vect2.push_back(400);
//     vect2.push_back(500);

//     vect3.push_back(100);
//     vect3.push_back(200);
//     vect3.push_back(300);
//     vect3.push_back(400);
//     vect3.push_back(500);


    
//     //ft::vector<int> vect2(1 , 2 , 100);
//     ft::vector<int>::iterator i;
//     std::vector<int>::iterator i2;
//     ft::vector<int>::iterator i3;
//     i3 = vect2.begin()+1;
//     //i2 = vect2.begin()+1;
//     for (int i = 0; i < 10; i++)
//     {
//         //push_back function
//       vect1.push_back(i);
//       vectTest1.push_back(i);
//     }
//     //pop_back function
//     vect1.pop_back(); // delete the last element -->9
//     std::cout << "Print vector \n";
    
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }

//     std::cout << "***************start test ************\n";
//     std::cout << "size() && Max_size() && capacity()" << std::endl;

//     std::cout << "size() function ------>" << std::endl;
//     std::cout << "size of our vector = " << vect1.size() << std::endl;
//     std::cout << "size to test = " << vectTest1.size() << std::endl;

//     std::cout << "*********************************************\n";

//     std::cout << "max_size() function ---->" << std::endl;
//     std::cout << "max_size of out vector = " << vect1.max_size() << std::endl;
//     std::cout << "max size to test = " << vectTest1.max_size() << std::endl;

//     std::cout << "*********************************************\n";

//     std::cout << "capacity befaure resinzing :-->" << vect1.capacity() << std::endl;
//     std::cout << "capacity befaure resinzing :-->" << vectTest1.capacity() << std::endl;

//     std::cout << "*********************************************\n";

//     std::cout << "resize function *****---->" << std::endl;

//     vect1.resize(21,20);
//     vectTest1.resize(21,20);
//     //vectTest1.resize(20,20);
//     std::cout << "resize func of our vector-->" << vect1.size() << std::endl;
//     std::cout << "resize function to test--->" << vectTest1.size() <<std::endl;
//     std::cout << "capacity func of our vector-->" << vect1.capacity() << std::endl;
//     std::cout << "capacity function to test--->" << vectTest1.capacity() <<std::endl;


//     std::cout << "our vector after resizing \n";

//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     std::cout << "Test vector after resizing \n";

//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }


//     std::cout << "*********************************************\n";

//     std::cout << "function reserve --****->" << std::endl;
//     vect1.reserve(50);
//     vectTest1.reserve(50);
//     std::cout<< "size after reserve function of our vector--->" << vect1.size() << std::endl;
//     std::cout << "capacity after reserve function of our vector-->" << vect1.capacity() << std::endl;
//     std::cout<< "size after reserve function to test--->" << vectTest1.size() << std::endl;
//     std::cout << "capacity after reserve function to test-->" << vectTest1.capacity() << std::endl;
   


//     std::cout << "*************************** at() function ******************\n";
//     std::cout << "at() function--------->" << std::endl;
//     std::cout << "at() function of our vector is --> " << vect1.at(4) <<std::endl;
//     std::cout << "at() function to test --->" << vectTest1.at(4) << std::endl;

//     std::cout << "***********Front() and back()  functions*************\n";

//     std::cout << "Front() for our vect-->" << vect1.front() << std::endl;
//     std::cout << "back() for our vect -->" << vect1.back() << std::endl;
    

//     std::cout<< "Front() for vect test-->" << vectTest1.front() << std::endl;
//     std::cout << "Back() for vect test-->" << vectTest1.back() << std::endl;

//     std::cout << "**********Function assign() with integral******\n";

//     vect1.assign(50,70);
//     vectTest1.assign(50,70);
//     std::cout << "Print our vect after assigning new element-->\n";

//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }
//     std::cout << "size func of our vector-->" << vect1.size() << std::endl;
//     std::cout << "size function to test--->" << vectTest1.size() <<std::endl;
//     std::cout << "capacity func of our vector-->" << vect1.capacity() << std::endl;
//     std::cout << "capacity function to test--->" << vectTest1.capacity() <<std::endl;

//     std::cout << "Function assign with iterator*******\n";

//     vect1.assign(i3,vect2.end());
//     vectTest1.assign(i3,vect2.end());

//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }


//     std::cout << "Erase function with one iterator*******\n";

//     vect1.erase(vect1.begin());//--> //remove the first element
//     vectTest1.erase(vectTest1.begin());
    
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//    for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }
//     std::cout << "Erase function with two iterators\n";

//     vect1.erase(vect1.begin() + 1, vect1.begin() + 3);
//     vectTest1.erase(vectTest1.begin() + 1, vectTest1.begin() + 3);
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }

//     // std::cout << "swap() function\n";

//     // vect1.swap(vect2);
//     // vectTest1.swap(vect3);
//     //  for(i = vect1.begin(); i != vect1.end(); i++)
//     // {
//     //     std::cout << "Our vect element -->" << *i << std::endl;
//     // }
//     // for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     // {
//     //     std::cout << "Test element -->" << *i2 << std::endl;
//     // }

//     std::cout << "Insert() function with two element in parameter**********\n";
//     ft::vector<int> vector;
//     std::vector<int> vectorTest;
//     std::vector<int> vectInsertTest;
//     ft::vector<int> vectInsert;
//     ft::vector<int>::iterator iter1;
//     std::vector<int>::iterator iter2;
//     std::vector<int>::iterator iterTest;

//     vector.push_back(110);
//     vector.push_back(120);
//     vector.push_back(130);
//     vector.push_back(140);
//     vector.push_back(150);
//     vector.push_back(160);
//     vector.push_back(170);
//     vector.push_back(180);
//     vector.push_back(190);
//     vectorTest.push_back(110);
//     vectorTest.push_back(120);
//     vectorTest.push_back(130);
//     vectorTest.push_back(140);
//     vectorTest.push_back(150);
//     vectorTest.push_back(160);
//     vectorTest.push_back(170);
//     vectorTest.push_back(180);
//     vectorTest.push_back(190);
//     vectInsertTest.push_back(1000);
//     vectInsertTest.push_back(2000);
//     vectInsertTest.push_back(3000);
//     vectInsertTest.push_back(4000);
//     vectInsertTest.push_back(5000);
//     vectInsertTest.push_back(6000);
//     vectInsertTest.push_back(7000);
//     vectInsertTest.push_back(8000);
//     vectInsertTest.push_back(9000);
//     iter1 = vector.begin() + 3;
//     iter2 = vectorTest.begin() + 3;
//     iter1 = vector.insert(iter1,200);
//     iter2 = vectorTest.insert(iter2, 200);
//     for(i = vector.begin(); i != vector.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     std::cout << "Test for vector test-->" << *iter2 << std::endl;
//     std::cout << "Test our vector-->" << *iter1 << std::endl;
//     std::cout << "insert() with 3 element in parameter\n";

//     iter1 = vector.insert(iter1,4,444);
//     iter2 = vectorTest.insert(iter2,4, 444);

//     std::cout << "Our vector-->" <<*iter1<<std::endl;
//     std::cout << "Test vector-->" << *iter2 << std::endl;
//     for(i = vector.begin(); i != vector.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(iterTest = vectorTest.begin(); iterTest != vectorTest.end(); iterTest++)
//     {
//         std::cout << "Test element -->" << *iterTest << std::endl;
//     }
//     std::cout << "insert() with 3 iterators\n";
//     iterTest = vectorTest.begin()+2;
//     iter1 = vector.begin() + 2;
//     vectorTest.insert(iterTest,vectInsertTest.begin(), vectInsertTest.end());
//     vector.insert(iter1,vectInsertTest.begin(), vectInsertTest.end());
//     for(i = vector.begin(); i != vector.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(iterTest = vectorTest.begin(); iterTest != vectorTest.end(); iterTest++)
//     {
//         std::cout << "Test element -->" << *iterTest << std::endl;
//     }

// //******** I should testing vector_reverse_iterator && constructers &&and inserting by using subscript operator

    
// }
