#include <iostream>
#include <cstring>

using namespace std;

enum Categorie
{
	ALIMENTAR, NEALIMENTAR
};

class Produs
{
private:
	string denumire="-";
	int stoc=0;
	int nrAproxizionari = 0;
	int* cantitate = nullptr;
	int categorie = ALIMENTAR;

public:
	Produs(string _denumire, int _stoc, int _nrAproxizionari, int* _cantitate, int _categorie)
	{
		this->denumire = _denumire;
		this->stoc = _stoc;
		this->nrAproxizionari = _nrAproxizionari;
		this->cantitate = new int[this->nrAproxizionari];
		for (int i = 0; i < this->nrAproxizionari; i++)
		{
			if (_cantitate[i] > 0 && _cantitate[i] <= 100)
			{
				this->cantitate[i] = _cantitate[i];
			}
			else
				this->cantitate[i] = 1;
		}
		this->categorie = _categorie;


	}
	
};

int main()
{

}