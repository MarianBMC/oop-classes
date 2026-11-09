#include<iostream>
using namespace std;

//suma

int suma(int* v, int n)
{
	int suma = 0;
	for (int i = 0; i < n; i++)
		suma += v[i];
	return suma;
}

void suma(int* v, int n, int& suma)
{
	suma = 0;
	for (int i = 0; i < n; i++)
		suma += v[i];
}

//fct care elimina ultimul elem din vect
void del_last(int*& v, int& n)
{
	/*delete[] v[n];
	v[n] = nullptr;
	n -= 1;*/
	int m = n - 1;
	int* aux = new int[m];
	for (int i = 0; i < m; i++)
		aux[i] = v[i];
	delete[] v;
	v = aux;//shadowcopy
	n = m;
	/*delete[] aux;
	aux = nullptr; E GRESIT*/
}

int main()
{
	int x = 5, y = 2;
	cout << x / y;

	{
		int v1[20];
	}

	int* v2;
	int n = 5;
	v2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		v2[i] = i + 10;
	}
	// to do pe v2
	delete[] v2;
	v2 = nullptr;

	return 0;
}