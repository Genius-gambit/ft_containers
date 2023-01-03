`#DATE:` 8 December 2022

`#NOTES:`

1. https://cplusplus.com/reference/vector/vector/
2. https://www.geeksforgeeks.org/vector-in-cpp-stl/
3. https://www.simplilearn.com/tutorials/cpp-tutorial/iterators-in-cpp
4. https://www.geeksforgeeks.org/iterators-c-stl/
5. https://en.cppreference.com/w/cpp/container/vector


`#BUGS:`
1. Operator overloads of the vector comparisons.

`#TODO:`

1. ~~Set up an instanciation for the vector classes using std::allocator.~~
~~2. Set up an Iterator for the starting and the ending index of the vector container.~~
3. Implement member functions which adds values to the vectors.
~~4. Get the allocation working for the vector classes.~~
5. ~~Get Destructor working to free all the memory for the vector classes.~~
~~6. Implement working on simple vectors.~~
~~7. Implement iterator positions.~~
~~8. Get the references of each and every element in the vector container.~~
~~9. Work on Insertion using iterators, allocator in vectors.~~
10. Implement all member functions of the vectors.
~~11. Implement Enable if.~~
12. Implement vector container operator overloads.
13. Implement lexicograhical comparisons of the vector.
14. Implement structure for the map container.
15. Understand the logic of the red black tree.

`#LOG:`
1. Created a vector.hpp file for the instanciation.
2. Created a test.cpp file for testing different test cases like iterators, std::allocators, vector classes.
3. Created a main.cpp file for testing my implementation for the STL Containers.
4. Created a v_iterator.hpp file which will be the iterator for the vector classes.
5. Instanciation for the vector classes is done using std::allocator.
6. Copy Constructor for the vector classes is implemented successfully.
7. Iterator structure initiated.
8. Working on filling the vector container.
9. Set up for the class iterators.
10. Set up Implement insert, push_back member functions
11. Set up max_size().
12. Set up "at()" member function in vector.hpp.
13. Work on push_back() in vector.hpp.
14. Implemented member functions, size(), pop_back(), operator[], capacity, back.
15. Implemented member functions, back, front, clear, empty.
16. Implemented member functions, resize, assign, get_allocator.
17. Basic operations done for the vector iterators.
18. Operators overloads for the iterators: -, -=, +, +=, *, ++, ->, ++(int), --, --(int).
19. Operators overloads for the two iterators comparison: -, ==, <, !=, >, >=, <=, +.
20. Reverse Iterators done in v_iterator.
21. Finished Enable if.
22. Created map.hpp.
23. Finished implementation of insert function in vector.
24. Completed swap function for vector.
