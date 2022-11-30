/**
* Title :BST.cpp
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 2
* Description : BST implementation
*/



#include "BST.h"
#include <iostream>
using namespace std;

//constructors
BST::BST()
{
    // root is null means empty tree.
    root = nullptr;
}

BST::BST(const BST& BStree)
{


}

//destructor
BST::~BST()
{
}

// insert method
void BST::insert(int key)
{
    insertItem(key,root);

}
// delete method
void BST::deleteKey(int key)
{
    searchKeytoDelete(key,root);

}

// helper method for getHeight() method
int BST::calculateTreeHeight(TreeNode *&node)
{
    if(node == nullptr)
    {
        return 0;
    }
    else
    {
        return max(calculateTreeHeight(node->leftChildPtr),calculateTreeHeight(node->rightChildPtr)) + 1;
    }

}

// helper method median func
int BST::countNodes(TreeNode *&node)
{
    int counter = 1;
    // base case
   if(node == nullptr)
   {

       return 0;
   }
   else
   {
       // add 1 and calculate right and left portions
       counter += countNodes(node->leftChildPtr);
       counter += countNodes(node->rightChildPtr);
       return counter;
   }

}

// getHeight() method
int BST::getHeight()
{
    calculateTreeHeight(root);

}


//this method implies Morris Inorder traversal method, which's time complexity is O(n).
double BST::medianOfBST()
{
    if(root == nullptr)
    {
        return 0;
    }
    // get the number of nodes
    int numNodes = countNodes(root);
    // this is the counter to return
    int counter = 0;
    // tree navigators.
    TreeNode *current = root;
    TreeNode*pre,*prev;
    while(current != nullptr)
    {
        // if left is empty, go to right immediately
        if(current->leftChildPtr == nullptr)
        {
            counter++;
            //for odd. numNodes = (numNodes+1)/2 is the base case for finding median for odd number of nodes
            if(numNodes % 2 == 1 && counter == (numNodes+1)/2)
            {
                // then prev (mother) is the median
                return current->item *1.0;

            }
            // for even. numNodes = (numNodes/2)+1 is the base case for finding median for even number of nodes
            else if( numNodes % 2 == 0 && counter == (numNodes/2) + 1)
            {
                // average of current and prev is the median.
                return (current->item + prev->item)*0.5;
            }
            // adjust prev value to use it again.
            prev = current;
            //go to right immediately.
            current = current->rightChildPtr;

        }
        else
        {
            // check left portion of the tree
            pre = current->leftChildPtr;
            //if right ancestor of pre is not null and not equal to same value
            while(pre->rightChildPtr != nullptr  && pre->rightChildPtr != current)
            {
                //go to right
                pre = pre->rightChildPtr;
            }
            if(pre->rightChildPtr == nullptr)
            {
                // go to mother
                pre->rightChildPtr = current;
                // adjust to left
                current = current->leftChildPtr;
            }
            // restoring tree
            else
            {
                pre->rightChildPtr = nullptr;
                prev = pre;
                counter++;
                // odd case
                if(numNodes%2 != 0 && counter == ((numNodes+1) / 2) )
                {
                    return (current->item)*1.0;
                }
                // even case
                else if( numNodes % 2 == 0 && counter == ((numNodes/2) + 1))
                {
                    return (prev->item + current->item )*0.5;
                }
                // restore values.
                prev = current;
                current = current->rightChildPtr;
            }
        }
    }
}


void BST::rangeSearch(int startPoint, int endPoint)
{
    cout << "Keys between " << startPoint << " and " << endPoint << " is : ";
    rangeSearchHelper(startPoint,endPoint,root,0);


}
// helper method for range search
void BST::rangeSearchHelper(int startValue, int endValue, TreeNode *&node, int flag)
{
    // base case #1
    if(nullptr == node )
    {
        return;
    }
    // base case #2
    if ( node == root && flag == 1)
    {
        return;
    }
    // check left portion
    if ( startValue < node->item)
    {
        rangeSearchHelper(startValue,endValue,node->leftChildPtr,1);
    }
    // print the value
    if ( startValue <= node->item && endValue >= node->item)
    {
        cout << node->item << " ";
    }
    // go to right portion
    rangeSearchHelper(startValue,endValue,node->rightChildPtr,1);

}

//helper method for insert method
void BST::insertItem(const int& item, TreeNode *&rootNode)
{
    if(rootNode == nullptr)
    {
        //if rootNode is null, then create a new tree node
        rootNode = new TreeNode(item,nullptr,nullptr);
    }
    else
    {
        if(item < rootNode->item)
        {
            // if item is smaller than root, then go left subtree
            insertItem(item,rootNode->leftChildPtr);

        }
        else
        {
            // if not, go to right subtree
            insertItem(item,rootNode->rightChildPtr);

        }
    }

}



// helper method for delete method
void BST::deleteNode(TreeNode *&nodeToDelete)
{
    // pointer to deleted node
    TreeNode *delPtr;
    //to hold value
    int replacementItem;
    // case 1: node is a leaf node ( which is it does not have any child )
    if((nodeToDelete->leftChildPtr == nullptr) && (nodeToDelete->rightChildPtr == nullptr))
    {
        delete nodeToDelete;
        nodeToDelete = nullptr;
    }
    // case 2: node has only one child
    //case 2.1: Left child is null
    else if (nodeToDelete->leftChildPtr == nullptr)
    {
        delPtr = nodeToDelete;
        nodeToDelete = nodeToDelete->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    //case 2.2 : right child is null
    else if ( nodeToDelete->rightChildPtr == nullptr)
    {
        delPtr = nodeToDelete;
        nodeToDelete = nodeToDelete->leftChildPtr;
        delPtr->leftChildPtr = nullptr;
        delete delPtr;
    }
    //Case 3: node has both right and left child
    else
    {
        processLeftMost(nodeToDelete->rightChildPtr,replacementItem);
        // we get- replacement item from processleftmost method. then equal it to node value.
        nodeToDelete->item = replacementItem;

    }
}

// helper method for delete method
void BST::processLeftMost(TreeNode *& node, int& itemToGet)
{
    if(node->leftChildPtr == nullptr)
    {
        // if we found the end node, get the value
        itemToGet = node->item;
        // pointer for deletion
        TreeNode *delPtr = node;
        // move to right child
        node = node->rightChildPtr;
        //equal to null
        delPtr->rightChildPtr = nullptr;
        //delete
        delete delPtr;

    }
    else
    {
        // recursive call until we reach the end level
        processLeftMost(node->leftChildPtr,itemToGet);
    }
}

// helper method for delete method
void BST::searchKeytoDelete(int &itemToSearch, TreeNode *&node)
{
    if(node == nullptr)
    {
        // if empty, terminate function
        return;
    }
    else if (node->item == itemToSearch)
    {
        // if item found, delete its node
        deleteNode(node);
    }
    else if ( itemToSearch < node->item)
    {
        // else search left
        searchKeytoDelete(itemToSearch,node->leftChildPtr);
    }
    else
    {
        // else search right
        searchKeytoDelete(itemToSearch,node->rightChildPtr);
    }

}
