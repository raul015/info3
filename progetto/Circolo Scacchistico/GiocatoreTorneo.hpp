#ifndef GIOCATORETORNEO_HPP_
#define GIOCATORETORNEO_HPP_

#include "Giocatore.hpp"
#include<memory>


class GiocatoreTorneo {

public :

	double punteggio;

	//	GiocatoreTorneo(shared_ptr<Giocatore>);
	//	shared_ptr<Giocatore> getGiocatore();

	GiocatoreTorneo(Giocatore*);
	double getPunteggio();
	Giocatore* getGiocatore();
	int getElo();
	virtual ~GiocatoreTorneo();
private:

	Giocatore* giocatore;
//	shared_ptr<Giocatore> giocatore;



};

#endif /* GIOCATORETORNEO_HPP_ */
