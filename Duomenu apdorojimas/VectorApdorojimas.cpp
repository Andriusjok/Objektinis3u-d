#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::setfill;
using std::vector;

struct studentas {
	string vardas;
	string pavarde;
	vector<int> v;
	int e;
	double galutinis;
	double mediana;

	void Print(int Pilgis, int Vilgis) {
		cout << setw(Pilgis + 3) << std::left << setfill(' ') << pavarde;
		cout << setw(Vilgis + 3) << std::left << setfill(' ') << vardas;
		cout << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << galutinis << endl;
	}
	double getMedian()
	{
		if (v.size() > 0) {
			std::sort(v.begin(), v.end());
			if (v.size() % 2 != 0)
				mediana = v[v.size() - 1];
			else
				mediana = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
			galutinis = 0.4 * mediana + 0.6 * e;
		}
		else galutinis = 0.6 * e;
		return galutinis;
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
void Input(vector<studentas> &studentai, int &Pilgis, int &Vilgis) {
	studentas ivedimas;
	cout << "Iveskite Studento varda" << endl;
	cin >> ivedimas.vardas;
	cin.clear();
	cin.ignore(100, '\n');
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Vardo ivestyje padarete klaida, bandykite dar karta" << endl;
		cin >> ivedimas.vardas;
	}
	if (Vilgis < ivedimas.vardas.length())
		Vilgis = ivedimas.vardas.length();
	cout << "Iveskite studento pavarde" << endl;
	cin >> ivedimas.pavarde;
	cin.clear();
	cin.ignore(100, '\n');
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Pavardes ivestyje padarete klaida, bandykite dar karta" << endl;
		cin >> ivedimas.pavarde;

	}

	if (Pilgis < ivedimas.pavarde.length())
		Pilgis = ivedimas.pavarde.length();
	int r;//response
	cout << "Ar norite kad pazymius sugeneruotu automatiskai? 1=taip 0=ne" << endl;
	cin >> setw(1) >> r;
	cin.clear();
	cin.ignore(100, '\n');
	while (cin.fail() or r != 0 and r != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ivedete ne 1 ar 0, bandykite dar karta" << endl;
		cin >> r;
	}
	if (r == 0) {
		cout << "Iveskite namu darbu pazymius (nuo 1 iki 10), jei pazymiu nebera, iveskite 0" << endl;
		bool Pazymiuivedimas = true;
		int l; //response
		while (Pazymiuivedimas = true)
		{
			cin >> setw(2) >> l;
			cin.clear();
			cin.ignore(100, '\n');
			while (cin.fail() or l > 10 or l < 0)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ivedete ne skaiciu (1-10), bandykite dar karta" << endl;
				cin >> setw(2) >> l;
			}
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
		cin >> setw(2) >> ivedimas.e;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail() or ivedimas.e > 10 or ivedimas.e < 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete ne skaiciu (0-10), bandykite dar karta" << endl;
			cin >> setw(2) >> ivedimas.e;
		}
	} else
	{
		int u;
		cout << "Kiek norite sugeneruoti namu darbu pazymiu (iki milijono)?" << endl;
		cin >> u;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail() or u > 1000000)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
			cin >> u;
		}
		//Stephan T. Lavavej siulomas random library solution
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(1, 11);
		for (int i = 0; i < u; i++)
		{
			ivedimas.v.push_back(round(dist(mt)));
		}
		ivedimas.e = round(dist(mt));
	}
	studentai.push_back(ivedimas);

}
void Printing(vector<studentas> &studentai, int Pilgis, int Vilgis)
{
	int c;
	cout << "Jei norite studentu vidurkiu iveskite 1, jei medianu 0" << endl;
	cin >> c;
	cin.clear();
	cin.ignore(100, '\n');
	while (cin.fail() or c != 0 && c != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		cin >> c;
	}
	if (c == 1) {
		for (int i = 0; i < studentai.size(); i++)
		{
			studentai[i].GetAverage();
		}
	} else
	{
		for (int i = 0; i < studentai.size(); i++)
		{
			studentai[i].getMedian();
		}
	}
	cout << setw(Pilgis + 3) << std::left << setfill(' ') << "Pavarde ";
	cout << setw(Vilgis + 3) << std::left << setfill(' ') << "Vardas ";
	if (c == 1)
		cout << "Galutinis vid. " << endl;
	else cout << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 20, '-');
	cout << eilute << endl;

	for (int i = 0; i < studentai.size(); i++)
	{
		studentai[i].Print(Pilgis, Vilgis);
	}
}
int main()
{
	vector<studentas> studentai;
	cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
	int Pilgis = 7;
	int Vilgis = 6;
	int o = 0;
	int a;
	cin >> a;
	while (cin.fail() or a != 0 && a != 1)
	{
		studentai.reserve(o + 1);
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		cin >> a;
	}
	while (a == 1)
	{
		Input(studentai, Pilgis, Vilgis);
		cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
		cin >> a;
		o++;
	}
	Printing(studentai, Pilgis, Vilgis);
	return 0;
}