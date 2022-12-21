# ft_container

STL CONTAINERS
---------------

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of container classes, algorithms, and iterators. It is a generalized library and so, its components are parameterized. Working knowledge of template classes is a prerequisite for working with STL. 

--What is template class or function:

A template is a simple yet very powerful tool in C++. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types. For example, a software company may need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one sort() and pass data type as a parameter. 
C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second keyword can always be replaced by the keyword ‘class’.

--Class Templates like function templates, class templates are useful when a class defines something that is independent of the data type. Can be useful for classes like LinkedList, BinaryTree, Stack, Queue, Array, etc. 




***Template class with one argument**

                          #include <iostream>
                           using namespace std;

                          template <typename T> class Array 
                          {
                              private:
	                                T* ptr;
	                                int size;

                              public:
	                                Array(T arr[], int s);
	                                void print();
                          };

                          template <typename T> Array<T>::Array(T arr[], int s)
                          {
	                            ptr = new T[s];
	                            size = s;
	                            for (int i = 0; i < size; i++)
		                          ptr[i] = arr[i];
                          }

                          template <typename T> void Array<T>::print()
                          {
	                            for (int i = 0; i < size; i++)
		                          cout << " " << *(ptr + i);
	                            cout << endl;
                          }

                          int main()
                          {
	                          int arr[5] = { 1, 2, 3, 4, 5 };
	                          Array<int> a(arr, 5);
	                          a.print();
	                          return 0;
                          }
			  
**Template class with double argument:
	
			
			#include <iostream>
			using namespace std;
  
			template <class T, class U> class A 
			{
    				T x;
   				U y;
  
				public:
    					A() { cout << "Constructor Called" << endl; }
			};
  
			int main()
			{
    				A<char, char> a;
   				A<int, double> b;
    				return 0;
			}
