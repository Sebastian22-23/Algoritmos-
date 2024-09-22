#pragma once
#include <iostream>

using namespace std;
using namespace System;

class monstruo {
private:
    int POSx[10];
    int POSy[10];
    int x;
    int y;
    int dx;
    int dy;
public:
    monstruo(int x, int y, int dx, int dy, int px[10], int py[10]) {
        this->x = x;
        this->y = y;
        this->dy = dy;
        this->dx = dx;
        for (int i = 0; i < 10; i++) {
            POSx[i] = px[i];
            POSy[i] = py[i];
        }
    }
    ~monstruo() {

    }
    void borrar() {
        Console::SetCursorPosition(x, y);     cout << "      ";
        Console::SetCursorPosition(x, y + 1); cout << "      ";
        Console::SetCursorPosition(x, y + 2); cout << "      ";
    }

    bool colisionaConArbol(int arbolX, int arbolY) {
        bool colisionX = (x < arbolX + 3) && (x + 3 > arbolX);
        bool colisionY = (y < arbolY + 3) && (y + 3 > arbolY);
        return colisionX && colisionY;
    }

    void mover() {
        x += dx;
        y += dy;

        if (x <= 4 || x >= 115) {
            dx = -dx;
        }
        if (y <= 4 || y >= 30) {
            dy = -dy;
        }

        for (int i = 0; i < 10; i++) {
            if (colisionaConArbol(POSx[i], POSy[i])) {
                if (x > 9) {
                    x--;
                }
                dx = -dx;
                dy = -dy;
                break;
            }
        }
    }

    void dibujar() {
        Console::SetCursorPosition(x, y);     cout << char(220) << char(219) << char(220);
        Console::SetCursorPosition(x, y + 1); cout << char(219) << "@" << char(219);
        Console::SetCursorPosition(x, y + 2); cout << "@ @";
    }
};

