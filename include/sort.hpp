#include <iostream>
#include <vector>

#define SIZE 90

void startGame();

void selectionSort(std::vector<int>& array, const size_t size);

void bubbleSort(std::vector<int>& array, size_t size);

void insertionSort(std::vector<int>& array, const size_t size);

void createRandomArray(std::vector<int>& array, const size_t size);

class Graphics{
public:
  char algoTitle[3][20] = {"Selection Sort", "Bubble Sort", "Insertion Sort"};
  int atual = 0;
  void appUI(std::vector<int>& array, const size_t size); 
  int userInput();
};

class WindowManagment : public Graphics{
public:
  std::vector<int> array;
  int input = 0;
  void windowLoop();
};


