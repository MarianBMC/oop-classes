#include <iostream>
#include <string>
using namespace std;
/*clasa + exemple alege atribute
incapsulare (mmetode accesor)
constructor + siutatuii de apel+ sizeof
char-> string
meth de prelucrare
meth de afisare

atribute + metode*/

struct Data
{
	int zi;
	int luna;
	int an;
};

enum Disciplina
{
	POO,
	BAZA_DE_DATE,
	MICROSTATISTICA
};

class Proiect
{
private:
	Data deadline;
	char nume[20];
	//char disciplina[20];
	Disciplina disciplina;
	int nrPuncte;
	string titlu;
	//list de cerinte
	//char listaCerinte[10][20];//vector de siruri de caractere
	//int nrCerinte;
	// 
	//SAU
	// 
	//char** ListaCerinte;//vector de pointeri la siruri de caractere
	//int nrCerinte2;
	// 
	//SAU
	string* listaCerinte;//vector de siruri de caractere
	int nrCerinte;
	bool esteObligatoriu;

public:
	Proiect()
	{
		cout << "\nApel constructor fara parametri";
	}
	void afisare()
	{
		cout << "\nDeadLine: ";
		cout << deadline.zi << "." << deadline.luna << "." << deadline.an;
		cout << "\nTitlu proiect: " << titlu;
		cout << "\nDisciplina: " << disciplina;
		cout << "\nNumar puncte: " << nrPuncte;
		for (int i = 0; i < nrCerinte; i++)
		{
			cout << "\nCerinta " << i + 1 << ": " << listaCerinte[i];
		}
		cout << "\nEste obligatoriu: " << esteObligatoriu;
	}

	//meteodelor accesor (get si set)
	string getTitlu()
	{
		return titlu;
	}

	void setTitlu(string titluNou)
	{
		if (titluNou.size() > 0)
			titlu = titluNou;
	}

	void setNrPuncte(int nrPuncteNou)
	{
		if (nrPuncteNou > 0)
			nrPuncte = nrPuncteNou;
	}

	int getNrPuncte()
	{
		return nrPuncte;
	}
};

int main()
{
	Proiect p;
	string sir;
	p.afisare();
	cout << "\n-----METH ACCESOR-------";
	cout << "\nTitlu proiect: " << p.getTitlu();
	cout << "\nNumar puncte: " << p.getNrPuncte();
	p.setTitlu("Tema 1 POO");
	p.setNrPuncte(10);
	cout << "\nTitlu proiect: " << p.getTitlu();
	cout << "\nNumar puncte: " << p.getNrPuncte();

	cout << "\n-------VERIFICARE INCAPSULARE-------";
	cout << endl << p.getTitlu();
	p.setTitlu("Titlu nou");
	cout << endl << p.getTitlu();
	string titlu = p.getTitlu();
	cout << "\nTitlu prin variabila string: " << titlu;
	titlu = "Am schimabt titlul: ";
	cout << "\nTitlu prin variabila string dupa shcimbare: " << titlu;
	cout << "\nTitlu prin metoda getTitlu: " << p.getTitlu();

	cout << "\n-------Apel constructor-------";

	Proiect pr;
	cout << endl << sizeof(pr);
	Proiect* ppr;
	ppr = new Proiect();
	cout << endl << sizeof(*ppr);
	return 0;
}