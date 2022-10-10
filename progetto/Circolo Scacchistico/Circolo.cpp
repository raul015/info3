#include "Circolo.hpp"

Circolo& Circolo:: instance(){

    static Circolo CIRCOLO;

    return CIRCOLO;
}


string Circolo::getName(){
	return this->name;
}

string Circolo::getNumber(){
	return this->number;
}

//void Circolo::aggiungiTorneo(Torneo* a){

void Circolo :: aggiungiTorneo(shared_ptr<Torneo> a){

	bool token = true;

	for(int i = 0; i < (int) lista_tornei.size();i++){
		if(lista_tornei.at(i)->getCodice() == a->getCodice()){

			token= false;
		}
	}

	if(token== true)
		lista_tornei.push_back(a);
	else
		cout<<"Torneo "<< a->getNome() <<" gi� presente al circolo";


}

//void Circolo::eliminaTorneo(Torneo* a){
void Circolo::eliminaTorneo(shared_ptr<Torneo> a){

	bool token = false;

	if(int(lista_tornei.size()) == 0){
		cout<<"non ci sono tornei presenti nel circolo scacchistico..."<<endl;
	}

	else {

		// Controllo che sia presente o no all'interno della lista ...

		for(int i = 0; i < (int) lista_tornei.size();i++){
			if(lista_tornei.at(i)->getCodice() == a->getCodice()){
				lista_tornei.erase(lista_tornei.begin()+i);
			cout<<"Torneo "<< a->getNome()<<"trovato e rimosso "<<endl;
			token = true;
			}
		}

		if(token == false)
			cout<<"Non � stato trovato il torneo " <<a->getNome() <<endl;

	}

}


void Circolo::stampaListaTornei(){

	for(int i = 0; i < (int) lista_tornei.size();i++){

		cout<< lista_tornei.at(i)->getNome()<<endl;
	}

}
