#pragma once
#include "Vehículo.h"
#include <vector>

using namespace std;

class CController {
private:
	int contadorCarro1 = 0;
	int contadorCarro2 = 0;
	int contadorCarro3 = 0;
	vector<CVehiculo*> autos;
	int max = 20;
	int tiempo = 0;
public:
	CController(Graphics^ g);
	CController(Graphics^ g, int f);
	~CController();
	void dibujarTodos(Graphics^ g);
	void moverTodos(Graphics^ g);
	void moverTodos2(Graphics^ g);
	void crearNuevoCarro(Graphics^ g);
	void colisionando(CVehiculo* a, CVehiculo* b);
	void dibujarMeta(Graphics^ g);
	bool colisionmeta();
	void contarTiposDeCarro();

	int getContadorCarro1() { return contadorCarro1; }
	int getContadorCarro2() { return contadorCarro2; }
	int getContadorCarro3() { return contadorCarro3; }
};
CController::CController(Graphics^ g)
{
	srand(time(nullptr));
	/*
	autos.push_back(new Carro1(rand() % 600 + 5, rand() % 280 + 90, 1, 1));
	autos.push_back(new Carro2(rand() % 600 + 5, rand() % 280 + 90, 1, 1));
	autos.push_back(new Carro3(rand() % 600 + 5, rand() % 280 + 90, 1, 1));
	*/
	autos.push_back(new Carro1(10, 150, 1, 0));
	autos.push_back(new Carro2(10, 300, 1, 0));
	autos.push_back(new Carro3(10, 450, 1, 0));

}
CController::CController(Graphics^ g, int f)
{
	f = 0;
	srand(time(nullptr));
	//int numeroFiguras = 3;
	//int seccion = g->VisibleClipBounds.Height / numeroFiguras;
	autos.push_back(new Carro1(rand() % 700 + 5, rand() % 280 + 90, 1, 1));
	autos.push_back(new Carro2(rand() % 700 + 5, rand() % 280 + 90, 1, 1));
	autos.push_back(new Carro3(rand() % 700 + 5, rand() % 280 + 90, 1, 1));

}
CController::~CController()
{
	for (auto figura : autos) {
		delete figura;
	}
	autos.clear();
}

void CController::dibujarTodos(Graphics^ g)
{
	g->Clear(Color::White);
	for (int i = 0; i < autos.size(); i++)
	{
		autos[i]->dibujar(g);
	}
}
void CController::moverTodos(Graphics^ g) {
	for (int i = 0; i < autos.size(); i++) {
		int dx = (rand() % 16 + 5);
		autos[i]->setDx(dx);
		autos[i]->mover(g);

		/*
		Otro modo, que no usa el movimiento de Vehículo.h
		int dx;
		if ((autos[i]->getX() + autos[i]->getWidth()) >= 800)
		{
			autos[i]->setDx(0);
		}
		else
		{
			dx = (rand() % 5 - 1);
			autos[i]->setDx(dx);
			autos[i]->mover(g);
		}
		*/

	}
	dibujarTodos(g);
}
void CController::dibujarMeta(Graphics^ g)
{
	Pen^ pencil = gcnew Pen(Color::Red, 3);
	g->DrawLine(pencil, Point(873, 0), Point(873, 637));
}
void CController::moverTodos2(Graphics^ g) {
	tiempo++;

	if (tiempo >= 20 && autos.size() < max) {
		crearNuevoCarro(g);
		tiempo = 0;
	}

	for (int i = 0; i < autos.size(); i++) {
		autos[i]->mover2(g);
	}

	// colichon
	for (int i = 0; i < autos.size(); i++) {
		for (int j = i + 1; j < autos.size(); j++) {
			colisionando(autos[i], autos[j]);
		}
	}

	dibujarTodos(g);
}

void CController::colisionando(CVehiculo* a, CVehiculo* b) {
	float distX = abs(a->getX() - b->getX());
	float distY = abs(a->getY() - b->getY());

	if (distX < a->getWidth() && distY < a->getHeight()) {

		//colision eliminarlos
		if (typeid(*a) == typeid(Carro3) && typeid(*b) == typeid(Carro2)) {
			autos.erase(remove(autos.begin(), autos.end(), a), autos.end());
			autos.erase(remove(autos.begin(), autos.end(), b), autos.end());
		}

	}
}

void CController::crearNuevoCarro(Graphics^ g) {
	int tipo = rand() % 3;
	float randomDx, randomDy;
	CVehiculo* nuevoAuto;

	//ayuda de ia
	int centerX = static_cast<int>(g->VisibleClipBounds.Width / 2);
	int centerY = static_cast<int>(g->VisibleClipBounds.Height / 2);
	int posX = static_cast<int>(rand() % 200 + centerX - 100); // Rango de 200 píxeles alrededor del centro X
	int posY = static_cast<int>(rand() % 100 + centerY - 50);  // Rango de 100 píxeles alrededor del centro Y

	do {
		randomDx = static_cast<float>(rand() % 3) - 1.0;
		randomDy = static_cast<float>(rand() % 3) - 1.0;
	} while (randomDx == 0 && randomDy == 0);


	if (tipo == 0) nuevoAuto = new Carro1(posX, posY, randomDx, randomDy);
	else if (tipo == 1) nuevoAuto = new Carro2(posX, posY, randomDx, randomDy);
	else nuevoAuto = new Carro3(posX, posY, randomDx, randomDy);

	autos.push_back(nuevoAuto);
}

void CController::contarTiposDeCarro() {
	contadorCarro1 = 0;
	contadorCarro2 = 0;
	contadorCarro3 = 0;

	for (CVehiculo* autos : autos) {
		if (typeid(*autos) == typeid(Carro1)) contadorCarro1++;
		else if (typeid(*autos) == typeid(Carro2)) contadorCarro2++;
		else if (typeid(*autos) == typeid(Carro3)) contadorCarro3++;
	}

}

bool CController::colisionmeta() {
	for (int i = 0; i < autos.size(); i++) {

		if ((autos[i]->getX()) >= 800)
		{
			return true;
		}

	}
	return false;
}