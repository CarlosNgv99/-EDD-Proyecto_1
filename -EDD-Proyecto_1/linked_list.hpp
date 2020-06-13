//
//  linked_list.hpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/13/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <stdio.h>
#include "transaction.hpp"
class LinkedListNode
{
private:
    LinkedListNode* next;
    Transaction* transaction;
public:
    LinkedListNode();
    friend class LinkedList;
    Transaction* getTransaction(){return transaction;};
    
};

class LinkedList
{
private:
    LinkedListNode* first;
public:
    LinkedList();
    void InsertFirst(int);
    void InsertLast(Transaction*);
    void InsertBefore(int,int);
    void InsertAfter(int,int);
    void RemoveFirst();
    void RemoveLast();
    void Remove(int);
    void Display();
    void graph(std::string);
};

#endif /* linked_list_hpp */
