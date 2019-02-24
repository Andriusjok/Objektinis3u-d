#include "header.h"
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
	for (int i = 0; i < input.size(); i++)
	{
		if (Vilgis < input[i].vardas.length())
			Vilgis = input[i].vardas.length();
		if (Pilgis < input[i].pavarde.length())
			Pilgis = input[i].pavarde.length();
	}
}
void FileRead(vector<studentas> &studentai, ifstream &file)
{
	studentas input;
	if (file.eof())
		exit(EXIT_FAILURE);
	string line;
	getline(file, line);
	istringstream fin(line);
	fin >> input.vardas;
	fin >> input.pavarde;
	int k;
	input.v.reserve(10);
	while (fin.rdbuf()->in_avail() > 0)
	{
		fin >> k;
		if (fin.fail())
		{
			if (file.eof())
				break;
			cout << "Praleistas netinkamas simbolis" << endl;
			fin.clear();
			string dummy;
			fin >> dummy;
			continue;
		}
		if (k > 10 or k < 0) {
			cout << "Pazymiai neteisingai ivesti faile" << endl;
			exit(EXIT_FAILURE);

		}
		input.v.push_back(k);

	}
	input.e = input.v.back();
	input.v.pop_back();
	studentai.push_back(input);
}
void Interface(vector<studentas> &studentai)
{
	cout << "Ar norite nuskaityti faila?1=taip 0=ne" << endl;
	int f = CinFail(0);
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
		try {
			ifstream file (pav);
			while (!file.eof())
				{
					FileRead(studentai, file);
				}
		
		}
		catch (const std::exception &exc)
		{

			std::cerr <<"ERROR:"<< exc.what()<<" Nepavyko atidaryti failo ";
			std::exit(EXIT_FAILURE);
		}

	} else if (f != 1) {
		cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
		int o = 0;
		int a = CinFail(0);
		while (a == 1)
		{
			Input(studentai);
			cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
			cin >> a;
			o++;
		}
	}
}
