// Script for correction :
--------------------------



---> srand():
-------------

How srand() and rand() are related to each other?

srand() sets the seed which is used by rand to generate “random” numbers. If you don’t call srand before your first call to rand, it’s as if you had called srand(1) to set the seed to one. 
In short, srand() — Set Seed for rand() Function. 

srand() function is an inbuilt function in C++ STL, which is a header file defined in <cstdlib>. 
srand() is used to initialize random number generators. The srand() function sets the starting point for producing a series of pseudo-random integers.
If srand() is not called, the rand() seed is set as if srand(1) were called at the program start.
Any other value for seed sets the generator to a different starting point. 

  
  
Friend class:
--------------

A friend class can access private and protected members of other classes in which it is declared as a friend

  
  
  
Class value_compare in stl container c++:
---------------------------------------
  
value_compare value_comp() const;
  
Return value comparison object
  
Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.

The arguments taken by this function object are of member type value_type (defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type part of the value is not taken into consideration in this comparison.
  
  
  
  
The public member of this comparison class returns true if the key of the first argument is considered to go before that of the second (according to the strict weak ordering specified by the container's comparison object, key_comp), and false otherwise.
  
  
The difference between private, public and protected:
  ---------------------------------------------------
  
  
public - members are accessible from outside the class
  
private - members cannot be accessed (or viewed) from outside the class
  
protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. You will learn more about Inheritance later.
  
