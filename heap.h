#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:
    void insert(int value);
    void insert2(int value, bool bb);// insert value; //duplicates are allowed
    void bubbleupMin(int i);
    void bubbleupMax(int i);
    void deleteMin();
    void deleteMax();
    void bubbledownMin(int i);
    void bubbledownMax(int i);


    void getMin();
    void getMax();
    void print(); 
 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array
};

#endif
