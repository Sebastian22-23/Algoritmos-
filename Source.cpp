#include"ArrPro.h"
#include"ArrProve.h"
#include"conio.h"
using namespace std;
using namespace System;
int menu() {
	int opc;
	do {
		cout << "------------MENU-----------" << endl;
		cout << " 1. Insertar Producto" << endl;
		cout << " 2. Insertar Proveedor" << endl;
		cout << " 3. Modificar Producto" << endl;
		cout << " 4. Eliminar porducto vencido" << endl;
		cout << " 5. Reporte de productos" << endl;
		cout << " 6. Salir" << endl;
		cout << endl;
		cout << "Ingrese opcion: "; cin >> opc;
	} while (opc < 1 || opc>6);
	return opc;
}
int main() {
	ArrPro* obj1Arr = new ArrPro();
	Producto* objProducto;
	ArrProve* obj2Arr = new ArrProve();
	Proveedores* objProve;
	int id;
	string nombre;
	string tipo;
	int cantidad;
	char categoria;
	int anio;
	int precio;
	string proveedor;
	int ruc;
	int Rsocial;
	//char categoria;
	string direccion;
	int telefono;

	while (true) {
		Console::Clear();
		int opc;
		opc = menu();
		if (opc == 1) {
			objProducto = new Producto();
			cout << "Id de producto: "; cin >> id;
			objProducto->setId(id);
			cout << "Nombre: "; cin >> nombre;
			objProducto->setNombre(nombre);
			cout << "Tipo(Liquido o Polvo): "; cin >> tipo;
			objProducto->setTipo(tipo);
			cout << "Cantidad: "; cin >> cantidad;
			objProducto->setCanidad(cantidad);
			cout << " Categoria (A, B o C): "; cin >> categoria;
			objProducto->setCategoria(categoria);
			cout << "Anio: "; cin >> anio;
			objProducto->setAnio(anio);
			cout << "Precio: "; cin >> precio;
			objProducto->setPrecio(precio);
			cout << "Proveedor: "; cin >> proveedor;
			objProducto->setProveedor(proveedor);

			obj1Arr->insertarPro(objProducto);
		}
		if (opc == 2) {
			objProve = new Proveedores();
			cout << "Ruc: "; cin >> ruc;
			objProve->setRuc(ruc);
			cout << "Razon Social: "; cin >> Rsocial;
			objProve->setRSocial(Rsocial);
			cout << "Categoria: "; cin >> categoria;
			objProve->setCategoria(categoria);
			cout << "Direccion: "; cin >> direccion;
			objProve->setDireccion(direccion);
			cout << "Telefono: "; cin >> telefono;
			objProve->setTelefono(telefono);

			obj2Arr->agregarProve(objProve);
		}
		if (opc == 3) {
			int pos, opcM;
			cout << "Ingrese la opcion a modificar: "; cin >> pos;
			Producto* objProducto = obj1Arr->modificar(pos);
			int id;
			string nombre;
			string tipo;
			int cantidad;
			char categoria;
			int anio;
			int precio;
			string proveedor;

			cout << "Que desea modificar: " << endl;
			cout << "1.Id del Producto" << endl;
			cout << "2.Nombre" << endl;
			cout << "3.Tipo" << endl;
			cout << "4.Cantidad" << endl;
			cout << "5.Categoria" << endl;
			cout << "6.Anio" << endl;
			cout << "7.Precio" << endl;
			cout << "8.Proveedor";
			cin >> opcM;
			switch (opcM) {
			case 1:
				cout << "Id del Producto (" << objProducto->getId() << ": "; cin >> id;
				objProducto->setId(id);
				break;
			case 2:
				cout << "Nombre (" << objProducto->getNombre() << ": "; cin >> nombre;
				objProducto->setNombre(nombre);
				break;
			case 3:
				cout << "Tipo (" << objProducto->getTipo() << ": "; cin >> tipo;
				objProducto->setTipo(tipo);
				break;
			case 4:
				cout << "Cantidad (" << objProducto->getCantidad() << ": "; cin >> cantidad;
				objProducto->setCanidad(cantidad);
				break;
			case 5:
				cout << "Categoria (" << objProducto->getCategoria() << ": "; cin >> categoria;
				objProducto->setCategoria(categoria);
				break;
			case 6:
				cout << "Anio (" << objProducto->getAnio() << ": "; cin >> anio;
				objProducto->setAnio(anio);
				break;
			case 7:
				cout << "Precio (" << objProducto->getPrecio() << ": "; cin >> precio;
				objProducto->setPrecio(precio);
				break;
			case 8:
				cout << "Proveedor (" << objProducto->getProveedor() << ": "; cin >> proveedor;
				objProducto->setPrecio(precio);
				break;
			default:
				cout << "Ha digitado un numero invalido " << endl;
				break;
			}
			if (opc == 4) {
				cout << "Los productos vencidos han sido eliminados " << endl;
			}
			if (opc == 5) {
				obj1Arr->mostrar();
			}
			if (opc == 6) {
				return 0;
			}
			
		}
	}
	_getch();
	return 0;
}