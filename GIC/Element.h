#ifndef ELEMENT_H_
#define ELEMENT_H_

class Element {
protected:
	char nume;    
public:
	Element();
	Element(char); 
	char getTip();
};

class Neterminal :public Element {

	public:
		Neterminal();
		Neterminal(char);
		char getTip();
};

class Terminal :public Element {

	public:
		Terminal();
		Terminal(char);
		char getTip();
};

#endif