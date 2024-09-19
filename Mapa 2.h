#pragma once
#include"Basura.h"
#include "Personaje.h"
#include"Mapa3.h"
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void mapa2() {
	char forma1 = 219;
	char forma2 = 219;
	char forma3 = 196;

	int caracter[] = { 119, 46, 46, 40, 40, 34, 34, 28, 28, 22, 22, 16, 16 };
	int espacio[] = { 119, 71, 71, 77, 77, 83, 83, 92, 92, 98, 98, 104, 104 };

	for (int l = 0; l <= 118; l++) {
		cout << char(forma3);
	}
	for (int i = 0; i < 2; i++) {
		cout << endl;

	}
	for (int l = 0; l <= 118; l++) {
		cout << char(forma3);
	}


	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < caracter[i]; j++) {
			cout << forma2;
		}
		for (int j = caracter[i]; j < espacio[i]; j++) {
			cout << " ";
		}
		for (int j = espacio[i]; j < 119; j++) {
			cout << forma2;
		}
	}

	for (int j = 13; j <= 28; j++) {
		cout << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1);

		for (int k = 0; k <= 101; k++) {
			cout << " ";
		}
		cout << " " << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1) << char(forma1); //<< endl;
	}

}
class juego2 {
private:
	persona1* objp2;
	semilla_buena* objsb;
	semilla_mala* objsm;
	juego3* objjuego3;
	int ns = 1;
public:
	juego2() {
		objp2 = new persona1(55, 28, 6);
		objsb = new semilla_buena(10, 15, 1, 0, 3);
		objsm = new semilla_mala(10, 15, 1, 0, 5);
		objjuego3 = new juego3();
	}
	~juego2() {
		delete objp2;
		delete objsb;
		delete objsm;
		delete objjuego3;
	}
	bool choque_suelosb() {
		if (objsb->getY() == 32) {
			return true;
		}
		return false;
	}
	bool choque_personasb() {
		if (objsb->getX() >= objp2->X() && objsb->getX() < objp2->X() + 6 &&
			objsb->getY() >= objp2->Y() && objsb->getY() < objp2->Y() + 1) {
			return true;
		}
		return false;
	}
	bool choque_personasm() {
		if (objsm->getX() >= objp2->X() && objsm->getX() < objp2->X() + 6 &&
			objsm->getY() >= objp2->Y() && objsm->getY() < objp2->Y() + 1) {
			return true;
		}
		return false;
	}
	void imprimir_semillabuena() {
		Console::SetCursorPosition(1, 1); cout << "SEMILLAS RECOGIDAS: " << ns++;
	}
	bool level3() {
		if (ns == 11) {
			system("cls");
			objjuego3->movimiento3();
			return false;
		}
		return true;
	}
	bool perdiste() {
		if (objp2->get_vidas() == 0) {
			Console::Clear();
			lose();
			if (_getch()) {  // Esperar a que el usuario presione una tecla
				objp2->set_vidas(8);
				ns = 1;
				Console::Clear();
				movimiento2();  // Volver a ejecutar el ciclo de movimiento
			}
			return true;
		}

		return false;
	}
	void movimiento2() {
		mapa2();
		while (true) {
			objp2->borrar();
			objp2->mover2();
			objp2->dibujar2();

			objsb->borrarsemilla_buena();
			objsb->moversemilla_buena();
			objsb->dibujarsb();

			objsm->borrarsemilla_mala();
			objsm->moversemilla_mala();
			objsm->dibujarsm();

			if (choque_personasb()) {
				imprimir_semillabuena();

				objsb->setX(rand() % 90 + 20);
				objsb->setY(15);
			}
			if (choque_personasm()) {

				objsm->setX(rand() % 85 + 20);
				objsm->setY(15);
				objp2->set_vidas(objp2->get_vidas() - 1);
				objp2->actualizar_vidas();
			}
			if (choque_suelosb()) {
				objp2->set_vidas(objp2->get_vidas() - 1);
				objsb->borrarsemilla_buena();
				objsb->setX(rand() % 90 + 20);
				objsb->setY(15);

				objp2->actualizar_vidas();

			}
			objp2->imprimir_vidas();
			perdiste();
			level3();
			_sleep(50);
		}
	}
};

