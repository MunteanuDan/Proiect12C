//#include <iostream>
//using namespace std;
//
//class angajat;
//class angajat_hr
//{
//public:
//	char functie[20];
//	char* returneaza_cnp(angajat& a);
//};
//
//class angajat
//{
//public:
//	char nume[40];
//	void set_cnp(char* cod)
//	{
//		strcpy(cnp, cod);
//	}
//private:
//	char cnp[13];
//	friend char* angajat_hr::returneaza_cnp(angajat&);
//};
//
//
//char* angajat_hr::returneaza_cnp(angajat& a)
//{
//	return a.cnp;
//}
//
//void main()
//{
//	angajat a;
//	a.set_cnp("12345");
//	angajat_hr a_hr;
//	a_hr.returneaza_cnp(a);
//
//}