/**
* Title: BST class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include <iostream>
#include "DictionarySearchTree.h"
#include "TreeNode.h"
#ifndef DICTIONARYBST__H
#define DICTIONARYBST__H
using namespace std;
class DictionaryBST: public DictionarySearchTree
{
public:
    DictionaryBST(string file);
    void insert(string word);
    void insertItem(const string &word,TreeNode*& rootNode);
    void search(string word,int& numComparison, bool& found) const;
    void searchHelper(const string &word,TreeNode *rootNode,int &numComparison, bool  &found)const;
    void search(string queryFile,string outputFile) const;
    void searchHelperQuery(const string &word,TreeNode *rootNode,int &numComparison, bool  &found)const;


};
#endif // DICTIONARYBST__H
