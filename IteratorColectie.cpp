#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    //Θ(1)
	curent = 0;
}

void IteratorColectie::prim() {
    //Θ(1)
	curent = 0;
}


void IteratorColectie::urmator() {
    //Θ(1)
	curent++;
}


bool IteratorColectie::valid() const {
    //Θ(1)
	return curent < col.dim();
}



TElem IteratorColectie::element() const {
    //Θ(1)
	return col.D[col.P[curent]];
}
