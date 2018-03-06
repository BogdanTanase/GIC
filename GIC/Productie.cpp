#include <string>
#include "Productie.h"
#include <iostream>
using namespace std;

Productie::Productie(char c, string str) {
	this->baza = *new Neterminal(c);
	nrCai = 1;
	pozCai.push_back(0);
	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			this->tinta[i] = new Neterminal(str[i]);
		}
		else {
			if ('a' <= str[i] && str[i] <= 'z') {
				this->tinta[i] = new Terminal(str[i]);
			}
			else {
				nrCai++;
				pozCai.push_back(i+1);
				this->tinta[i] = new Element();
			}
		}
	}

	this->dimTinta = str.size();
}

char Productie::getBaza() {
	return this->baza.getTip();
}

char Productie::getTinta(int poz) {
	return (*tinta[poz]).getTip();
}

int Productie::getDimTinta() {
	return this->dimTinta;
}
void Productie::afisare() {
	cout << baza.getTip() << " -> ";
	for (int i = 0; i < dimTinta; i++) {
		if (tinta[i]->getTip() == ' ') {
			cout << "|";
		}
		else {
			cout << tinta[i]->getTip();
		}
	}
	cout << "\n";
}
int Productie::getNrCai() {
	return this->nrCai;
}
int Productie::getCale(int care) {
	return pozCai[care];
}