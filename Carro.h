#pragma once
#include "Chasis.h"
#include "Llanta.h"

class CARRO {
private:
    int x;
    int y;
    int dx;
    llanta* objllanta;
    chasis* objchasis;

public:
    CARRO(int x, int y) {
        this->x = x;
        this->y = y;
        this->dx = 1;
        objllanta = new llanta(x, y + 4);
        objchasis = new chasis(x, y);
        
    };

    ~CARRO() {
        delete objllanta;
        delete objchasis;
    };

    void imprimir() {
        objllanta->dibujar_llanta();
        objchasis->dibujar();
    }

    void mover() {
        borrar();
        x += dx;
        if (x == 101) {
            x = 0;
            objchasis->setColor();
        } 
        
        objchasis->setX(x);
        objllanta->setX(x);
        imprimir();
    }

    void borrar() {
        Console::SetCursorPosition(x, y);     cout << "                    ";
        Console::SetCursorPosition(x, y + 1); cout << "                    ";
        Console::SetCursorPosition(x, y + 2); cout << "                    ";
        Console::SetCursorPosition(x, y + 3); cout << "                    ";
        Console::SetCursorPosition(x, y + 4); cout << "                    ";

    }
    
   
};

