/**
* Title : Binary Search Trees
* Author : Emre Karatas
* ID: 22001641
* Section : 1
* Assignment : 2
* Description : description of your code
*/

#include "BST.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
using namespace std;


// random array creator (global func)
void createRandomArray(int *&arr,const int size)
{
    int randomNumber = 0;
    for(int i = 0; i < size; i++)
    {
        randomNumber = rand()%30000;
        arr[i] = randomNumber;

    }
}

// for shuffling the array (global func)
void shuffleArray(int *&arr,const int size)
{
    for(int i = 0; i < size; i++)
    {
        int randomIndex = i + (rand() % (size-i));
        int temp = arr[i];
        arr[i] = arr[randomIndex];
        arr[randomIndex] = temp;
    }
}

// for printing
template<typename T> void printElement(T t, const int& width)
{
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

// analysis code
void heightAnalysis()
{
    BST analyseBST;
    int *arr = new int[30000];
    createRandomArray(arr,30000);
    // part 1
    printElement("Analysis of BST Height - Part 1",30);
    cout << endl;
    printElement("-----------------------------------",40);
    cout << endl;
    printElement("Tree Size",15);
    printElement("Tree Height",15);
    cout << endl;
    printElement("-----------------------------------",40);
    cout << endl;
    for (int i = 0; i <= 30000; i++)
    {
        if( i % 1500 == 0)
        {
            printElement(i,15);
            printElement(analyseBST.getHeight(),15);
            cout << endl;
        }
        analyseBST.insert(arr[i]);
    }
    shuffleArray(arr,30000);
    cout << endl;
    cout << "Array is shuffled..." << endl << endl;
    //part 2
    printElement("Analysis of BST Height - Part 2",30);
    cout << endl;
    printElement("-----------------------------------",40);
    cout << endl;
    printElement("Tree Size",15);
    printElement("Tree Height",15);
    cout << endl;
    printElement("-----------------------------------",40);
    cout << endl;
    for (int i = 30000; i >= 0 ; i--)
    {
        analyseBST.deleteKey(arr[i]);
        if( i % 1500 == 0 && i != 30000)
        {
            printElement(i,15);
            printElement(analyseBST.getHeight(),15);
            cout << endl;
        }
    }

    delete[] arr;

}




