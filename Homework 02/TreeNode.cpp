/**
* Title :Tree Node.cpp
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 2
* Description : tree Node impl
*/

#include "TreeNode.h"

//default constructor
TreeNode::TreeNode()
{
    //nothing happens there
}

//constructor
TreeNode::TreeNode(const int& nodeItem, TreeNode *left, TreeNode *right)
{
    // adjusting values
    item = nodeItem;
    rightChildPtr = right;
    leftChildPtr = left;
}
