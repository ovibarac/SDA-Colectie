#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

class Colectie
{
	friend class IteratorColectie;

private:
	/* aici e reprezentarea */
	
	//capacitatea pentru D
	int cpD;

	//capacitatea pentru P
	int cpP;

	//numarul de elemente distincte
	int nD;

	//dimensiunea colectiei
	int nP;

	//vectorul de elemente distincte
	TElem* D;

	//vectorul de pozitii in D ale elementelor colectiei
	int* P;

public:
		//constructorul implicit
		Colectie(int);

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

		//returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();

};

