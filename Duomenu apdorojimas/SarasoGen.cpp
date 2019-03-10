#include <fstream>
#include <iostream>
#include <random>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
int main()
{
	cout<<"Kiek norite sugeneruoti studentu (iki 10m)?"<<endl;
	int r;
	cin>>r;
	while (!cin>>r or r<0 or r>10000000)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete netinkama skaiciu, bandykite dar karta" << endl;
			cin >> r;
		}
		cout<<"Kiek norite studentams sugeneruoti pazymiu?(iki 100)"<<endl;
			int e;
			cin>>e;
		while (!cin>>e or e<0 or e>100)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ivedete netinkama skaiciu, bandykite dar karta" << endl;
			cin >> e;
		}
	std::random_device rd;
    std::mt19937 mt(rd());	
	std::uniform_int_distribution<int> dist(1, 10);
	std::uniform_int_distribution<int> Ndist(1, 100000);
	std::uniform_int_distribution<int> skaicius(10, 50);
	std::ofstream file ("kursiokai.txt");
	std::string vardas="Vardas";
	std::string pavarde="Pavarde";
	{for (int i=0;i<r;i++)
		{
			file<<vardas<<Ndist(mt)<<" "<<pavarde<<Ndist(mt)<<" ";
			for(int j=0;j<e;j++)
			{
				file<<dist(mt)<<" ";
			}
			file<<dist(mt);
			if (i!=r-1)
			file<<std::endl;
		}
	}
	return 0;
}