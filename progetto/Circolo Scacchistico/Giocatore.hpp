#ifndef GIOCATORE_HPP_
#define GIOCATORE_HPP_

#include"Persona.hpp"


class Giocatore : public Persona{

public :

	int elo;
	Giocatore(string,string,int);
	Giocatore(string,string);

	virtual ~Giocatore();
private:


};



#endif /* GIOCATORE_HPP_ */
