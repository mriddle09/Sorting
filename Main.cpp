#include "Sorting.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Invalid command line argument" << endl;
    return 0; 
  } //Validating command line arguments

  Sorting sort; 
  ifstream file;
  file.open(argv[1]); //opening file

  int sortMe[10000];
  int a;
  int count = 0; 

  while (file >> a) {
    sortMe[count] = a;
    count++; 
  } //populating array with file data

  cout << "selection-sort (s)  merge-sort(m)  heap-sort (h)  quick-sort-fp (q)  quick-sort-rp (r)" << endl;

  char input;

  cout << "Enter the alogrithm: ";
  cin >> input;
  switch (input) {
  case 's' : { //selection sort call
    sort.SelectionSort(sortMe, 10000);
    cout << endl;
    cout << "Number of comparisons: " << sort.compCount << endl;
    break;
  }
  case 'm' : { //merge sort call
    sort.MergeSort(sortMe, 0, 9999);
    for (int i = 0; i < 10000; i++) {
      cout << sortMe[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << sort.compCount << endl;
    break;
  }
  case 'h' : { //heap sort call
    sort.HeapSort(sortMe, 10000);
    cout << endl;
    cout << "Number of comparisons: " << sort.compCount << endl;
    break;
  }
  case 'q' : { //quicksort fp call
    sort.QuickSortFP(sortMe, 0, 9999);
    for (int i = 0; i < 10000; i++) {
      cout << sortMe[i] << " "; 
    }
    cout << endl;
    cout << "Number of comparisons: " << sort.compCount << endl;
    break;
  }
  case 'r' : { //quicksort rp call
    sort.QuickSortRP(sortMe, 0, 9999);
    for (int i = 0; i < 10000; i++) {
      cout << sortMe[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << sort.compCount << endl;
    break;
  }
  }
}
