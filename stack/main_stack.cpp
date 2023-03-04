/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:20:38 by souchen           #+#    #+#             */
/*   Updated: 2023/02/22 09:18:49 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stack.hpp"
#include "iostream"
#include "stack"

int main()
{
    ft::stack<int> mystack;
    std::stack<int> mystackTest;

    int sum(0);
    int sum2(0);
    for(int i=1; i <= 10; i++)
    {
        mystack.push(i*10);
        mystackTest.push(i*10);
    }
    std::cout << "*********empty()********\n";
    while(!mystack.empty())
    {
        //Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
        sum = sum + mystack.top();
        sum2 = sum2 + mystackTest.top();
        mystack.pop();
        mystackTest.pop();
    }
    std::cout << "total for our stack :" << sum << "\n";
    std::cout << "total for stackTest :" << sum2 << "\n";

    mystack.push(100);
    mystack.push(200);
    mystack.push(300);
    mystack.push(400);
    mystack.push(500);
    mystackTest.push(100);
    mystackTest.push(200);
    mystackTest.push(300);
    mystackTest.push(400);
    mystackTest.push(500);

    std::cout << "************size()*************\n";

    std::cout << "Size of my stack-->"<< mystack.size() << std::endl;
    std::cout << "Size of test stack-->" << mystackTest.size() << std::endl;



}