#include "Controlador.h"
#include <time.h> 
#include <stdio.h> 
#include <dos.h> 
#include <thread>
#include <iostream>
#include <ctime> 
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int * arr = NULL;
int * copia = NULL;
int tamanio = 0;

Controlador::Controlador()
{
}

Controlador::~Controlador()
{
}

int Controlador::ValidarNumeroOpcion()
{
	//creamos variables locales
	int dato = 0;
	bool continuar;
	int cont = 0;
	do {
		continuar = false;
		cin.clear();
		if (cont > 0)cin.ignore(1024, '\n');
		{
			cout << "Ingrese un opcion" << endl;
			cin >> dato;
			cont++;
		}
		if (cin.fail() && cin.rdstate()) {
			//limpiamos la pantalla
			system("cls");
			//mandamos un mensaje de error
			cout << "Ingreso un caracter no valido, Ingrese Nuevamente un numero" << endl << endl;
			//continuamos hasta obtener un numero
			continuar = true;
		}
	} while (continuar == true);
	//si es un numero se retorna
	return dato;
}

void Controlador::LeerArchivo()
{
	// asignamos el archivo astronauta para su lectura
	ifstream archivoDatos("datos.txt");
	//verificamos que el archivo astronauta exista
	if (!archivoDatos) {
		// si no existe, lanza un mensaje de error y se termina la ejecucion
		cout << " El archivo datos no existe" << endl;
		// se realiza una pausa para que lea el mensaje
		system("pause");
		// se termina la ejecucion del programa
		exit(0);
	}
	//verificamos el peso del archivo
	archivoDatos.seekg(0, ios::end);
	//determinamos que el archivo se encuentra vacio
	if (archivoDatos.tellg() < 1) {
		// si no existe, lanza un mensaje de error y se termina la ejecucion
		cout << " El archivo Datos se encuentra vacio" << endl;
		// se realiza una pausa para que lea el mensaje
		system("pause");
		// se termina la ejecucion del programa
		exit(0);
	}
	//regresamos el apuntador al inicio
	archivoDatos.seekg(0, ios::beg);
	string valor;
	while (!archivoDatos.eof()) {
		getline(archivoDatos, valor, ',');
		tamanio++;
	}
	// cerramos el archivo
	archivoDatos.close();
	//creamos el arreglo 
	arr = new int[tamanio];
	int i = 0;
	ifstream archivoDatos2("datos.txt");
	while (!archivoDatos2.eof()) {
		getline(archivoDatos2, valor, ',');
		arr[i] = stoi(valor);
		i++;
	}
	// cerramos el archivo
	archivoDatos2.close();
	copia = new int[tamanio];
}

void Controlador::heapSortS()
{
	cout << "nombre del algoritmo utilizado: HeapSort Secuencial" << endl;
	cout << "numero de datos del arreglo " << tamanio << endl;
	cout << "arreglo original" << endl;
	Imprimir();
	copiar(arr);
	clock_t tiempo = clock();
	double time_used;
	heapSort(arr, tamanio);
	cout << "arreglo ordenado" << endl;
	Imprimir();
	time_used = ((double)(clock() - tiempo) / 1000);
	cout << "tiempo que demoro el ordenamiento " << time_used << " segundos"<< endl;
	reinicio(arr, copia);
	system("pause");
}

void Controlador::heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heap(arr, i, 0);
	}
}

void Controlador::heap(int arr[],int n, int i)
{
	int masGrande = i;  // masGrande como raíz
	int izq = 2 * i + 1;  // izquierdo = 2*i + 1
	int der = 2 * i + 2;  // derecho = 2*i + 2

						  // si el hijo izquierdo es más grande que la raíz
	if (izq < n && arr[izq] > arr[masGrande]) {
		masGrande = izq;
	}
	// si el hijo izquierdo es más grande
	if (der < n && arr[der] > arr[masGrande]) {
		masGrande = der;
	}
	// si el mas grande no es la raíz
	if (masGrande != i)
	{
		swap(arr[i], arr[masGrande]);

		// llamada recuriva a heap para los subarboles
		heap(arr, n, masGrande);
	}
}

void Controlador::Imprimir()
{
	for (int i = 0; i<tamanio; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void Controlador::quickSortS()
{
	cout << "nombre del algoritmo utilizado: quickSort secuencial" << endl;
	cout << "numero de datos del arreglo " << tamanio << endl;
	cout << "arreglo original" << endl;
	Imprimir();
	copiar(arr);
	clock_t tiempo = clock();
	double time_used;
	quickSort(arr, 0, tamanio - 1);
	cout << "arreglo ordenado" << endl;
	Imprimir();
	time_used = ((double)(clock() - tiempo) / 1000);
	cout << "tiempo que demoro el ordenamiento " << time_used << " segundos" << endl;
	reinicio(arr, copia);
	system("pause");
}

void Controlador::quickSort(int arr[],int bajo, int alto)
{
	if (bajo < alto)
	{
		// referenciaParticion es donde se particiona la referencia
		//arr ahora está en el lugar correcto
		int referenciaParticion = particion(arr, bajo, alto);

		// separadamente elementos ordenados antes
		// partición y luego prtición
		quickSort(arr, bajo, referenciaParticion - 1);
		quickSort(arr, referenciaParticion + 1, alto);
	}
}

void Controlador::swaps(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Controlador::particion(int arr[],int bajo, int alto)
{
	int pivote = arr[alto];    // pivote
	int i = (bajo - 1);  // referencia al más pequeño elemento

	for (int j = bajo; j <= alto - 1; j++)
	{
		// si el elemento actual es iguaal o más pequeño que el pivote
		if (arr[j] <= pivote)
		{
			i++;    // se le suma 1 a la referencia
			swaps(&arr[i], &arr[j]); //intercambiar
		}
	}
	swaps(&arr[i + 1], &arr[alto]); //intercambiar
	return (i + 1);
}

void Controlador::quickSortP()
{
	cout << "nombre del algoritmo utilizado: quickSort en paralelo" << endl;
	cout << "numero de datos del arreglo " << tamanio << endl;
	cout << "arreglo original" << endl;
	Imprimir();
	copiar(arr);
	double time_used;
	int hilos = validarNumero();
	cout << "numero de hilos ocupados " << hilos << endl;
	clock_t tiempo = clock();
	quickSortHilos(arr, 0, tamanio - 1, hilos);
	cout << "arreglo ordenado" << endl;
	Imprimir();
	time_used = ((double)(clock() - tiempo) / 1000);
	cout << "tiempo que demoro el ordenamiento " << time_used << " segundos" << endl;
	reinicio(arr, copia);
	system("pause");
}

int Controlador::validarNumero()
{
	//creamos variables locales
	int dato = 0;
	bool continuar;
	int cont = 0;
	do {
		continuar = false;
		cin.clear();
		if (cont > 0)cin.ignore(1024, '\n');
		{
			cout << "Ingrese un numero" << endl;
			cin >> dato;
			cont++;
		}
		if (cin.fail() && cin.rdstate() ) {
			//limpiamos la pantalla
			system("cls");
			//mandamos un mensaje de error
			cout << "Ingreso un caracter no valido, Ingrese Nuevamente un numero" << endl << endl;
			//continuamos hasta obtener un numero
			continuar = true;
		}
		else {
			if (dato < 2) {
				//limpiamos la pantalla
				system("cls");
				//mandamos un mensaje de error
				cout << "Ingreso un numero de hilos bajo, Ingrese Nuevamente un numero" << endl << endl;
				//continuamos hasta obtener un numero
				continuar = true;
			}
		}
	} while (continuar == true && dato < 2);
	//si es un numero se retorna
	return dato;
}

void Controlador::quickSortHilos(int arr[], int bajo, int alto, int nHilos)
{
	if (bajo < alto)
	{
		// referenciaParticion es donde se particiona la referencia
		//arr ahora está en el lugar correcto
		int referenciaParticion = particion(arr, bajo, alto);
		if (nHilos > 0) {
			thread h1([&] {quickSortHilos(ref(arr), bajo, alto, nHilos - 1); });
			thread h2([&] {quickSortHilos(ref(arr), bajo, alto, nHilos - 1); });
			h1.join();
			h2.join();
		}
		else {
			// separadamente elementos ordenados antes
			// partición y luego prtición
			quickSort(arr, bajo, referenciaParticion - 1);
			quickSort(arr, referenciaParticion + 1, alto);
		}
	}
}

void Controlador::copiar(int arr[])
{
	for (int i = 0; i < tamanio; i++) {
		copia[i] = arr[i];
	}
}

void Controlador::reinicio(int arr[], int copia[])
{
	for (int i = 0; i < tamanio; i++) {
		arr[i] = copia[i];
	}
}

void Controlador::heapSortP()
{
	cout << "nombre del algoritmo utilizado: heapSort en paralelo" << endl;
	cout << "numero de datos del arreglo " << tamanio << endl;
	cout << "arreglo original" << endl;
	Imprimir();
	copiar(arr);
	double time_used;
	int hilos = validarNumero();
	cout << "numero de hilos ocupados " << hilos << endl;
	clock_t tiempo = clock();
	heapSortHilos(arr,tamanio, hilos);
	cout << "arreglo ordenado" << endl;
	Imprimir();
	time_used = ((double)(clock() - tiempo) / 1000);
	cout << "tiempo que demoro el ordenamiento " << time_used << " segundos" << endl;
	reinicio(arr, copia);
	system("pause");
}

void Controlador::heapSortHilos(int arr[], int n, int nHilos)
{
	if (nHilos > 0) {
		thread h1([&] {heapSortHilos(ref(arr), n, nHilos - 1); });
		thread h2([&] {heapSortHilos(ref(arr), n, nHilos - 1); });
		h1.join();
		h2.join();
	}
	else {
		for (int i = n / 2 - 1; i >= 0; i--)
			heap(arr, n, i);

		for (int i = n - 1; i >= 0; i--)
		{
			swap(arr[0], arr[i]);
			heap(arr, i, 0);
		}
	}
}

void Controlador::borrar()
{
	delete[]arr;
	delete[]copia;
}




