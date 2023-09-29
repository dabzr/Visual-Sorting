#include <iostream>
#define SIZE 90

void startGame();

void selectionSort(int * array, size_t size);

void bubbleSort(int *array, size_t size);

void insertionSort(int * array, int size);

void createRandomArray(int * array, size_t size);

class Graphics{
public:
  char algoTitle[3][20] = {"Selection Sort", "Bubble Sort", "Insertion Sort"};
  int atual = 0;
  void appUI(int * array); 
  int userInput();
};

class WindowManagment : public Graphics{
public:
  int array[SIZE];
  int input = 0;
  void windowLoop();
};


