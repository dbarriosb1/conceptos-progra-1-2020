/*
	Listas enlazadas
	INSERTAR NODOS AL FINAL DE LA LISTA
	(First In - First On) fifo
*/

#include <iostream>

using namespace std;

//Declaraci�n de estructura Nodo
/*
	*i: Nodo inicial
	*f: Nodo final 
*/
struct nodo{
	int dato;
	nodo *apuntador;
} *i, *f;

//Se encarga de insertar nodos
void insertarDatos(){
	nodo *nuevo = new nodo();
	
	cout << "Ingrese el dato del nuevo nodo: " << endl;
	cin >> nuevo->dato;
	
	//Validamos si el nodo inicial es NULL
	if(i == NULL){
		//Enviamos el nodo "nuevo" al nodo "i" que es el inicial
		i = nuevo;
		//El apuntador del nodo inicial ser� igual a NULL
		i->apuntador = NULL;
		//El nodo final ser� igual al inicial (cuando solo tengamos un dato)
		f = i;
	}else{
		//el apuntador del nodo final "f" ser� igual al nodo "nuevo"
		f->apuntador = nuevo;
		//El apuntador del nodo "nuevo" ser� NULL
		nuevo->apuntador = NULL;
		//El nodo final "f" ser� igual al nodo "nuevo"
		f = nuevo;
	}
	
	cout << "Nodo creado!" << endl;
	system("Pause");
}


void mostrarDatos(){
	//Declaramos puntero "actual" y lo inicializamos en la posici�n inicial "i"s
	nodo *actual = new nodo();
	actual = i;
	
	//Si la posici�n inicial no es NULL, mostramos los datos. De lo contrario es porque la lista est� vac�a
	if(i != NULL){
		cout << "La lista es: " << endl;
		
		while(actual != NULL){
			cout << " " << actual->dato << " "<< endl;
			//Asignamos el apuntador de "actual" a la siguiente posici�n
			actual = actual->apuntador;
		}
		system("Pause");
	}else{
		cout << "La lista est� vac�a" << endl;
		system("Pause");
	}	
}

int main(){
	//Declaraci�n de variables para el manejo del men�
	int opcion;
	bool finalizar = false;
	
	do{
		system("CLS");
		cout << "-----------MENU PRINCIPAL-----------" << endl;
		cout << "1) Insertar Nodo" << endl;
		cout << "2) Mostrar la lista" << endl;
		cout << "3) Salir" << endl;
		cout << "Seleccione una opcion:" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				insertarDatos();
				break;
			case 2:
				mostrarDatos();
				break;
			case 3:
				finalizar = true;
				break;
			default:
				cout <<"opcion invalida!" << endl;
				break;
		}
		
	}while(finalizar != true);
	
	return 0;
}
