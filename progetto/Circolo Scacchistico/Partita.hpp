#ifndef PARTITA_HPP_
#define PARTITA_HPP_

#include"GiocatoreTorneo.hpp"
#include "Risultato.cpp"

class Partita{

public:

	int stato_partita = 1;

//	shared_ptr<GiocatoreTorneo> giocatore1;
//	shared_ptr<GiocatoreTorneo> giocatore2;

	GiocatoreTorneo* giocatore1;
	GiocatoreTorneo* giocatore2;
	Partita(GiocatoreTorneo*,GiocatoreTorneo*);

//	Partita(shared_ptr<GiocatoreTorneo>,shared_ptr<GiocatoreTorneo>);
	// voglio gestire i punti di un turno.

	void risultato(ris,ris);
	void reset();

	double getrisultato1();
	double getrisultato2();

	virtual ~Partita();

private:



double risultato1;
double risultato2;





};




#endif /* PARTITA_HPP_ */
