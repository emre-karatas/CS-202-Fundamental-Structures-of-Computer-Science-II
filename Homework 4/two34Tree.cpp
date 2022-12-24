/**
* Title: 23 class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 4
* Description: description of your code
*/
#include "two34Tree.h"
two34Tree::two34Tree()
{

    firstitem = 0;
    seconditem = 0;
    thirdItem = 0;
    leaf = true;
    full = false;
    left=nullptr;
    middleLeft = nullptr;
    middleRight = nullptr;
    right=nullptr;
    parent = nullptr;
    size = 0;
}
two34Tree::two34Tree(int value)
{

    firstitem = value;
    seconditem = 0;
    thirdItem = 0;
    leaf = true;
    full = false;
    left=nullptr;
    middleLeft = nullptr;
    middleRight = nullptr;
    right=nullptr;
    parent = nullptr;
    size = 0;
}

two34Tree* two34Tree::rbtTo234(TreeNode *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    two34Tree *two34Root = new two34Tree(root->Item);
    two34Root->middleLeft = rbtTo234(root->leftChildPtr);
    two34Root->middleRight= rbtTo234(root->rightChildPtr);
    two34Root->full = true;
    return two34Root;
}

