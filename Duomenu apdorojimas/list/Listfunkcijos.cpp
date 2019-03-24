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
void Input(list<studentas> &studentai) {
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
	}
	else
	{
		int u;
		cout << "Kiek norite sugeneruoti namu darbu pazymiu (iki milijono)?" << endl;
		cin >> u;
		while (cin.fail() or u > 1000000 or u < 0)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete netinkama skaiciu, bandykite dar karta" << endl;
			cin >> u;
		}
		ivedimas.v.reserve(u);
		std::default_random_engine generator;
		std::uniform_int_distribution<int> dist(1, 10);
		for (int i = 0; i < u; i++)
		{
			ivedimas.v.push_back(dist(generator));
		}
		ivedimas.e =dist(generator);
	}
	studentai.push_back(ivedimas);

}
void Printing(list<studentas> &studentai, unsigned int &Pilgis, unsigned int &Vilgis)
{
	for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
	{

		(*it).GetAverage();
		(*it).getMedian();
	}
	cout << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	cout << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	cout << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	cout << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 40, '-');
	cout << eilute << endl;
	for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
	{
		(*it).Print(Pilgis, Vilgis);
	}
}
bool compare_by_word(const studentas& lhs, const studentas& rhs) {
	return lhs.pavarde < rhs.pavarde;
}
bool compare_by_name(const studentas& lhs, const studentas& rhs) {
	return lhs.vardas < rhs.vardas;
}
bool compare_by_grades(studentas& lhs, studentas& rhs) {
	return lhs.galutinis < rhs.galutinis;
}
void FindLongest(list<studentas> &input, unsigned int &Vilgis, unsigned int &Pilgis)
{
	for (list<studentas>::iterator it = input.begin(); it != input.end(); ++it)
	{
		if (Vilgis < (*it).vardas.length())
			Vilgis = (*it).vardas.length();
		if (Pilgis < (*it).pavarde.length())
			Pilgis = (*it).pavarde.length();
	}
}
void Generavimas(int r, int e, Timer& t)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> dist(1, 10);
	std::uniform_int_distribution<int> Ndist(1, 100000);
	std::ofstream file("kursiokai.txt");

	std::string vardas = "Vardas";
	std::string pavarde = "Pavarde";
	for (int i = 0; i < r; i++)
	{
		file << vardas << Ndist(generator) << " " << pavarde << Ndist(generator) << " ";
		for (int j = 0; j < e; j++)
		{
			file << dist(generator) << " ";
		}
		file << dist(generator);
		if (i != r - 1)
			file << std::endl;
	}
}
void FileRead(list<studentas> &studentai, ifstream &file)
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
	while (fin >> k)
	{
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
void Interface(list<studentas> &studentai)
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
			ifstream file(pav);
			while (!file.eof())
			{
				FileRead(studentai, file);
			}

		}
		catch (const std::exception &exc)
		{

			std::cerr << "ERROR:" << exc.what() << " Nepavyko atidaryti failo arba failas neatitinka formato ";
			std::exit(EXIT_FAILURE);
		}

	}
	else if (f != 1) {
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
void VectorSplit(list <studentas> &studentai, int &b, unsigned int& Vilgis,unsigned int& Pilgis)
{
	for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
	{

		(*it).GetAverage();
		(*it).getMedian();
	}

	studentai.sort(compare_by_grades);
	int n = 0;
	if (b == 1) {
		for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
		{
			if ((*it).galutinis < 5)
				n++;
		}
	}
	else {
		for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
		{
			if ((*it).galutmed < 5)
				n++;

		}
	}


	std::ofstream failas("vargsiukai.txt");
	failas << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	failas << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	failas << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	failas << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 40, '-');
	failas << eilute << endl;
	list<studentas>::iterator itmax = studentai.begin();
	std::advance(itmax, n);
	for (list<studentas>::iterator it = studentai.begin(); it != itmax; ++it) {
		failas << setw(Pilgis + 6) << std::left << setfill(' ') << (*it).pavarde;
		failas << setw(Vilgis + 6) << std::left << setfill(' ') << (*it).vardas;
		failas << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << (*it).galutinis << (*it).galutmed << endl;
	}
	std::ofstream failas1("kietekai.txt");
	failas1 << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	failas1 << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	failas1 << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	failas1 << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute1(Pilgis + Vilgis + 40, '-');
	failas1 << eilute1 << endl;
	for (list<studentas>::iterator it = itmax++; it != studentai.end(); ++it)
	{
		failas1 << setw(Pilgis + 6) << std::left << setfill(' ') << (*it).pavarde;
		failas1 << setw(Vilgis + 6) << std::left << setfill(' ') << (*it).vardas;
		failas1 << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << (*it).galutinis << (*it).galutmed << endl;
	}
}
void SpartosAnalize(list<studentas> &studentai)
{
	unsigned int Pilgis = 7;
	unsigned int Vilgis = 6;
	cout << "Kiek norite sugeneruoti studentu (iki 10m)?" << endl;
	int r;
	cin >> r;
	while (cin.fail() or r > 10000000 or r < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Ivedete netinkama skaiciu, bandykite dar karta" << endl;
		cin >> r;
	}
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Kiek norite studentams sugeneruoti pazymiu?(iki 100)" << endl;
	int e;
	cin >> e;
	while (cin.fail() or e > 100 or e < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Ivedete netinkama skaiciu, bandykite dar karta" << endl;
		cin >> e;
	}

	cin.clear();
	cin.ignore(100, '\n');
	cout << "Ar norite skaiciuoti vargsiukus ir kietekus pagal medianas ar vidurkius? 1-vidurkis 0-mediana" << endl;
	int b = CinFail(0);
	cout << "Pradedamas matuoti laikas" << endl;
	Timer t;
	Generavimas(r, e, t);
	ifstream file("kursiokai.txt");
	while (!file.eof())
	{
		FileRead(studentai, file);
	}
	FindLongest(studentai, Vilgis, Pilgis);
	VectorSplit(studentai, b, Vilgis, Pilgis);
	cout << "Praejo " << t.elapsed() << " s" << endl;
}