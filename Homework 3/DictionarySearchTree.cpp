/**
* Title: DST class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: base class
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "DictionarySearchTree.h"
#include "DictionaryBST.h"
#include "TreeNode.h"
using namespace std;

// file reader for all classes
DictionarySearchTree::DictionarySearchTree(string DictionaryFile)
{
    actualSize = 0;
    string line;
    ifstream file;
    file.open(DictionaryFile);
    if(!file.is_open())
    {
        cout << "Unable to open the file." << endl;
    }
    else
    {
        //read file and write it to the array
        while(getline(file,line))
        {
            words[actualSize] = line;
            actualSize++;
        }
    }
    file.close();

}
DictionarySearchTree::~DictionarySearchTree()
{

}
//implemented in subclasses
void DictionarySearchTree::insert(string word)
{

}
//implemented in subclasses
void DictionarySearchTree::search(string queryFile,string outputFile) const
{



}
//implemented in subclasses
void DictionarySearchTree::search(string word,int& numComparisons,bool& found) const
{

}

