#include <iostream>
#include <string>

using namespace std;

enum Combustibil
{
	BENZINA, MOTORINA, GAZ, ELECTRIC
};
class Curier
{
private:
	string numeCurier="-";
	int nrLivrari = 0;
	int* distantaPerLivrare = nullptr;
	int distantaMaxima = 0;
	Combustibil combustibil = GAZ;

public:
	Curier(string _numeCurier, int _nrLivrari, int* _distantaPerLivrare, int _distantaMaxima, int _combustibil)
	{
		this->numeCurier = _numeCurier;
		this->nrLivrari = _nrLivrari;
		this->distantaMaxima = _distantaMaxima;
		int distantaParcursa = 0;
		this->distantaPerLivrare = new int[this->nrLivrari];
		for (int i = 0; i < this->nrLivrari; i++)
		{
			this->distantaPerLivrare[i] = _distantaPerLivrare[i];
			if ((distantaParcursa += _distantaPerLivrare[i])>this->distantaMaxima)
			{
				this->distantaPerLivrare[i] = 0;
			}
			else {
				distantaParcursa += _distantaPerLivrare[i];
			}
		}
	}

	void stergere(int k) {
		int* aux;
		aux = new int[this->nrLivrari - k];

		for (int i = 0;i < this->nrLivrari - k;i++) {
			aux[i] = this->distantaPerLivrare[i];
		}
		delete[] this->distantaPerLivrare;
		this->distantaPerLivrare = aux;
		this->nrLivrari -= k;
	}
};

int main()
{

}
