/**
* Title: RBTree class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 4
* Description: description of your code
*/
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
#include  "RBTree.h"
#include "TreeNode.h"

RBTree::RBTree()
{

}
// file reader for all classes
RBTree::RBTree(string filePath)
{
    int numOfNodes;
    int rootNodeID;
    string line;
    ifstream file;
    file.open(filePath);
    if(!file.is_open())
    {
        cout << "Unable to open the file." << endl;
    }
    else
    {
        getline(file, line);
        istringstream(line) >> numOfNodes >> rootNodeID;

        rootNodeIDList = new int[numOfNodes];
        leftChildList = new int[numOfNodes];
        rightChildList = new int[numOfNodes];
        type = new int[numOfNodes];
        for(counter = 0; counter < numOfNodes; counter++)
        {
            getline(file, line);
            istringstream(line) >> rootNodeIDList[counter] >> leftChildList[counter] >> rightChildList[counter] >> type[counter];
        }
        value = rootNodeIDList[0];
        for(int i = 0; i < numOfNodes; i++)
        {
            cout << "id: " << rootNodeIDList[i] << endl;
            insert(rootNodeIDList[i]);
            cout << "left: " << leftChildList[i] << endl;
            cout << "right: " << rightChildList[i] << endl;
            cout << "type: " << type[i] << endl;
        }
    }
    file.close();

}

void RBTree::insert(const int& value)
{
    TreeNode *ptr = new TreeNode(value,nullptr,nullptr,nullptr);
    root = ptr->insertItem(root,ptr);
    fixVio(root,ptr);

}

void RBTree::rotateLeft(TreeNode*& root, TreeNode*& ptr)
{

    TreeNode *ptrRight = ptr->rightChildPtr;
    ptr->rightChildPtr = ptrRight->leftChildPtr;

    if(ptr->rightChildPtr !=nullptr)
    {
        ptr->rightChildPtr->parentPtr = ptr;
    }
    ptrRight->parentPtr = ptr->parentPtr;
    if(ptr->parentPtr == nullptr)
    {
        root = ptrRight;
    }
    else if(ptr == ptr->parentPtr->leftChildPtr)
    {
        ptr->parentPtr->leftChildPtr = ptrRight;
    }
    else
    {
        ptr->parentPtr->rightChildPtr  = ptrRight;
    }
    ptrRight->leftChildPtr = ptr;
    ptr->parentPtr = ptrRight;
}
void RBTree::rotateRight(TreeNode*& root, TreeNode*& ptr)
{

    TreeNode *ptrLeft = ptr->leftChildPtr;
    ptr->leftChildPtr = ptrLeft->rightChildPtr;

    if(ptr->leftChildPtr != nullptr)
    {
        ptr->leftChildPtr->parentPtr = ptr;
    }
    ptrLeft->parentPtr = ptr->parentPtr;

    if(ptr->parentPtr == nullptr)
    {
        root = ptrLeft;

    }
    else if (ptr == ptr->parentPtr->leftChildPtr)
    {
        ptr->parentPtr->leftChildPtr = ptrLeft;
    }
    else
    {
        ptr->parentPtr->rightChildPtr = ptrLeft;
    }
    ptrLeft->rightChildPtr = ptr;
    ptr->parentPtr = ptrLeft;
}

void RBTree::fixVio(TreeNode *&root,TreeNode*& ptr)
{
    TreeNode *grandPtr = nullptr;
    TreeNode *grandParentPtr = nullptr;

    while((ptr!= root) && (ptr->color != BLACK) && (ptr->parentPtr->color == RED))
    {
        grandPtr = ptr->parentPtr;
        grandParentPtr = ptr->parentPtr->parentPtr;

        if(grandPtr == grandParentPtr->leftChildPtr)
        {
            TreeNode *unclePtr = grandParentPtr->rightChildPtr;
            if(unclePtr != nullptr && unclePtr->color == RED)
            {
                grandParentPtr->color = RED;
                grandPtr->color = BLACK;
                unclePtr->color = BLACK;
                ptr = grandParentPtr;
            }
            else
            {
                if(ptr == grandPtr->rightChildPtr)
                {
                    rotateLeft(root,grandPtr);
                    ptr = grandPtr;
                    grandParentPtr = ptr->parentPtr;
                }
                rotateRight(root,grandParentPtr);
                swap(grandPtr->color,grandParentPtr->color);
                ptr = grandPtr;
            }
        }
        else
        {
            TreeNode *unclePtr = grandParentPtr->leftChildPtr;
            if((unclePtr!=nullptr) && (unclePtr->color == RED))
            {
                grandParentPtr->color = RED;
                grandPtr->color = BLACK;
                unclePtr->color = BLACK;
                ptr = grandParentPtr;

            }
            else
            {
                if(ptr==grandPtr->leftChildPtr)
                {
                    rotateRight(root,grandPtr);
                    ptr = grandPtr;
                    grandPtr =ptr->parentPtr;
                }
                rotateLeft(root,grandParentPtr);
                swap(grandPtr->color,grandParentPtr->color);
                ptr = grandPtr;
            }
        }
    }
    root->color = BLACK;
}


