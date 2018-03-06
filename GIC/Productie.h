#ifndef PRODUCTIE_H_
#define PRODUCTIE_H_
#include <vector>
#include "Element.h"

#define Max 100

using namespace std;


class Productie {
	Neterminal baza;
	Element * tinta[Max];
	int dimTinta;
	int nrCai;
	vector<int> pozCai;
	public:
		Productie(char, string);
		char getBaza();
		char getTinta(int);
		int getDimTinta();
		void afisare();
		int getNrCai();
		int getCale(int);
};

#endif