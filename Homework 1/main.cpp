
/*
* Title: Sorting and Algorithm Efficiency
* Author: Emre Karatas
* ID: 22001641
* Section: 1
* Assignment: 1
* Description: description of your code
*/
#include <iostream>
#include "sorting.h"
using namespace std;

int main()
{
    sorting S;
    //----------------------------------------------
    int fixedArray1[] = {40,25,29,56,37,27,24,32,79,12,35,38,23,31,33,26};
    int compCount = 0;
    int moveCount = 0;
    cout << "Array given in the lab instruction: " << endl;
    displayArray(fixedArray1,16);
    cout << "---- BUBBLE SORT ----" << endl;
    S.bubbleSort(fixedArray1,16,compCount,moveCount);
    cout << "Number of comparison: " << compCount << endl;
    cout << "Number of moves: " << moveCount << endl;
    displayArray(fixedArray1,16);

    int fixedArray2[] = {40,25,29,56,37,27,24,32,79,12,35,38,23,31,33,26};
    compCount = 0;
    moveCount = 0;
    cout << "---- MERGE SORT ----" << endl;
    S.mergeSort(fixedArray2,16,compCount,moveCount);
    cout << "Number of comparison: " << compCount << endl;
    cout << "Number of moves: " << moveCount << endl;
    displayArray(fixedArray2,16);

    int fixedArray3[] = {40,25,29,56,37,27,24,32,79,12,35,38,23,31,33,26};
    compCount = 0;
    moveCount = 0;
    cout << "---- QUICK SORT ----" << endl;
    S.quickSort(fixedArray3,16,compCount,moveCount);
    cout << "Number of comparison: " << compCount << endl;
    cout << "Number of moves: " << moveCount << endl;
    displayArray(fixedArray3,16);
    cout << endl << endl << endl << endl;
    S.performanceAnalysis();


}
