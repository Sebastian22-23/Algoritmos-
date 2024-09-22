#pragma once
#include "iostream"
#include "Personaje.h"
#include "conio.h"

using namespace System;
using namespace std;
class Maceta
{
private:
	persona1* objPlayerr;
	int x, y;
	bool detectado;
public:
	Maceta(int px, int py, persona1* objPlayer);
	~Maceta();
	void funciones();
};

Maceta::Maceta(int px, int py, persona1* objPlayer)
{
	this->x = px;
	this->y = py;
	this->detectado = false;
	this->objPlayerr = objPlayer;
}

Maceta::~Maceta()
{
}

void Maceta::funciones() {
	if (objPlayerr->getX() == x && objPlayerr->getY() == y)
		detectado = true;
	if (objPlayerr->getX() == x && objPlayerr->getY() == y - 1)
		detectado = true;
	if (objPlayerr->getX() == x && objPlayerr->getY() == y + 1)
		detectado = true;
	if (objPlayerr->getX() == x && objPlayerr->getY() == y - 2)
		detectado = true;
	if (!detectado) {
		Console::SetCursorPosition(x, y);
		cout << char(219) << char(220) << char(219);
	}
	else {
		Console::SetCursorPosition(x + 1, y);
		cout << char(219);
		Console::SetCursorPosition(x + 1, y - 1);
		cout << char(219);
	}

}