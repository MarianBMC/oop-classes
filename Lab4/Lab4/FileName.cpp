#include <iostream>
using namespace std;

/*
fct globala
get si set pe vector + pastrare incapsulare
met de afisare
constructor
*/

class Produs
{

private:
	string denumire = "Anonim";
	int stoc = 0;
	float* preturi = nullptr;//istoricul preturilor ( diferite de la unul la altul )
	int nrPreturi = 0;
public:
	Produs(string _denumire, int _stoc, float _pret)
	{
		if (_denumire.size() >= 3)
		{
			this->denumire = _denumire;
		}
		if (_stoc > 0)
		{
			this->stoc = _stoc;
		}
		if (_pret > 0)
		{
			this->nrPreturi = 1;
			this->preturi = new float[this->nrPreturi];
			this->preturi[0] = _pret;
		}

	}
	void afisare()
	{
		cout << "Produs: " << this->denumire << "\nstoc: " << this->stoc << "\nistoric preturi: ";
		for (int i = 0; i < this->nrPreturi; i++)
			cout << this->preturi[i] << ", ";
	}
	void setStoc(int _stoc)
	{
		if (stoc > 0)
		{
			this->stoc = _stoc;
		}
	}
	void setPret(float _pret)
	{
		if (_pret > 0 && this->preturi != nullptr && _pret != this->preturi[this->nrPreturi - 1])
		{
			float* aux = new float[this->nrPreturi + 1];
			for (int i = 0;i < this->nrPreturi;i++) {
				aux[i] = this->preturi[i];
			}
			aux[this->nrPreturi] = _pret;
			delete[] this->preturi;
			this->preturi = aux;
			this->nrPreturi++;
		}
	}///cautam greseli in aceasta implementare

	int getPret(int index)
	{
		if (index >= 0 && index < this->nrPreturi)
		{
			return this->preturi[index];
		}
		return -1;
	}
};

int main()
{
	Produs p1("Lamaie", 20, 10);
	p1.afisare();
	p1.setStoc(25);
	p1.afisare();
	p1.setPret(21);
	p1.afisare();
	p1.setPret(21);
	p1.afisare();
	p1.setPret(20);
	p1.afisare();
	p1.setPret(-5);
	p1.afisare();
	cout << endl << p1.getPret(0);
	return 0;

	//tema getPreturi(); care sa respecte incapsulare
	//meth care elimina pretul sub pretul mediu
	//meth care eliminca primele k preturi
}