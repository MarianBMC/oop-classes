#include<iostream>
#include <string.h>
using namespace std;

int main()
{
	char s1[25];
	cout << s1;
	int x = 5;
	cout << x;
	//s1="Ana";
	//strcpy_s(s1, strlen("Ana"+1), "Ana");
	strcpy_s(s1, strlen("Ana") + 1, "Ana");

	char* ps;//4 sau 8
	cout << endl << s1;//0xcccc
	//cout << endl << ps;//o adresa pe stiva
	cout << endl << &ps;//4
	cout << endl << sizeof(ps);//4
	cout << endl << sizeof(&ps);//1


	ps = s1;//shallow copy
	cout << endl << ps;
	cout << endl << s1;
	s1[1] = 'm';
	s1[2] = 'i';
	cout << endl << ps;
	cout << endl << s1;
	//delete[]ps; dezaloc o adresa de pe stiva, practic asta arata catre s1
	ps = new char[strlen("Gigel") + 1];
	strcpy_s(ps, strlen("Gigel") + 1, "Maria");
	cout << endl << ps;
	delete[] ps;
	//TEM DIN SIRURI
	// avem o lista de prieteni, cate un prieten pe fiecare linie a unei matrice
	//s.s.c prietenii si sa se verifice daca un anume prieten este in lista
	int m1[2][4];
	int** m2;
	m2 = new int* [2];
	for (int i = 0; i < 2; i++) {
		m2[i] = new int[4];
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
			m2[i][j] = i + j + 10;
	}
	for (int i = 0; i < 2; i++)
	{
		delete[] m2[i];
		m2[i] = nullptr;
	}
	delete[]m2;
	m2 = nullptr;

	int m3[4][20];
	int gasit = 0;

	return 0;
}