#include <iostream>
#include <string>

using namespace std;

class Produs
{
	string denumire = "-";
	float pret = 0;
	int stoc = 0;

public:
	Produs(string _denumire, float _pret, int _stoc) {
		this->denumire = _denumire;
		if (_pret > 0) {
			this->pret = _pret;
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
	}

	void afisare()
	{
		cout << "\nProdus " << this->denumire << ", pret " << this->pret << ", stoc " << this->stoc;
	}

	bool operator>(Produs p, int x)
	{

	}

	Produs()
	{

	}
};

int main()
{
	Produs p1("stilou", 450, 10);
	p1.afisare();
	Produs p2 = p1;
	p2.afisare();
	Produs p3;
	p3 = p2;
	p3.afisare();
	p3 = p2 = p1;
	p1.afisare();

	if (p1 > 10)
	{
		cout << "\nCeva";
	}
	else
	{
		cout << "\Altceva";
	}
	/*p1 += 5;
	p1++;
	++p1;
	p1=p2+10
	float pret = p1;
	int stoc = (int)p1;*/
	return 0;
}