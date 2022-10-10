#ifndef TURNO_HPP_
#define TURNO_HPP_

#include<vector>
#include "GiocatoreTorneo.hpp"
#include"Partita.hpp"

class Turno{

public:

	bool stato = false;
	vector<GiocatoreTorneo*> giocatori;
	vector<Partita*> partite;

//	vector<shared_ptr<GiocatoreTorneo>> giocatori;
//	vector<shared_ptr<Partita>> partite;

//	Turno(vector<shared_ptr<GiocatoreTorneo>>);

	Turno(vector<GiocatoreTorneo*>);
	void generaAccoppiamenti();
	void stampaAccoppiamenti();
	bool controlloTurno();
	int getNumeroPartite();
	virtual ~Turno();

private:

};



#endif /* TURNO_HPP_ */
