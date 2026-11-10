///SUBIECT 7-Angajat
#include <iostream>
#include <string>

using namespace std;

class Angajat
{
private:
	string nume = "-";
	int nrLuni = 0;
	int* oreLucrate = nullptr;
	int nrMinimOreLucrate = 0;
	double tarifOraSuplimentara = 0;
	double salariuBaza = 0;

public:
	Angajat(string _nume, int _nrLuni, int* _oreLucrate, int _nrMinimOreLucrate,
		double _tarifOraSuplimentara, double _salariuBaza)
	{
		this->nume = _nume;
		this->salariuBaza = _salariuBaza;
		this->tarifOraSuplimentara = _tarifOraSuplimentara;
		this->nrMinimOreLucrate = _nrMinimOreLucrate;

		if (_nrLuni > 0 && _oreLucrate != nullptr)
		{
			this->nrLuni = _nrLuni;
			this->oreLucrate = new int[this->nrLuni];
			for (int i = 0; i < this->nrLuni; i++)
			{
				if (_oreLucrate[i] >= this->nrMinimOreLucrate && _oreLucrate[i] <= 360)
				{
					this->oreLucrate[i] = _oreLucrate[i];
				}
				else
				{
					if (i == 0)
					{
						this->oreLucrate[i] = this->nrMinimOreLucrate;

					}
					else
					{
						int minim = this->oreLucrate[0];
						for (int j = 0; j < i; j++)
						{
							if (this->oreLucrate[j] < minim)
							{
								minim = this->oreLucrate[j];
							}
						}
						this->oreLucrate[i] = minim;
					}
				}
			}
		}
	}

	void afisare()
	{
		cout << "\nNume: " << this->nume;
		cout << "\nNr Luni: " << this->nrLuni;
		cout << "\nOre lucrate: ";
		for (int i = 0; i < this->nrLuni; i++)
		{
			cout << this->oreLucrate[i] << ", ";
		}
		cout << "\nNr. min ore lucrate: " << this->nrMinimOreLucrate;
		cout << "\nTarif: " << this->tarifOraSuplimentara;
		cout << "\nSalariu: " << this->salariuBaza;
		cout << "\nSalariul suplimentar este: " << calcSalariuSuplimentar();
	}

	float calcSalariuSuplimentar() const
	{
		int oreSuplimentare = 0;
		double salariuSuplimentar = 0;
		for (int i = 0; i < nrLuni; i++)
		{
			oreSuplimentare += this->oreLucrate[i] - this->nrMinimOreLucrate;
		}
		salariuSuplimentar = oreSuplimentare * this->tarifOraSuplimentara;
		return salariuSuplimentar;
	}

	void adaugareKLuni(int k)
	{
		int* aux = new int[this->nrLuni + k];

		for (int i = 0; i < this->nrLuni; i++)
		{
			aux[i] = this->oreLucrate[i];
		}
		for (int i = this->nrLuni; i < this->nrLuni + k; i++)
		{
			aux[i] = this->nrMinimOreLucrate;
		}
		delete[] this->oreLucrate;
		this->oreLucrate = aux;
		this->nrLuni += k;
	}
};

int main()
{
	int ore[] = { 210, 100, 160 };
	Angajat a1("Andrei", 3, ore, 100, 10, 2000);
	a1.afisare();
	a1.adaugareKLuni(3);
	a1.afisare();
	return 0;
}