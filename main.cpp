/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:46:23 by souchen           #+#    #+#             */
/*   Updated: 2023/03/04 19:46:29 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map/map.hpp>
// 	#include <stack/stack.hpp>
// 	#include <vector/vector.hpp>
//     #include "vector/vector_iterator.hpp"
//     # include "vector/vector_reverse_iterator.hpp"
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
//     public:
// 	    MutantStack() {}
// 	    MutantStack(const MutantStack<T>& src) 
//         { 
//             *this = src; 
//         }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv)
// {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
//     /*rand() returns a pseudo-random number in the range of [0, RAND_MAX). 
//     RAND_MAX: is a constant whose default value may vary between implementations but it is granted to be at least 32767.*/
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
//     ft::vector<int>::iterator iter1;
// 	ft::map<int, int> map_int;

// 	// for (int i = 0; i < COUNT; i++)
// 	// {
// 	// 	vector_buffer.push_back(Buffer());
// 	// }

//     // // print our vect

//     // // for(size_t k = 0; k < vector_buffer.size(); k++)
//     // // {
//     // //     std::cout<< "Our vect-->" << vector_buffer[k] << std::endl;
//     // // }
//     // // for(iter1 = vector_int.begin(); iter1 != vector_int.end() ; iter1++ )
//     // // {
//     // //     std::cout << *iter1 << std::endl;
//     // // }

// 	// for (int i = 0; i < COUNT; i++)
// 	// {
// 	// 	const int idx = rand() % COUNT;
// 	// 	vector_buffer[idx].idx = 5;
// 	// }
// 	// // ft::vector<Buffer>().swap(vector_buffer);

// 	// try
// 	// {
// 	// 	for (int i = 0; i < COUNT; i++)
// 	// 	{
// 	// 		const int idx = rand() % COUNT;
// 	// 		vector_buffer.at(idx);
// 	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 	// 	}
// 	// }
// 	// catch(const std::exception& e)
// 	// {
// 	// 	//NORMAL ! :P
// 	// }
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	// {
// 	// 	ft::map<int, int> copy = map_int;
// 	// }
// 	// MutantStack<char> iterable_stack;
// 	// for (char letter = 'a'; letter <= 'z'; letter++)
// 	// 	iterable_stack.push(letter);
// 	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	// {
// 	// 	std::cout << *it;
// 	// }
// 	// std::cout << std::endl;
// 	return (0);
// }
