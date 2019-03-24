#include "listheader.h"
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
void VectorSplit(list <studentas> &studentai, int &b, unsigned int& Vilgis,unsigned int& Pilgis)
{
	for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
	{
		(*it).GetAverage();
		(*it).getMedian();
	}
	list<studentas> vargsiukas;
	if (b == 1) {
		list<studentas>::iterator it = studentai.begin();
		while (it != studentai.end())
		{
			if ((*it).galutinis < 5) {
				vargsiukas.push_back(*it);
				it = studentai.erase(it);
			}
			else it++;
		}
	}
	else {
		list<studentas>::iterator it = studentai.begin();
		while (it != studentai.end())
		{
			if ((*it).galutmed < 5) {
				vargsiukas.push_back(*it);
				it = studentai.erase(it);
			}
			else it++;
		}
	}

	studentai.sort(compare_by_word);
	vargsiukas.sort(compare_by_word);
	std::ofstream failas("vargsiukai.txt");
	failas << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	failas << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	failas << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	failas << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 40, '-');
	failas << eilute << endl;
	for (list<studentas>::iterator it = vargsiukas.begin(); it != vargsiukas.end(); ++it) {
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
	for (list<studentas>::iterator it = studentai.begin(); it != studentai.end(); ++it)
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
	cout << "Ar norite skaiciuoti pagal medianas ar vidurkius? 1-vidurkis 0-mediana" << endl;
	int b = CinFail(0);
	string pav;
	cout << "Iveskite studentu failo pavadinima" << endl;
	cin >> pav;
	cout << "Pradedamas matuoti laikas" << endl;
	Timer t;

	ifstream file(pav);
	if (!file)
	{
		cout << "Pavadinimas ivestas neteisingai" << endl;
		exit(EXIT_FAILURE);
	}
	while (!file.eof())
	{
		FileRead(studentai, file);
	}
	FindLongest(studentai, Vilgis, Pilgis);
	VectorSplit(studentai, b, Vilgis, Pilgis);
	cout << "Praejo " << t.elapsed() << " s" << endl;
}