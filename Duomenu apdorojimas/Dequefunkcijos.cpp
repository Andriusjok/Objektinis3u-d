#include "Dequeheader.h"
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

bool compare_by_word(const studentas& lhs, const studentas& rhs) {
	return lhs.pavarde < rhs.pavarde;
}
bool compare_by_name(const studentas& lhs, const studentas& rhs) {
	return lhs.vardas < rhs.vardas;
}
bool compare_by_grades(studentas& lhs, studentas& rhs) {
	return lhs.galutinis < rhs.galutinis;
}
void FindLongest(deque<studentas> &input, unsigned int &Vilgis, unsigned int &Pilgis)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (Vilgis < input[i].vardas.length())
			Vilgis = input[i].vardas.length();
		if (Pilgis < input[i].pavarde.length())
			Pilgis = input[i].pavarde.length();
	}
}
void FileRead(deque<studentas> &studentai, ifstream &file)
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
void dequeSplit(deque <studentas> &studentai, int &b, unsigned int &Vilgis, unsigned int &Pilgis)
{
	for (auto i = 0; i < studentai.size(); i++)
	{
		studentai[i].GetAverage();
		studentai[i].getMedian();
	}
	deque<studentas> vargsiukas;
	if (b == 1) {
		for (auto i = 0; i < studentai.size(); i++)
		{
			if (studentai[i].galutinis < 5)
			{
				vargsiukas.push_back(studentai[i]);
				studentai.erase(studentai.begin() + i);
			}
		}

	}
	else {
		for (auto i = 0; i < studentai.size(); i++)
		{
			if (studentai[i].galutmed < 5)
			{
				vargsiukas.push_back(studentai[i]);
				studentai.erase(studentai.begin() + i);
			}
		}
	}
	studentai.shrink_to_fit();
	std::sort(studentai.begin(), studentai.end(), compare_by_word);
	std::sort(vargsiukas.begin(), vargsiukas.end(), compare_by_word);

	std::ofstream failas("vargsiukai.txt");
	failas << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	failas << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	failas << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	failas << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute(Pilgis + Vilgis + 40, '-');
	failas << eilute << endl;
	for (size_t i = 0; i < vargsiukas.size(); i++) {
		failas << setw(Pilgis + 6) << std::left << setfill(' ') << vargsiukas[i].pavarde;
		failas << setw(Vilgis + 6) << std::left << setfill(' ') << vargsiukas[i].vardas;
		failas << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << vargsiukas[i].galutinis << vargsiukas[i].galutmed << endl;
	}
	std::ofstream failas1("kietekai.txt");
	failas1 << setw(Pilgis + 6) << std::left << setfill(' ') << "Pavarde ";
	failas1 << setw(Vilgis + 6) << std::left << setfill(' ') << "Vardas ";
	failas1 << setw(16) << std::left << setfill(' ') << "Galutinis vid. ";
	failas1 << setw(16) << std::left << setfill(' ') << "Galutinis med. " << endl;
	string eilute1(Pilgis + Vilgis + 40, '-');
	failas1 << eilute1 << endl;
	for (size_t i = 0; i < studentai.size(); i++)
	{
		failas1 << setw(Pilgis + 6) << std::left << setfill(' ') << studentai[i].pavarde;
		failas1 << setw(Vilgis + 6) << std::left << setfill(' ') << studentai[i].vardas;
		failas1 << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << studentai[i].galutinis << studentai[i].galutmed << endl;
	}
}
void SpartosAnalize(deque<studentas> &studentai)
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
	dequeSplit(studentai, b, Vilgis, Pilgis);
	cout << "Praejo " << t.elapsed() << " s" << endl;
}
