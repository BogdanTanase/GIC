#include <iostream>
#include "Element.h"

Element::Element() {
	this->nume = ' ';
}

Element::Element(char c) {
	this->nume = c;
}
char Element::getTip() {
	return this->nume; 
}

Neterminal::Neterminal() :Element() {
}

Neterminal::Neterminal(char c) :Element(c) {
}

char Neterminal::getTip() {
	return this->nume;
}

Terminal::Terminal() :Element() {
}

Terminal::Terminal(char c) :Element(c) {
}

char Terminal::getTip() {
	return this->nume;
}