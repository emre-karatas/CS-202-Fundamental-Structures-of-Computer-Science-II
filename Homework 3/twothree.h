/**
* Title: 23 class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/

#ifndef twothree_h
#define twothree_h
#include <string>
using namespace std;

class twothree
{
    public:
    twothree();
    string firstitem, seconditem;
    twothree *first, *second, *third;
    twothree *parent;
    bool leaf;
    bool full;
    int size;
    friend class Dictionary23Tree;

};


#endif // twothree_h
