//
//  tree.cpp
//  avl_tree
//
//  Created by Carlos NG on 6/10/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "avl.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

std::string str;

TreeNode* auxSearch = nullptr;
TreeNode* Tree::LLRotation(TreeNode* p, TreeNode* aux)
{
    p -> setLeft(aux -> getRight());
    aux -> setRight(p);
    p -> setFE(0);
    return aux;
}

TreeNode* Tree::RRRotation(TreeNode* p, TreeNode* aux)
{
    p -> setRight(aux -> getLeft());
    aux -> setLeft(p);
    p -> setFE(0);
    return aux;
}

TreeNode* Tree::LRRotation(TreeNode* p, TreeNode* aux)
{
    TreeNode* aux2;
    aux2 = aux -> getRight();
    p -> setLeft(aux2 -> getRight());
    aux2 -> setRight(p);
    aux -> setRight(aux2 -> getLeft());
    aux2 -> setLeft(aux);
    
    if(aux2 -> getFE() == -1){
        p -> FE = 1;
    }
    else
    {
        p -> setFE(0);
    }
    if(aux2 -> getFE() == 1)
    {
        aux -> setFE(-1);
    }
    else
    {
        aux -> setFE(0);
    }
    return aux2;
    
}

TreeNode* Tree::RLRotation(TreeNode* p, TreeNode* aux)
{ // CAMBIAR ESTE
    TreeNode* aux2;
    aux2 = aux -> getLeft();
    p -> setRight(aux2 -> getLeft());
    aux2 -> setLeft(p);
    aux -> setLeft(aux2 -> getRight());
    aux2 -> setRight(aux);
    
    if(aux2 -> getFE() == 1){
        p -> setFE(-1);
    }
    else
    {
        p -> setFE(0);
    }
    if(aux2 -> getFE() == -1)
    {
        aux -> setFE(1);
    }
    else
    {
        aux -> setFE(0);
    }
    return aux2;
}

TreeNode* Tree::Search(TreeNode* node, std::string value) // Extracted from BST
{
    if(node != nullptr)
    {
        if(value < (node -> getAsset() -> getId()))
        {
            return Search(node -> getLeft(), value);
        }
        else
        {
            if(value > (node -> getAsset() -> getId()))
            {
                return Search(node -> getRight(), value);
            }
            else
            {
                std::cout << "Node found: " << node -> getAsset() -> getName() << std::endl;
                return node;
            }
        }
    }
    else
    {
        std::cout << "Node not found." << std::endl;
        return nullptr;
    }
}

void Tree::Insert(Asset* asset, TreeNode* p, int* valueAux) // data to insert, Node to visit and aux value. (valueAux = 0)
{
    TreeNode* aux1, *aux2;
    if(p != NULL) // verifies if pointer is not empty
    {
        if(asset -> getId() <  (p -> getAsset() -> getId()))
        {
            // starts method at left subtree.
            Insert(asset, p -> getLeft(), valueAux);
            p -> setLeft(root);
            if(0 < *valueAux) // Verify if left subtree has grown.
            {
                switch(p -> getFE())
                {
                    case 1:
                    {
                        p -> setFE(0);
                        *valueAux = 0;
                        break;
                    }
                    case 0:
                    {
                        p -> setFE(-1);
                        break;
                    }
                    case -1:
                    {
                        aux1 = p -> getLeft();
                        if(aux1 -> getFE() <= 0)
                        {
                            p = LLRotation(p, aux1);
                        }
                        else
                        {
                            p = LRRotation(p, aux1);
                        }
                        p -> setFE(0);
                        *valueAux = 0;
                    }
                }
            }
        }
        else
        {
            if(asset -> getId() > (p -> getAsset() -> getId()))
            {
                // Starts right subtree method.
                Insert(asset, p -> getRight(), valueAux);
                p -> setRight(root);
                if(0 < *valueAux)
                {
                    switch(p -> getFE())
                    {
                        case -1:
                        {
                            p -> setFE(0);
                            *valueAux = 0;
                            break;
                        }
                        case 0:
                        {
                            p -> setFE(1);
                            break;
                        }
                        case 1:
                        {
                            aux1 = p -> getRight();
                            if(aux1 -> getFE() >= 0)
                            {
                                p = RRRotation(p, aux1);
                            }
                            else
                            {
                                p = RLRotation(p, aux1);
                            }
                            p -> setFE(0);
                            *valueAux = 0;
                        }
                    }
                }
            }
        }
        root = p;
    }
    else
    {
        // Inserts new node updating valueAux value and setting that the tree has grown up.
        aux2 = new TreeNode();
        aux2 -> setAsset(asset);
        aux2 -> setFE(0);
        *valueAux = 1;
        root = aux2;
    }
}

TreeNode* Tree::LRestructure(TreeNode *p, int *auxValue) // Restructure left when right side got diminished
{
    TreeNode* aux;
    if(*auxValue > 0)
    {
       switch(p -> getFE())
       {
           case -1:
               p -> setFE(0);
               break;
           case 0:
               p -> setFE(1);
               *auxValue = 0;
               break;
           case 1:
               aux = p -> getRight();
               if(aux -> getFE() >= 0) // Applies RR Rotation.
               {
                   p -> setRight(aux -> getLeft());
                   aux -> setLeft(p);
                   switch(aux -> getFE())
                   {
                       case 0:
                           p -> setFE(1);
                           aux -> setFE(-1);
                           *auxValue = 0;
                           break;
                       case 1:
                           p -> setFE(0);
                           aux -> setFE(0);
                           break;
                   }
                   p = aux;
               }
               else // Applies RL Rotation.
               {
                   p = RLRotation(p, aux);
                   p -> setFE(0);
               }
               break;
       }
    }
    return p;
}

TreeNode* Tree::RRestructure(TreeNode *p, int *auxValue) // Restructure tree when right side got diminished
{
    TreeNode* aux;
    if(*auxValue > 0)
    {
       switch(p -> getFE())
       {
           case 1:
               p -> setFE(0);
               break;
           case 0:
               p -> setFE(-1);
               *auxValue = 0;
               break;
           case -1:
               aux = p -> getLeft();
               if(aux -> getFE() <= 0) // Applies LL Rotation.
               {
                   p -> setLeft(aux -> getRight());
                   aux -> setRight(p);
                   switch(aux -> getFE())
                   {
                       case 0:
                           p -> setFE(-1);
                           aux -> setFE(1);
                           *auxValue = 0;
                           break;
                       case 1:
                           p -> setFE(0);
                           aux -> setFE(0);
                           break;
                   }
                   p = aux;
               }
               else // Applies LR Rotation.
               {
                   p = LRRotation(p, aux);
                   p -> setFE(0);
               }
               break;
       }
    }
    return p;
}

void Tree::Susbstitute(TreeNode* p, TreeNode *aux, int *auxValue)
{ // Substitutes the deleted value for the rightmost value from the left subtree.
    if(p -> getRight() != NULL)
    {
        Susbstitute(p -> getRight(), aux, auxValue);
        if(aux -> getLeft() == NULL)
        {
            p -> setRight(NULL);
        }
        else
        {
            p -> setRight(aux -> getLeft());
        }
        p = RRestructure(p, auxValue);
    }
    else
    {
        aux -> setData(p -> getData());
        p = p -> getLeft();
        *auxValue = 1;
    }
    aux -> setLeft(p);
}

void Tree::Remove(TreeNode *p, TreeNode *pAnt, int *auxValue, std::string value)
{
    TreeNode* aux = nullptr;
    int top = 0;
    if(p != NULL)
    {
        if(value < (p -> getAsset() -> getId()))
        {
            if(*auxValue > 0)
            {
                top = 1;
            }
            else
            {
                if(*auxValue != 0)
                {
                    top = -1;
                }
            }
            *auxValue = -1;
            Remove(p -> getLeft(), p, auxValue, value);
            p = LRestructure(p, auxValue);
            if(pAnt != NULL)
            {
                switch(top)
                {
                    case -1:
                        pAnt -> setLeft(p);
                        break;
                    case 1:
                        pAnt -> setRight(p);
                        break;
                    default: break;
                }
            }
            else
            {
                root = p;
            }
        }
    
        else
        {
            if(value > (p -> getAsset() -> getId()))
            {
                if(*auxValue < 0)
                {
                    top = -1;
                }
                else
                {
                    if(*auxValue != 0)
                    {
                        top = 1;
                    }
                }
                *auxValue = 1;
                Remove(p -> getRight(), p, auxValue, value);
                p = RRestructure(p, auxValue);
                if(pAnt != NULL)
                {
                    switch(top)
                    {
                        case -1:
                            pAnt -> setLeft(p);
                            break;
                        case 1:
                            pAnt -> setRight(p);
                            break;
                        default: break;
                    }
                }
                else
                {
                    root = p;
                }
            }
            else
            {
                aux = p;
                if(aux -> getRight() == NULL)
                {
                    p = aux -> getLeft();
                    if(*auxValue != 0)
                    {
                        if(*auxValue < 0)
                        {
                            pAnt -> setLeft(p);
                        }
                        else
                        {
                            pAnt -> setRight(p);
                        }
                    }
                    else
                    {
                        if(p == NULL)
                        {
                            root = NULL;
                        }
                        else
                        {
                            root = p;
                        }
                        *auxValue = 1;
                    }
                }
                else
                {
                    if(p -> getLeft() == NULL)
                    {
                        p = aux -> getRight();
                        if(*auxValue != 0)
                        {
                            if(*auxValue <0)
                            {
                                pAnt -> setLeft(p);
                            }
                            else
                            {
                                pAnt -> setRight(p);
                            }
                        }
                        else
                        {
                            if(p == NULL)
                            {
                                root = NULL;
                            }
                            else
                            {
                                root = p;
                            }
                            *auxValue = 1;
                        }
                    }
                    else
                    {
                        Susbstitute(aux -> getLeft(), aux, auxValue);
                        p = LRestructure(p, auxValue);
                        if(pAnt != NULL)
                        {
                            if(*auxValue <= 0)
                            {
                                pAnt -> setLeft(p);
                            }
                            else
                            {
                                pAnt -> setRight(p);
                            }
                        }
                        else
                        {
                            root = p;
                        }
                    }
                }
            }
        }
    }
}

void Tree::graphAVL(std::string name)
{
    ofstream file;
    file.open("avlTrees/"+name+".dot", ios::out);
    str = "digraph g{ ";
    str += "node [fontname=";
    str+="\"Arial\"";
    str+="];";
    Inorder(getRoot());
    str += "}";
    file << str << endl;
    file.close();
    
    std::string dotName ="dot -Tpng avlTrees/"+ name +".dot -o avlTrees/"+name+".png";
    std::string pngFile = name+".png";
    system(dotName.c_str());
    system(pngFile.c_str());


    
}

void Tree::Inorder(TreeNode* node)
{
    if(node != NULL)
    {
        Inorder(node -> left);
        str += (node -> getAsset() -> getName()) + "[label=\"Activo: " + (node -> getAsset() -> getName()) +"\\nID: "+(node ->getAsset()->getId())+ "\"];";

        if(node -> getLeft()!=NULL)
        {
            str+= (node -> getAsset() -> getName())+ "->" +(node->getLeft()->getAsset() -> getName())+";";

        }
        if(node -> getRight()!=NULL)
        {
            str+= (node -> getAsset() -> getName()) + "->" +(node->getRight()->getAsset() -> getName())+";";

        }
        Inorder(node -> right);
    }
}

void Tree::Preorder(TreeNode *node)
{
    if(node != NULL)
    {
        if(node -> getAsset() -> rented == false){
           std::cout <<">> ******* ID: " << node -> getAsset() -> getIdNum() << " ; Nombre: " << node -> getAsset() -> getName() << "; Descripción: " << node ->getAsset() -> getDescription() << std::endl;
        }
        Preorder(node -> left);
        Preorder(node -> right);
    }
}

void Tree::MyRentedAssets(TreeNode* node)
{
    if(node != NULL)
    {
        if(node -> getAsset() -> rented == true){
           std::cout <<">> ID: " << node -> getAsset() -> getIdNum() << " ; Nombre: " << node -> getAsset() -> getName() << "; Descripción: " << node ->getAsset() -> getDescription() << std::endl;
        }
        Preorder(node -> left);
        Preorder(node -> right);
    }
}

TreeNode* Tree::searchAssetIdNum(TreeNode *node, int id_num)
{
    
    if(node != NULL)
    {
        if(node -> getAsset() -> getIdNum() == id_num)
        {
            auxSearch = node;
        }
        searchAssetIdNum(node -> left,id_num);
        searchAssetIdNum(node -> right,id_num);
    }
    return auxSearch;
}
