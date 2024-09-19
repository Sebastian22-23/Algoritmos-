#pragma once
#include <windows.h>
#include <iostream>
using namespace System;
class macetero {
private:
	int posx[10];
	int posy[10];
	int contador;
public:
	macetero() : contador(0) {
		srand(time(0));
	};
	~macetero() {};
	void gotoxy(int x, int y, const string& texto) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos;
		pos.X = x;
		pos.Y = y;
		SetConsoleCursorPosition(hConsole, pos);
		cout << texto;
	}
    void generar() {
        while (contador < 10) {
            int x = rand() % 98 + 5; // Genera una posición x
            int y = rand() % 24 + 5; // Genera una posición y

            // Verifica si la posición ya ha sido utilizada
            bool ocupada = false;
            for (int i = 0; i < contador; ++i) {
                if (posx[i] == x && posy[i] == y) {
                    ocupada = true;
                    break;
                }
            }

            // Si la posición no está ocupada, la añade y dibuja
            if (!ocupada) {
                posx[contador] = x;
                posy[contador] = y;
                gotoxy(x, y, "/-----\\");
                contador++;
            }
        }
    }
    //int X() { return x; }
    //int Y() { return y; }
};
