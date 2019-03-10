#pragma once
#include <cctype>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <list>
#include <random>
#include <fstream>
#include <sstream>
#include <exception>
#include <chrono>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::setfill;
using std::vector;
using std::list;
using std::getline;
using std::ifstream;
using std::istringstream;
struct studentas
{
	string vardas;
	string pavarde;
	vector<int> v;
	int e;
	double galutinis;
	double galutmed;
	double mediana;

	void Print(unsigned int &Pilgis, unsigned int &Vilgis) {
		cout << setw(Pilgis + 6) << std::left << setfill(' ') << pavarde;
		cout << setw(Vilgis + 6) << std::left << setfill(' ') << vardas;
		cout << setw(16) << std::left << setfill(' ') << std::setprecision(2) << std::fixed << galutinis << galutmed << endl;
	}
	double getMedian()
	{
		std::sort(v.begin(), v.end());
		if (v.size() % 2 != 0)
			mediana = v[v.size() - 1];
		else
			mediana = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
		galutmed = 0.4 * mediana + 0.6 * e;
		return galutmed;
	}
	double GetAverage()
	{
		double suma = 0;
		if (v.size() > 0)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				suma += v[i];
			}
			galutinis = 0.4 * suma / v.size() + 0.6 * e;
		}
		else
			galutinis = 0.6 * e;
		return galutinis;
	}
};

class Timer {
private:
	// panaudojame using
	using hrClock = std::chrono::high_resolution_clock;
	using durationDouble = std::chrono::duration<double>;
	std::chrono::time_point<hrClock> start;
public:
	Timer() : start{ hrClock::now() } {}
	void reset() {
		start = hrClock::now();
	}
	double elapsed() const {
		return durationDouble(hrClock::now() - start).count();
	}
};
