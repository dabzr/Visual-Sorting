#include <raylib.h>
#include <unistd.h>
#include "../include/sort.hpp"

void createRandomArray(std::vector<int>& array, const size_t size) {
  array.resize(size);
  for (int i = 0; i<size; i++)
    array[i] = GetRandomValue(1, 500);
}
 
void Graphics::appUI(std::vector<int>& array, const size_t size){
  ClearBackground(BLACK);
  BeginDrawing();
  for (int i = 0; i < size; i ++)
    DrawRectangle((30 + i * 10), 500 + (250 - array[i]), 10, array[i], RAYWHITE);
  EndDrawing();
} 

int Graphics::userInput() {
  if (IsKeyPressed(KEY_RIGHT)) atual<2?atual++:atual=0;
  if (IsKeyPressed(KEY_LEFT)) atual>0?atual--:atual=2;
  if (IsKeyPressed(KEY_ENTER)) return atual;

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
  SetTargetFPS(250);
  while(!WindowShouldClose()) {
    if (IsKeyPressed(KEY_ESCAPE)) WindowShouldClose();
    if (!input) input = userInput() + 1;
    else {
      appUI(array, SIZE);
      switch (input) {
        case 1:
          selectionSort(array, SIZE);
          break;
        case 2: 
          bubbleSort(array, SIZE);
          break;
        case 3:
          insertionSort(array, SIZE);
          break;
      }
      if (IsKeyPressed(KEY_R)) {
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
