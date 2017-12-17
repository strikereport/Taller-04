#include "Controlador.h"
#include <iostream>
#include <ctime> 
using namespace std;
int arr[] = { 1254,1253,5,3,9,6,7,1,15,21,13 };
int n = sizeof(arr) / sizeof(arr[0]);

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

void Controlador::Imprimirarreglo(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void Controlador::HeapsortSecuencial(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heap(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heap(arr, i, 0);
	}
}

void Controlador::HeapsortParalelo()
{
}

void Controlador::QuickSortS()
{
	cout << "Nombre del algoritmo utilizado : Heapsort Secuencial" << endl;
	cout << "Numero de datos del arreglo" << " " << endl;
	cout << "Arreglo Original" << endl;
	Imprimirarreglo(arr, n);
	unsigned t0, t1;
	t0 = clock();
	QuickSortSecuencial(arr, 0, n - 1);
	t1 = clock();
	double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Arreglo ordenado" << endl;
	Imprimirarreglo(arr, n);
	cout << "tiempo que demoro el ordenamiento" << "  " << tiempo << endl;
	system("pause");
}

void Controlador::HeapsortS()
{
	cout << "Nombre del algoritmo utilizado : Heapsort Secuencial" << endl;
	cout << "Numero de datos del arreglo" << " " << endl;
	cout << "Arreglo Original" << endl;
	Imprimirarreglo(arr, n);
	unsigned t0, t1;
	t0 = clock();
	HeapsortSecuencial(arr, n);
	t1 = clock();
	double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << "Arreglo ordenado" << endl;
	Imprimirarreglo(arr, n);
	cout << "tiempo que demoro el ordenamiento" <<"  "<< tiempo << endl;
	system("pause");
}

void Controlador::QuickSortSecuencial(int arr[], int bajo, int alto)
{
	if (bajo < alto)
	{
		// referenciaParticion es donde se particiona la referencia
		//arr ahora está en el lugar correcto
		int referenciaParticion = particion(arr, bajo, alto);

		// separadamente elementos ordenados antes
		// partición y luego prtición
		QuickSortSecuencial(arr, bajo, referenciaParticion - 1);
		QuickSortSecuencial(arr, referenciaParticion + 1, alto);
	}
}

void Controlador::QuickSortParalelo()
{
}

void Controlador::heap(int arr[], int n, int i)
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

void Controlador::swapquick(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int Controlador::particion(int arr[], int bajo, int alto)
{
	int pivote = arr[alto];    // pivote
	int i = (bajo - 1);  // referencia al más pequeño elemento

	for (int j = bajo; j <= alto - 1; j++)
	{
		// si el elemento actual es iguaal o más pequeño que el pivote
		if (arr[j] <= pivote)
		{
			i++;    // se le suma 1 a la referencia
			swapquick(&arr[i], &arr[j]); //intercambiar
		}
	}
	swapquick(&arr[i + 1], &arr[alto]); //intercambiar
	return (i + 1);
}

void Controlador::LeerArchivo()
{
}
