#pragma once
#include "Personaje.h"
class juego3 {
private:
    persona1* objp2;
public:
    juego3() {
        objp2 = new persona1(55, 15, 6);
    }
    ~juego3() {
        delete objp2;
    }
    void movimiento3() {
        while (true)
        {
            objp2->borrar();
            objp2->mover3();
            objp2->dibujar2();

            _sleep(50);
        }

    }
};