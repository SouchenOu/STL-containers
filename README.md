// Script for correction :
--------------------------



---> srand():

How srand() and rand() are related to each other?

srand() sets the seed which is used by rand to generate “random” numbers. If you don’t call srand before your first call to rand, it’s as if you had called srand(1) to set the seed to one. 
In short, srand() — Set Seed for rand() Function. 

srand() function is an inbuilt function in C++ STL, which is a header file defined in <cstdlib>. 
srand() is used to initialize random number generators. The srand() function sets the starting point for producing a series of pseudo-random integers.
If srand() is not called, the rand() seed is set as if srand(1) were called at the program start.
Any other value for seed sets the generator to a different starting point. 
