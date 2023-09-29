#include "../include/sort.hpp"

void selectionSort(int * array, size_t size){
  Graphics app;
  for (int i = 0; i < size; i++) {
    for (int j = (i+1); j < size; j++) {
      if (array[i] > array[j]) {
        array[i]= array[i] ^ array[j];
        array[j] = array[i] ^ array[j];
        array[i] = array[i] ^ array[j];
        app.appUI(array);
      }
    }
  }
}


void bubbleSort(int *array, size_t size){
  Graphics app;
  while(size) {
    size--;
    for(int i = 0; i < size; i++) {
      if (array[i] > array[i+1]) {
        array[i] = array[i] ^ array[i+1];
        array[i+1] = array[i] ^ array[i+1];
        array[i] = array[i] ^ array[i+1];
        app.appUI(array);
      }
    }
  }
}


void insertionSort(int * array, int size) {
  Graphics app;
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      app.appUI(array);
      --j;
    }
    array[j + 1] = key;
  }
}
