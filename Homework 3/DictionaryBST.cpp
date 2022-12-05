/**
* Title: BST class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include "DictionaryBST.h"
#include "TreeNode.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//constructor which calls base class.
DictionaryBST::DictionaryBST(string file): DictionarySearchTree(file)
{
    for(int i = 0; i < actualSize; i++)
    {
        insert(words[i]);
    }

}
//insert
void DictionaryBST::insert(string word)
{
    insertItem(word,root);

}
// file table output creator
template<typename T> void printElement(T t, const int& width)
{
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

//helper method for insert method
void DictionaryBST::insertItem(const string &word, TreeNode *&rootNode)
{
    if(rootNode == nullptr)
    {
        //if rootNode is null, then create a new tree node
        rootNode = new TreeNode(word,nullptr,nullptr);
    }
    else
    {

        if(word < rootNode->nodeWord)
        {
            // if item is smaller than root, then go left subtree
            insertItem(word,rootNode->leftChildPtr);
            //cout << "left insert " << rootNode->leftChildPtr->nodeWord << endl;

        }
        else
        {
            // if not, go to right subtree
            insertItem(word,rootNode->rightChildPtr);
            //cout << "right insert " << rootNode->rightChildPtr->nodeWord << endl;
        }
    }


}

//search from query.txt and print the results to output.txt file
void DictionaryBST::search(string queryFile, string outputFile) const
{
    bool found = false;
    int number = 0;
    int maxFound = 0;
    int comparisonTotal = 0;
    int counter = 0;
    string line;
    ifstream file;
    ofstream output;
    output.open(outputFile);
    file.open(queryFile);
    // read file and print out to output file immediately.
    if(!file.is_open())
    {
        output << "Unable to open the file." << endl;
    }
    else
    {
        while(getline(file,line))
        {
            //helper method for search
            searchHelperQuery(line,root,number,found);
            output << line << " ";
            output << found << " " ;
            output << number<< " " ;
            output << endl;
            //calculating max
            if(number > maxFound)
            {
                maxFound = number;
            }
            //comp total and counter operations
            comparisonTotal += number;
            counter++;
            number = 0;
        }
    }
    file.close();
    //results printing to output file
    output << "# of Queries: " << counter << endl;
    output << "Maximum # of Comparisons: " << maxFound << endl;
    double average = static_cast<double>(comparisonTotal)/static_cast<double>(counter);
    output << "Average # of Comparisons: " << average << endl;
    output.close();
}

//search from a given word
void DictionaryBST::search(string word, int& numComparison, bool& found) const
{
    found = false;
    numComparison = 0;
    // helper method
    searchHelper(word,root,numComparison,found);

}

//helper method
void DictionaryBST::searchHelper(const string &word,TreeNode *rootNode,int &numComparison, bool &found) const
{
    if(rootNode == nullptr)
    {
        cout << "Word " << word << " cannot be found in the BST." << endl;
        return;
    }
    else
    {
        if(rootNode->nodeWord == word)
        {
            found = true;
            numComparison++;
            cout << "Word: " << word << ", is found. " << endl;
            cout << "Number of comparisons: " << numComparison << endl;
            return;

        }
        if(rootNode->nodeWord> word)
        {
            numComparison++;
            searchHelper(word,rootNode->leftChildPtr,numComparison,found);

        }
        else
        {
            numComparison++;
            searchHelper(word,rootNode->rightChildPtr,numComparison,found);
        }
    }

}

//helper method
void DictionaryBST::searchHelperQuery(const string &word,TreeNode *rootNode,int &numComparison, bool &found) const
{
    if(rootNode == nullptr)
    {
        found = false;
        return;
    }
    else
    {
        if(rootNode->nodeWord == word)
        {
            found = true;
            numComparison++;
            return;

        }
        if(rootNode->nodeWord > word)
        {
            numComparison++;
            searchHelperQuery(word,rootNode->leftChildPtr,numComparison,found);

        }
        else
        {
            numComparison++;
            searchHelperQuery(word,rootNode->rightChildPtr,numComparison,found);
        }
    }

}


