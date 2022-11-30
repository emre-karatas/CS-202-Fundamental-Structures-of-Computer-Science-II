/*
* Title: Sorting and Algorithm Efficiency
* Author: Emre Karatas
* ID: 22001641
* Section: 1
* Assignment: 1
* Description: description of your code
*/

#include <iostream>
#pragma once


using namespace std;
#ifndef DISPLAYARRAY
#define DISPLAYARRAY
void displayArray(const int* array,const int size);
#endif
#ifndef CREATERANDOMARRAYS
#define CREATERANDOMARRAYS
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3,const int size);
#endif
#ifndef CREATEASCENDINGARRAYS
#define CREATEASCENDINGARRAYS
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3,const int size);
#endif
#ifndef CREATEDESCENDINGARRAYS
#define CREATEDESCENDINGARRAYS
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3,const int size);
class sorting
{
public:
    void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
    void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
    void quickSort(int *arr, const int size, int &compCount, int &moveCount);
    void merge(int *arr,int first,int mid,int last,int &compCount, int& moveCount);
    void partition(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
    void swap(int &arr1Element, int &arr2Element);
    void performanceAnalysis();

private:

#endif

};
