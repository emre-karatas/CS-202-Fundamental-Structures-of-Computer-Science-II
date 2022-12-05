/**
* Title: DST class
* Author: EMRE KARATAS
* ID: 22001641
* Section: 1
* Assignment: 3
* Description: description of your code
*/
#include "Dictionary23Tree.h"
#include "twothree.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

Dictionary23Tree::Dictionary23Tree(string file): DictionarySearchTree(file)
{
    size = 0;
    root = nullptr;
    for(int i = 0; i < actualSize; i++)
    {
        insert(words[i]);
    }
}
void Dictionary23Tree::insert(string word)
{
     if (size == 0)
     {
            this->root = new twothree();
            this->root->firstitem = word;
            this->size++;
            return;
     }
    twothree *ptr = this->root;
    // Find proper leaf node
    while (!ptr->leaf)
    {
        if (word < ptr->firstitem)
        {
            ptr = ptr->first;
        }
        else if (!ptr->full || word < ptr->seconditem)
        {
            ptr = ptr->second;
        }
        else
        {
            ptr = ptr->third;
        }
    }

        if (ptr->full)
            split(ptr, word, nullptr, nullptr, nullptr, nullptr);
        else
        {
            if (ptr->firstitem > word)
            {
                ptr->seconditem = ptr->firstitem;
                ptr->firstitem = word;
            }
            else
            {
                ptr->seconditem = word;
            }
            ptr->full = true;
        }
        this->size++;

}

void Dictionary23Tree::split(twothree *ptr, string word, twothree *first, twothree *second, twothree *third, twothree *fourth)
{
    twothree *ptr1 = new twothree();
    twothree *ptr2 = new twothree();
    twothree *p = ptr == this->root ? new twothree : ptr->parent;

    // Get the keys in order
    string min = ptr->firstitem, mid = ptr->seconditem, max;
    if (word  < min)
    {
        max = mid;
        mid = min;
        min = word;
    }
    else if (word < mid)
    {
        max = mid;
        mid = word;
    }
    else
    {
        max = word;
    }

    ptr1->firstitem = min;
    ptr2->firstitem = max;
    ptr1->parent = p;
    ptr2->parent = p;

    if (!ptr->leaf)
    {
        ptr1->first = first;
        ptr1->second = second;
        ptr2->first = third;
        ptr2->second = fourth;

        first->parent = ptr1;
        second->parent = ptr1;
        third->parent = ptr2;
        fourth->parent = ptr2;

        ptr1->leaf = ptr2->leaf = false;
    }

    if (ptr == this->root)
    {
        p->firstitem = mid;
        p->first = ptr1;
        p->second = ptr2;
        p->leaf = false;
        this->root = p;
    }
    else if (p->full)
    {
        if (ptr == p->first)
        {
            split(p, mid, ptr1, ptr2, p->second, p->third);
        }
        else if (ptr == p->second)
        {
            split(p, mid, p->first, ptr1, ptr2, p->third);
        }
        else
        {
            split(p, mid, p->first, p->second, ptr1, ptr2);
        }
    }
    else
    {

        if (mid < p->firstitem )
        {
            p->seconditem = p->firstitem;
            p->firstitem = mid;

            p->third = p->second;
            p->second = ptr2;
            p->first = ptr1;
        }
        else
        {
            p->seconditem = mid;

            p->second = ptr1;
            p->third = ptr2;
        }
        p->full = true;
    }
    delete ptr;
}

void Dictionary23Tree::searchHelper(twothree* curr, const string & word, bool & val,int &count) const
{
    if (curr!=nullptr)
    {
        count++;
        if (curr->firstitem==word )
        {
            val = true;
            cout << "Word: " << word << ", is found. " << endl;
            cout << "Number of comparisons: " << count << endl;
            return;

        }
        else if( curr->seconditem == word)
        {
            val = true;
            count++;
            cout << "Word: " << word << ", is found. " << endl;
            cout << "Number of comparisons: " << count << endl;
            return;

        }
        else
        {

            if (word < curr->firstitem )
            {

                searchHelper(curr->first, word, val,count);
            }
            else if (word < curr->seconditem)
            {

                count++;
                searchHelper(curr->second, word, val,count);
            }
            else if (curr->seconditem == "")
            {

                searchHelper(curr->second, word, val,count);
            }
            else
            {
                count++;
                searchHelper(curr->third, word, val,count);

            }
        }
    }
}

//Searches the given word in the dictionary, and returns the number
//of comparisons made and whether the word is found or not
void Dictionary23Tree::search( string word, int& numComparisons, bool& found ) const
{
    found = false;
    numComparisons = 0;
    searchHelper(root, word, found,numComparisons);

}

//search
void Dictionary23Tree::search(string queryFile, string outputFile) const
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
            searchHelperQuery(root,line,found,number);
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

void Dictionary23Tree::searchHelperQuery(twothree* curr, const string &word, bool &val,int &count) const
{
    if (curr!=nullptr)
    {
        count++;
        if (curr->firstitem==word )
        {
            val = true;
            return;

        }
        else if( curr->seconditem == word)
        {
            val = true;
            count++;
            return;

        }
        else
        {

            if (word < curr->firstitem )
            {
                //count++;
                searchHelperQuery(curr->first, word, val,count);
            }
            else if (word < curr->seconditem)
            {

                count++;
                searchHelperQuery(curr->second, word, val,count);
            }
            else if (curr->seconditem == "")
            {
                //count++;
                searchHelperQuery(curr->second, word, val,count);
            }
            else
            {
                count++;
                searchHelperQuery(curr->third, word, val,count);

            }
        }
    }
    else
    {
        val = false;
    }
}

//formatting vector
template<typename T> void printElement(T t, const int& width)
{
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

