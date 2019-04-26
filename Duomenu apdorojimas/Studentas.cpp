#include "Studentas.h"
#include "header.h"


bool compare_by_word(const Studentas& lhs, const Studentas& rhs) {
	return lhs.pavarde() < rhs.pavarde();
}
bool compare_by_name(const Studentas& lhs, const Studentas& rhs) {
	return lhs.vardas() < rhs.vardas();
}
bool compare_by_grades(const Studentas& lhs)
{
	if(lhs.galutinisVid() >= 5)
	return true;
	return false;
}
bool compare_by_mediana(const Studentas& lhs)
{
	if(lhs.galutinisMed() >= 5)
	return true;
	return false;
}
Studentas::Studentas(ifstream& file, unsigned int &Vilgis, unsigned int &Pilgis)
{
	if (file.eof())
		exit(EXIT_FAILURE);

	string line;
	getline(file, line);
	istringstream fin(line);

	fin >> vardas_;
	fin >> pavarde_;
Vilgis=*this>>Vilgis;
Pilgis=*this<<Pilgis;
	if(pavarde_.size()>Pilgis)
		Pilgis=pavarde_.size();
	int k;
	v_.reserve(10);
	while (fin >> k)
	{
		if (k > 10 or k < 0) {
			cout << "Pazymiai neteisingai ivesti faile" << endl;
			exit(EXIT_FAILURE);

		}

		*this+=k;

	}
	setEback();
	getMedian();
	getAverage();
}
void Studentas::getMedian()
{
	double mediana;
	std::sort(v_.begin(), v_.end());
	if (v_.size() % 2 != 0)
		mediana = v_[v_.size() - 1];
	else
		mediana = (v_[v_.size() / 2] + v_[v_.size() / 2 - 1]) / 2;
	galutmed_ = 0.4 * mediana + 0.6 * e_;
}
void Studentas::getAverage()
{
	double suma = 0;
	if (v_.size() > 0)
	{
		for (int i = 0; i < v_.size(); i++)
		{
			suma += v_[i];
		}
		galutinis_ = 0.4 * suma / v_.size() + 0.6 * e_;
	}
	else
		galutinis_ = 0.6 * e_;
}
void Studentas::setEback() {
	e_ = v_.back();
	v_.pop_back();
}
// OPERATORIUS v1.2
bool operator == (const Studentas& a, const Studentas & b)
{
	return a.galutinisVid()==b.galutinisVid() or a.galutinisMed()==b.galutinisMed();
}