/**
* Title: 23 TREE class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include <iostream>
#include "DictionarySearchTree.h"
#include "twothree.h"
#ifndef DICTIONARY23TREE__H
#define DICTIONARY23TREE__H
using namespace std;
class Dictionary23Tree: public DictionarySearchTree
{
public:
    Dictionary23Tree(string file);
    void insert(string word);
    void insertItem(const string &word,TreeNode*& rootNode);
    void split(TreeNode *& node);
    void search(string word,int& numComparison, bool& found) const;
    void searchHelper(twothree *curr,const string &word,bool &val, int &numComparison)const;
    void search(string queryFile,string outputFile) const;
    void searchHelperQuery(twothree* rootNode,const string &word,bool &found,int &numComparison)const;
    void split(twothree *n, string key, twothree *first, twothree *second, twothree *third, twothree *fourth);
    int size;
    twothree *root;


};
#endif // DICTIONARY23TREE_H

