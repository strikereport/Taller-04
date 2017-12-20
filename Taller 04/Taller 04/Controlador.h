#pragma once
class Controlador
{
public:
	Controlador();
	~Controlador();
	int ValidarNumeroOpcion();
	void LeerArchivo();
	void heapSortS();
	void heapSort(int [], int );
	void heap(int [],int n, int i);
	void Imprimir();
	void quickSortS();
	void quickSort(int [],int bajo, int alto);
	void swaps(int*, int*);
	int particion(int[],int bajo, int alto);
	void quickSortP();
	int validarNumero();
	void quickSortHilos(int arr[], int bajo, int alto, int nHilos);
	void copiar(int []);
	void reinicio(int arr[], int copia[]);
};

