/**
* Title: MAIN class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 4
* Description: description of your code
*/
#include <string>
#include "TreeNode.h"
#pragma once
using namespace std;
class RBTree
{
public:
    RBTree();
    RBTree(string filePath);
    void insert(const int& value);
    void rotateLeft(TreeNode*& node1, TreeNode*& node2);
    void rotateRight(TreeNode*& node3, TreeNode*& node4);
    void fixVio(TreeNode*& node5, TreeNode*& node6);
    TreeNode *root;
    int value;
    int* rootNodeIDList;
    int* leftChildList;
    int* rightChildList;
    int* type;
    int counter = 0;

};

