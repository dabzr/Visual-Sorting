#include "../include/sort.hpp"
#include <raylib.h>
#include <unistd.h>
#include <array>

#define SIZE 90

void createRandomArray(int * array, size_t size){
  for (int i = 0; i<size; i++){
    array[i] = GetRandomValue(1, 500);
  }
}
 
void Graphics::appUI(int * array){
  ClearBackground(BLACK);
  BeginDrawing();
  usleep(4000);
  for (int i = 0; i < SIZE; i ++){
    DrawRectangle((30 + i * 10), 500 + (250 - array[i]), 10, array[i], RAYWHITE);
  }
  EndDrawing();
} 
int Graphics::UserInput(int *atual){
  if(IsKeyDown(KEY_RIGHT)){
    usleep(120000);
    *atual<2?*atual+=1:*atual=0;
  }
  if(IsKeyDown(KEY_LEFT)){
    usleep(120000);
    *atual>0?*atual-=1:*atual=2;
  }
  std::array<char[20], 3> algo = {"Selection Sort", "Bubble Sort", "Insertion Sort"};
  BeginDrawing();
  ClearBackground(BLACK);
  for (int i = 0; i < 3; i++){
    *atual==i?DrawText(algo[i], 100 + 300 * i, 500, 30, RAYWHITE):DrawText(algo[i], 100 + 300 * i, 500, 30, GRAY);
  }
  EndDrawing();
  if(IsKeyDown(KEY_ENTER))
    return *atual;
  return -1;
}  

void WindowLoop::windowLoop(){
  SetRandomSeed(time(nullptr));
  int array[SIZE];
  createRandomArray(array, SIZE);
  int input = 0, atual = 0;
  InitWindow(1000, 1000, "Sorting");
  while(!WindowShouldClose()){
    if(IsKeyDown(KEY_ESCAPE)) WindowShouldClose();
    if (!input){
      input = UserInput(&atual) + 1;
    }
    else{
      appUI(array);
      switch(input){
        case 1:
          selectionSort(array, SIZE);
          break;
        case 2: 
          bubbleSort(array, SIZE);
        case 3:
          insertionSort(array, SIZE);
      }
      if (IsKeyDown(KEY_R)){
        createRandomArray(array, SIZE);
        input = 0;
      }
    }
  }
  CloseWindow();
}

void startGame(){
  WindowLoop window;
  window.windowLoop();
}
