/**
* Title :BST.h
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 2
* Description :BST.h class
*/


#ifndef BST_h
#define BST_h

#include "TreeNode.h"
class BST
{
public:

    //Constructors
    BST();
    BST(const BST& tree);

    //Destructor
    ~BST();


    //methods
    void insert(int key);
    void deleteKey(int key);
    int getHeight();
    double medianOfBST();
    void rangeSearch(int a, int b);
    TreeNode *root;
    //helper methods
    void insertItem(const int& item, TreeNode *&root);
    void searchKeytoDelete(int &toDeleteItem, TreeNode *&node);
    void deleteNode(TreeNode *&nodeToDelete);
    void processLeftMost(TreeNode *&node, int& item);
    int calculateTreeHeight(TreeNode *&node);
    int countNodes(TreeNode *&node);
    void rangeSearchHelper(int startPoint,int endPoint, TreeNode *&node, int flag);

};

#endif // BST_h
