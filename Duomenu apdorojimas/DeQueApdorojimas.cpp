#include "Dequeheader.h"
int ErrorFun(int nr);
int CinFail(int e);
int CinDecimal(int e);
bool compare_by_word(const studentas& lhs, const studentas& rhs);
bool compare_by_name(const studentas& lhs, const studentas& rhs);
bool compare_by_grades(studentas& lhs, studentas& rhs);
void FindLongest(deque <studentas> &input, unsigned int &Vilgis, unsigned int &Pilgis);
void FileRead(deque<studentas> &studentai, ifstream &file);
void SpartosAnalize(deque<studentas> &studentai);
void dequeSplit(deque<studentas> &studentai, int &b, unsigned int &Vilgis, unsigned int &Pilgis);
int main()
{
	deque<studentas> studentai;
		SpartosAnalize(studentai);
}
