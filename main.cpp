#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;

int main() 
{
    ft::vector<int> vect1;
    vector<int> vectTest1;
    //ft::vector<int> vect2(1 , 2 , 100);
    ft::vector<int>::iterator i;
    int nb = 1;
    for (int i = 0; i < 10; i++)
    {
      nb = nb + 1;
      std::cout << nb << "\n";
      vect1.push_back(nb);
      vectTest1.push_back(nb);
    }


    std::cout << "***************start test ************\n";

    std::cout << "size() function ------>" << endl;
    std::cout << "size of our vector = " << vect1.size() << endl;
    std::cout << "size to test = " << vectTest1.size() << endl;

    cout << "*********************************************\n";

    std::cout << "max_size() function ---->" << endl;
    std::cout << "max_size of out vector = " << vect1.max_size() << endl;
    std::cout << "max size to test = " << vectTest1.max_size() << endl;

    cout << "*********************************************\n";

    std::cout << "capacity befaure resinzing :-->" << vect1.capacity() << endl;
    std::cout << "capacity befaure resinzing :-->" << vectTest1.capacity() << endl;

    cout << "*********************************************\n";

    std::cout << "resize function ---->" << endl;

    vect1.resize(20,20);;
    vectTest1.resize(20,20);
    std::cout << "resize func of our vector-->" << vect1.size() << endl;
    std::cout << "resize function to test--->" << vectTest1.size() <<endl;
    std::cout << "capacity func of our vector-->" << vect1.capacity() << endl;
    std::cout << "capacity function to test--->" << vectTest1.capacity() <<endl;

    cout << "*********************************************\n";

    std::cout << "at() function--------->" << endl;
    std::cout << "at() function of our vector is --> " << vect1.at(4) <<endl;
    std::cout << "at() function to test --->" << vectTest1.at(4) << endl;

    cout << "*********************************************\n";

    cout << "function reserve --->" << endl;
    vect1.reserve(50);
    vectTest1.reserve(50);
    std::cout<< "size after reserve function of our vector--->" << vect1.size() << endl;
    std::cout << "capacity after reserve function of our vector-->" << vect1.capacity() << endl;
    std::cout<< "size after reserve function to test--->" << vectTest1.size() << endl;
    std::cout << "capacity after reserve function to test-->" << vectTest1.capacity() << endl;
   




    // for (int i = 0; i < 100; i++)
    // {
    //   std::cout << vect1[i] << "\n";
    // }
    // for(i = vect2.begin(); i != vect2.end(); ++i)
    // {
    //   cout << *i << " ";
    // }
}
