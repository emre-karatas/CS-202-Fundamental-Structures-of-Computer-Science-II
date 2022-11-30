/**
* Title :Tree Node.h
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 2
* Description : description of your code
*/

#ifndef TreeNode_h
#define TreeNode_h

#include <stdio.h>
class TreeNode
{
private:

     //instance variables
    int item;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;

    // default constructor
    TreeNode();

    //other constructor
    TreeNode(const int& nodeItem,TreeNode *left = NULL, TreeNode *right = NULL);

    // declaring friend as to see private variables of it.
    friend class BST;


};

#endif // TreeNode

