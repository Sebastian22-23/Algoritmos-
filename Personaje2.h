#pragma once
#pragma once
#include <conio.h>
#include <iostream>

using namespace std;
using namespace System;
class persona2 {
private:
	int px, py;
	float dx;
	int vidas;
	int basurita;
	int n = 1;
	int na = 1;
public:
	persona2(int px, int py, float dx) {
		this->px = px;
		this->py = py;
		this->dx = 4;
		this->vidas = 8;
		this->basurita = 10;
	}
	~persona2() {};
	void borrar() {
		Console::SetCursorPosition(px, py);     cout << "      ";
		Console::SetCursorPosition(px, py + 1); cout << "      ";
		Console::SetCursorPosition(px, py + 2); cout << "      ";
	}
	void mover() {
		if (_kbhit()) {
			char tecla = _getch();

			borrar();

			if (tecla == 75) {
				px -= dx;
				if (px < 8) px = 8;
			}
			else if (tecla == 77) {
				px += dx;
				if (px > 105) px = 105;
			}

			dibujar();
		}
	}
	void dibujar() {
		Console::SetCursorPosition(px, py);     cout << "  O";
		Console::SetCursorPosition(px, py + 1); cout << " /|\\";
		Console::SetCursorPosition(px, py + 2); cout << " / \\";
	}
	void imprimir_vidas2() {
		Console::SetCursorPosition(100, 1);     cout << "Vidas: ";
		for (int i = 0; i < vidas; i++)
		{
			cout << char(3);
		}
	}
	void imprimir_semillas() {
		Console::SetCursorPosition(1, 1); cout << "Semillas RECOGIDA: " << n++;
	}
	void actualizar_vidas2() {
		Console::SetCursorPosition(100, 1);     cout << "               ";

	}
	int get_vidas2() {
		return vidas;
	}

	void set_vidas2(int x) {
		this->vidas = x;
	}
	int X2() {
		return px;
	}
	int Y2() {
		return py;
	}
};