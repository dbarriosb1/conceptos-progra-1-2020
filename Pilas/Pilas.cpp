/*
	PILAS
	
	push: insertar elemento en la pila
	pop: extraer elemento de la pila (extrae el elemento top de la pila)
*/

#include <iostream>
#include <string>
using namespace std;

struct nodo{
	int dato;
	nodo *apuntador;
};

nodo *inicio = NULL;

void push(){
	int valor;
	nodo *nuevo = new nodo();
	
	cout << "Ingrese valor: " << endl;
	cin >> valor;
	
	nuevo->dato = valor;
	nuevo->apuntador = inicio;
	inicio = nuevo;
	
	cout << "Dato insertado en la pila" << endl;
	system("Pause");
}

bool vacio(){
	if(inicio == NULL){
		return true;
	}else{
		return false;
	}
}

void pop(){
	//valida si la lista está vacía
	if(vacio()){
		cout << "La pila está vacía!" << endl;
	}else{
		//Se asigna el registro top de la pila a la variable "pop" para eliminarlo 
		nodo *pop = inicio;
		//Se asgina el apuntador de la posición del siguiente registro a la varible "inicio"
		inicio = inicio->apuntador;
		//Eliminación del registro TOP
		delete(pop);
	}
	
	cout << "Dato eliminado en la pila" << endl;
	system("Pause");
}

//Mostrar el top de la pila
void mostrarInicio(){
	if(vacio()){
		cout << "La pila está vacía!" << endl;
	}else{
		cout << "Dato inicial/top: " << inicio->dato << endl;
	}
	
	system("Pause");
}


//Mostrar todos los elementos en pila
void mostrarPila(){
	if(vacio()){
		cout << "La pila está vacía!" << endl;
	}else{
		nodo *temp = inicio;
		cout << "La pila es: " << endl;
		while(temp != NULL){
			cout << " " << temp->dato << endl;
			temp = temp->apuntador;
		}
	}
	
	system("Pause");
}

int main(){
	//Declaración de variables para el manejo del menú
	int opcion;
	bool finalizar = false;
	
	do{
		system("CLS");
		cout << "-----------MENU PRINCIPAL-----------" << endl;
		cout << "1) Push" << endl;
		cout << "2) Pop" << endl;
		cout << "3) Top" << endl;
		cout << "4) Pila" << endl;
		cout << "5) Salir" << endl;
		cout << "Seleccione una opcion:" << endl;
		cin >> opcion;
		
		switch(opcion){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				mostrarInicio();
				break;
			case 4:
				mostrarPila();
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
