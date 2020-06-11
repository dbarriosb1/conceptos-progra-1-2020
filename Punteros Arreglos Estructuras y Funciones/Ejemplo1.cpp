/*
Ingresar 5 empleados y determinar el empleado que m�s gana y el total de la planilla
utilizando:
	Estructuras	X
	Funciones	X
	Arreglos	X
	Punteros	X
*/

#include <iostream>
#include <string>
//Declaraci�n de variable constante
#define N 5

using namespace std;


/*
	Declaraci�n de estructura para almacenar datos del Empleado.
	Emp[]: Se declara al final un arreglo de tipo estructura, con el tama�o de N.
	*ptr_Emp: Puntero de tipo arreglo de estructura declarado anteriormente.
	
*/
struct empleado{
	int codigo;
	string nombre;
	int edad;
	int puesto;
	float salario;
}emp[N], *ptr_emp = emp; //Asigna la primera posici�n del arreglo emp[] al puntero.

//Ingreso de datos
void ingresoDatos(){
	//Declaraci�n de variable para iteraci�n en ciclo
	int i;
	
	//Ingreso de datos seg�n la posici�n del campo en la estructura utilizando el puntero.
	for(i = 0; i < N; i++){
		//Limpiar pantalla
		system("CLS");
		
		cout << "Ingrese codigo de empleado:" << endl;
		cin >> (ptr_emp +i) -> codigo;
		
		cout << "Ingrese nombre de empleado:" << endl;
		cin.ignore();
		getline(cin, (ptr_emp +i)-> nombre);
		
		cout << "Ingrese edad de empleado:" << endl;
		cin >> (ptr_emp +i)-> edad;
		
		cout << "Ingrese puesto de empleado:" << endl;
		cin >> (ptr_emp +i)-> puesto;
		
		cout << "Ingrese salario de empleado:" << endl;
		cin >> (ptr_emp +i)-> salario;
	}
}

//Calculo de planilla
/*
	Recibe como referencia el puntero de tipo estructura
*/
void calculoPlanilla(empleado* punteroEmpleado){
	//Declaraci�n de variable para recorrer la estructura
	int i;
	//Declaraci�n de variable para determinar la posici�n
	int posicion;
	//Declaraci�n de variable para guardar quien es mayor y el total de la planilla
	float mayorSalario = 0.00, total = 0.00;
	
	//Ciclo para recorrer la estructura
	for (i = 0; i < N; i++){
		//Si el salario es mayor a la variable mayorSalario, el salario se almacena en la variable mayorSalario
		if((punteroEmpleado+i)-> salario > mayorSalario){
			mayorSalario = (punteroEmpleado+1)-> salario;
			posicion = i;
		}
		
		//Suma de planilla
		total += (punteroEmpleado+i)-> salario;
	}
	
	cout << "El empleado que posee mayor salario es: " << (punteroEmpleado + posicion)->nombre << endl;
	cout << "Con un salario de: " << (punteroEmpleado + posicion) -> salario << endl;
	cout << "Total planilla: Q." << total << endl;
}

//Programa principal
int main(){
	ingresoDatos();
	calculoPlanilla(ptr_emp);
	return 0;
}
