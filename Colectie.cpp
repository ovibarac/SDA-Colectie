#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {
    //Θ(1)
	int cp = 1; //capacitatea initiala

	this->cpD = cp;
	this->cpP = cp;

	D = new TElem[cp];
	P = new int[cp];

	this->nD = 0;
	this->nP = 0;
}


void Colectie::redimD() {
    //Θ(n)
	//alocare spatiu dublu
	TElem* dNou = new TElem[2 * cpD];

	//copiem vechile valori
	for (int i = 0; i < nD; i++) {
		dNou[i] = D[i];
	}

	//dublam capacitatea
	cpD *= 2;

	//eliberam vechea zona
	delete[] D;

	//vectorul indica spre noua zona
	D = dNou;
}

void Colectie::redimP() {
    //Θ(n)
	//alocare spatiu dublu
	TElem* pNou = new TElem[2 * cpP];

	//copiem vechile valori
	for (int i = 0; i < nP; i++) {
		pNou[i] = P[i];
	}

	//dublam capacitatea
	cpP *= 2;

	//eliberam vechea zona
	delete[] P;

	//vectorul indica spre noua zona
	P = pNou;
}

void Colectie::adauga(TElem elem) {
    //Θ(n)
	//cauta elementul in vectorul de elemente distincte
	int i = 0;
	for (i = 0; i < nD; i++) {
		if (D[i] == elem) {
			break;
		}
	}

	//daca elementul este nou
	if (i == this->nD) {
		if (nD == cpD) {
			redimD();
		}
		if (nP == cpP) {
			redimP();
		}
		this->D[nD] = elem;
		this->P[nP] = nD; //se pune in P noua pozitie din D
		nD++;
		nP++;
	}
	else {
		//daca elementul apare in D i arata pozitia sa
		if (nP == cpP) {
			redimP();
		}
		//se pune i in P
		P[nP++] = i;
	}
}


bool Colectie::sterge(TElem elem) {
    //Θ(n)
	int nrA = nrAparitii(elem);
	if(nrA == 0)
		return false;

	//gasim pozitia elementului in D
	int i = 0;
	for (i = 0; i < nD; i++) {
		if (D[i] == elem) {
			break;
		}
	}

	if (nrA == 1) {
		//daca apare o singura data se sterge din D si din P
		//stergem D[i]
		TElem* dNou = new TElem[cpD];
		int k = 0;
		for (int j = 0; j < nD; j++) {
			if (j!= i) {
				dNou[k] = D[j];
				k++;
			}
		}
		delete[] D;
		D = dNou;

		//stergem P[j] = i
		TElem* pNou = new TElem[cpP];

		k = 0;
		for (int j = 0; j < nP; j++) {
			if (P[j] > i) {
				P[j]--; //pozitiile de dupa pozitia i vor scadea cu 1
				pNou[k] = P[j];
				k++;
			}
			else if (P[j] != i) {
				pNou[k] = P[j];
				k++;
			}

		}
		delete[] P;
		P = pNou;

		nD--;
		nP--;
	}
	else if (nrA > 1) {
		//daca apare de mai multe ori se sterge o aparitie in P
		TElem* pNou = new TElem[cpP];

		bool sters = false;
		int k = 0;
		for (int j = 0; j < nP; j++) {
			if (P[j] != i || sters) {
				pNou[k] = P[j];
				k++;
			}
			if (P[j] == i) {
				sters = true;
			}
		}
		delete[] P;
		P = pNou;

		nP--;
	}

	return true;
}


bool Colectie::cauta(TElem elem) const {
    //Θ(n)
	int i = 0;
	for (i = 0; i < nD; i++) {
		if (D[i] == elem) {
			break;
		}
	}

	//daca nu s-a ajuns la final inseamna ca s-a gasit elementul
	if (i < nD) {
		return true;
	}

	return false;
}

int Colectie::nrAparitii(TElem elem) const {
    //Θ(n)
	int i = 0;
	for (i = 0; i < nD; i++) {
		if (D[i] == elem) {
			break;
		}
	}

	//daca s-a ajuns la final inseamna ca nu s-a gasit elementul
	if (i == nD) {
		return 0;
	}

	//se numara aparitiile pozitiei i in vectorul de pozitii
	int ct = 0;
	for (int j = 0; j < nP; j++) {
		if (P[j] == i) {
			ct++;
		}
	}
	return ct;
}


int Colectie::dim() const {
    //Θ(1)
	return nP;
}


bool Colectie::vida() const {
    //Θ(1)
	if (nD == 0 || nP == 0) {
		return true;
	}
	return false;
}

IteratorColectie Colectie::iterator() const {
    //Θ(1)
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
    //Θ(1)
	delete[] D;
	delete[] P;
}


