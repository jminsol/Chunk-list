//
//  ItemT.cpp
//  ChunkList
//
//  Created by JeongMinsol on 2/23/20.
//  Copyright © 2020 Minsol Jeong. All rights reserved.
//

#include "Chunk.hpp"
#include <iostream>

template <class ItemT>
ChunkList<ItemT> :: ChunkList()
//Constructor
{
    head = NULL;
    tail = NULL;
}

//destructor
template <class ItemT>
ChunkList<ItemT> :: ~ChunkList(){
    while (!this->IsEmpty()){
        Chunk<ItemT>* temp = new Chunk<ItemT>;
        temp = head->next;
        delete head;
        head = temp;
        
    }
}

template <class ItemT>
void ChunkList<ItemT>:: Append(ItemT elem)
//Func: Add an element that user entered will be added in a chunk
//Pre: Initialized Chunk List which is signly linked list
//Post: An element is added. If it is empty or full, it creates a new chunk. If not, it just added on a current one.

{
    if (!IsEmpty()){
        if (tail->len < ARRAY_SIZE){
            tail -> values[tail->len++] = elem;
        }
        else{
            Chunk<ItemT>* temp = new Chunk<ItemT>;
            temp -> values [temp -> len++] =elem;
            temp -> next = NULL;
            tail -> next = temp;
            tail = tail -> next;
        }
    }
    else{
        Chunk<ItemT>* temp = new Chunk<ItemT>;
        temp -> values [temp -> len++] =elem;
        temp -> next = NULL;
        head = temp;
        tail = temp;
    }
}

template <class ItemT>
int ChunkList<ItemT>:: GetLength()
//Func: Count all the elements in the chunk list and return the length
//Pre: Initialized Chunk list
//Post: Return a int value for length
{
    int collections_size = 0;

    auto iter = head;
    for (iter= head; iter != NULL; iter = iter -> next){
        collections_size += iter -> len;
    }
    return collections_size;
}

template <class ItemT>
ItemT ChunkList<ItemT>:: GetIndex(int i)
//Func: Find the value according to the index
//Pre: Initialized Chunk list, receive the index that user entered, Added elements
//Post: Return the value of index in the chunk list, if there is no index in the chunk list or the index is a negative value, then catch the error.

{
    auto iter = head;
    try {
        if (i <0) throw i;
        else if (iter -> len > i)
            return (iter -> values[i]);
        else{
            int loc =-1;
            for (iter= head; iter != NULL; iter = iter -> next){
                for (int n = 0; n < iter -> len; n++){
                    loc++;
                    if (loc == i)
                        return (iter -> values[n]);
                }
            }
        }
        throw std::runtime_error("No index");
    }
    catch (int err){
        std:: cout << "Index should be postivie integers" << std:: endl;
    }
    catch (...) {
        std:: cout << "There is no such index" << std:: endl;
    }
    return 0;
}

template <class ItemT>
bool ChunkList<ItemT>:: Contains(ItemT elem)
//Func: Tell if it is true when the element is in the chunk list. As soon as they find the element in the chunk list, it returns true
//Pre: Initialized Chunk list, Added the element.
//Post: Return boolean to tell if the element is in the chunk list
{
    bool found = false;
    auto iter =head;
    for (iter =head; iter != NULL; iter=iter -> next){
        for(int n=0; n < iter->len; n++){
            if (iter->values[n] == elem){
                found = true;
                return found;
            }
        }
    }
    return found;
}

template <class ItemT>
void ChunkList<ItemT>:: Print()
//Func: Print all the element in the list
//Pre: Initialized chunk list, Added elements
//Post: Display all the elements in the chunk list

{
    auto iter =head;
    for (iter =head; iter != NULL; iter=iter -> next){
        for(int n=0; n < iter->len; n++)
            std::cout<< iter->values[n] << " ";
        }
    std::cout << "\n";
}

template <class ItemT>
void ChunkList<ItemT>:: Remove(ItemT elem)
//Func: Remove the specific element if it is in the chunk list
//Pre: Initialized chunk list, Added the elements
//Post: Deleted the element and sort the element in the list starting from index 0

{
    if (Contains(elem)){
        auto iter =head;
        for (iter =head; iter != NULL; iter=iter -> next){
            for(int n=0; n < iter->len; n++){
                if (iter->values[n] == elem){
                    for (int i=n; i< iter->len; i++)
                        iter->values[i]= iter->values[i+1];
                    iter->len--;
                    break;
                }
            }
        }
    }
    else
        std::cerr<< "There is no such an element in this Chunk List" << std::endl;
}

template <class ItemT>
bool ChunkList<ItemT>:: IsEmpty()
//Func: Tell if the list is empty or not
//Pre: Constructed the Chunk List
//Post: Return boolean which tells if it is empty or not

{
    return (head == NULL);
}

