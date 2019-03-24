
#include "listheader.h"
int ErrorFun(int nr);
int CinFail(int e);
int CinDecimal(int e);
bool compare_by_word(const studentas& lhs, const studentas& rhs);
bool compare_by_name(const studentas& lhs, const studentas& rhs);
bool compare_by_grades(studentas& lhs, studentas& rhs);
void FindLongest(list <studentas> &input, unsigned int &Vilgis, unsigned int &Pilgis);
void FileRead(list<studentas> &studentai, ifstream &file);
void SpartosAnalize(list<studentas> &studentai);
void VectorSplit(list<studentas> &studentai, int &b, unsigned int &Vilgis, unsigned int &Pilgis);
int main()
{
	int r;

	list<studentas> studentai;
	SpartosAnalize(studentai);
	
}
