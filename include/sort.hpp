#include <iostream>

void selectionSort(int * array, size_t size);

void bubbleSort(int *array, size_t size);

void insertionSort(int * array, int size);

void createRandomArray(int * array, size_t size);

class Graphics{
public: 
  void appUI(int * array); 
  int UserInput(int * atual);  
};

class WindowLoop : public Graphics{
public:
  void windowLoop();
};


