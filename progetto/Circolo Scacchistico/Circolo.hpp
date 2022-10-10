#ifndef SRC_CIRCOLO_HPP_
#define SRC_CIRCOLO_HPP_

#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include"Torneo.hpp"

using namespace std;


class Circolo{ // Design Pattern Singleton...

public:

	static Circolo& instance();

//	void aggiungiTorneo(Torneo*);
//	void eliminaTorneo(Torneo*);

	string getName();
	string getNumber();
	void aggiungiTorneo(shared_ptr<Torneo>);
	void eliminaTorneo(shared_ptr<Torneo>);
	void stampaListaTornei();
private:
    string name = "Excelsior";
    string number = "035222830";

//    vector<Torneo*> lista_tornei;
    vector<shared_ptr<Torneo>> lista_tornei;
	 Circolo(){
	}
	 virtual ~Circolo(){
	}


};

#endif /* SRC_CIRCOLO_HPP_ */
