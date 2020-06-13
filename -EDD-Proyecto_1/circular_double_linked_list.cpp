
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
#include <string>
#include <fstream>
using namespace std;

List::List()
{
    first = NULL;
    last = NULL;
    size = 0;
}

ListNode::ListNode()
{
    prev = NULL;
    next = NULL;
    transaction = nullptr;
}

void List::InsertFirst(Transaction* value)
{
    ListNode* p = new ListNode();
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
        ListNode* p;
        p = first;
        for(int i = 0; i < size; i++)
        {
            cout <<">> Transacción de usuario: " + p -> getTransaction() -> getUser() -> getUser() + " ; Activo: " + p -> getTransaction() -> getName() << endl;
            p = p -> next;
        }
    }
}

void List::InsertLast(Transaction* value)
{
    ListNode* p = new ListNode();
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
    ListNode* p;
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
    ListNode* p;
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

void List::InsertSorted(Transaction * value)
{
    ListNode* aux1, *aux2, *aux3;
    if(first == NULL || value -> getId() < first -> getTransaction() -> getId()) // Compares transaction IDs.
    {
        InsertFirst(value);
    }
    else
    {
        if(value -> getId() > last -> getTransaction() -> getId()) // If data to insert is greater that last data
        {                                                          // new value is gonna be inserted last.
            InsertLast(value);
        }
        else // Else value is gonna be compared one by one in order to get inserted sorted.
        {
            aux1 = new ListNode();
            aux1 -> setTransaction(value);
            aux2 = first;
            while(aux2 -> getTransaction() -> getId() < aux1 -> getTransaction() -> getId())
            {
                aux2 = aux2 -> getNext();
            }
            aux3 = aux2 -> getPrev();
            aux3 -> setNext(aux1);
            aux1 -> setNext(aux2);
            aux1 -> setPrev(aux3);
            aux2 -> setPrev(aux1);
            size ++;
        }
    }
}

ListNode* List::Search(Transaction* pos)
{
    if(first == NULL)
    {
        cout << ">> No hay ninguna transacción." << endl;
        return nullptr;
    }
    else
    {
        ListNode* p = first;
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
    ListNode* p = Search(value);
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
    size--;
}

void List::InsertM(Transaction* pos, Transaction* value)
{
    ListNode* p = new ListNode();
    p -> setTransaction(value);
    ListNode* search;
    search = Search(pos);
    
    p -> prev = search;
    p -> next = search -> next;
    
    search -> next -> prev = p;
    search -> next = p;
}

void List::graphAsc()
{
    ofstream file;
    file.open("transactions/transactionsAsc.dot", ios::out);
    
    file << "digraph g{" << endl;
    file << "rankdir=LR;" << endl;
    file << "node [shape=record];" << endl;
    ListNode* aux = first;
    
    // Creates all transaction nodes.
    
    while(aux -> getNext() != first)
    {
        
        file << aux -> getTransaction() -> getName() + "[label = \"{" +"<prev>|Usuario que rentó: "+(aux -> getTransaction() -> getUser() ->getUser())+"\\nActivo: "+(aux -> getTransaction() -> getName())+"\\nID: "+(aux->getTransaction()->getId())+"\\nTiempo Rentado: "+(aux -> getTransaction()->getTimeRented())+" días \\nFecha de renta: " + aux -> getTransaction()->getDate()+"|<next>}\"];" << endl;

        
        aux = aux -> getNext();
    }
    
    file << aux -> getTransaction() -> getName() + "[label = \"{" +"<prev>|Usuario que rentó: "+(aux -> getTransaction() -> getUser() ->getUser())+"\\nActivo: "+(aux -> getTransaction() -> getName())+"\\nID: "+(aux->getTransaction()->getId())+"\\nTiempo Rentado: "+(aux -> getTransaction()->getTimeRented())+" días \\nFecha de renta: " + aux -> getTransaction()->getDate()+"|<next>}\"];" << endl;

    
    
    aux = first;
    
    
    while(aux -> getNext() != first)
    {
        
        file << aux -> getTransaction() -> getName() +":next->"+aux -> getNext() -> getTransaction()->getName()+":prev [arrowhead=vee, dir=both, tailclip=false];" << endl;

        
        aux = aux -> getNext();
    }
    
    file << aux -> getTransaction() -> getName() +":next->"+aux -> getNext() -> getTransaction()->getName()+":prev [arrowhead=vee, dir=both, tailclip=false];" << endl;

    
    
    file << "}" << endl;
    file.close();
    
    std::string dotName ="dot -Tpng transactions/transactionsAsc.dot -o transactions/transactionsAsc.png";
    std::string pngFile = "transactionsAsc.png";
    system(dotName.c_str());
    system(pngFile.c_str());
}


void List::graphDesc()
{
    ofstream file;
    file.open("transactions/transactionsDesc.dot", ios::out);
    
    file << "digraph g{" << endl;
    file << "rankdir=LR;" << endl;
    file << "node [shape=record];" << endl;
    ListNode* aux = last;
    
    // Creates all transaction nodes.
    
    while(aux -> getPrev() != last)
    {
        
        file << aux -> getTransaction() -> getName() + "[label = \"{" +"<prev>|Usuario que rentó: "+(aux -> getTransaction() -> getUser() ->getUser())+"\\nActivo: "+(aux -> getTransaction() -> getName())+"\\nID: "+(aux->getTransaction()->getId())+"\\nTiempo Rentado: "+(aux -> getTransaction()->getTimeRented())+" días \\nFecha de renta: " + aux -> getTransaction()->getDate()+"|<next>}\"];" << endl;

        
        aux = aux -> getPrev();
    }
    
    file << aux -> getTransaction() -> getName() + "[label = \"{" +"<prev>|Usuario que rentó: "+(aux -> getTransaction() -> getUser() ->getUser())+"\\nActivo: "+(aux -> getTransaction() -> getName())+"\\nID: "+(aux->getTransaction()->getId())+"\\nTiempo Rentado: "+(aux -> getTransaction()->getTimeRented())+" días \\nFecha de renta: " + aux -> getTransaction()->getDate()+"|<next>}\"];" << endl;

    
    
    aux = last;
    
    
    while(aux -> getPrev() != last)
    {
        
        file << aux -> getTransaction() -> getName() +":next->"+aux -> getPrev() -> getTransaction()->getName()+":prev [arrowhead=vee, dir=both, tailclip=false];" << endl;

        
        aux = aux -> getPrev();
    }
    
    file << aux -> getTransaction() -> getName() +":next->"+aux -> getPrev() -> getTransaction()->getName()+":prev [arrowhead=vee, dir=both, tailclip=false];" << endl;

    
    
    file << "}" << endl;
    file.close();
    
    std::string dotName ="dot -Tpng transactions/transactionsDesc.dot -o transactions/transactionsDesc.png";
    std::string pngFile = "transactionsAsc.png";
    system(dotName.c_str());
    system(pngFile.c_str());
}

