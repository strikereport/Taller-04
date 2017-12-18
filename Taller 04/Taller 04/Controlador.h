#pragma once
class Controlador
{
public:
	Controlador();
	~Controlador();
	int ValidarNumeroOpcion();
	void LeerArchivo();
	void heapSortS();
	void heapSort();
	void heap(int n, int i);
	void Imprimir();
	void quickSortS();
	void quickSort(int bajo, int alto);
	void swaps(int*, int*);
	int particion(int bajo, int alto);
};

