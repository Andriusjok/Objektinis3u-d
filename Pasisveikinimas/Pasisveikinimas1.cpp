#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
int main()
{
	printf("Iveskite varda: \n");
	string vardas;
	cin>>vardas;
	string sveikinimas;
	if (vardas.back() == 's')
		sveikinimas = {" Sveikas, " + vardas + "! "};
	else
		sveikinimas = {" Sveika, " + vardas + "! "};
	string eilute1;
	for (int i = 0; i <= sveikinimas.length() + 1; i++)
	{
		eilute1 += '*';
	}
	string eilute2;
	eilute2 += '*';
	for (int i = 0; i < sveikinimas.length(); i++)
	{
		eilute2 += ' ';
	}
	eilute2 += '*';
	string eilute3 = {'*' + sveikinimas + '*'};
	string eilute4 = eilute2;
	string eilute5 = eilute1;
	cout << eilute1 << endl;
	cout << eilute2 << endl;
	cout << eilute3 << endl;
	cout << eilute4 << endl;
	cout << eilute5 << endl;
	return 0;
}