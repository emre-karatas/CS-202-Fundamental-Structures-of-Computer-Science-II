
/*
* Title: Sorting and Algorithm Efficiency
* Author: Emre Karatas
* ID: 22001641
* Section: 1
* Assignment: 1
* Description: description of your code
*/

#include <iostream>
#include <chrono>
#include <iomanip>

#include "sorting.h"
using namespace std;

void sorting::swap(int &arr1Element, int &arr2Element)
{
    int temp = arr2Element;
    arr2Element = arr1Element;
    arr1Element = temp;

}
void sorting::bubbleSort(int * arr,const int size, int& compCount, int &moveCount)
{
    bool sorted = false;
    for (int pass = 1; (pass < size) && !sorted; ++pass)
    {
        sorted = true;
        for (int index = 0; index < size-pass; ++index)
        {
            int nextIndex = index + 1;
            if( *(arr+index) > *(arr+nextIndex) )
            {
                swap(arr[index],arr[nextIndex]);
                moveCount = moveCount + 3;
                sorted = false;
            }
            compCount++;
        }
        compCount++;
    }

}

void sorting::mergeSort(int* arr,const int size, int& compCount, int& moveCount)
{
    int firstIndex = 0;
    int lastIndex = size-1;

    if(firstIndex < lastIndex)
    {
        int midIndex = (firstIndex + lastIndex)/2;
        mergeSort((arr+firstIndex),midIndex+1,compCount,moveCount);
        moveCount += midIndex+1;
        mergeSort((arr+midIndex+1),lastIndex-midIndex,compCount,moveCount);
        moveCount += lastIndex-midIndex;
        merge(arr,firstIndex,midIndex,lastIndex,compCount,moveCount);


    }
}

void sorting::merge(int *arr, int first, int mid, int last,int& compCount,int& moveCount)
{
    int tempArray[last-first];

    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;
    int index = first1;

    for(;(first1 <= last1) && (first2 <= last2); ++index)
    {
        if(arr[first1]<arr[first2])
        {
            tempArray[index] = arr[first1];
            ++first1;
        }
        else
        {
            tempArray[index] = arr[first2];
            ++first2;
        }
        compCount++;
        moveCount++;
    }

    for (; first1 <= last1; ++first1, ++index)
    {
        tempArray[index] = arr[first1];
        moveCount++;
    }

   // finish off the second subarray, if necessary
   for (; first2 <= last2; ++first2, ++index)
   {
       tempArray[index] = arr[first2];
       moveCount++;
   }

   // copy the result back into the original array
   for (index = first; index <= last; ++index)
   {
       arr[index] = tempArray[index];
   }
}

void sorting::quickSort(int* arr,const int size, int& compCount, int& moveCount)
{
    int pivotIndex = 0;
    int first = 0;
    int last = size-1;

    if( first < last)
    {
        partition(arr,first,last,pivotIndex,compCount,moveCount);
        quickSort(arr,pivotIndex+1-first,compCount,moveCount);
        quickSort(arr+pivotIndex+1,last-pivotIndex,compCount,moveCount);
    }


}

void sorting::partition(int *arr,int first,int last,int &pivotIndex,int &compCount, int &moveCount)
{
    int pivot = arr[0];
    int lastS1 = first;
    int firstUnknown = first + 1;
    for ( ; firstUnknown <= last; ++firstUnknown)
    {
        if(arr[firstUnknown] < pivot)
        {
            ++lastS1;
            swap(arr[firstUnknown],arr[lastS1]);
            moveCount++;

        }
        compCount++;
    }
    moveCount++;
    swap(arr[0],arr[lastS1]);
    pivotIndex = lastS1;
}

void displayArray(const int* array,const int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3,const int size)
{
    int randomNumber = 0;
    for(int i = 0; i < size; i++)
    {
        randomNumber = rand()%100;
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
        arr3[i] = randomNumber;

    }
}
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3,const int size)
{
    int randomNumber = 0;
    for(int i = 0; i < size; i++)
    {
            randomNumber += rand()%10;
            arr1[i] = randomNumber;
            arr2[i] = randomNumber;
            arr3[i] = randomNumber;

    }

}
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3,const int size)
{
    int randomNumber = 1000000;
    for (int i = 0; i < size; i++)
    {
        randomNumber -= rand()%10;
        arr1[i] = randomNumber;
        arr2[i] = randomNumber;
        arr3[i] = randomNumber;
    }

}

template<typename T> void printElement(T t, const int& width)
{
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

void sorting::performanceAnalysis()
{
    int minVal = 4000;
    int gap = 4000;
    int maxVal = 48000;
    int compCount = 0;
    int moveCount = 0;
    int length = 20;
    int *arr1 = new int[maxVal];
    int *arr2 = new int[maxVal];
    int *arr3 = new int[maxVal];
    for (int i = minVal; i <= maxVal; i+=gap)
    {
        createRandomArrays(arr1,arr2,arr3,i);
    }
    printElement("RANDOM ARRAYS",30);
    cout << endl;
    printElement("-----ANALYSIS OF BUBBLE SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;

    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        bubbleSort(arr1,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    printElement("-----------------------------------",30);
    cout << endl;
    printElement("-----ANALYSIS OF MERGE SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl << endl;

    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        mergeSort(arr2,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    printElement("-----------------------------------",30);
    cout << endl;
    printElement("-----ANALYSIS OF QUICK SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl << endl;
    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        quickSort(arr3,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    delete [] arr1;
    delete [] arr2;
    delete [] arr3;


    int *arr4 = new int[maxVal];
    int *arr5 = new int[maxVal];
    int *arr6 = new int[maxVal];

    for (int i = minVal; i <= maxVal; i+=gap)
    {
        createAscendingArrays(arr4,arr5,arr6,i);
    }
    printElement("ASCENDING RANDOM ARRAYS",30);
    cout << endl;
    printElement("-----ANALYSIS OF BUBBLE SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;

    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        bubbleSort(arr4,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    printElement("-----------------------------------",30);
    cout << endl;
    printElement("-----ANALYSIS OF MERGE SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;

    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        mergeSort(arr5,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    printElement("-----------------------------------",30);
    cout << endl;
    printElement("-----ANALYSIS OF QUICK SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;
    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        quickSort(arr6,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;

    int *arr7 = new int[maxVal];
    int *arr8 = new int[maxVal];
    int *arr9 = new int[maxVal];

    compCount = 0;
    moveCount = 0;

    for (int i = minVal; i <= maxVal; i+=gap)
    {
        createDescendingArrays(arr7,arr8,arr9,i);
    }
    printElement("DESCENDING RANDOM ARRAYS",30);
    cout << endl;
    printElement("-----ANALYSIS OF BUBBLE SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;

    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        bubbleSort(arr7,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;

    }
    printElement("-----------------------------------",30);
    cout << endl;
    printElement("-----ANALYSIS OF MERGE SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;

    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        mergeSort(arr8,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }
    printElement("-----------------------------------",30);
    cout << endl;
    printElement("-----ANALYSIS OF QUICK SORT-----",30);
    cout << endl;
    printElement("Array Size",length);
    printElement("Time Elapsed",length);
    printElement("CompCount",length);
    printElement("MoveCount",length);
    cout << endl;
    for (int k = minVal; k <= maxVal; k+=gap)
    {
        compCount = 0;
        moveCount = 0;
        auto begin = chrono::steady_clock::now();
        quickSort(arr9,k,compCount,moveCount);
        auto end = chrono::steady_clock::now();
        printElement(k,length);
        printElement(chrono::duration_cast<chrono::milliseconds>(end - begin).count(),6);
        printElement("ms",14);
        printElement(compCount,length);
        printElement(moveCount,length);
        cout << endl;


    }




}
