#include "../include/sort.hpp"

void selectionSort(std::vector <int>& array){
  const size_t size = array.size();
  Graphics app;
  for (int i = 0; i < size; i++) {
    for (int j = (i+1); j < size; j++) {
      if (array[i] > array[j]) {
        std::swap(array[i], array[j]);
        app.Draw(array);
      }
    }
  }
}


void bubbleSort(std::vector<int>& array){
  Graphics app;
  const size_t initialSize = array.size();
  size_t size = array.size();
  while(size) {
    size--;
    for(int i = 0; i < size; i++) {
      if (array[i] > array[i+1]) {
        std::swap(array[i], array[i+1]);
        app.Draw(array);
      }
    }
  }
}


void insertionSort(std::vector<int>& array) {
  const size_t size = array.size();
  Graphics app;
  int j, key;
  for (int i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      app.Draw(array);
      j--;
    }
    array[j + 1] = key;
  }
}
