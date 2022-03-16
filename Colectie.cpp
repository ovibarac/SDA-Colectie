#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie(int cp) {
	this->cpD = cp;
	this->cpP = cp;

	D = new TElem[cp];
	P = new int[cp];

	this->nD = 0;
	this->nP = 0;
}


void Colectie::adauga(TElem elem) {
	//cauta elementul in vectorul de elemente distincte
	int i = 0;
	for (i = 0; i < this->nD; i++) {
		if (D[i] == elem) {
			break;
		}
	}

	//daca elementul este nou
	if (i == this->nD) {
		if (nD == cpD) {
			//redim
		}
		if (nP == cpP) {
			//redim
		}
		this->D[nD] = elem;
		this->P[nP] = nD; //se pune in P noua pozitie din D
		nD++;
		nP++;
	}
	else {
		//daca elementul apare in D i arata pozitia sa
		if (nP == cpP) {
			//redim
		}
		//se pune i in P
		P[nP++] = i;
	}
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
	return false;
}


bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
	return 0;
}


int Colectie::dim() const {
	return np;
}


bool Colectie::vida() const {
	/* de adaugat */
	return true;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	delete[] D;
	delete[] P;
}


