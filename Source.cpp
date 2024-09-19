#include <windows.h>
#include <iostream>
#include"Mapa1.h"
#include"Mapa3.h"
#include"Personaje.h"
#include"conio.h"
using namespace System;
void MAPA1() {
    Console::CursorVisible = false;
    juego1* objJUEGO;
    juego3* hola;

    hola = new juego3();

    objJUEGO = new juego1();

    //objJUEGO->movimiento();
    //objJUEGO->perdiste();
    hola->movimiento3();
}
int main() {
    Console::SetWindowSize(119, 34);
    //mapa1();
    MAPA1();
    _getch();
    return 0;
}
