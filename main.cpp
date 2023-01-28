#include "vector.hpp"
#include <iostream>
#include <string>
#include <vector>

using std::cout;

int main() 
{
    ft::vector<std::string> vect1;
    std::string x = "a";
    for (int i = 0; i < 100; i++)
    {
      x = x + "a";
      std::cout << x << "\n";
      vect1.push_back(x);
    }
    std::cout << vect1.size() << "\n";
    for (int i = 0; i < 100; i++)
    {
      std::cout << vect1[i] << "\n";
    }
}
