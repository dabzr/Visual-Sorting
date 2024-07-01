#include <iostream>
#include <string>
#include <vector>

#define SIZE 90

void startGame();

void selectionSort(std::vector<int>& array);

void bubbleSort(std::vector<int>& array);

void insertionSort(std::vector<int>& array);

std::vector<int> createRandomArray(const size_t size);

class Graphics{
public:
  Graphics();
  Graphics(std::vector<std::string> algoTitle);
  std::vector<std::string> algoTitle;
  int currentSelected = 0;
  void Draw(std::vector<int> array); 
  void DrawOptions();
  int userInput();
private:

};

class WindowManagment {
public:
  WindowManagment();
  Graphics app;
  std::vector<int> array;
  int input = 0;
  void Tick();
};


