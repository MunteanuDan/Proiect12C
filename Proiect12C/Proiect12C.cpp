#include <iostream>
using namespace std;

class Student
{
public:
	//char nume[40];
	char* nume;
private:
	int matricol;
protected:
	float medie;
public:

	Student()
	{
		// urmatoarele 2 linii sunt pt ca nume este pointer
		nume = new char[7];
		strcpy(nume, "Anonim");
		matricol = 0;
		medie = 0;
		cout << "S-a apelat constructorul implicit" << endl;
	}

	Student(const char* n, int nr, float m)
	{
		this->nume = new char[strlen(n) + 1];
		strcpy(nume, n);
		matricol = nr;
		medie = m;
		cout << "S-a apelat constructorul cu parametri" << endl;
	}

	// varianta in care contopim cei 2 constructori de mai sus
	/*Student(const char* n, int nr, float m) : matricol(nr), medie(m)
	{
		strcpy_s(nume, n);
		cout << "S-a apelat constructorul hibrid " << endl;
	}*/

	// constructorul de copiere
	Student(const Student& s)
	{
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		this->matricol = s.matricol;
		this->medie = s.medie;
		cout << "S-a apelat constructorul de copiere " << endl;
	}

	// supraincarcare operator =
	Student& operator=(const Student& s)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		this->matricol = s.matricol;
		this->medie = s.medie;
		cout << "S-a apelat operator=" << endl;
		return *this;

	}

	//DESTRUCTORUL
	~Student()
	{
		delete[] this->nume; // ce este pointer trb dezalocat asa in destructor
		cout << "S-a apelat destructorul " << endl;
	}

	void init(const char* n = "Anonim", int nr = 0, float m = 0)
	{
		strcpy(nume, n);
		matricol = nr;
		medie = m;
	}

	char* returneaza_nume()
	{
		return this->nume;
	}

	void modifica_nume(char* n)
	{
		strcpy(this->nume, n);
	}

	float get_medie()
	{
		if (this->medie > 9)
		{
			return this->medie;
		}
		else
		{
			return 0;
		}
	}

	void set_medie(float m)
	{
		this->medie = m;
	}


	void afiseaza_adresa();

	friend const Student& operator++(Student&);
	friend const Student operator++(Student&, int);

	friend double operator+(Student&, float);
	friend double operator+(float, Student&);
	double operator+(Student& s)
	{
		return this->medie + s.medie;
	}
	friend istream& operator>>(istream&, Student&); // operator de citit
	friend ostream& operator<<(ostream&, Student); // operator de afisare

};

void Student::afiseaza_adresa()
{
	cout << "Adresa obiectului curent este: " << this << endl; // prin this aici luam adresa
}



const Student& operator++(Student& s)
{
	s.medie++;
	return s;
}

const Student operator++(Student& s, int i) // i este doar pt a-i spune compilatorului ca asta este operatorul de postincrementare
{
	Student aux = s;
	s.medie++;
	return aux;
}

double operator+(Student& s, float m)
{
	return s.medie + m;
}

double operator+(float m, Student& s)
{
	return s.medie + m;
}

istream& operator>>(istream& intrare, Student& s)
{
	cout << "Nume: ";
	intrare >> s.nume;
	cout << endl << "Matricol: ";
	intrare >> s.matricol;
	cout << endl << "Medie: ";
	intrare >> s.medie;
	return intrare;
}

ostream& operator<<(ostream& iesire, Student s)
{
	iesire << "Studentul cu matricolul " << s.matricol << " si media " << s.medie << " are numele " << s.nume << endl;
	return iesire;
}

void main()
{
	Student s1;
	Student s2("Andrei", 123, 10);
	//s.init("Andrei", 123, 5);
	cout << s1.nume << endl; // afiseaza anonim
	// s.afiseaza_adresa();
	cout << s2.get_medie() << endl; // afiseaza 10

	// pt a apela constructorul de copiere
	//Student s3 = s2; // putem apela si asa
	Student s3(s2); // putem apela si asa

	// apelare operator =
	Student s4 = s2;
	Student s41;
	s41 = s2;

	cout << "Medie pentru s1 inainte de preincrementare: " << s1.get_medie() << endl;
	++s1;
	cout << "Medie pentru s1 inainte, dupa preincrementare: " << s1.get_medie() << endl;
	Student s5 = ++s1;
	Student s6 = s1++;
	cout << "Diferenta intre preincrementare -> " << s5.get_medie() << " si postincrementare -> " << s6.get_medie() << endl;
	cout << s5 + 2 << endl;
	cout << 3 + s5 << endl;
	cout << s5 + s6 << endl;
	Student s7;
	cin >> s7;
	cout << s7;




	// cu pointer
	Student* ps;
	ps = new Student; // s-a apelat constructorul implicit
	delete ps; // trb sa facem dezalocarea inainte
	ps = new Student("Nume", 1, 10); // s-a apelat constructorul cu parametri
	delete ps;

	//// vector alocat static
	//Student grupa[3];
	//grupa[0] = Student("Nume1", 1, 10);
	//grupa[1] = Student("Nume2", 2, 9.5);
	//grupa[2] = Student("Nume3", 3, 8);

	// vector alocat dinamic
	Student* grupa = new Student[3];
	grupa[0] = Student("Nume1", 1, 10);
	grupa[1] = Student("Nume2", 2, 9.5);
	grupa[2] = Student("Nume3", 3, 8);

	cout << grupa[1].get_medie();





}
