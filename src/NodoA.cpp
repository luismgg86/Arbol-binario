#include "NodoA.h"

NodoA::NodoA(int Dato)
{
	this->Dato = Dato;
	this->Padre = NULL;
}

NodoA::NodoA(int Dato , NodoA* padre)
{
	this->Dato = Dato;
	this->Padre = padre;
}
void NodoA::setDato(int Dato)
{
	this->Dato = Dato;

}
void NodoA::setPadre(NodoA* Padre)
{
	this->Padre = Padre;
}
void NodoA::setHder(NodoA* Hder)
{
	this->Hder = Hder;
}
void NodoA::setHizq(NodoA* Hizq)
{
	this->Hizq = Hizq;
}
int NodoA::getDato()
{
	return this->Dato;
}

NodoA* NodoA::getPadre()
{
	return this->Padre;

}
NodoA* NodoA::getHder()
{
	return this->Hder;

}
NodoA* NodoA::getHizq()
{
	return this->Hizq;

}
