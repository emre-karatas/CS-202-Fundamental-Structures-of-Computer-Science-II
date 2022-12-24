/**
* Title :Tree Node.cpp
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 4
* Description : tree Node impl
*/

#include "TreeNode.h"
#include "two34Tree.h"
//default constructor
TreeNode::~TreeNode()
{

}

//constructor
TreeNode::TreeNode(const int& nodeItem,TreeNode *parent, TreeNode *left, TreeNode *right)
{
    // adjusting values
    Item = nodeItem;
    rightChildPtr = right;
    leftChildPtr = left;
    parentPtr = parent;
    this->color = BLACK;
}


//helper method for insert method
TreeNode* TreeNode::insertItem(TreeNode* rootNode, TreeNode* ptr)
{
    if (rootNode == nullptr)
    {
        return ptr;

    }
    if(ptr->Item < rootNode->Item)
    {
        rootNode->leftChildPtr = insertItem(rootNode->leftChildPtr,ptr);
        rootNode->leftChildPtr->parentPtr = rootNode;
    }
    else if(ptr->Item > rootNode->Item)
    {
        rootNode->rightChildPtr = insertItem(rootNode->rightChildPtr,ptr);
        rootNode->rightChildPtr->parentPtr = rootNode;
    }
    return rootNode;


}

