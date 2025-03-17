#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

// Проверка, что строка содержит только цифры
bool isValidNumber(const string& str) {
  for (char c : str) {
    if (!isdigit(c)) {
      return false; // Если хотя бы один символ не цифра, возвращаем false
    }
  }
  return true;
}

// Функция для деления большого числа, представленного строкой, на число base
pair<string, int> divideStringByBase(const string& number, int base) {
  string quotient = ""; // Результат деления
  int remainder = 0;    // Остаток от деления

  for (char digit : number) {
    int current = remainder * 10 + (digit - '0'); // Текущее число
    quotient += (current / base) + '0';          // Целая часть
    remainder = current % base;                 // Остаток
  }

  // Убираем ведущие нули из результата деления
  size_t nonZeroPos = quotient.find_first_not_of('0');
  if (nonZeroPos == string::npos) {
    quotient = "0"; // Если всё число было равно нулю
  } else {
    quotient = quotient.substr(nonZeroPos);
  }

  return {quotient, remainder};
}

// Функция перевода числа из 10-ичной системы в 16-ричную
string decimalToHex(const string& decimalNumber) {
  string hexResult = "";
  string number = decimalNumber;
  const string hexChars = "0123456789ABCDEF";

  // Пока число не станет равно нулю
  while (number != "0") {
    auto [quotient, remainder] = divideStringByBase(number, 16); // Делим число на 16
    hexResult += hexChars[remainder]; // Добавляем остаток в результат
    number = quotient; // Обновляем число
  }

  reverse(hexResult.begin(), hexResult.end()); // Разворачиваем результат
  return hexResult;
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  setlocale(LC_ALL, "ru_RU.UTF-8");
  string bigNumber;

  cout << "Введите десятичное число: ";
  cin >> bigNumber;

  // Проверка на корректность ввода
  if (!isValidNumber(bigNumber)) {
    cout << "Ошибка: введённая строка содержит недопустимые символы! Допустимы только цифры." << endl;
    return 1; // Завершаем выполнение программы с ошибкой
  }

  string hexNumber = decimalToHex(bigNumber); // Переводим в 16-ричную систему
  cout << "16-ричное представление числа " << bigNumber << ": " << hexNumber << endl;

  return 0;
}