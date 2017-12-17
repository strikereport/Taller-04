#pragma once
class Controlador
{
public:
	Controlador();
	~Controlador();
	int ValidarNumeroOpcion();
	void Imprimirarreglo(int [], int);
	void HeapsortSecuencial(int[], int);
	void HeapsortParalelo();
	void QuickSortS();
	void HeapsortS();
	void QuickSortSecuencial(int[], int, int);
	void QuickSortParalelo();
	void heap(int[], int, int);
	void swapquick(int*, int*);
	int particion(int[], int, int);
	void LeerArchivo();
};

