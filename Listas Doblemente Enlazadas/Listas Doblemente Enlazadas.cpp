/*
	LISTAS DOBLEMENTE ENLAZADAS
	INSERCIÓN DE NODOS Y DESPLIEGUE DE LISTA
*/
#include <iostream>

using namespace std;

//Declaración de estructura nodo
/*
	*inicio: apuntador posición inicial.
	*fin: apuntador posición final
*/
struct nodo{
	int dato;
	nodo* apuntadorAnterior;
	nodo* apuntadorSiguiente;
} *inicio, *fin;

void insertarNodo(){
	system("CLS");
	
	//Creación de nuevo espacio en memoria con los apuntadores para crear un nuevo nodo
	nodo* nuevo = new nodo();
	
	//Agregamos dato a la lista
	cout << "Ingrese nuevo dato: " << endl;
	cin >> nuevo->dato;
	
	//Validación si la lista está vacía o posee datos
	if(inicio == NULL){
		//Lista vacía 
		
		//Insertamos nuevo dato
		inicio = nuevo;
		inicio->apuntadorSiguiente = NULL;
		inicio->apuntadorAnterior = NULL;
		
		//El fin será igual al inicio
		fin = inicio;
		
	}else{
		
		fin->apuntadorSiguiente = nuevo;
		nuevo->apuntadorSiguiente = NULL;
		nuevo->apuntadorAnterior = fin;
		fin = nuevo;
	}
	
	cout << "Dato agregado con éxito!" << endl;
	system("Pause");
}

//Mostrar datos del primero al ultimo
void mostrarDatosPrimeroAUltimo(){
	system("CLS");
	nodo* temp = new nodo();
	
	temp = inicio;
	
	//Validación si la lista se encuentra llena
	if(inicio != NULL){
		
		cout << "La lista es: " << endl;
		while(temp != NULL){
			
			//Mostramos el dato insertado
			cout << " " << temp->dato << endl;
			
			//Asignamos la siguiente posición a la variable temp
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
	
	//Validación si la lista se encuentra llena
	if(fin != NULL){
		
		cout << "La lista es: " << endl;
		while(temp != NULL){
			
			//Mostramos el dato insertado
			cout << " " << temp->dato << endl;
			
			//Asignamos la siguiente posición a la variable temp
			temp = temp->apuntadorAnterior;
		}
		
		system("Pause");
	}else{
		cout << "La lista no posee datos!" << endl;
		system("Pause");
	}	
}

int main(){
	//Declaración de variables para el manejo del menú
	int opcion;
	bool finalizar = false;
	
	do{
		system("CLS");
		cout << "-----------MENU PRINCIPAL-----------" << endl;
		cout << "1) Insertar Nodo" << endl;
		cout << "2) Mostrar la lista primero al último" << endl;
		cout << "3) Mostrar la lista último al primero" << endl;
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
