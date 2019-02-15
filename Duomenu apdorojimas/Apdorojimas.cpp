#include <iostream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>

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
	int mediana=0;
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
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Vardo ivestyje padarete klaida, bandykite dar karta" << endl;
			cin >> new_node->vardas;
		}
		cout << "Iveskite studento pavarde" << endl;
		cin >> new_node->pavarde;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Pavardes ivestyje padarete klaida, bandykite dar karta" << endl;
			cin >> new_node->pavarde;
		}
		cout << "Iveskite namu darbu pazymius (nuo 1 iki 10), jei pazymiu nebera, iveskite 0" << endl;
		bool Pazymiuivedimas = true;
		int l; //response
		int n = 0; //namu darbu pazymiu kiekis
		while (Pazymiuivedimas = true)
		{
			cin >> l;
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
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
			cin >> new_node->e;
		}
		new_node->suma = getSum(new_node->dydis, new_node->A);
		new_node->galutinis = 0.4 * new_node->suma / n + 0.6 * new_node->e;
	}


	else {
		root = new node;
		cout << "Iveskite studento varda" << endl;
		cin >> root->vardas;
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
		cout << "Iveskite namu darbu pazymius (nuo 1 iki 10), jei pazymiu nebera, iveskite 0" << endl;
		bool Pazymiuivedimas = true;
		int l; //response
		int n = 0; //namu darbu pazymiu kiekis
		while (Pazymiuivedimas = true)
		{
			cin >> l;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
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
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete ne skaiciu, bandykite dar karta" << endl;
			cin >> root->e;
		}
		root->next = nullptr;
		if (n != 0) {
			root->suma = getSum(root->dydis, root->A);
			root->galutinis = 0.4 * root->suma / n + 0.6 * root->e;
		}
		else if (root->e != 0)
			root->galutinis = 0.6 * root->e;
		else
			root->galutinis = 0;
	}
	return root;
}

void istrinti (node *root)
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
int FindLongest(int a, node*root)
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

void isvedimas (node *root)
{
	int a;
	cout << "Jei norite isvesti studento vidurki, iveskite 1, jei mediana, iveskite 0" << endl;
	cin >> a;
	while (cin.fail() or a != 0 && a != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		cin >> a;
	}
	int Pilgis = FindLongest(1, root);
	int Vilgis = FindLongest(0, root);
	cout << setw(Pilgis + 3) << std::left << setfill(' ') << "Pavarde ";
	cout << setw(Vilgis + 3) << std::left << setfill(' ') << "Vardas ";
	if (a==1)
	cout << "Galutinis vid. " << endl;
	else cout << "Galutinis med. " << endl;
	
	string eilute(Pilgis + Vilgis + 20, '-');
	cout << eilute << endl;
	node *t = root;
	while (t) {
		cout << setw(Pilgis + 3) << std::left << setfill(' ') << t->pavarde;
		cout << setw(Vilgis + 3) << std::left << setfill(' ') << t->vardas;
		if (a==1)
		cout << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << t->galutinis << endl;
		else{
		 std::sort(t->A,t->A+t->dydis);
		 t->mediana=t->A[t->dydis/2];
		 cout << setw(16) << std::left <<t->mediana<<endl;
			}
		t = t->next;
	}
}
main()
{
	node *root = nullptr;
	int a;
	cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
	cin >> a;
	while (cin.fail() or a != 0 && a != 1)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ivedete ne 1 arba 0, bandykite dar karta" << endl;
		cin >> a;
	}
	while (a == 1)
	{
		insert(root);
		cout << "Jei norite irasyti studenta, iveskite 1, jei ne, iveskite 0" << endl;
		cin >> a;

	}
	isvedimas(root);
	istrinti(root);
	return 0;
}