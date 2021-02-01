class Sorting {
 public:
  long compCount; //Used for tracking number of comparisons
  void SelectionSort(int values[], int numVals);
  int MinIndex(int values[], int start, int end);
  void MergeSort(int values[], int first, int last);
  void Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast);
  void HeapSort(int values[], int numVals);
  void ReheapDown(int values[], int root, int bottom);
  void QuickSortFP(int values[], int first, int last);
  int firstSplit(int values[], int low, int high);
  void QuickSortRP(int values[], int first, int last);
  int randSplit(int values[], int low, int hight);
};
