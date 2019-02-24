
#include "header.h"
int ErrorFun(int nr);
int CinFail(int e);
int CinDecimal(int e);
void Input(vector<studentas> &studentai);
void Printing(vector<studentas> &studentai, int &Pilgis, int &Vilgis);
bool compare_by_word(const studentas& lhs, const studentas& rhs);
void FindLongest(vector<studentas> &input, int &Vilgis, int &Pilgis);
void FileRead(vector<studentas> &studentai, ifstream &file);
void Interface(vector<studentas> &studentai);
int main()
{
	int Pilgis = 7;
	int Vilgis = 6;
	vector<studentas> studentai;
	Interface(studentai);
	FindLongest(studentai,Vilgis,Pilgis);
	std::sort(studentai.begin(), studentai.end(), compare_by_word);
	Printing(studentai, Pilgis, Vilgis);

}