#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <math.h>
#include <random>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::setfill;
struct node {
	string vardas = "";
	string pavarde = "";
	int *A = nullptr; //namu darbai
	int e = 0; //egzamino rezultatas
	node *next = nullptr;
	double suma = 0;
	double galutinis = 0;
	int dydis = 1;
	double mediana = 0;
	void prideti(int k)
	{
		if (!A)
		{
			A = new int[1];
			*A = k;
		}
		else
		{
			dydis = sizeof(A) / sizeof(A[0]) + 1;
			int *B = new int[dydis];
			for (int i = 0; i < dydis - 1; i++)
			{
				*(B + i) = *(A + i);
			}
			delete[] A;
			A = B;
			A[dydis - 1] = k;
		}
	}
};

double getSum (int dydis, int *A)
{
	double suma = 0;
	for (int i = 0; i < dydis; i++)
	{
		suma += A[i];
	}
	return suma;
}
node* insert(node *&root) {
	node *new_node = root;
	if (root != nullptr)
	{
		while (new_node->next) {
			new_node = new_node->next;
		}
		new_node->next = new node;
		new_node = new_node->next;
		new_node->next = nullptr;
		cout << "Iveskite Studento varda" << endl;
		cin >> new_node->vardas;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Vardo ivestyje padarete klaida, bandykite dar karta" << endl;
			cin >> new_node->vardas;
		}
		cout << "Iveskite studento pavarde" << endl;
		cin >> new_node->pavarde;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Pavardes ivestyje padarete klaida, bandykite dar karta" << endl;
			cin >> new_node->pavarde;
		}
		int r;
		cout << "Ar norite kad pazymius generuotu uz jus? 1=taip 0=ne" << endl;
		cin >> r;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail() or r != 0 && r != 1)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
			cin >> r;
		} int n;
		if (r == 0) {
			cout << "Iveskite namu darbu pazymius (nuo 1 iki 10), jei pazymiu nebera, iveskite 0" << endl;
			bool Pazymiuivedimas = true;
			int l; //response
			int n = 0; //namu darbu pazymiu kiekis
			while (Pazymiuivedimas = true)
			{
				cin >> l;
				cin.clear();
				cin.ignore(100, '\n');
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
					cin >> l;
				}
				if (l >= 1 && l <= 10)
				{

					new_node->prideti(l);
					n++;
				}
				else
				{
					Pazymiuivedimas = false;
					break;
				}
			}
			cout << "Iveskite egzamino rezultata" << endl;
			cin >> new_node->e;
			cin.clear();
			cin.ignore(100, '\n');
			while (cin.fail() or new_node->e > 10 or new_node->e < 0)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ivedete ne skaiciu (0-10), bandykite dar karta" << endl;
				cin >> new_node->e;
			}
		} else
		{
			int n;
			cout << "Kiek norite sugeneruoti namu darbu pazymiu (iki milijono)?" << endl;
			cin >> n;
			cin.clear();
			cin.ignore(100, '\n');
			while (cin.fail() or n > 1000000)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
				cin >> n;
			}
			new_node->dydis = n;
			//Stephan T. Lavavej siulomas random library solution
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_real_distribution<double> dist(1, 11);
			for (int i = 0; i < n; i++)
			{
				new_node->prideti(round(dist(mt)));
			}
			new_node->e = round(dist(mt));
		}
		int c;
		cout << "Jei norite isvesti studento vidurki, iveskite 1, jei mediana, iveskite 0" << endl;
		cin >> c;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail() or c != 0 && c != 1)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
			cin >> c;
		}
		if (c == 1) {
			if (n != 0) {
				new_node->suma = getSum(new_node->dydis, new_node->A);
				new_node->galutinis = 0.4 * new_node->suma / n + 0.6 * new_node->e;
			}
			else new_node->galutinis = 0.6 * new_node->e;
		} else
		{
			if (n != 0) {
				int temp;
				for (int i = 0; i < new_node->dydis; i++)
				{
					for (int j = i + 1; j < new_node->dydis; j++)

					{
						if (new_node->A[i] > new_node->A[j])
						{
							temp = new_node->A[i];
							new_node->A[i] = new_node->A[j];
							new_node->A[j] = temp;
						}
					}
				}
				if (new_node->dydis % 2 != 0)
					new_node->mediana = new_node->A[new_node->dydis - 1];
				else
					new_node->mediana = (new_node->A[new_node->dydis / 2] + new_node->A[new_node->dydis / 2 - 1]) / 2;
				new_node->galutinis = 0.4 * new_node->mediana + 0.6 * new_node->e;
			}
			else new_node->galutinis = 0.6 * new_node->e;
		}
	}


	else {
		root = new node;
		cout << "Iveskite studento varda" << endl;
		cin >> root->vardas;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Vardo ivestyje padarėte klaida, bandykite dar karta" << endl;
			cin >> root->vardas;
		}
		cout << "Iveskite studento pavarde" << endl;
		cin >> root->pavarde;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Pavardes ivestyje padarete klaida, bandykite dar karta" << endl;
			cin >> root->pavarde;
		}
		int r;
		cout << "Ar norite kad pazymius uz jus? 1=taip 0=ne" << endl;
		cin >> r;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail() or r != 0 && r != 1)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
			cin >> r;
		}

		int n = 0; //namu darbu pazymiu kiekis
		if (r == 0) {
			cout << "Iveskite namu darbu pazymius (nuo 1 iki 10), jei pazymiu nebera, iveskite 0" << endl;
			bool Pazymiuivedimas = true;
			int l; //response
			while (Pazymiuivedimas = true)
			{
				cin >> l;
				cin.clear();
				cin.ignore(100, '\n');
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Ivedete ne skaiciu (1-10), bandykite dar karta" << endl;
					cin >> l;
				}
				if (l >= 1 && l <= 10)
				{
					root->prideti(l);
					n++;
				}
				else
				{
					Pazymiuivedimas = false;
					break;
				}
			}
			cout << "Iveskite egzamino rezultata" << endl;
			cin >> root->e;
			cin.clear();
			cin.ignore(100, '\n');
			while (cin.fail() or root->e > 10 or root->e < 0)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ivedete ne skaiciu (0-10), bandykite dar karta" << endl;
				cin  >> root->e;
			}
		} else
		{
			cout << "Kiek norite sugeneruoti namu darbu pazymiu (iki 1000000)?" << endl;
			cin >> n;
			cin.clear();
			cin.ignore(100, '\n');
			while (cin.fail() or n > 1000000)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
				cin >> n;
				cin.clear();
				cin.ignore(100, '\n');
			}
			root->dydis = n;
			//Stephan T. Lavavej siulomas random library solution
			std::random_device rd;
			std::mt19937 mt(rd());
			std::uniform_real_distribution<double> dist(1, 11);
			for (int i = 0; i < n; i++)
			{
				root->prideti(round(dist(mt)));
			}
			root->e = round(dist(mt));
		}
		int c;
		cout << "Jei norite isvesti studento vidurki, iveskite 1, jei mediana, iveskite 0" << endl;
		cin >> c;
		cin.clear();
		cin.ignore(100, '\n');
		while (cin.fail() or c != 0 && c != 1)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
			cin  >> c;
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (c == 1) {
			if (n != 0)
			{
				root->suma = getSum(root->dydis, root->A);
				root->galutinis = 0.4 * root->suma / n + 0.6 * root->e;
			}
			else root->galutinis = 0.6 * root->e;
		}
		else

		{
			if (n != 0) {
				int temp;
				for (int i = 0; i < root->dydis; i++)
				{
					for (int j = i + 1; j < root->dydis; j++)

					{
						if (root->A[i] > root->A[j])
						{
							temp = root->A[i];
							root->A[i] = root->A[j];
							root->A[j] = temp;
						}
					}
				}
				if (root->dydis % 2 != 0)
					root->mediana = root->A[(root->dydis - 1)];
				else
					root->mediana = (root->A[root->dydis / 2] + root->A[root->dydis / 2 - 1]) / 2;
			}
			root->galutinis = 0.4 * root->mediana + 0.6 * root->e;

		}
	}
	return root;
}

void istrinti (node * root)
{
	node *temp;
	int k = 0;
	node *t = root;
	while (t)
	{
		k++;
		t = t->next;
	}
	t = root;
	for (int i = 0; i < k; i++)
	{
		temp = t->next;

		delete[] t->A;
		delete t;
		t = temp;
	}
}
int FindLongest(int a, node * root)
{
	int Pilgiausias = 8;
	int Vilgiausias = 7;
	node *t = root;
	while (t) {
		if (Pilgiausias < t->pavarde.length())
		{
			Pilgiausias = t->pavarde.length();
		}
		if (Vilgiausias < t->vardas.length())
		{
			Vilgiausias = t->vardas.length();
		}
		t = t->next;
	}
	if (a == 1)
		return Pilgiausias;
	else	return Vilgiausias;
}

void isvedimas (node * root)
{

	int Pilgis = FindLongest(1, root);
	int Vilgis = FindLongest(0, root);
	cout << setw(Pilgis + 3) << std::left << setfill(' ') << "Pavarde ";
	cout << setw(Vilgis + 3) << std::left << setfill(' ') << "Vardas ";
	if (root->mediana == 0)
		cout << "Galutinis vid. " << endl;
	else cout << "Galutinis med. " << endl;

	string eilute(Pilgis + Vilgis + 20, '-');
	cout << eilute << endl;
	node *t = root;
	while (t) {
		cout << setw(Pilgis + 3) << std::left << setfill(' ') << t->pavarde;
		cout << setw(Vilgis + 3) << std::left << setfill(' ') << t->vardas;
		cout << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << t->galutinis << endl;
		t = t->next;
	}
}
main()
{
	node *root = nullptr;
	int a;
	cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
	cin >> a;
	cin.clear();
	cin.ignore(100, '\n');
	while (cin.fail() or a != 0 && a != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		cin >> a;
		cin.clear();
		cin.ignore(100, '\n');
	}
	while (a == 1)
	{
		insert(root);
		cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
		cin >> a;
		cin.clear();
		cin.ignore(100, '\n');

	}
	isvedimas(root);
	istrinti(root);
	return 0;
}