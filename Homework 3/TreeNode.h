/**
* Title :Tree Node.h
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 3
* Description : description of your code
*/

#ifndef TreeNode_h
#define TreeNode_h

#include <stdio.h>
#include <string>
class TreeNode
{
private:

     //instance variables
    std::string nodeWord;
    int height;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;

    // default constructor
    TreeNode();

    //other constructor
    TreeNode(const std::string& nodeWord,TreeNode *left = NULL, TreeNode *right = NULL);

    // declaring friend as to see private variables of it.
    friend class DictionaryBST;
    friend class DictionaryAVLTree;


};

#endif // TreeNode
