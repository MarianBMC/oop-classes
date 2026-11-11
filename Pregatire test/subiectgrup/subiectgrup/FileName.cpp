#include <iostream>

using namespace std;

class Student {
	string nume = "anonim";
	const int nrMatricol;
	int nrDiscipline = 0;
	int* note = nullptr;
	bool integralist = true;

public:
	Student(string _nume, int _nrMatricol, int _nrDiscipline, int* _note, bool _integralist) :nrMatricol(_nrMatricol) {
		this->nume = _nume;
		this->nrDiscipline = _nrDiscipline;
		this->integralist = _integralist;
		this->note = new int[this->nrDiscipline];
		for (int i = 0; i < this->nrDiscipline; i++) {
			if (_note[i] >= 1 && _note[i] <= 10) {
				this->note[i] = _note[i];
			}
			else if (_note[i] < 1) {
				this->note[i] = 1;
			}
			else {
				this->note[i] = 10;
			}
		}
	}

	int medie() {
		int s = 0;
		int notePeste5 = 0;
		for (int i = 0; i < this->nrDiscipline; i++) {
			if (this->note[i] >= 5) {
				s = s + this->note[i];
				notePeste5++;
			}
		}
		return s / notePeste5;
	}

	void afisare() {
		cout << "Nume: " << this->nume << ", ";
		cout << "Nr Matricol: " << this->nrMatricol << ", ";
		cout << "Nr Discipline: " << this->nrDiscipline << ", ";
		cout << "Integralist: " << this->integralist << ", ";
		int res = 0, cinciSapte = 0, optZece = 0;
		for (int i = 0; i < this->nrDiscipline; i++) {
			if (this->note[i] < 5 ) {
				res++;
			}
			else if (this->note[i] <= 7) {
				cinciSapte++;
			}
			else {
				optZece++;
			}
		}
		cout << "Restante: " << res << " | ";
		cout << "5-7: " << cinciSapte << " | ";
		cout << "8-10: " << optZece;
	}
};

int main()
{
	int note[] = { 3, 11, 0, 5, 7, 9 };
	Student s1("Andrei", 325, 6, note, true);
	s1.afisare();
	return 0;
}