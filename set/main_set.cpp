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

#include "set.hpp"
#include "iostream"
#include "set"
int main()
{
    std::set<int> myset;
    ft::set<int> set1;
    ft::set<int>::iterator it1;
    ft::pair<ft::set<int>::iterator, bool> ret; 



    std::cout << "********** Testing insert() *********\n";
    for(int i=1; i<= 5; i++)
    {
        set1.insert(i*10);
    }
    std::cout << "inserting from 10 to 50\n";
    for(it1 = set1.begin(); it1 != set1.end(); it1++)
    {
        std::cout << *it1 << std::endl;
    }

    ret = set1.insert(20);

    if(ret.second == false)
    {
        it1 = ret.first;
    }

    std::cout << "try to modifier the value\n";
    set1.insert(it1, 25);
    // set1.insert(it1, 24);
    // set1.insert(it1, 26);
    for(it1 = set1.begin(); it1 != set1.end(); it1++)
    {
        std::cout << *it1 << std::endl;
    }

    // int array[] = {5,10,15};
    // set1.insert(array, array+3);
    // std::cout << "our set after putting another three value\n";
    // for(it1 = set1.begin(); it1 != set1.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }

    // insert map by using two iters

    ft::set<int>::iterator it2;
    ft::set<int> set2;
    it2=set1.find(24);
    set2.insert(it2, set1.end());

    std::cout << "printing second set\n";
    for(it1 = set2.begin(); it1 != set2.end(); it1++)
    {
        std::cout << *it1 << std::endl;
    }

    std::cout << "************* testing erase()**********\n ";

    // ft::set<int>::iterator it3;
    // it3 = set1.begin();

    // it3++;
    // set1.erase(it3);
    // std::cout << "printing our set after remove an element that it3 point in it\n";

    // for(it1 = set1.begin(); it1 != set1.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }
    // ft::set<int>::iterator it4;
    // it4 = set2.begin();
    // it4++;
    // set2.erase(it4,set2.end());
    // std::cout << "Printing after remove from the second element to the end\n";
    // for(it1 = set2.begin(); it1 != set2.end(); it1++)
    // {
    //     std::cout << *it1 << std::endl;
    // }

    set1.erase(26);
    std::cout << "printing set after removing 26 element\n ";
    for(it1 = set1.begin(); it1 != set1.end(); it1++)
    {
        std::cout << *it1 << std::endl;
    }

    std::cout << "********testing find()********\n";

    ft::set<int>::iterator it5;
    it5=set1.find(20);

    set2.erase(it5);
    std::cout << "Printing our map after removing 20\n";
    for(it1 = set1.begin(); it1 != set1.end(); it1++)
    {
        std::cout << *it1 << std::endl;
    }








    






 




}