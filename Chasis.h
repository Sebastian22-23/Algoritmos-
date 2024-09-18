#pragma once
#include"iostream"
#include "windows.h"
using namespace System;
using namespace std;

class chasis {
private:
    int color;
    int x;
    int y;
    int dx;
public:
    chasis(int x, int y) {
        this->x = x;
        this->y = y;

        setColor();
    };
    ~chasis() {};

    void setColor() {
        color = (rand() % 15) + 1;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
	void dibujar() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		Console::SetCursorPosition(x, y);     cout << "  _____________ ";
		Console::SetCursorPosition(x, y + 1); cout << " |             \\ ";
		Console::SetCursorPosition(x, y + 2); cout << " |----------------- ";
		Console::SetCursorPosition(x, y + 3); cout << " |                 | ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	}
	void setX(int valor) {
		x = valor;
	}
};
