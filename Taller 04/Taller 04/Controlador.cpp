#include "Controlador.h"
#include <time.h>
#include <iostream>
#include <ctime> 
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
vector<int> arr;

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
		//guardamos en el arreglo
		arr.push_back(stoi(valor));
	}
	// cerramos el archivo
	archivoDatos.close();
}

void Controlador::heapSortS()
{
	cout << "nombre del algoritmo utilizado: HeapSort Secuencial" << endl;
	cout << "numero de datos del arreglo " << arr.size() << endl;
	cout << "arreglo original" << endl;
	Imprimir();
	clock_t start, end;
	double time_used;
	start = clock();
	heapSort();
	end = clock();
	cout << "arreglo ordenado" << endl;
	Imprimir();
	time_used = ((double)(end - start) / CLOCKS_PER_SEC);
	cout << "tiempo que demoro el ordenamiento " << time_used * 1000.0 << endl;
	system("pause");
}

void Controlador::heapSort()
{
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heap(arr.size(), i);

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heap(i, 0);
	}
}

void Controlador::heap(int n, int i)
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
		heap(n, masGrande);
	}
}

void Controlador::Imprimir()
{
	for (int i = 0; i<arr.size(); ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void Controlador::quickSortS()
{
	cout << "nombre del algoritmo utilizado: quickSort secuencial" << endl;
	cout << "numero de datos del arreglo " << arr.size() << endl;
	cout << "arreglo original" << endl;
	Imprimir();
	clock_t start, end;
	double time_used;
	start = clock();
	quickSort(0, arr.size() - 1);
	end = clock();
	cout << "arreglo ordenado" << endl;
	Imprimir();
	time_used = ((double)(end - start) / CLOCKS_PER_SEC);
	cout << "tiempo que demoro el ordenamiento " << time_used << endl;
	system("pause");
}

void Controlador::quickSort(int bajo, int alto)
{
	if (bajo < alto)
	{
		// referenciaParticion es donde se particiona la referencia
		//arr ahora está en el lugar correcto
		int referenciaParticion = particion(bajo, alto);

		// separadamente elementos ordenados antes
		// partición y luego prtición
		quickSort(bajo, referenciaParticion - 1);
		quickSort(referenciaParticion + 1, alto);
	}
}

void Controlador::swaps(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Controlador::particion(int bajo, int alto)
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


