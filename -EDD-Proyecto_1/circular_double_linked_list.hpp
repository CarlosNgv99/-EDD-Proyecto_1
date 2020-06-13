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
#include "linked_list.hpp"
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
    ListNode* getPrev(){return prev;};
    ListNode* getNext(){return next;};
    void setPrev(ListNode*prev){this -> prev = prev;};
    void setNext(ListNode*next){this -> next = next;};


};

class List
{
private:
    ListNode* first;
    ListNode* last;
    int size;
public:
    List();
    void InsertSorted(Transaction*);
    void Insert(Transaction*);
    void InsertFirst(Transaction*);
    void InsertLast(Transaction*);
    void InsertM(Transaction*,Transaction*);
    void Remove(Transaction*);
    void RemoveFirst();
    void RemoveLast();
    void SearchByName(std::string);
    ListNode* Search(Transaction*);
    ListNode* SearchUser(std::string,int);
    void Display();
    void graphAsc();
    void graphDesc();
    void sendTransactionLinkedList(std::string,LinkedList*);
};

#endif /* list_hpp */
