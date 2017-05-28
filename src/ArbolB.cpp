#include "ArbolB.h"
//constructor del arbol con un dato entero
ArbolB::ArbolB(int Dato)
{
	this->Raiz = new NodoA(Dato);
}
//metodo para insertar un dato
bool ArbolB::Insertar(int Dato)
{
	if(BuscarNodo(Dato)!=NULL)
	{
		return true;
	}
	return InsertarRec(Dato, Raiz);
}
//metodo para insertar un dato recursivamente
bool ArbolB::InsertarRec(int Dato, NodoA* aux)
{
	bool Res; 
	if (Dato<aux->getDato())
	{
		if(aux->Hizq!=NULL)
		{
			Res=InsertarRec(Dato, aux->Hizq);

		}else{

			NodoA* n= new NodoA(Dato,aux);
			aux->Hizq=n;
			return true;
		}

	}else{
		if(aux->Hder!=NULL)
		{
			Res=InsertarRec(Dato, aux->Hder);

		}else{
			NodoA* n= new NodoA(Dato,aux);
			aux->Hder=n;
			return true;

		}

	}
return Res;
}
//metodo para borrar un dato
bool ArbolB::Borrar(int ref){
	NodoA* aux=BuscarNodo(ref);
	if (aux==NULL)
	{
		return false;
	}
	if (aux->Hizq==NULL&&aux->Hder==NULL)
	{
		if (aux->Padre->Hizq==aux)
		{
			aux->Padre->Hizq=NULL;
		}
		else{
			aux->Padre->Hder=NULL;
		}
		aux->Padre=NULL;
	}
	if (aux->Hizq!=NULL)
	{
		if (aux->Hizq->Hder==NULL)
		{
			aux->Padre->Hder=aux->Hizq;
			aux->Hizq->Padre=aux->Padre;
			aux->Padre=NULL;
			aux->Hizq->Hder=aux->Hder;
			aux->Hder->Padre=aux->Hizq;
			aux->Hder=NULL;
			aux->Hizq=NULL;
		}
	}
	else{
		NodoA* a=aux->Hizq->Hder;
		while(a->Hder!=NULL){
			a=a->Hder;
		}
		if (a->Hizq!=NULL)
		{
			a->Hizq->Padre=a->Padre;
			a->Padre->Hder=a->Hizq;
			a->Hizq=NULL;
		}
		Intercambio(a,aux);
	}
	return true;
	
}
//metodo que hace el intercambio entre los nodos necesarios para guardar una rama o un nodo al eliminar otro
void ArbolB::Intercambio(NodoA* a, NodoA* aux){

	a->Padre->Hder=NULL;
	a->Padre=aux->Padre;
	a->Hder=aux->Hder;
	a->Hizq=aux->Hizq;
	aux->Hizq->Padre=a;
	aux->Hder->Padre=a;
	aux->Padre=a;
	aux->Hizq=NULL;
	aux->Hder=NULL;
}

//metodo para buscar nodo, recibe una reerencia
NodoA* ArbolB::BuscarNodo(int ref)
{
	if(Raiz==NULL)
	{
		return NULL;
	} 
	
	return BuscarRec(ref,Raiz);
}
//metod para buscar un nodo, ecibe una referencia y un nodo aux
NodoA* ArbolB::BuscarRec(int ref,NodoA* aux){
	NodoA* Busq=aux;
	NodoA* Res;
	if (Busq->getDato()==ref)
	{
		return Busq;
	}
	if (Busq->Hder==NULL&&Busq->Hizq==NULL)
	{
		return NULL;
	}
	if (ref<Busq->getDato()&&Busq->Hizq!=NULL)
	{
		Res=BuscarRec(ref,Busq->Hizq);
	}
	else{
		if (ref>Busq->getDato()&&Busq->Hder!=NULL)
	{
		Res=BuscarRec(ref,Busq->Hder);
	}
	}
	if (Res!=NULL)
	{
		return Res;
	}
	return NULL;
}
//meotod para imprimir
 void ArbolB::Imprimir()
{
		
	if(this->Raiz==NULL)
	{
		std::cout<<"El arbol esta vacio"<<std::endl;
	}
	
	std::cout<<"\t "<<Raiz->getDato()<<std::endl;
	ImprimirRec(this->Raiz);

}
//metodo para imprimir recursivo
void ArbolB::ImprimirRec(NodoA* aux)
{
	if(aux->Hizq!=NULL)
	{
		std::cout<<"\t"<<aux->Hizq->getDato()<<" ";
		std::cout<<"\t"<<" ";
	}
	if(aux->Hder!=NULL)
	{
		std::cout<<"\t"<<" ";
		std::cout<<aux->Hder->getDato()<<std::endl;		
	}
	if (aux->Hizq!=NULL)
	{		
	ImprimirRec(aux->Hizq);
	}

	if (aux->Hder!=NULL)
	{		
	ImprimirRec(aux->Hder);
	}
}