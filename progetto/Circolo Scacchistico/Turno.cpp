#include"Turno.hpp"

/*
 * 	vector<GiocatoreTorneo*> giocatori;
	vector<Partita*> partite;
 */

Turno::Turno(vector<GiocatoreTorneo*> giocatori){
//Turno::Turno(vector<shared_ptr<GiocatoreTorneo>> giocatori){

	this->giocatori = giocatori;

}

void Turno:: generaAccoppiamenti(){

	for(int i = 0; i < (int) giocatori.size(); i = i+2 ){

		Partita* p = new Partita(giocatori.at(i), giocatori.at(i+1));
		partite.push_back(p);

//		shared_ptr<Partita> p (new Partita(giocatori.at(i),giocatori.at(i+1)));
//		partite.push_back(p);
	}

}

void Turno:: stampaAccoppiamenti(){

	for(int i = 0; i < (int) partite.size(); i++ ){
		cout<<"accoppiamento "<<i+1<<"|"<<partite.at(i)->giocatore1->getGiocatore()->nome<<","<<partite.at(i)->giocatore1->getGiocatore()->nome;
		cout<<" vs ";
		cout<<partite.at(i)->giocatore2->getGiocatore()->nome<<","<<partite.at(i)->giocatore2->getGiocatore()->nome<<endl;
	}


}

int Turno:: getNumeroPartite(){
	return partite.size();
}


Turno::~Turno(){

}
