//
//  list.hpp
//  double_linked_circular_list
//
//  Created by Carlos NG on 06/09/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef list_hpp
#define list_hpp

#include "transaction.hpp"
#include <stdio.h>

class List;

class ListNode
{
private:
    ListNode* prev;
    ListNode* next;
    Transaction* transaction;

public:
    ListNode();
    friend class List;
    Transaction* getTransaction(){return transaction;};
    void setTransaction(Transaction* value){transaction = value;};
};

class List
{
private:
    ListNode* first;
    ListNode* last;
    int size;
public:
    List();
    void Insert(Transaction*);
    void InsertFirst(Transaction*);
    void InsertLast(Transaction*);
    void InsertM(Transaction*,Transaction*);
    void Remove(Transaction*);
    void RemoveFirst();
    void RemoveLast();
    ListNode* Search(Transaction*);
    void Display();
    void graph();
    
};

#endif /* list_hpp */
