#include"Persona.hpp"

Persona::Persona(string nome, string cognome) {
	this->nome = nome;
	this->cognome = cognome;

	cout<<"Creazione persona ["<<this->nome<<"|"<<this->cognome<<"]"<<endl;
}

Persona::~Persona(){}

