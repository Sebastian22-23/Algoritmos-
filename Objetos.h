#pragma once
#include"iostream"

using namespace std;
using namespace System;

class Basura {
protected:
	int x;
	int y;
	int dy;
public:
	Basura(int x, int y, int dy) {
		this->x = rand() % (75 - 20) + 12;
		this->y = y;
		this->dy = 1;
	};
	Basura(int x, int y) {
		this->x = rand() % (75 - 20) + 12;
		this->y = rand()% (29-5)+12;
	}
	~Basura() {};
	void borrar() {
		Console::SetCursorPosition(x, y); cout << " ";
	}
	void mover() {
		y += dy;
		if (y == 31) {
			x = rand() % (75 - 20) + 12;
			y = 12;
		}
		dibujar();
	}
	void dibujar() {
		Console::SetCursorPosition(x, y); cout << char(64);
	}
	void setY(int y) { this->y = y; }
	void setX(int x) { this->x = x; }
	int getX() { return x; }
	int getY() { return y; }
};
class semilla_buena : public Basura {
private:
	int contador;
	int intervalo;
public:
	semilla_buena(int x, int y, int dy, int c1, int i1) :Basura(x, y, dy) {
		this->contador = c1;
		this->intervalo = i1;
	}
	~semilla_buena() {

	}
	void borrarsemilla_buena() {
		Console::SetCursorPosition(x, y); cout << " ";;
	}
	void moversemilla_buena() {
		contador++;
		if (contador >= intervalo) {
			y += dy;
			if (y == 33) {
				x = rand() % (75 - 20) + 12;
				y = 12;
			}
			dibujarsb();
			contador = 0;
		}
	}
	void dibujarsb() {
		Console::SetCursorPosition(x, y); cout << char(59);
	}
	int getX() { return x; }
	int getY() { return y; }
};
class semilla_mala : public Basura {
private:
	int contador;
	int intervalo;
public:
	semilla_mala(int x, int y, int dy, int c2, int i2) :Basura(x, y, dy) {
		this->contador = c2;
		this->intervalo = i2;
	}
	~semilla_mala() {

	}
	void borrarsemilla_mala() {
		Console::SetCursorPosition(x, y); cout << " ";;
	}
	void moversemilla_mala() {
		contador++;
		if (contador >= intervalo) {
			y += dy;
			if (y == 33) {
				x = rand() % (75 - 20) + 12;
				y = 12;
			}
			dibujarsm();
			contador = 0;
		}
	}
	void dibujarsm() {
		Console::SetCursorPosition(x, y); cout << char(45);
	}
	int getX() { return x; }
	int getY() { return y; }
};
class macetero: public Basura {
public:
	macetero(int x, int y) : Basura(x, y) {
	};
	~macetero();
	void dibujar_macetero() {
		Console::SetCursorPosition(x, y); cout << "\\__/";
	}
	void borrar_macetero() {
		Console::SetCursorPosition(x, y); cout << "     ";
	}
	void setY(int y) { this->y = y; }
	void setX(int x) { this->x = x; }
	int getX() { return x; }
	int getY() { return y; }
};