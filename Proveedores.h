#pragma once
#include"iostream"
using namespace std;
class Proveedores {
private:
	int ruc;
	int Rsocial;
	char categoria;
	string direccion;
	int telefono;
public:
	Proveedores() {
		ruc = 0;
		Rsocial = ' ';
		categoria = 0;
		direccion = " ";
		telefono = 0;
	}
	~Proveedores() {};
	//getters
	int getRuc() { return ruc; }
	int getRSocial() { return Rsocial; }
	int getCategoria() { return categoria; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }

	//setters
	void setRuc(int r) { ruc = r; }
	void setRSocial(int rs) { Rsocial = rs; }
	void setCategoria(char c) { categoria = c; }
	void setDireccion(string d) { direccion = d; }
	void setTelefono(int t) { telefono = t; }
};