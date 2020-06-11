/*
	COLAS
*/

#include <iostream>
#include <string>

using namespace std;

struct nodo{
	int dato;
	nodo *apuntador;
};

//Apuntadores de inicio y fin de tipo estructura
nodo *inicio = NULL;
nodo *fin  = NULL;

//funci�n para encolar nodos
void enqueue(){
	int valor;
	nodo *nuevo = new nodo();
	
	cout << "Ingrese dato: " << endl;
	cin >> valor;
	
	nuevo->dato = valor;
	nuevo->apuntador = NULL;
	
	//Validaci�n si es el primer dato a encolar
	if(inicio == NULL){
		inicio = nuevo;
		fin = nuevo;
	}else{
		fin->apuntador = nuevo;
		fin = nuevo;
	}
	
	cout << "Dato insertado!" << endl;
	system("Pause");
}

//Funci�n encargada de validar si la lista est� vac�a
bool vacio(){
	if(inicio == NULL && fin == NULL){
		return true;
	}else{
		return false;
	}
}

//funci�n para desencolar nodos
void dequeue(){
	if(vacio()){
		cout << "La lista se encuentra vac�a!" << endl;
	}else{
		if(inicio == fin){
			//si se tiene solo un dato
			free(inicio);
			inicio = fin = NULL;
		}else{
			//Si se tienen m�s datos
			nodo *elemento = inicio;
			inicio = inicio->apuntador;
			free(elemento);
		}
		
		cout << "Dato desencolado!" << endl;
		system("Pause");
	}
}

//mostrar� el primer nodo de la cola
void mostrarInicio(){
	if(vacio()){
		cout << "La lista se encuentra vac�a!" << endl;
	}else{
		cout << "Primer dato: " << inicio->dato << endl;
	}
	system("Pause");
}

//Muestra los datos de la cola
void desplegarLista(){
	if(vacio()){
		cout << "La lista se encuentra vac�a!" << endl;
	}else{
		nodo *lista = inicio;
		
		cout << "La lista es: " << endl;
		while(lista != NULL){
			cout << " " << lista->dato << " "<< endl; 
			lista = lista->apuntador;
		}
	}
	system("Pause");
}

int main(){
	//Declaraci�n de variables para el manejo del men�
	int opcion;
	bool finalizar = false;
	
	do{
		system("CLS");
		cout << "-----------MENU PRINCIPAL-----------" << endl;
		cout << "1) Queue" << endl;
		cout << "2) Dequeue" << endl;
		cout << "3) Top" << endl;
		cout << "4) Lista" << endl;
		cout << "5) Salir" << endl;
		cout << "Seleccione una opcion:" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				mostrarInicio();
				break;
			case 4:
				desplegarLista();
				break;
			case 5:
				finalizar = true;
				break;
			default:
				cout <<"opcion invalida!" << endl;
				break;
		}
		
	}while(finalizar != true);
	
	return 0;
}
