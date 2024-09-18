#include <windows.h>
#include <iostream>
#include"Mapa1.h"
#include"Personaje.h"
#include"conio.h"
void MAPA1() {
    Console::CursorVisible = false;
    juego1* objJUEGO;

    objJUEGO = new juego1();

    objJUEGO->movimiento();
    objJUEGO->perdiste();
}
int main() {
    Console::SetWindowSize(119, 34);
    mapa1();
    MAPA1();
    _getch();
    return 0;
}