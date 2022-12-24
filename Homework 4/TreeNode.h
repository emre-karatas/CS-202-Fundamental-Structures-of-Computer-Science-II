/**
* Title :Tree Node.h
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 4
* Description : description of your code
*/

#ifndef TreeNode_h
#define TreeNode_h
#pragma once
#include <stdio.h>
using namespace std;
enum color {RED,BLACK};
class TreeNode
{
private:

     //instance variables
    int Item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
    TreeNode *rootNode = nullptr;
    TreeNode *parentPtr;
    bool color;

    // default constructor
    ~TreeNode();

    //other constructor
    TreeNode(const int& Item,TreeNode* parent = nullptr,TreeNode *left = nullptr, TreeNode *right=nullptr);
    void insert(int val);
    TreeNode* insertItem(TreeNode *rootNode, TreeNode* ptr);
    // declaring friend as to see private variables of it.
    TreeNode* rbtTo234(TreeNode *root);
    friend class RBTree;
    friend class two34Tree;


};

#endif // TreeNode
