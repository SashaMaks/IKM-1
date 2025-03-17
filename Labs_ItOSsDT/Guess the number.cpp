#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

int Rand(int min, int max) {
  return min + rand()%(max-min+1);
}

int Inp() {
  int a, b;
  std::cin >> a;
  std::cin >> b;
  if (a < b) {
    return Rand(a, b);
  }
  else {
    return Rand(b, a);
  }
}

int Guessing (int num) {
  int guess;

  std::cin >> guess;
  if (guess == num) {
    std::cout << "Правильно!";
    return 0;
  } else if (guess < num) {
    std::cout << "Число меньше загаданого";
    Guessing(num);
  } else if (guess > num) {
    std::cout << "Число больше загаданого";
    Guessing(num);
  }
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  srand(time(0));
  int num;

  num = Inp();
  Guessing(num);
}