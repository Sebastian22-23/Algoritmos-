#include"Proveedores.h"
using namespace std;
class ArrProve {
private:
	Proveedores** arreglo;
	int n, indice;
public:
	ArrProve() {
		arreglo = nullptr;
		n = 0;
	}
	void agregarProve(Proveedores* obj) {
		Proveedores** aux = new Proveedores * [n + 1];
		for (int i = 0; i < n; i++) {
			aux[i] = arreglo[i];
		}
		aux[n] = obj;
		n++;
		if (arreglo != nullptr)
			delete[] arreglo;
		arreglo = aux;
	}
};