/**
* Title: DST class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/

#ifndef DICTIONARYSEARCHTREE__H
#define DICTIONARYSEARCHTREE__H

#include "TreeNode.h"
using namespace std;
//Search tree implementation for the dictionary
class DictionarySearchTree
{
public:
    //Constructor that constructs the dictionary from the input file
    DictionarySearchTree(string dictionaryFile);
    //Destructor
    virtual ~DictionarySearchTree();
    //Inserts the given word into the dictionary
    virtual void insert( string word );
    //Searches the given word in the dictionary, and returns the number
    //of comparisons made and whether the word is found or not
    virtual void search( string word, int& numComparisons, bool& found ) const;
    //Searches all words in the query file in the dictionary, and
    //summarizes the results in the output file
    virtual void search( string queryFile, string outputFile ) const;

    int actualSize;
    TreeNode *root = nullptr;
    const int MaxSize = 30;
    string *words = new string[MaxSize];
};
#endif // DICTIONARYSEARCHTREE__H
