#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h>

const int size = 4;
std::vector<std::vector<int>> board(size, std::vector<int>(size));
int ZeroX, ZeroY;

void shuffle() {
  std::vector<int> numbers;
  for (int i = 0; i < size * size; i++) numbers.push_back(i);
  random_shuffle(numbers.begin(), numbers.end());

  int k = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = numbers[k++];
      if (board[i][j] == 0) {
        ZeroX = i;
        ZeroY = j;
      }
    }
  }
}

void printBoard() {
  std::cout << "\n";
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (board[i][j] == 0) {
        std::cout << "\t";
      }
      else {
        std::cout << board[i][j] << "\t";
      }
    }
    std::cout << "\n";
  }
}

// Функция проверки победы
bool isWin() {
  int k = 1;

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i == size - 1 && j == size - 1) {
        return board[i][j] == 0;
      }
      if (board[i][j] != ++k) {
        return false;
      }
    }
  }
  return true;
}

void move(int x, int y) {
  int X = ZeroX + x;
  int Y = ZeroY + y;

  if (X >= 0 && X < size && Y >= 0 && Y < size) {
    std::swap(board[ZeroX][ZeroY], board[X][Y]);

    ZeroX = X;
    ZeroY = Y;
  }
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  srand(time(0));
  shuffle();

  while (true) {
    printBoard();
    if (isWin()) {
      std::cout << "Поздравляю! Вы выиграли!\n";
      break;
    }

    std::cout << "Введите ход (wasd): ";
    char Key;
    std::cin >> Key;

    switch (Key) {
      case 'w': move(1, 0); break;
      case 'a': move(0, 1); break;
      case 's': move(-1, 0); break;
      case 'd': move(0, -1); break;

    }
  }
}