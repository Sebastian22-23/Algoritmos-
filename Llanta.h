#pragma once
#include"iostream"
using namespace std;
using namespace System;
class llanta {
private:
	int x;
	int y;
public:
	llanta(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~llanta() {};
	void dibujar_llanta() {
		Console::SetCursorPosition(x, y); cout << " -----O--------O--/ ";
	}
	void setX(int valor) {
		x = valor;
	}
};
