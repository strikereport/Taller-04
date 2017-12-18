#pragma once
class Controlador
{
public:
	Controlador();
	~Controlador();
	int ValidarNumeroOpcion();
	void Imprimirarreglo(vector<int>);
	void HeapsortSecuencial(int[], int);
	void HeapsortParalelo();
	void QuickSortS();
	void HeapsortS();
	void QuickSortSecuencial(vector<int>, int, int);
	void QuickSortParalelo();
	void heap(int[], int, int);
	void swapquick(int*, int*);
	int particion(vector<int>, int, int);
	void LeerArchivo();
};

