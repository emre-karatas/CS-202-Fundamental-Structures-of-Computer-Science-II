/**
* Title: AVL TREE class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include "DictionaryAVLTree.h"
#include "TreeNode.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
DictionaryAVLTree::DictionaryAVLTree(string file): DictionarySearchTree(file)
{
    for(int i = 0; i < actualSize; i++)
    {
        insert(words[i]);
    }

}

void DictionaryAVLTree::insert(string word)
{
    insertItem(word,root);

}


//helper method for insert method
void DictionaryAVLTree::insertItem(const string &word, TreeNode *&rootNode)
{
    if(rootNode == nullptr)
    {
        rootNode = new TreeNode(word,nullptr,nullptr);
    }
    if(word < rootNode->nodeWord)
    {
        insertItem(word,rootNode->leftChildPtr);
    }
    else if ( word > rootNode->nodeWord)
    {
        insertItem(word,rootNode->rightChildPtr);
    }
    rootNode->height = max(getHeight(rootNode->leftChildPtr),getHeight(rootNode->rightChildPtr))+ 1;

    int balanced = getBalanced(rootNode);
    if(balanced > 1 && word < rootNode->leftChildPtr->nodeWord)
    {
        rootNode = rightRotate(rootNode);
        return;
    }
    if(balanced < -1 && word > rootNode->rightChildPtr->nodeWord)
    {
        rootNode = leftRotate(rootNode);
        return;
    }
    if(balanced > 1 && word > rootNode->leftChildPtr->nodeWord)
    {
        rootNode->leftChildPtr = leftRotate(rootNode->leftChildPtr);
        rootNode = rightRotate(rootNode);
        return;
    }
    if(balanced < -1 && word < rootNode->rightChildPtr->nodeWord)
    {
        rootNode->rightChildPtr = rightRotate(rootNode->rightChildPtr);
        rootNode = leftRotate(rootNode);
        return;
    }



}
//formatting vector
template<typename T> void printElement(T t, const int& width)
{
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

//search
void DictionaryAVLTree::search(string queryFile, string outputFile) const
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
    //read file
    if(!file.is_open())
    {
        output << "Unable to open the file." << endl;
    }
    else
    {
        while(getline(file,line))
        {
            searchHelperQuery(line,root,number,found);
            output << line << " " ;
            output << found << " ";
            output << number<< " ";
            output << endl;
            if(number > maxFound)
            {
                maxFound = number;
            }
            comparisonTotal += number;
            counter++;
            number = 0;
        }
    }
    file.close();
    output << "# of Queries: " << counter << endl;
    output << "Maximum # of Comparisons: " << maxFound << endl;
    double average = static_cast<double>(comparisonTotal)/static_cast<double>(counter);
    output << "Average # of Comparisons: " << average << endl;
    output.close();

}

//search
void DictionaryAVLTree::search(string word, int& numComparison, bool& found) const
{
    found = false;
    numComparison = 0;
    //helper method
    searchHelper(word,root,numComparison,found);
}

//for getting height
int DictionaryAVLTree::getHeight(TreeNode *node) const
{
    if(node == nullptr)
        return 0;
    else
    {
        return node->height;
    }
}

//calculate the height differences
int DictionaryAVLTree::getBalanced(TreeNode *rootNode)
{
    if(rootNode == nullptr)
    {
        return 0;
    }
    else
    {
        return getHeight(rootNode->leftChildPtr) - getHeight(rootNode->rightChildPtr);
    }
}
//for right rotation
TreeNode* DictionaryAVLTree::rightRotate(TreeNode *node)
{
    TreeNode* child = node->leftChildPtr;
    TreeNode* rightChild = child->rightChildPtr;

    child->rightChildPtr = node;
    node->leftChildPtr = rightChild;

    node->height = max(getHeight(node->leftChildPtr),getHeight(node->rightChildPtr)) + 1;
    child->height = max(getHeight(child->leftChildPtr),getHeight(child->rightChildPtr)) + 1;

    return child;

}
//for left rotation
TreeNode* DictionaryAVLTree::leftRotate(TreeNode *node)
{
    TreeNode* child = node->rightChildPtr;
    TreeNode* leftChild = child->leftChildPtr;

    child->leftChildPtr = node;
    node->rightChildPtr= leftChild;

    node->height = max(getHeight(node->leftChildPtr),getHeight(node->rightChildPtr)) + 1;
    child->height = max(getHeight(child->leftChildPtr),getHeight(child->rightChildPtr)) + 1;

    return child;


}

//helper method
void DictionaryAVLTree::searchHelper(const string &word,TreeNode *rootNode,int &numComparison, bool &found) const
{
    if(rootNode == nullptr)
    {
        cout << "Word " << word << " cannot be found in the tree." << endl;
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
        if(rootNode->nodeWord > word)
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
void DictionaryAVLTree::searchHelperQuery(const string &word,TreeNode *rootNode,int &numComparison, bool &found) const
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
