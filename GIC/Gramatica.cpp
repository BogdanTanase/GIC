#include <fstream>
#include <string>
#include "Gramatica.h"
#include <iostream>
using namespace std;

Gramatica::Gramatica(ifstream &f) {
	f >> this->nr_neterminale;
	f >> this->nr_terminale;
	f >> this->nr_productii;
	char tmp;
	for (int i = 0; i < this->nr_neterminale; i++) {
		f >> tmp;
		Net.push_back(Neterminal(tmp));
		if ( f.peek() == ' ') {
			f.get();
		}
	}
	for (int i = 0; i < this->nr_terminale; i++) {
		f >> tmp;
		Ter.push_back(Terminal(tmp));
		if (f.peek() == ' ') {
			f.get();
		}
	}
	for (int i = 0; i < this->nr_productii; i++) {
		char tmpB;
		f >> tmpB;
		f.ignore(4);
		char tmpV;
		string tmpT;
		while (f.peek() != '\n' && f.peek() != EOF) {
			f >> tmpV;
			tmpT.push_back(tmpV);
		}
		Prod.push_back(Productie(tmpB, tmpT));
	}
}


bool Gramatica::inNeterminale(char c) {
	for (int i = 0; i < nr_neterminale; i++) {
		if (Net[i].getTip() == c) {
			return true;
		}
	}
	return false;
}


bool Gramatica::inTerminale(char c) {
	for (int i = 0; i < nr_terminale; i++) {
		if (Ter[i].getTip() == c) {
			return true;
		}
	}
	return false;
}


void Gramatica::afisare() {
	cout << nr_neterminale << " " << nr_terminale << " " << nr_productii << " \n";
	for (int i = 0; i < this->nr_neterminale; i++) {
		cout << Net[i].getTip() << " ";
	}
	cout << " \n";
	for (int i = 0; i < this->nr_terminale; i++) {
		cout << Net[i].getTip() << " ";
	}
	cout << " \n";
	for (int i = 0; i < this->nr_productii; i++) {
		Prod[i].afisare();
	}
}


void Gramatica::generare() {
	string mare, tmp , mic  ;
	for (int i = 0; i < nr_productii; i++) {
		for (int j = 0; j < Prod[i].getDimTinta(); j++) {
			mare.push_back(Prod[i].getTinta(j));
		}
		mare.push_back(' ');
	}

	ofstream exit("exit.txt");
	for (int i = 0; i < mare.size(); i++) {
		if (mare[i] == ' ') {
			mic.clear();
			tmp.clear();
		}//daca e spatiu o iau de la capat
		else {
			if (mare[i] > 91) {
				mic.push_back(mare[i]);
			}//daca e litera mica o bag in ala mic
			else {
				int poz;     //gasesc productia aferenta
				for (int j = 0; j < nr_productii; j++) {
					if (Prod[j].getBaza() == mare[i]) {
						poz = j;
						break;
					}
				}
				int stop = Prod[poz].getNrCai(); //gasesc cate cai are productia respectriva
				if (tmp.size() == 0) {
					for (int j = 0; j < stop; j++) {
						for (int k = 0; k < mic.size(); k++) {
							tmp.push_back(mic[k]);
						}//am pus literele mici
						if (j < stop - 1) {
							for (int k = Prod[poz].getCale(j); k < Prod[poz].getCale(j + 1) - 1; k++) {
								tmp.push_back(Prod[poz].getTinta(k));
							}
						}
						if (j = stop - 1) {
							for (int k = Prod[poz].getCale(j); k < Prod[poz].getDimTinta(); k++) {
								tmp.push_back(Prod[poz].getTinta(k));
							}
						}//adauga pe rand cate o cale
						tmp.push_back(' ');
						//spatii
					}

				}//generez sirul temporar
				else {

				}
			

			}
		}
	}

	
}