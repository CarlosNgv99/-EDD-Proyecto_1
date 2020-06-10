
#include "circular_double_linked_list.hpp"
//
//  list.cpp
//  double_linked_circular_list
//
//  Created by Carlos NG on 6/09/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "circular_double_linked_list.hpp"
#include <iostream>

using namespace std;

List::List()
{
    first = NULL;
    last = NULL;
    size = 0;
}

Node::Node()
{
    prev = NULL;
    next = NULL;
    transaction = nullptr;
}

void List::InsertFirst(Transaction* value)
{
    Node* p = new Node();
    p -> setTransaction(value);
    if(first == NULL)
    {
        first = p;
        last = p;
        first -> prev = last;
        last -> next = first;
        size++;
    }
    else
    {
        p -> next = first;
        p -> prev = last;
        last -> next = p;
        first -> prev = p;
        first = p;
        size++;
    }
}

void List::Display()
{
    
    if(first == NULL)
    {
        cout << ">> No hay ninguna transacción." << endl;
    }
    else
    {
        Node* p;
        p = first;
        for(int i = 0; i < size; i++)
        {
            cout << p -> transaction -> getUser() << endl;
            p = p -> next;
        }
    }
}

void List::InsertLast(Transaction* value)
{
    Node* p = new Node();
    p -> setTransaction(value);
    if(first == NULL)
    {
        first = p;
        last = p;
        first -> prev = last;
        last -> next = last;
    }
    else
    {
        last -> next = p;
        p -> prev = last;
        p -> next = first;
        first -> prev = p;
        last = p;
        size++;
    }
}

void List::Insert(Transaction* value)
{
    if(first == NULL){
        InsertFirst(value);
    }
    else
    {
        InsertLast(value);
    }
}

void List::RemoveFirst()
{
    Node* p;
    if(first == NULL)
    {
        cout << ">> No hay ninguna transacción." << endl;
    }
    else
    {
        p = first -> next;
        p -> prev = last;
        first = p;
        size--;
        delete p;
    }
    
}

void List::RemoveLast()
{
    Node* p;
    if(first == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        p = first;
        int index = 1;
        while(index < size)
        {
            p = p -> next;
            index++;
        }
        p -> next = first;
        first -> prev = p;
        last = p;
        size--;
        delete p;
    }
        
}

Node* List::Search(Transaction* pos)
{
    if(first == NULL)
    {
        cout << ">> No hay ninguna transacción." << endl;
        return nullptr;
    }
    else
    {
        Node* p = first;
        while(p -> next != last)
        {
            if(p -> getTransaction() == pos)
            {
                cout << ">> Transacción con ID: " << p-> getTransaction() -> getId() <<" del usuario: "<< p -> getTransaction() -> getUser() << endl;
                return p;
            }
            p = p -> next;
        }
        return nullptr;
    }
    
}

void List::Remove(Transaction* value)
{
    Node* p = Search(value);
    p -> next -> prev = p -> prev;
    p -> prev -> next = p -> next;
    
    if(p == first)
    {
        first = p -> next;
    }
    if(p == last)
    {
        last = p -> prev;
    }
    delete p;
}

void List::InsertM(Transaction* pos, Transaction* value)
{
    Node* p = new Node();
    p -> setTransaction(value);
    Node* search;
    search = Search(pos);
    
    p -> prev = search;
    p -> next = search -> next;
    
    search -> next -> prev = p;
    search -> next = p;
}

void List::graph()
{
    
}
