#include <raylib.h>
#include "../include/sort.hpp"
#include <unistd.h>
std::vector<int> createRandomArray(const size_t size) {
  std::vector<int> array;
  for (int i = 0; i<size; i++) array.push_back(GetRandomValue(1, 500));
  return array;
}
Graphics::Graphics(std::vector<std::string> algoTitle) : algoTitle(algoTitle) {}
Graphics::Graphics(): Graphics(std::vector<std::string>()){} 
void Graphics::Draw(std::vector<int> array){
  ClearBackground(BLACK);
  BeginDrawing();
  int i = 0;
  for (int item : array) DrawRectangle((30 + i++ * 10), 500 + (250 - item), 10, item, RAYWHITE);
  EndDrawing();
} 

int Graphics::userInput() {
  if (IsKeyPressed(KEY_RIGHT)) currentSelected < algoTitle.size()-1 ? currentSelected++ : currentSelected = 0;
  if (IsKeyPressed(KEY_LEFT)) currentSelected > 0 ? currentSelected-- : currentSelected = algoTitle.size()-1;
  if (IsKeyPressed(KEY_ENTER)) return currentSelected;
  return -1;
}
void Graphics::DrawOptions() {
  BeginDrawing();
  ClearBackground(BLACK);
  for (int i = 0; i < algoTitle.size(); i++) 
    currentSelected==i ? DrawText(algoTitle[i].c_str(), 100 + 300 * i, 500, 30, RAYWHITE) : DrawText(algoTitle[i].c_str(), 100 + 300 * i, 500, 30, GRAY);
  EndDrawing();
}
WindowManagment::WindowManagment() {
  SetRandomSeed(time(nullptr));
  array = createRandomArray(SIZE);
  app = Graphics({"Selection Sort", "Bubble Sort", "Insertion Sort"});
  InitWindow(1000, 1000, "Sorting");
  SetTargetFPS(250);
  SetExitKey(KEY_Q);
}
void WindowManagment::Tick() {
  void (*sort[])(std::vector <int>& array) = {selectionSort, bubbleSort, insertionSort};
  while (!WindowShouldClose()) {
    if (!input){
      input = app.userInput() + 1;
      app.DrawOptions();
      continue;
    }
    app.Draw(array);
    (*sort[input-1])(array);
    if (IsKeyPressed(KEY_ESCAPE)) {
      array = createRandomArray(SIZE);
      input = 0;
    }
  }
  CloseWindow();
}

void startGame() {
  WindowManagment window;
  window.Tick();
}
