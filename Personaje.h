#pragma once
#include"Objetos.h"
#include"iostream"
#include"conio.h"
using namespace std;
using namespace System;
class persona1 {
private:
	int px, py;
	float dx;
	float dy;
	int vidas;
	int basurita;
public:
	persona1(int px, int py, float dx) {
		this->px = px;
		this->py = py;
		this->dx = 4;
		this->dy = 2;
		this->vidas = 8;
		this->basurita = 10;
	}
	~persona1() {};
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
				if (px < 10) px = 10;
			}
			else if (tecla == 77) {
				px += dx;
				if (px > 103) px = 103;
			}

			dibujar();
		}
	}
	void mover2() {
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

			dibujar2();
		}
	}
	void dibujar() {
		Console::SetCursorPosition(px, py);     cout << "  O";
		Console::SetCursorPosition(px, py + 1); cout << "__|__";
		Console::SetCursorPosition(px, py + 2); cout << "\\___/";
	}
	void dibujar2() {
		Console::SetCursorPosition(px, py);     cout << "  O";
		Console::SetCursorPosition(px, py + 1); cout << " /|\\";
		Console::SetCursorPosition(px, py + 2); cout << " / \\";
	}
	void mover3() {
		if (_kbhit()) {
			char tecla = _getch();

			borrar();

			if (tecla == 75) {
				px -= dx;
				if (px < 2) px = 2;
			}
			else if (tecla == 77) {
				px += dx;
				if (px > 105) px = 105;
			}
			else if (tecla == 72)
			{
				py -= dy;
				if (py < 4) py = 4;
			}
			else if (tecla == 80)
			{
				py += dy;
				if (py > 29) py = 29;
			}

			dibujar2();
		}
	}
	void imprimir_vidas() {
		Console::SetCursorPosition(100, 1);     cout << "Vidas: ";
		for (int i = 0; i < vidas; i++)
		{
			cout << char(3);
		}
	}

	void actualizar_vidas() {
		Console::SetCursorPosition(100, 1);     cout << "               ";

	}
	int get_vidas() {
		return vidas;
	}

	void set_vidas(int x) {
		this->vidas = x;
	}
	int getX() {
		return px;
	}
	int getY() {
		return py;
	}


};