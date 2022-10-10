#include "Giocatore.hpp"

Giocatore:: Giocatore(string nome, string cognome): Persona(nome,cognome){
	this->elo = 1000;
}

Giocatore:: Giocatore(string nome, string cognome, int elo): Giocatore(nome,cognome){
	this->elo = elo;
}

Giocatore::~Giocatore(){}




