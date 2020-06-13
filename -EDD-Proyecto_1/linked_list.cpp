//
//  linked_list.cpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/13/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "linked_list.hpp"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
LinkedList::LinkedList()
{
    first = NULL;
}

LinkedListNode::LinkedListNode()
{
    next = NULL;
}


void LinkedList::InsertLast(Transaction* value)
{
    LinkedListNode* p, *last;
    p = new LinkedListNode();
    p->transaction = value;
    if(first != NULL)
    {
        last = first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = p;
    }
    else
    {
        first = p;
    }
}

void LinkedList::graph(std::string username)
{
    ofstream file;
    
    file.open("assetsRented/"+username+".dot", ios::out);
    
    file << "digraph g{" << endl;
    file << "rankdir=LR;" << endl;
    file << "node [shape=record];" << endl;
    LinkedListNode* aux = first;
    while(aux -> next != NULL)
    {
        file << aux -> getTransaction() -> getName() + "[label = \"" +"Usuario que rentó: "+(aux -> getTransaction() -> getUser() ->getUser())+"\\nActivo: "+(aux -> getTransaction() -> getName())+"\\nID: "+(aux->getTransaction()->getId())+"\\nTiempo Rentado: "+(aux -> getTransaction()->getTimeRented())+" días \\nFecha de renta: " + aux -> getTransaction()->getDate()+"\"];" << endl;
        
        file << aux -> getTransaction() -> getName() +"->"+aux -> next -> getTransaction()->getName()+"[arrowhead=vee, tailclip=false];" << endl;
        aux = aux -> next;


        
    }
    file << aux -> getTransaction() -> getName() + "[label = \"" +"Usuario que rentó: "+(aux -> getTransaction() -> getUser() ->getUser())+"\\nActivo: "+(aux -> getTransaction() -> getName())+"\\nID: "+(aux->getTransaction()->getId())+"\\nTiempo Rentado: "+(aux -> getTransaction()->getTimeRented())+" días \\nFecha de renta: " + aux -> getTransaction()->getDate()+"\"];" << endl;

    
    file << "}" << endl;
    file.close();
    
    std::string dotName ="dot -Tpng assetsRented/"+username+".dot -o assetsRented/"+username+".png";
    std::string pngFile = username+".png";
    system(dotName.c_str());
    system(pngFile.c_str());
    
}
