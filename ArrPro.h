#include"Producto.h"
using namespace std;
class ArrPro {
private:
	Producto** arreglo;
	int n, indice;
public:
	ArrPro() {
		arreglo = nullptr;
		n = 0;
	};
	void insertarPro(Producto* obj) {
		Producto** aux = new Producto * [n + 1];
		for (int i = 0; i < n; i++) {
			aux[i] = arreglo[i];
		}
		aux[n] = obj;
		n++;
		if (arreglo != nullptr)
			delete[]arreglo;
		arreglo = aux;
	}
	Producto* eliminar() {//por revisar
		for (int i = 0; i < n; i++) {
				for (int j = i; j < n - 1; j++) {
					if (arreglo[j]->getAnio() == 2020) {
						arreglo[j] = arreglo[j + 1];
					}
				}
		}
		n--;
	}
	Producto* modificar(int pos) {
		for (int i = 0; i < n; i++) {
			return arreglo[pos];
		}
	}
	void mostrar() {
		for (int i = 0; i < n; i++) {
			arreglo[i]->info();
		}
	}
};