# С++ TString Class
Реализация пользовательского класса динамической строки на C++, использующая ручное управление памятью и поддерживающая перегрузку базовых операторов C++.  
Разработан в учебных целях для демонстрации работы с динамической памятью, конструкторами и деструкторами, правилом трех и перегрузкой операторов.  
Цель - понять устройство стандартного контейнера `string` и отработать навыки программирования.  
![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)  
![License](https://img.shields.io/badge/license-MIT-green.svg)  
[![CMake](https://img.shields.io/badge/Build-CMake-green.svg)](https://cmake.org/)  

---

## О программе
### Реализованный функционал:

- **Управление памятью** - динамическое выделение и освобождение памяти (конструктор по умолчанию, конструктор инициализации, конструктор копирования, деструктор).
- **Конкатенация строк** - перегружена операция + для объединения двух объектов класса TString.
- **Сравнение** - операции `==`, `<`, `>`.
- **Доступ к элементам** - перегруженный оператор `[]` с проверкой выхода за границы массива `char`.
- **Ввод и вывод** - перегруженные операторы потокового ввода `>>` и вывода `<<`.

### Заголовочный файл класса TString (TString.h)
```cpp
#include <iostream>

class TString {
	int size;
	char* str;
public:
	TString();
	TString(int n);
	TString(const char* ch);
	TString(const TString& s);
	~TString();

	TString& operator=(const TString& s);
	TString operator+(const TString& s);
	TString operator+(char c);
	bool operator==(const TString& s) const;
	bool operator>(const TString& s);
	bool operator<(const TString& s);
	char& operator[](int index);

	int getlen() const;
	friend std::ostream& operator<<(std::ostream& out, const TString& s);
	friend std::istream& operator>>(std::istream& is, TString& s);
};
```

---

## Сборка и запуск

**Windows (MSVC)**
```bash
cl /EHsc TString.cpp main.cpp /Fe:tstring.exe
tstring.exe
```

**Linux/maxOS**
```bash
g++ TString.cpp main.cpp -o tstring.exe
./tstring
```
### Visual Studio
1. Откройте файл решения .sln в Visual Studio
2. Нажмите `F5` для запуска с отладкой (`Ctrl+F5` без отладки)

*UPD. Сборка через CMake*  
В папке проекта, где лежит CMakeLists.txt:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```


---
