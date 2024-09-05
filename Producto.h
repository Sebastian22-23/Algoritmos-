#pragma once
#include"iostream"
using namespace std;
class Producto {
private:
	int id;
	string nombre;
	string tipo;
	int cantidad;
	char categoria;
	int anio;
	int precio;
	string proveedor;
public:
	Producto() {
		id = 0;
		nombre = " ";
		tipo = " ";
		cantidad = 0;
		categoria = ' ';
		anio = 0;
		precio = 0;
		proveedor = " ";
	}
	~Producto() {};
	//getters
	int getId() { return id; }
	string getNombre() { return nombre; }
	string getTipo() { return tipo; }
	int getCantidad() { return cantidad; }
	char getCategoria() { return categoria; }
	int getAnio() { return anio; }
	int getPrecio() { return precio; }
	string getProveedor() { return proveedor; }
	//setters
	void setId(int i) { id = i; }
	void setNombre(string n) { nombre = n; }
	void setTipo(string t) { tipo = t; }
	void setCanidad(int c) { cantidad = c; }
	void setCategoria(char cat) { categoria = cat; }
	void setAnio(int a) { anio = a; }
	void setPrecio(int pc) { precio = pc; }
	void setProveedor(string p) { proveedor = p; }
	void info() {
		cout << "----INFORMACION----" << endl;
		cout << "Id de producto: " << id << "\t";
		cout << "Nombre: " << nombre << "\t";
		cout << "Tipo(Liquido o polvo): " << tipo << "\t";
		cout << "Cantidad: " << cantidad << "\t";
		cout << "Categoria (A, B o C): " << categoria << "\t";
		cout << "Anio: " << anio << "\t";
		cout << "Precio: " << precio << "\t";
		cout << "Proveedor: " << proveedor << "\t";
		cout << endl;
	}
};