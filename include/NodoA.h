#include <iostream>
#include <vector>

class NodoA
{
public:
	//Dato del nodo
	int Dato;

	//Nodos padre,Hijo iqz. e hijo der.
	NodoA* Padre;
	NodoA* Hder;
	NodoA* Hizq;

	//Constructores,setters y getters
	NodoA(int Dato);
	NodoA(int Dato, NodoA* Padre);
	void setDato(int Dato);
	void setPadre(NodoA* Padre);
	void setHder(NodoA* Hder);
	void setHizq(NodoA* Hizq);
	int getDato();
	NodoA* getPadre();
	NodoA* getHder();
	NodoA* getHizq();
};
