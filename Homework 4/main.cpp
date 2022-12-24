/**
* Title: MAIN class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 4
* Description: description of your code
*/
#include <iostream>
#include "RBTree.h"
#include "TreeNode.h"
#include "two34Tree.h"
using namespace std;
int main()
{
    RBTree* rbt = new RBTree("input.txt");
    two34Tree *tn = new two34Tree(rbt->value);
    tn->rbtTo234(rbt->root);
    return 0;
}
