#include "Vista.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int arr[] = { 1254,1253,5,3,9,6,7,1,15,21,13 };
int n = sizeof(arr) / sizeof(arr[0]);

Vista::Vista()
{
}


Vista::~Vista()
{
}

void Vista::MenuPrincipal()
{
	cout << " Este es el taller 04" << endl << endl;
	//declaramos una variable para seleccionar la opcion elegida
	int opcion = 0;
	//iniciamos el menu principal
	while (opcion != -1)
	{
		//limpiamos el valor de la opcion cada vez que se reinicie el menu
		cin.clear();
		//desplegamos el menu por pantalla
		cout << " Menu Principal" << endl << endl;
		cout << "[1] Ordenar Arreglo  " << endl;
		cout << "[2] Salir " << endl;
		//validamos que la opcion sea un numero
		opcion = Ejecutar.ValidarNumeroOpcion();
		//luego de validar, nos dirigimos a la opcion seleccioanda
		switch (opcion)
		{
		case 1:
			//limpiamos la pantalla
			system("cls");
			//nos vamos al menu de arreglo
			MenuArreglo();
			break;
		case 2:
			//limpiamos la pantalla
			system("cls");
			//cambiamos la condicion para salir
			opcion = -1;
			//damos el mensaje de despedida
			cout << "Gracias por acceder a nuestro sistema, Hasta pronto" << endl;
			system("pause");
			break;
		default:
			//en caso que sea otra opcion no listada, dar un mensaje y se repite el proceso
			cout << "Error: Ingrese opcion valida" << endl;
			system("pause");
			break;
		}// termino del switch
		 //limpiamos la pantalla
		system("cls");
	}//termino del while
	 //para finalizar el programa
	exit(0);
}

void Vista::MenuArreglo()
{
	int opcion = 0;
	//iniciamos el menu principal
	while (opcion != -1)
	{
		//limpiamos el valor de la opcion cada vez que se reinicie el menu
		cin.clear();
		//desplegamos el menu por pantalla
		cout << " Menu  de arreglo" << endl << endl;
		cout << "[1] Algoritmo quicksort secuencial  " << endl;
		cout << "[1] Algoritmo quicksort con paralelismo  " << endl;
		cout << "[1] Algoritmo heapsort secuencial " << endl;
		cout << "[1] Algoritmo heapsort con paralelismo  " << endl;
		cout << "[5] Regresar al menu Principal " << endl;
		//validamos que la opcion sea un numero
		opcion = Ejecutar.ValidarNumeroOpcion();
		//luego de validar, nos dirigimos a la opcion seleccioanda
		switch (opcion)
		{
		case 1:
			//limpiamos la pantalla
			system("cls");
			Ejecutar.QuickSortSecuencial(arr, 0, n - 1);
			break;
		case 2:
			//limpiamos la pantalla
			system("cls");
			Ejecutar.QuickSortParalelo();
			break;
		case 3:
			//limpiamos la pantalla
			system("cls");
			Ejecutar.HeapsortSecuencial(arr, n);
			break;
		case 4:
			Ejecutar.HeapsortParalelo();
			//limpiamos la pantalla
			system("cls");
			break;
		case 5:
			//cambiamos la condicion para salir
			opcion = -1;
			break;
		default:
			//en caso que sea otra opcion no listada, dar un mensaje y se repite el proceso
			cout << "Error: Ingrese opcion valida" << endl;
			system("pause");
			break;
		}// termino del switch
		 //limpiamos la pantalla
		system("cls");
	}//termino del while
}
