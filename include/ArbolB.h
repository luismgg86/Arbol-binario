#include "NodoA.h"
#include <cstring>

class ArbolB
{
	
public:
	//Atributo del Nodo raiz y el contructor
	NodoA* Raiz;
	ArbolB(int Dato);
    //Metodos del arbol binario
	NodoA* BuscarNodo(int ref);
	NodoA* BuscarRec(int ref, NodoA* aux);
	bool InsertarRec(int Dato, NodoA* aux);
	bool Insertar(int Dato);
	bool Borrar(int ref);
    void Imprimir();
    void ImprimirRec(NodoA* aux);
    void Intercambio(NodoA* a, NodoA*aux);

};

