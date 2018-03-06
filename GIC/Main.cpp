#include <iostream>
#include <string>
#include "Gramatica.h"
#include <fstream>
using namespace std;

int main(){
	ifstream f("in.txt");
	Gramatica gigel(f);
	gigel.afisare();
	gigel.generare();
	return 0;
}