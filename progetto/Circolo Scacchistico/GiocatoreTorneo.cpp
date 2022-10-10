#include "GiocatoreTorneo.hpp"

//GiocatoreTorneo:: GiocatoreTorneo(shared_ptr<Giocatore> giocatore){
GiocatoreTorneo:: GiocatoreTorneo(Giocatore* giocatore){

	this->giocatore = giocatore;
	this->punteggio = 0;
}



double GiocatoreTorneo :: getPunteggio(){
	return this->punteggio;
}

//shared_ptr<Giocatore> GiocatoreTorneo ::  getGiocatore(){
Giocatore* GiocatoreTorneo ::  getGiocatore(){

	return giocatore;
}

int GiocatoreTorneo::getElo(){
	return this->giocatore->elo;
}



GiocatoreTorneo::~GiocatoreTorneo(){}

