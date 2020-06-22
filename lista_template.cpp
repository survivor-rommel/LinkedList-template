#include <iostream>
#include "nodo.h"
#include "LinkedL.h"

using namespace std;

int main()
{
	//Se declara un objeto de clase LinkedList
	LinkedList<char> lis;
	
	//Declarando objetos de Node 
	
	Node <char> nodo1 ('s');
	Node <char> nodo2 ('d');
	Node <char> nodo3 ('f');
	Node <char> nodo4 ('n');
	Node <char> nodo5 ('p');
	Node <char> nodo6 ('z');
	Node <char> nodo7 ('v');


	
	
	
	lis.insertar_adelante(nodo1);
	lis.insertar_adelante(nodo2);
	lis.insertar_adelante(nodo3);
	lis.insertar_adelante(nodo4);
	lis.insertar_adelante(nodo5);
	lis.insertar_adelante(nodo6);
	lis.insertar_adelante(nodo7);

	
	
	cout<< "Lista de Elmentos: \n\n";
	lis.show();
	
	//Eliminado elementos de la lista 

	lis.remover_atras();
	lis.remover_adelante();
	lis.remover_posicion(1);
	cout<<"\nLos elementos numero 4 y 2 han sido eliminados "<<endl;
	cout<< "Lista actualizada : "<<endl;
	lis.show();	
	
		
	return 0;
}
	
	

