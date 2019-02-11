
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;
using std::cin;
struct Parametrai
{
	string vardas;
	int tarpai;
};
int main() {
	Parametrai A;
	printf("Koks Jusu vardas: ");
	char *charas;
	cin >> A.vardas;
	string sveikinimas;
	if (A.vardas.back() == 's') {
		sveikinimas = "Sveikas, " + A.vardas + " !";
	} else {
		sveikinimas = "Sveika, " + A.vardas + " !";
	}
	printf("iveskite remelio dydi (nuo 1 iki 10): ");
	scanf("%i", &A.tarpai);
	if (A.tarpai > 10)
		A.tarpai = 10;
	if (A.tarpai < 1)
		A.tarpai = 1;
	const int eilutes = A.tarpai * 2 + 3;
	const int stulpeliai = sveikinimas.length() + A.tarpai * 2 + 2;
	cout << endl;
	for (int e = 0; e != eilutes; ++e) {
		int s = 0;
		while (s != stulpeliai) {
			if (e == A.tarpai + 1 && s == A.tarpai + 1) {

				printf("%s", sveikinimas.c_str());
				s += sveikinimas.size();
			} else {
				if (e == 0 || e == eilutes - 1 || s == 0 || s == stulpeliai - 1)
					printf("*");
				else
					printf(" ");
				++s;
			}
		}
		cout << endl;
	}
	return 0;
}
