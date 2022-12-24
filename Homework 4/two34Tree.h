/**
* Title: 23 class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 4
* Description: description of your code
*/
#include "RBTree.h"
#ifndef two34Tree_h
#define two34Tree_h
#include <string>
using namespace std;
#pragma once
class two34Tree
{
    public:
    two34Tree();
    two34Tree* rbtTo234(TreeNode *root);
    two34Tree(int value);
    int firstitem, seconditem, thirdItem;
    two34Tree *right, *middleRight, *middleLeft, *left;
    two34Tree *parent;
    bool leaf;
    bool full;
    int size;
    friend class RBTree;
    friend class TreeNode;

};


#endif // twothree_h
