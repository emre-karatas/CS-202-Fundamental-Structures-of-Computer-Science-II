/**
* Title: AVL  class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include <iostream>
#include "DictionarySearchTree.h"
#include "TreeNode.h"
#ifndef DICTIONARYAVLTREE__H
#define DICTIONARYAVLTREE__H
using namespace std;
class DictionaryAVLTree: public DictionarySearchTree
{
public:
    DictionaryAVLTree(string file);
    void insert(string word);
    void insertItem(const string &word,TreeNode*& rootNode);
    void search(string word,int& numComparison, bool& found) const;
    void search(string queryFile,string outputFile) const;
    int getHeight(TreeNode *node) const;
    int getBalanced(TreeNode *rootNode);
    TreeNode* rightRotate(TreeNode *node);
    TreeNode* leftRotate(TreeNode *node);
    void searchHelper(const string &word,TreeNode *rootNode,int &numComparison, bool  &found)const;
    void searchHelperQuery(const string &word,TreeNode *rootNode,int &numComparison, bool  &found)const;


};
#endif // DICTIONARYAVLTREE__H
