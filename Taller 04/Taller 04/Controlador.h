#pragma once
class Controlador
{
public:
	Controlador();
	~Controlador();
	int ValidarNumeroOpcion();
	void HeapsortSecuencial(int[], int);
	void HeapsortParalelo();
	void QuickSortSecuencial(int[], int, int);
	void QuickSortParalelo();
	void heap(int[], int, int);
	void swapquick(int*, int*);
	int particion(int[], int, int);
};

