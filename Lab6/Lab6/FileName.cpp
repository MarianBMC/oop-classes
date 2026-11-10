#include <iostream>

using namespace std;

//const si static
//functii globale
// p->afisare() adica se face deferientierea lui p
//(&p).afisare();

class Proiect {
	const int id;
	const string denumire;
	int nrEtape = 0;
	float* bugetEtape = nullptr;
	static string numeCompanie; // devine var globala de o alta natura, cum e si la enumeratie doar ca e ascuns cumva stii, nu ii sunt alocati octetii momentan

public:

	Proiect() : id(0), denumire("") {

	}

	Proiect(int _id, string _denumire, int _nrEtape, float* _bugetEtape) :id(_id), // nu primim ca parametru var statice ca ele sunt in constructor si nu au treaba 
		denumire(_denumire) {


		if (_nrEtape > 0 && _bugetEtape != nullptr) {
			this->nrEtape = _nrEtape;
			this->bugetEtape = new float[this->nrEtape];
			for (int i = 0;i < this->nrEtape;i++) {
				this->bugetEtape[i] = _bugetEtape[i];
			}
		}
	}
	void afisare() {
		cout << "\nId: " << this->id << "\nDenumire: " << this->denumire << "\nNr etape: " << this->nrEtape <<
			"\nBuget etape: ";
		for (int i = 0; i < this->nrEtape; i++)
		{
			cout << this->bugetEtape[i] << " ";
		}
	}
	//metoda statica nu are this pentru ca nu are obiect
	static string getNumeCompanie() { //const protejeaza this deci nu are sens aici
		return Proiect::numeCompanie;
	}

	static void setNumeCompanie(string _numeCompanie) { // de ex daca vr sa schimb numele companiei asta fac si modific cu ajutorul clasei
		Proiect::numeCompanie = _numeCompanie;
	}
	float getTotalBuget() const {
		float total = 0;
		for (int i = 0;i < this->nrEtape;i++) {
			total += this->bugetEtape[i];
		}
		return total;
	}

	string getDenumire()const{
		return this->denumire;
	}
		
};

//fvt globala
string getDenumireProiectBugetMaxim(Proiect v[], int n)//vector de proiecte  care necesita constructor fara parametri obligat fortat,pleaca de la obiecte goale
{
	float bugetMax = 0;
	string denumireMax;
	for (int i = 0;i < n;i++) {
		if (v[i].getTotalBuget() > bugetMax) {
			bugetMax = v[i].getTotalBuget();
			denumireMax = v[i].getDenumire();
		}
	}
	return"";
}

string Proiect::numeCompanie = "ABC";//declarare var globala,membru static pentru clasa

int main()
{
	//Proiect v[10]; //declarare vector de proiecte
	float* bugete = new float[5];
	for (int i = 0;i < 5;i++) {
		bugete[i] = 100 * i + 1000;
	}
	Proiect p1(1, "Proiect", 5, bugete);

	p1.afisare();

	cout << endl << Proiect::getNumeCompanie();
	cout << endl << getDenumireProiectBugetMaxim;
	return 0;
}