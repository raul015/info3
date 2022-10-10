#ifndef PERSONA_HPP_
#define PERSONA_HPP_

#include<string>
#include<iostream>
using namespace std;


class Persona{

public:

	string nome;
	string cognome;
	Persona(string,string);
	virtual ~Persona();
private:


};


#endif /* PERSONA_HPP_ */
