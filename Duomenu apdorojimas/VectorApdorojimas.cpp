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
struct studentas {
	string vardas;
	string pavarde;
	vector<int> v;
	int e;
	double galutinis;
	double galutmed;
	double mediana;

	void Print(int Pilgis, int Vilgis) {
		cout << setw(Pilgis + 3) << std::left << setfill(' ') << pavarde;
		cout << setw(Vilgis + 3) << std::left << setfill(' ') << vardas;
		cout << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << galutinis << galutmed << endl;
	}
	double getMedian()
	{
		if (v.size() > 0) {
			std::sort(v.begin(), v.end());
			if (v.size() % 2 != 0)
				mediana = v[v.size() - 1];
			else
				mediana = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
			galutmed = 0.4 * mediana + 0.6 * e;
		}
		else galutmed = 0.6 * e;
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

	for (int i = 0; i < studentai.size(); i++)
	{
		studentai[i].GetAverage();
		studentai[i].getMedian();
	}
	cout << setw(Pilgis + 3) << std::left << setfill(' ') << "Pavarde ";
	cout << setw(Vilgis + 3) << std::left << setfill(' ') << "Vardas ";
	cout << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	cout << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 20, '-');
	cout << eilute << endl;

	for (int i = 0; i < studentai.size(); i++)
	{
		studentai[i].Print(Pilgis, Vilgis);
	}
}
bool compare_by_word(const studentas& lhs, const studentas& rhs) {
    return lhs.pavarde < rhs.pavarde;
}
void FileRead(vector<studentas> &studentai, ifstream &file, int &Vilgis, int &Pilgis)
{
	studentas input;
	int n;
		if (file.eof())
			exit(EXIT_FAILURE);
		string line;
		getline(file, line);
		istringstream fin(line);
		fin >> input.vardas;
		if (Vilgis < input.vardas.length())
			Vilgis = input.vardas.length();
		fin >> input.pavarde;
		if (Pilgis < input.pavarde.length())
			Vilgis = input.pavarde.length();
		fin >> n;
		int k;
		for (int i = 0; i < n; i++) {
			fin >> k;
			if (fin.fail())
			{
				fin.clear();
				string dummy;
				fin >> dummy;
				continue;
			}

			if (k > 10 or k < 1) {
				cout << "Duomenys ivesti neteisingai" << endl;
				exit(EXIT_FAILURE);

			}
			input.v.push_back(k);
		}
		if (n != input.v.size())
		{
			cout << "Duomenys ivesti neteisingai" << endl;
			exit(EXIT_FAILURE);
		}
		fin >> k;
		input.e=k;
	studentai.push_back(input);
}
	int main()
	{
		setlocale(LC_ALL, "Lithuanian");
		vector<studentas> studentai;
		cout << "Ar norite nuskaityti faila?1=taip 0=ne" << endl;
		int f;
		int Pilgis = 7;
		int Vilgis = 6;
		cin >> f;
		while (cin.fail() or f != 0 && f != 1)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
			cin >> f;
		}
		if (f == 1)
		{
			cout << "Koks pilnas tekstinio failo pavadinimas?" << endl;
			string pav;
			cin >> pav;

			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Iveskit normalu pavadinima" << endl;
				cin >> pav;
			}
			ifstream file (pav);
				if (!file)
				{
				cout << "Failas neatsidare" << endl;
				exit(EXIT_FAILURE);
			}	while(!file.eof()){
				FileRead(studentai, file, Pilgis, Vilgis);
			}
			
		} if (f != 1) {
			cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
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
		}
		std::sort(studentai.begin(), studentai.end(), compare_by_word);
		Printing(studentai, Pilgis, Vilgis);
	}