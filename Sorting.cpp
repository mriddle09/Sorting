#include "Sorting.h"
#include <iostream>

using namespace std;

void Sorting::SelectionSort(int values[], int numVals) { //Performs selection sort on provided array values
  int endIndex = numVals - 1;
  for (int current = 0; current < endIndex; current++) {
    swap(values[current], values[MinIndex(values, current, endIndex)]); 
  }
  for (int i = 0; i < numVals; i++) {
    cout << values[i] << " "; 
  }
}

int Sorting::MinIndex(int values[], int start, int end) { //utility for selection sort that finds lowest value index in array
  int indexOfMin = start;
  for (int index = start + 1; index <= end; index++) {
    compCount++; 
    if (values[index] < values[indexOfMin])
      indexOfMin = index;
  }
  return indexOfMin; 
}

void Sorting::MergeSort(int values[], int first, int last) { //Recursive merge sort
  if (first < last) {
    int middle = (first + last) / 2;
    MergeSort(values, first, middle);
    MergeSort(values, middle + 1, last);
    Merge(values, first, middle, middle + 1, last);
  }
}

void Sorting::Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast) { //utility function for merge sort that remerges arrays after they have been split
  int tempArr[10000];
  int index = leftFirst;
  int saveFirst = leftFirst;

  while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
    compCount++; 
    if (values[leftFirst] < values[rightFirst]) {
      tempArr[index] = values[leftFirst];
      leftFirst++;
    } else {
      tempArr[index] = values[rightFirst];
      rightFirst++;
    }
    index++;
  }
  while (leftFirst <= leftLast) {
    tempArr[index] = values[leftFirst];
    leftFirst++;
    index++;
  }
  while (rightFirst <= rightLast) {
    tempArr[index] = values[rightFirst];
    rightFirst++;
    index++;
  }
  for (index = saveFirst; index <= rightLast; index++) {
    values[index] = tempArr[index];
  }
}

void Sorting::HeapSort(int values[], int numVals) { //heap sort
  int index;
  for (index = numVals/2 -1; index >= 0; index--) {
    ReheapDown(values, index, numVals - 1);
  }
  for (index = numVals - 1; index >= 1; index--) {
    swap(values[0], values[index]);
    ReheapDown(values, 0, index - 1);
  }
  for (int i = 0; i < 10000; i++) {
    cout << values[i] << " "; 
  }
}

void Sorting::ReheapDown(int values[], int root, int bottom) { //Util function for heap sort
  int maxChild;
  int rightChild;
  int leftChild;
  compCount++;
  
  leftChild = root * 2 + 1;
  rightChild = root * 2 + 2;

  if (leftChild <= bottom) {
    if (leftChild == bottom)
      maxChild = leftChild;
    else {
      if (values[leftChild] <= values[rightChild])
	maxChild = rightChild;
      else
	maxChild = leftChild;
    }
    if (values[root] < values[maxChild])
      {
	swap (values[root], values[maxChild]);
	ReheapDown(values, maxChild, bottom);
      }
  }
}

void Sorting::QuickSortFP(int values[], int first, int last) { //Quicksort using first index as pivot point
  if (first < last) {
    compCount++;
    int splitPoint = firstSplit(values, first, last);
    QuickSortFP(values, first, splitPoint - 1);
    QuickSortFP(values, splitPoint + 1, last);
  }
}

int Sorting::firstSplit(int values[], int low, int high) { //Quicksort utility method that partitions an array at the first index
  int pivot = values[low];
  int i = (low + 1);
  for (int j = low; j <= high; j++) {
    if (values[j] < pivot) {
      compCount++;
      swap(values[i], values[j]);
      i++;
    } else {
      compCount++;
    }
  }
  swap (values[i-1], values[low]);
  return i - 1; 
}

void Sorting::QuickSortRP(int values[], int first, int last) { //Quicksort using a randomly selected index as the pivot point
  if (first < last) {
    compCount++;
    int splitPoint = randSplit(values, first, last);
    QuickSortRP(values, first, splitPoint - 1);
    QuickSortRP(values, splitPoint + 1, last); 
  }
}

int Sorting::randSplit(int values[], int low, int high) { //Util for Quicksort rp 
  int random = low + rand()% (high - low + 1); //generates random int
  swap(values[random], values[low]);
  return firstSplit(values, low, high); //calls previous partition method with random swapped with low
}
