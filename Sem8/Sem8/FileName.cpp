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

	bool operator>(int x) const
	{
		//if (this->pret > x)
		//{
		//	return true;
		//}
		//return false;
		return this->pret > x;
	}

	Produs& operator+=(int x)
	{
		this->stoc += x;
		return *this;
	}

	Produs& operator+=(const Produs& p)
	{
		//this->stoc = p.stoc;
		//this->operator+=(p.stoc);
		*this += p.stoc;
		return *this;
	}

	Produs()
	{

	}
	
	///forma de preincrementare
	Produs& operator++()
	{
		this->stoc++;
		return *this;
	}

	//forma d epostincremetnare
	Produs& operator++(int)
	{
		this->stoc++;
		return *this;
	}
	bool operator!()
	{
		return this->stoc == 0;
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
		cout << "\neste mai mare ca 10";
	}
	else
	{
		cout << "\mai mic decat 10";
	}
	p1 += 5;//adaugam 5 la stoc
	
	/*p1
	
	p1=p2+10
	float pret = p1;
	int stoc = (int)p1;*/
	p1.afisare();

	p1=p2+=10;
	p1.afisare();
	p1 += p2 += 10;
	p1.afisare();
	++p1;//se adauga o unitate la stoc
	p1.afisare();
	cout << "\n------------++p------------";
	p2=++p1;
	p1.afisare();
	p2.afisare();


	cout << "\n------------p++------------";
	p2=p1++;
	p1.afisare();
	p2.afisare();

	if (!p1)
	{
		cout << "\nceva";
	}
	else
	{
		cout << "\naltceva";
	}
	return 0;
}