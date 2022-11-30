/**
* Title : Binary Search Trees
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 2
* Description : For Testing Functions
*/

#include <iostream>
#include  "BST.h"
#include "TreeNode.h"
#include "analysis.h"
#include <iomanip>

using namespace std;

int main()
{
    cout << "Tree is created!" << endl;
    BST tree;
    cout << "Adding numbers..." << endl;
    tree.insert(30);
    tree.insert(40);
    tree.insert(35);
    tree.insert(20);
    tree.insert(50);
    tree.insert(45);
    tree.insert(10);
    tree.insert(25);
    tree.insert(5);
    tree.insert(15);

    cout << "all numbers are added" << endl;

    cout << "The height of the tree: " << tree.getHeight() << endl;

    tree.deleteKey(35);
    cout << "35 deleted..." << endl;
    tree.deleteKey(40);
    cout << "40 deleted..." << endl;

    cout << "Deletion operation is finished." << endl;
    cout << "Median of updated tree is: " << tree.medianOfBST() << endl;

    tree.rangeSearch(5,43);
    cout << endl;
    cout << endl;
    heightAnalysis();

}
