#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::setfill;
using std::vector;
using std::getline;
using std::ifstream;
using std::istringstream;
struct studentas
{
	string vardas;
	string pavarde;
	vector<int> v;
	int e;
	double galutinis;
	double galutmed;
	double mediana;

	void Print(int &Pilgis, int &Vilgis) {
		cout << setw(Pilgis + 6) << std::left << setfill(' ') << pavarde;
		cout << setw(Vilgis + 6) << std::left << setfill(' ') << vardas;
		cout << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << galutinis << galutmed << endl;
	}
	double getMedian()
	{
		std::sort(v.begin(), v.end());
		if (v.size() % 2 != 0)
			mediana = v[v.size() - 1];
		else
			mediana = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
		galutmed = 0.4 * mediana + 0.6 * e;
		return galutmed;
	}
	double GetAverage()
	{
		double suma = 0;
		if (v.size() > 0)
		{
			for (int i = 0; i < v.size(); i++)
			{
				suma += v[i];
			}
			galutinis = 0.4 * suma / v.size() + 0.6 * e;
		}
		else
			galutinis = 0.6 * e;
		return galutinis;
	}
};
int ErrorFun(int nr)
{
	if (nr == 0)
	{
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		return 0;
	}
	if (nr == 1)
	{
		cout << "Ivedete ne skaiciu (1-10), bandykite dar karta" << endl;
		return 0;
	}
	if (nr == 2) {
		cout << "Duomenys ivesti neteisingai" << endl;
		return 0;
	}
	return 0;
}
int CinFail(int e)
{
	int f;
	cin >> f;
	while (cin.fail() or f != 0 && f != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		ErrorFun(e);
		cin >> f;
	}
	cin.clear();
	cin.ignore(100, '\n');
	return f;

}

int CinDecimal(int e)
{
	int f;
	cin >> f;
	while (cin.fail() or f > 10 or f < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		ErrorFun(e);
		cin >> f;
	}
	cin.clear();
	cin.ignore(100, '\n');
	return f;

}
void Input(vector<studentas> &studentai) {
	studentas ivedimas;
	cout << "Iveskite Studento varda" << endl;
	cin >> ivedimas.vardas;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Vardo ivestyje padarete klaida, bandykite ivesti dar karta" << endl;
		cin >> ivedimas.vardas;
	}
	cout << "Iveskite studento pavarde" << endl;
	cin >> ivedimas.pavarde;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Pavardes ivestyje padarete klaida, bandykite dar karta" << endl;
		cin >> ivedimas.pavarde;

	}

	int r;//response
	cout << "Ar norite kad pazymius sugeneruotu automatiskai? 1=taip 0=ne" << endl;
	r = CinFail(0);
	if (r == 0) {
		cout << "Iveskite namu darbu pazymius (nuo 1 iki 10), jei pazymiu nebera, iveskite 0" << endl;
		bool Pazymiuivedimas = true;
		int l; //response
		while (Pazymiuivedimas = true)
		{
			l = CinDecimal(1);

			if (l >= 1 && l <= 10)
			{

				ivedimas.v.push_back(l);
			}
			else
			{
				Pazymiuivedimas = false;
				break;
			}
		}
		cout << "Iveskite egzamino rezultata" << endl;
		ivedimas.e = CinDecimal(1);
	} else
	{
		int u;
		cout << "Kiek norite sugeneruoti namu darbu pazymiu (iki milijono)?" << endl;
		cin >> u;
		while (cin.fail() or u > 1000000)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete netinkama skaiciu, bandykite dar karta" << endl;
			cin >> u;
		}
		ivedimas.v.reserve(u);
		//Stephan T. Lavavej siulomas random library solution
		std::default_random_engine generator;
		std::uniform_int_distribution<int> dist(1, 10);
		for (int i = 0; i < u; i++)
		{
			ivedimas.v.push_back(round(dist(generator)));
		}
		ivedimas.e = round(dist(generator));
	}
	studentai.push_back(ivedimas);

}
void Printing(vector<studentas> &studentai, int &Pilgis, int &Vilgis)
{

	for (int i = 0; i < studentai.size(); i++)
	{
		studentai[i].GetAverage();
		studentai[i].getMedian();
	}
	cout << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	cout << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	cout << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	cout << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 40, '-');
	cout << eilute << endl;

	for (int i = 0; i < studentai.size(); i++)
	{
		studentai[i].Print(Pilgis, Vilgis);
	}
}
bool compare_by_word(const studentas& lhs, const studentas& rhs) {
	return lhs.pavarde < rhs.pavarde;
}
void FindLongest(vector<studentas> &input, int &Vilgis, int &Pilgis)
{
	for (int i = 0; i <input.size(); i++)
	{
		if (Vilgis < input[i].vardas.length())
			Vilgis = input[i].vardas.length();
		if (Pilgis < input[i].pavarde.length())
			Pilgis = input[i].pavarde.length();
	}
}

void Interface(vector<studentas> &studentai)
{
	
		cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
		int a = CinFail(0);
		while (a == 1)
		{
			Input(studentai);
			cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
			cin >> a;
		}
}
int main()
{
	int Pilgis = 7;
	int Vilgis = 6;
	vector<studentas> studentai;
	Interface(studentai);
	FindLongest(studentai,Vilgis,Pilgis);
	std::sort(studentai.begin(), studentai.end(), compare_by_word);
	Printing(studentai, Pilgis, Vilgis);

}