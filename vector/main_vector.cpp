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

// #include "vector.hpp"
// #include "vector_iterator.hpp"
// # include "vector_reverse_iterator.hpp"
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

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
//     vect2.push_back(600);
//     vect2.push_back(700);
//     vect2.push_back(800);
//     vect2.push_back(900);

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
//         vect1.push_back(i);
//         vectTest1.push_back(i);
//     }
//     std::cout << "Print our vector\n";
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << *i << std::endl;
//     }
//      //pop_back function
//     vect1.pop_back(); // delete the last element -->9
//     vectTest1.pop_back();
//     std::cout << "Print vector after deleting last element\n";
    
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }

//     std::cout << "***********************start test ********************************\n";
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

//     vect1.resize(20,20);
//     vectTest1.resize(20,20);
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
//     // vect1.reserve(4611686018427387903);
//     // vectTest1.reserve(4611686018427387903);
//     vect1.reserve(46);
//     vectTest1.reserve(46);
//     std::cout<< "size after reserve function of our vector--->" << vect1.size() << std::endl;
//     std::cout << "capacity after reserve function of our vector-->" << vect1.capacity() << std::endl;
//     std::cout<< "size after reserve function to test--->" << vectTest1.size() << std::endl;
//     std::cout << "capacity after reserve function to test-->" << vectTest1.capacity() << std::endl;
   
//     std::cout << "**************************************************\n";
//     std::cout << "empty()*******\n";
//     if(vect1.empty() == 0)
//     {
//         std::cout << "Our vector is not empty\n";
//     }else
//         std::cout<< "Is empty\n";

//     std::cout << "*************************** at() function ******************\n";
//     std::cout << "at() function--------->" << std::endl;
//     std::cout << "at() function of our vector is --> " << vect1.at(4) <<std::endl;
//     std::cout << "at() function to test --->" << vectTest1.at(4) << std::endl;

//     std::cout << "******************Access element operator[]******************\n";

//     for(size_t j = 0; j < vect1.size(); j++)
//     {
//         //std::cout << "vect[" << j << "]" << vect1[j] << endl;
//         std::cout << vect1[j] << std::endl;
//     }
//     std::cout << "vect1-->" << vect1[100] << std::endl;
//     std::cout << "vectTest-->" << vectTest1[1000] << std::endl;
//     std::cout << "***********Front() and back()  functions*************\n";

//     std::cout << "Front() for our vect-->" << vect1.front() << std::endl;
//     std::cout << "back() for our vect -->" << vect1.back() << std::endl;
    

//     std::cout<< "Front() for vect test-->" << vectTest1.front() << std::endl;
//     std::cout << "Back() for vect test-->" << vectTest1.back() << std::endl;

//     std::cout << "**********Function assign() with integral******\n";

//     //vect1.assign(4611686018427387903,70);
//     //vectTest1.assign(4611686018427387903,70);
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

//     ft::vector<int>::iterator it1;
//     std::vector<int>::iterator it2;
//     //sigfault here because this element that in want to remove it doenst exist
//     // it1 = vect1.begin();
//     // it1= it1 + 5;
//     // it2 = vectTest1.begin();
//     // it2 = it2 + 5;
//     //vect1.erase(it1);//--> //remove the first element
//     //vectTest1.erase(it2);

//     ft::vector<int>::iterator ii1;
//     std::vector<int>::iterator ii2;
//     ii1 = vect1.erase(vect1.begin()); 
//     ii2 = vectTest1.erase(vectTest1.begin());//return next element to the first value position
//     std::cout << "ii1-->" << *ii1 << endl;
//     std::cout << "ii2-->" << *ii2 << endl;
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//    for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }
//     std::cout << "Erase function with two iterators\n";

//     ii1 = vect1.erase(vect1.begin() + 1, vect1.begin() + 3);// return last element in that case is 600
//     ii2 = vectTest1.erase(vectTest1.begin() + 1, vectTest1.begin() + 3);

//     std::cout << "ii1 =" << *ii1 << std::endl;
//     std::cout << "ii2 =" << *ii2 << std::endl;
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }

//     std::cout << "*************Pop_back() && push_bacck()**************\n";

//     vect1.push_back(1000);
//     vect1.push_back(2000);
//     vectTest1.push_back(1000);
//     vectTest1.push_back(2000);
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }
//     vect1.pop_back(); //remove last element in your vector ==> last elem that you push
//     vectTest1.pop_back();
//     std::cout << "After pop_back()\n";
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }
   
    

// //     // std::cout << "swap() function\n";

// //     // vect1.swap(vect2);
// //     // vectTest1.swap(vect3);
// //     //  for(i = vect1.begin(); i != vect1.end(); i++)
// //     // {
// //     //     std::cout << "Our vect element -->" << *i << std::endl;
// //     // }
// //     // for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
// //     // {
// //     //     std::cout << "Test element -->" << *i2 << std::endl;
// //     // }



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
//     for(i2 = vectorTest.begin(); i2 != vectorTest.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
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


//  std::cout << "******************************Clear() **********************\n";

//     vect1.clear();
//     vectTest1.clear();
//     std::cout << "After clearing()\n";

//     std::cout << "There is noo element in our vector & in test vector\n";
//     for(i = vect1.begin(); i != vect1.end(); i++)
//     {
//         std::cout << "Our vect element -->" << *i << std::endl;
//     }
//     for(i2 = vectTest1.begin(); i2 != vectTest1.end(); i2++)
//     {
//         std::cout << "Test element -->" << *i2 << std::endl;
//     }

//     std::cout << "get_Allocator()*********\n";
//     ft::vector<int>m_vector;
//     int *array;
//     //// allocate an array with space for 5 elements using vector's allocator:
//     array = m_vector.get_allocator().allocate(5);
//     for(size_t k = 0;k < 5; k++)
//     {
//         m_vector.get_allocator().construct(&array[k],k*10);
//     }
//     std::cout << "Our array***\n";
//     for(size_t k = 0; k < 5 ; k++)
//     {
//         std::cout << array[k] << std::endl;
//     }
//     //destroy and dealocate

//     for(size_t k = 0; k < 5 ; k++)
//     {
//         //problem !!
//        // m_vector.get_allocator().destroy(&array[k]);
//         //m_vector.get_allocator().deallocate(array, 5);
//     }
// //******** I should testing vector_reverse_iterator && constructers &&and inserting by using subscript operator
//     std::cout << "*****************Constructers**************\n";
//     ft::vector<int> third;
//     third.push_back(47);
//     third.push_back(48);
//     third.push_back(49);
//     third.push_back(50);
//     third.push_back(51);


//     ft::vector<int>first(4,100);
//     std::vector<int>second(4,100);
//     ft::vector<int> fifth(third.begin(),third.end());
   
//     //copy constructer
//     ft::vector<int> vectorr(third);
//     std::cout << "Our vector\n";
//     for(size_t m = 0; m < first.size(); m++)
//     {
//         std::cout << first[m] << std::endl;
//     }
//     std::cout << "Vector test\n";
//     for(size_t m = 0; m < second.size(); m++)
//     {
//         std::cout << second[m] << std::endl;
//     }

//     std::cout << "Print fifth vector\n";

//      for(size_t m = 0; m < fifth.size(); m++)
//     {
//         std::cout << fifth[m] << std::endl;
//     }

//     std::cout << "************Assignment operator************\n";

//     ft::vector<int>vv1(40,20);
//     ft::vector<int>vv2;
//     vv2 =  vv1;

//     std::cout << "Print vv1*****\n";
//     for(size_t m = 0; m < vv2.size(); m++)
//     {
//         std::cout << vv2[m] << std::endl;;
//     }

//     return 0;

// }
