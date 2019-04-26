#include "header.h"
#pragma once
class Studentas
{
private:
	string vardas_;
	string pavarde_;
	vector<int> v_;
	int e_;
	double galutinis_ = 0;
	double galutmed_ = 0;
public:
	Studentas(): vardas_(""), pavarde_(""), e_(0) {}
	Studentas(string vardas, string pavarde) : vardas_(vardas), pavarde_(pavarde), e_(0) { }
	Studentas(ifstream& input, unsigned int &Vilgis, unsigned int &Pilgis);
	inline string vardas() const {return vardas_;}
	inline string pavarde() const {return pavarde_;}
	double galutinisVid() const {return galutinis_;}
	double galutinisMed() const {return galutmed_;}

	void setVardas(string vardas) {vardas_ = vardas;}
	void setPavarde(string pavarde) {pavarde_ = pavarde;}
	void setE(int e) {e_ = e;}
	void pushV(int v) {v_.push_back(v);}
	void reserveV(int rsize) {v_.reserve(rsize);}
	void setEback();
	void FindLongest(vector<Studentas> &input, unsigned int &Vilgis, unsigned int &Pilgis);

	void getAverage();
	void getMedian();


	// operatoriai

void operator +=(int b)
{
	this->v_.push_back(b);
}
int operator >>(unsigned int & b)
{	if (this->vardas_.size()>b)
	return  this->vardas_.size();
	else
	return b;
}

int operator <<(unsigned int & b)
{	if (this->pavarde_.size()>b)
	return  this->pavarde_.size();
	else
	return b;
}
	};
bool compare_by_word(const Studentas& lhs, const Studentas& rhs);
bool compare_by_name(const Studentas& lhs, const Studentas& rhs);
bool compare_by_grades(const Studentas& lhs);
bool compare_by_mediana(const Studentas& lhs);