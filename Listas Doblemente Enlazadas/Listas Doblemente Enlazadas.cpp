/*
	LISTAS DOBLEMENTE ENLAZADAS
	INSERCI�N DE NODOS Y DESPLIEGUE DE LISTA
*/
#include <iostream>

using namespace std;

//Declaraci�n de estructura nodo
/*
	*inicio: apuntador posici�n inicial.
	*fin: apuntador posici�n final
*/
struct nodo{
	int dato;
	nodo* apuntadorAnterior;
	nodo* apuntadorSiguiente;
} *inicio, *fin;

void insertarNodo(){
	system("CLS");
	
	//Creaci�n de nuevo espacio en memoria con los apuntadores para crear un nuevo nodo
	nodo* nuevo = new nodo();
	
	//Agregamos dato a la lista
	cout << "Ingrese nuevo dato: " << endl;
	cin >> nuevo->dato;
	
	//Validaci�n si la lista est� vac�a o posee datos
	if(inicio == NULL){
		//Lista vac�a 
		
		//Insertamos nuevo dato
		inicio = nuevo;
		inicio->apuntadorSiguiente = NULL;
		inicio->apuntadorAnterior = NULL;
		
		//El fin ser� igual al inicio
		fin = inicio;
		
	}else{
		
		fin->apuntadorSiguiente = nuevo;
		nuevo->apuntadorSiguiente = NULL;
		nuevo->apuntadorAnterior = fin;
		fin = nuevo;
	}
	
	cout << "Dato agregado con �xito!" << endl;
	system("Pause");
}

//Mostrar datos del primero al ultimo
void mostrarDatosPrimeroAUltimo(){
	system("CLS");
	nodo* temp = new nodo();
	
	temp = inicio;
	
	//Validaci�n si la lista se encuentra llena
	if(inicio != NULL){
		
		cout << "La lista es: " << endl;
		while(temp != NULL){
			
			//Mostramos el dato insertado
			cout << " " << temp->dato << endl;
			
			//Asignamos la siguiente posici�n a la variable temp
			temp = temp->apuntadorSiguiente;
		}
		
		system("Pause");
	}else{
		cout << "La lista no posee datos!" << endl;
		system("Pause");
	}
}

void mostrarDatosUltimoAPrimero(){
	system("CLS");
	nodo* temp = new nodo();
	
	temp = fin;
	
	//Validaci�n si la lista se encuentra llena
	if(fin != NULL){
		
		cout << "La lista es: " << endl;
		while(temp != NULL){
			
			//Mostramos el dato insertado
			cout << " " << temp->dato << endl;
			
			//Asignamos la siguiente posici�n a la variable temp
			temp = temp->apuntadorAnterior;
		}
		
		system("Pause");
	}else{
		cout << "La lista no posee datos!" << endl;
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
		cout << "2) Mostrar la lista primero al �ltimo" << endl;
		cout << "3) Mostrar la lista �ltimo al primero" << endl;
		cout << "4) Salir" << endl;
		cout << "Seleccione una opcion:" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				insertarNodo();
				break;
			case 2:
				mostrarDatosPrimeroAUltimo();
				break;
			case 3:
				mostrarDatosUltimoAPrimero();
				break;
			case 4:
				finalizar = true;
				break;
			default:
				cout <<"opcion invalida!" << endl;
				break;
		}
		
	}while(finalizar != true);
	
	return 0;
}
