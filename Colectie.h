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

	//redimensionarea vectorului de elemente distincte
    //Θ(n)
	void redimD();

	//redimensionarea vectorului de pozitii
    //Θ(n)
	void redimP();

public:
		//constructorul implicit
        //Θ(1)
		Colectie();

		//adauga un element in colectie
        //Θ(n)
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
        //Θ(n)
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
        //Θ(n)
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
        //Θ(n)
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
        //Θ(1)
		int dim() const;

		//verifica daca colectia e vida;
        //Θ(1)
		bool vida() const;

		//returneaza un iterator pe colectie
        //Θ(1)
		IteratorColectie iterator() const;

		// destructorul colectiei
        //Θ(1)
		~Colectie();

};

