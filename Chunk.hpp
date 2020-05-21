//
//  Chunk.hpp
//  ChunkList
//
//  Created by JeongMinsol on 2/23/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#ifndef Chunk_hpp
#define Chunk_hpp

#include <stdio.h>

const int ARRAY_SIZE = 8;

template <class ItemT>
struct Chunk{
    Chunk* next;
    int len=0;
    ItemT values[ARRAY_SIZE];
};

template <class ItemT>
class ChunkList{
    
private:
    Chunk<ItemT>* head;
    Chunk<ItemT>* tail;
    
public:
    ChunkList();
    // constructor
    
    ~ChunkList();
    //destructor
    
    void Append(ItemT elem);
    //Func: Add an element that user entered will be added in a chunk
    //Pre: Initialized Chunk List which is signly linked list
    //Post: An element is added. If it is empty or full, it creates a new chunk. If not, it just added on a current one.
    
    int GetLength();
    //Func: Count all the elements in the chunk list and return the length
    //Pre: Initialized Chunk list
    //Post: Return a int value for length
    
    ItemT GetIndex(int i);
    //Func: Find the value according to the index
    //Pre: Initialized Chunk list, receive the index that user entered, Added elements
    //Post: Return the value of index in the chunk list, if there is no index in the chunk list or the index is a negative value, then catch the error.

    bool Contains(ItemT elem);
    //Func: Tell if it is true when the element is in the chunk list. As soon as they find the element in the chunk list, it returns true
    //Pre: Initialized Chunk list, Added the element.
    //Post: Return boolean to tell if the element is in the chunk list
    
    void Print();
    //Func: Print all the element in the list
    //Pre: Initialized chunk list, Added elements
    //Post: Display all the elements in the chunk list
    
    void Remove(ItemT elem);
    //Func: Remove the specific element if it is in the chunk list
    //Pre: Initialized chunk list, Added the elements
    //Post: Deleted the element and sort the element in the list starting from index 0
    
    bool IsEmpty();
    //Func: Tell if the list is empty or not
    //Pre: Constructed the Chunk List
    //Post: Return boolean which tells if it is empty or not
    
};

#endif /* Chunk_hpp */


