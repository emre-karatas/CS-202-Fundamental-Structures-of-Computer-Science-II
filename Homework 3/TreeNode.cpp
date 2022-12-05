/**
* Title :Tree Node.cpp
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 3
* Description : tree Node impl
*/

#include "TreeNode.h"
#include <string>

//default constructor
TreeNode::TreeNode()
{
    //nothing happens there
}

//constructor
TreeNode::TreeNode(const std::string& nodeItem, TreeNode *left,TreeNode *right)
{
    this->height = 1;
    // adjusting values
    nodeWord= nodeItem;
    rightChildPtr = right;
    leftChildPtr = left;
}
