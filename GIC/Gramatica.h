#ifndef GRAMATICA_H_
#define GRAMATICA_H_


#include "Productie.h"

using namespace std;

//Gramatica
class Gramatica {
	vector <Neterminal> Net;
	vector <Terminal> Ter;
	vector <Productie> Prod;
	int nr_neterminale;
	int nr_terminale;
	int nr_productii;

	public:
		Gramatica(ifstream &);
		bool inNeterminale(char);
		bool inTerminale(char); 
		void afisare();
		void generare();
};

#endif