//
//  tree.hpp
//  avl_tree
//
//  Created by Carlos NG on 6/10/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include "assets.hpp"
class Tree;

class TreeNode
{
private:
    TreeNode* right;
    TreeNode* left;
    Asset* asset;
    int FE;
    int data;
public:
    friend class Tree;
    TreeNode(){right = nullptr; left = nullptr;};
    Asset* getAsset(){return asset;};
    void setAsset(Asset* value){asset = value;};
    TreeNode* getLeft(){return left;};
    TreeNode* getRight(){return right;};
    void setLeft(TreeNode* value){left = value;};
    void setRight(TreeNode* value){right = value;};
    int getFE(){return FE;};
    void setFE(int value){FE = value;};
    int getData(){return data;};
    void setData(int data){this -> data = data;};

};

class Tree
{
private:
    TreeNode* root;
public:
    Tree(){root = NULL;};
    void setRoot(TreeNode* value){root = value;};
    TreeNode* LLRotation(TreeNode* p, TreeNode* aux);
    TreeNode* RRRotation(TreeNode* p, TreeNode* aux);
    TreeNode* LRRotation(TreeNode* p, TreeNode* aux);
    TreeNode* RLRotation(TreeNode* p, TreeNode* aux);
    TreeNode* Search(TreeNode*, std::string data);
    TreeNode* LRestructure(TreeNode* p, int* auxValue);
    TreeNode* RRestructure(TreeNode* p, int* auxValue);
    void Inorder(TreeNode* node);
    void Preorder(TreeNode* node);
    TreeNode* Preorder2(TreeNode* node, int);

    void Susbstitute(TreeNode* p, TreeNode* aux, int* auxValue);
    void Insert(Asset* asset, TreeNode* p, int* band);
    void Remove(TreeNode* p, TreeNode* pAnt, int* axuValue, std::string value);
    TreeNode* getRoot(){return root;};
    void graphAVL(std::string);
    
};

#endif /* tree_hpp */
