/*
	Implementaci�n de listas enlazadas
	INSERTAR NODOS AL INICIO DE LA LISTA
*/

#include <iostream>

using namespace std;

//Creaci�n de nodo
/*
	dato: El dato a insertar en la lista
	apuntador: puntero que hace referencia al siguiente espacio en memoria
*/
struct nodo{
	int dato;
	nodo* apuntador;
};

//Creaci�n de Head para el nodo este indica el inicio de la lista, como variable global
struct nodo* head;

//Ingreso de registro a la lista
void insertarNodo(int datoIngresar){
	//Inicializamos "temp" de tipo estructura y reservamos un nuevo espacio en memoria de tipo estructura Nodo
	struct nodo* temp = new nodo();
	
	//Asignamos los datos a ingresar a la estructura
	temp->dato = datoIngresar;
	temp->apuntador = NULL;
	
	/*
		Validaci�n para insertar el primer dato al inicio de la lista
		Y se asigna el apuntador insertado al head
	*/
	if(head != NULL){
		temp->apuntador = head;
	}
	
	//Asignamos temp a Head, para que este sea el primer dato en la lista, ya que es el primero que se insert�
	head = temp;
}


//Mostrar lista
void mostrarDatos(){
	//Inicializamos la variable "temp" como el inicio de la lista "head"
	struct nodo* temp = head;
	cout << "La lista es: " << endl;
	
	//Recorremos la lista hasta que encuentre el �ltimo apuntador que apunta a NULL
	while(temp != NULL){
		cout << " " << temp->dato << endl;
		
		//Asignamos el apuntador de la siguiente posici�n a "temp"
		temp = temp->apuntador;
	}
	
	cout << " " << endl;
}

int main(){
	//Variable para �ndice en ciclo
	int i;
	//Variable para capturar el n�mero de iteraciones
	int n;
	//Variable para almacenar el nodo a insertar
	int x;
	
	cout << "Cuantos nodos insertar�?" << endl;
	cin >> n;
	//el head por ser el inicio se asigna NULL
	head = NULL;
	for(i = 0; i<n; i ++){
		cout << "Ingrese un n�mero entero: " << endl;
		cin >> x;
		
		//Invocamos la funci�n para insertar el nodo y le enviamos el dato ingresado: x.
		insertarNodo(x);
	}
	
	//Invocaci�n de funci�n encargada de mostrar la lista
	mostrarDatos();
	
	return 0;
}

