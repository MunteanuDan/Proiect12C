//#include <iostream>
//using namespace std;
//
//class Student
//{
//public:
//	static int nr_studenti;
//	//char nume[40];
//	char* nume;
//
//	static int IsStudentBursier(Student& s) // pt o functie statica
//	{
//		if (s.medie > 9.5)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//private:
//	const int matricol;
//protected:
//	float medie;
//public:
//	class Catalog
//	{
//	public:
//		int nr_note;
//		int* note;
//		
//		Catalog()
//		{
//			nr_note = 0;
//			note = NULL;
//		}
//
//		Catalog(int* v, int nr) // pt vectori de note
//		{
//			this->nr_note = nr;
//			this->note = new int[nr];
//			for (int i = 0; i < nr; i++)
//			{
//				this->note[i] = v[i];
//			}
//		}
//
//		// constructor de copiere
//		Catalog(Catalog& c)
//		{
//			this->nr_note = c.nr_note;
//			this->note = new int[c.nr_note];
//			for (int i = 0; i < c.nr_note; i++)
//			{
//				this->note[i] = c.note[i];
//			}
//		}
//
//		// destructor
//		~Catalog()
//		{
//			delete[] this->note;
//		}
//
//	} situatie_scolara; //situatie_scolara este un membru public in clasa Student de tip Catalog
//
//
//	Student() : matricol(0)
//	{
//		// urmatoarele 2 linii sunt pt ca nume este pointer
//		nume = new char[7];
//		strcpy(nume, "Anonim");
//	//	matricol = 0;
//		medie = 0;
//		cout << "S-a apelat constructorul implicit" << endl;
//		Student::nr_studenti++;
//	}
//
//	Student(const char* n, int nr, float m) : matricol(nr)
//	{
//		this->nume = new char[strlen(n) + 1];
//		strcpy(nume, n);
//	//	matricol = nr;
//		medie = m;
//		cout << "S-a apelat constructorul cu parametri" << endl;
//		Student::nr_studenti++;
//	}
//
//	// varianta in care contopim cei 2 constructori de mai sus
//	/*Student(const char* n, int nr, float m) : matricol(nr), medie(m)
//	{
//		strcpy_s(nume, n);
//		cout << "S-a apelat constructorul hibrid " << endl;
//	}*/
//
//	// constructorul de copiere
//	Student(const Student& s) : matricol(s.matricol) // daca avem o variabila const, o initializam aici cu :, nu o initializam mai jos in constructor
//	{
//		this->nume = new char[strlen(s.nume) + 1];
//		strcpy(this->nume, s.nume);
//	//	this->matricol = s.matricol;
//		this->medie = s.medie;
//		cout << "S-a apelat constructorul de copiere " << endl;
//		Student::nr_studenti++;
//	}
//
//	//DESTRUCTORUL
//	~Student()
//	{
//		delete[] this->nume; // ce este pointer trb dezalocat asa in destructor
//		cout << "S-a apelat destructorul " << endl;
//		//Student::nr_studenti--;
//	}
//
//	void init(const char* n = "Anonim", int nr = 0, float m = 0)
//	{
//		strcpy(nume, n);
//	//	matricol = nr; // aici l-am comentat deoarece orice membru constant poate fi initializat doar de catre constructor  
//		medie = m;
//	}
//
//	char* returneaza_nume()
//	{
//		return this->nume;
//	}
//
//	void modifica_nume(char* n)
//	{
//		strcpy(this->nume, n);
//	}
//
//	float get_medie()
//	{
//		if (this->medie > 9)
//		{
//			return this->medie;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//
//	void set_medie(float m)
//	{
//		this->medie = m;
//	}
//
//
//	void afiseaza_adresa();
//};
//
//int Student::nr_studenti = 0; // variabilele statice se initializeaza global, nu in constructori sau clase
//
//void Student::afiseaza_adresa()
//{
//	cout << "Adresa obiectului curent este: " << this << endl; // prin this aici luam adresa
//}
//
//void main()
//{
//	//Student s1;
//	//Student s2("Andrei", 123, 10);
//	////s.init("Andrei", 123, 5);
//	//cout << s1.nume << endl; // afiseaza anonim
//	//// s.afiseaza_adresa();
//	//cout << s2.get_medie() << endl; // afiseaza 10
//
//	//// pt a apela constructorul de copiere
//	////Student s3 = s2; // putem apela si asa
//	//Student s3(s2); // putem apela si asa
//
//	Student::Catalog c; // se apeleaza constructorul implicit din Catalog
//
//	// pt constructorul Catalog cu parametri
//	int v[3] = { 10, 9, 8 };
//	Student::Catalog c1(v, 3);
//
//	
//	Student s;
//	/*s.situatie_scolara = Student::Catalog(v, 3);
//	cout << s.situatie_scolara.nr_note<< endl;*/
//
//	cout<< Student::nr_studenti<< endl;
//
//	cout << Student::IsStudentBursier(s)<< endl; // apel pt functie statica
//
//}
