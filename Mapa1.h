#pragma once
#include "Carro.h"
#include "Personaje.h"
#include"Objetos.h"
#include"Mapa 2.h"
using namespace System;
void mapa1() {
    char forma1 = 219;
    char forma2 = 219;
    char forma3 = 196;
    char forma4 = 177;

    setColor(1);


    for (int l = 0; l <= 118; l++) {
        cout << char(forma3);
    }

    for (int i = 0; i < 2; i++) {
        cout << endl;
    }

    for (int l = 0; l <= 118; l++) {
        cout << char(forma3);
    }

    for (int i = 0; i < 7; i++) {
        cout << endl;
    }

    setColor(8);


    for (int l = 0; l <= 118; l++) {
        cout << char(forma2);
    }

    setColor(8);

    for (int j = 11; j <= 29; j++) {
        cout << char(forma1) << char(forma1) << "  " << char(forma1) << char(forma1) << "  " << char(forma1) << char(forma1);

        for (int k = 0; k < 99; k++) {
            cout << " ";
        }
        cout << char(forma1) << char(forma1) << "  " << char(forma1) << char(forma1) << "  " << char(forma1) << char(forma1);
    }
    setColor(1);
    for (int l = 0; l <= 118; l++) {
        cout << char(forma4);
    }
    for (int l = 0; l <= 118; l++) {
        cout << char(forma4);
    }
    for (int l = 0; l <= 118; l++) {
        cout << char(forma4);
    }

    setColor(7);
}
class juego1 {
private:
    CARRO* objcarro;
    persona1* objp;
    Basura* objbasura;
    int n = 1;
    int na = 1;
    juego2* objJuego2;
public:
    juego1() {
        objcarro = new CARRO(0, 5);
        objp = new persona1(55, 28, 6);
        objbasura = new Basura(10, 15, 0.5);
        objJuego2 = new juego2;
    }

    ~juego1() {
        delete objcarro;
        delete objp;
        delete objbasura;
        delete objJuego2;
    }

    bool choque_persona() {
        if (objbasura->getX() >= objp->getX() && objbasura->getX() < objp->getX() + 6 &&
            objbasura->getY() >= objp->getY() && objbasura->getY() < objp->getY() + 1) {
            return true;
        }
        return false;
    }

    bool choque_rio() {
        if (objbasura->getY() == 30) {
            return true;
        }
        return false;
    }

    void imprimir_basura() {
        Console::SetCursorPosition(1, 1); cout << "BASURA RECOGIDA: " << n++;
    }
    void imprimir_agua() {
        Console::SetCursorPosition(26, 1); cout << "AGUA SALVADA: " << na++;
    }
    bool level2() {
        if (n == 11) {
            system("cls");
            objJuego2->movimiento2();
            return false;
        }
        return true;
    }
    bool perdiste() {
        if (objp->get_vidas() == 0) {
            Console::Clear();
            lose();
            if (_getch()) {
                objp->set_vidas(8);
                n = 1;
                na = 1;
                Console::Clear();
                movimiento();
            }
            return true;
        }
        return false;
    }
    void movimiento() {
        mapa1();
        while (true) {
            objcarro->borrar();
            objp->borrar();
            objbasura->borrar();

            objcarro->mover();
            objcarro->imprimir();

            objp->mover();
            objp->dibujar();

            objbasura->mover();
            objbasura->dibujar();

            if (choque_persona()) {
                imprimir_basura();
                imprimir_agua();

                objbasura->borrar();
                objbasura->setX(rand() % 80 + 25);
                objbasura->setY(12);
            }

            if (choque_rio()) {
                objp->set_vidas(objp->get_vidas() - 1);
                objp->actualizar_vidas();
                objbasura->borrar();
            }

            objp->imprimir_vidas();

            if (perdiste()) {
                return;
            }
            level2();
            _sleep(50);
        }
    }
};