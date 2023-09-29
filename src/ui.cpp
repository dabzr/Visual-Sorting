#include <raylib.h>
#include <unistd.h>
#include <array>
#include "../include/sort.hpp"

void createRandomArray(int * array, size_t size) {
  for (int i = 0; i<size; i++)
    array[i] = GetRandomValue(1, 500);
}
 
void Graphics::appUI(int * array){
  ClearBackground(BLACK);
  BeginDrawing();
  usleep(4000);
  for (int i = 0; i < SIZE; i ++)
    DrawRectangle((30 + i * 10), 500 + (250 - array[i]), 10, array[i], RAYWHITE);
  EndDrawing();
} 

int Graphics::userInput() {
  if (IsKeyDown(KEY_RIGHT)) {
    usleep(150000);
    atual<2?atual++:atual=0;
  }
  if (IsKeyDown(KEY_LEFT)) {
    usleep(150000);
    atual>0?atual--:atual=2;
  }
  if (IsKeyDown(KEY_ENTER)) return atual;

  BeginDrawing();
  ClearBackground(BLACK);
  for (int i = 0; i < 3; i++) 
    atual==i?DrawText(algoTitle[i], 100 + 300 * i, 500, 30, RAYWHITE):DrawText(algoTitle[i], 100 + 300 * i, 500, 30, GRAY);
  EndDrawing();
  return -1;
}

void WindowManagment::windowLoop() {
  SetRandomSeed(time(nullptr));
  createRandomArray(array, SIZE);
  InitWindow(1000, 1000, "Sorting");
  while(!WindowShouldClose()) {
    if (IsKeyDown(KEY_ESCAPE)) WindowShouldClose();
    if (!input) input = userInput() + 1;
    else {
      appUI(array);
      switch(input) {
        case 1:
          selectionSort(array, SIZE);
        case 2: 
          bubbleSort(array, SIZE);
        case 3:
          insertionSort(array, SIZE);
      }
      if (IsKeyDown(KEY_R)) {
        createRandomArray(array, SIZE);
        input = 0;
      }
    }
  }
  CloseWindow();
}

void startGame() {
  WindowManagment window;
  window.windowLoop();
}
