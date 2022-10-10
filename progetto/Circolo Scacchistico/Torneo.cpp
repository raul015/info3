#include "Torneo.hpp"
#include<iostream>
#include <algorithm>
#include <iomanip>
#include <sstream>



//Torneo::Torneo(string nome, float costo, Data* date,int codice, Tipo tipo_torneo){

Torneo::Torneo(string nome, float costo, shared_ptr<Data>date,int codice, Tipo tipo_torneo){
	this->nome = nome;
	this->costo = costo;
	this->data = date;
	this->codice = codice;
	this->tipo_torneo = tipo_torneo;
}

string Torneo::getNome(){
	return this->nome;
}

Data* Torneo::getData(){

	return data.get();
}

float Torneo::getCosto(){
	return this->costo;
}
int Torneo::getCodice(){
	return this->codice;
}

void Torneo::inserisci(shared_ptr<Giocatore> a){
//void Torneo::inserisci(Giocatore* a){

	if(stato_torneo == false){
		lista_Iscrizioni.push_back(a);

		GiocatoreTorneo* g = new GiocatoreTorneo(a.get());
//		shared_ptr<GiocatoreTorneo> g (new GiocatoreTorneo(a));
//		shared_ptr<Data> data (new Data(1, 1, 1));
		lista_score.push_back(g);
	}
	else
		cout<<"non è possibile accettare partecipanti mentre di sta svolgendo un torneo"<<endl;

}


void Torneo::avvia(){

		if(	(int)lista_Iscrizioni.size() >= 6){ // Per regolamento almeno 6 giocatori

			if((int) lista_Iscrizioni.size()%2 == 1){

				 GiocatoreTorneo* f = new GiocatoreTorneo(forfait);

//				shared_ptr<GiocatoreTorneo> f(new GiocatoreTorneo(forfait));
//				shared_ptr<GiocatoreTorneo> f (a);
//
//				shared_ptr<GiocatoreTorneo> f (new GiocatoreTorneo(forfait));
//				lista_Iscrizioni.push_back(forfait);

				lista_score.push_back(f);
			}
			stato_torneo = true;


		}
		else{

			cout<<"Numero di giocatori insufficienti per l'avvio del torneo"<<endl;
		}
	}



void Torneo::stampaRisultati(){

	cout<<"-----------------------------------------"<<endl;
	for(int i = 0; i< (int)lista_score.size();i++){

		cout<<"RISULTATI : "<<endl;
		cout<<"nome : " << lista_score.at(i)->getGiocatore()->nome <<"|"<<"cognome : " << lista_score.at(i)->getGiocatore()->cognome<<"|"<<"punteggio : " << lista_score.at(i)->getPunteggio()  <<endl;
	}

	cout<<"-----------------------------------------"<<endl;
}

bool Torneo::compareElo(GiocatoreTorneo* a, GiocatoreTorneo* b){

//bool Torneo::compareElo( shared_ptr<GiocatoreTorneo> a, shared_ptr<GiocatoreTorneo> b){

	return a->getElo() <= b->getElo();
}

bool Torneo::comparePunti(GiocatoreTorneo* a, GiocatoreTorneo* b){

//bool Torneo::comparePunti(shared_ptr<GiocatoreTorneo>a,shared_ptr<GiocatoreTorneo> b){

	return a->getPunteggio() <= b->getPunteggio();
}

void Torneo:: stampa(){

	for(int i = 0;  i< (int)lista_score.size();i++){

		cout<<lista_score.at(i)->getGiocatore()->nome<<"|"<<lista_score.at(i)->getPunteggio()<<"|"<<lista_score.at(i)->getElo()<<"|"<<endl;
	}

}

void Torneo::ordinaElo(){

	for(int i = 0;  i< (int)lista_score.size();i++){

		for(int j = 0 ;  j< (int)lista_score.size();j++){

			if(!compareElo(lista_score.at(i),lista_score.at(j))){

				GiocatoreTorneo* appoggio = lista_score[j];
//				shared_ptr<GiocatoreTorneo>  appoggio = lista_score[j];
				lista_score[j] = lista_score[i];
				lista_score[i] = appoggio;


			}

		}
	}

}


void Torneo::ordinaPunti(){

	for(int i = 0;  i< (int)lista_score.size();i++){

		for(int j = 0 ;  j< (int)lista_score.size();j++){

			if(!comparePunti(lista_score.at(i),lista_score.at(j))){

				GiocatoreTorneo* appoggio = lista_score[i];
//				shared_ptr<GiocatoreTorneo>  appoggio = lista_score[j];
				lista_score[i] = lista_score[j];
				lista_score[j] = appoggio;


			}

		}
	}

}

void  Torneo:: avvioTurno(){

		if(this->stato_turno == true || lista_turni.size() > turni-1){

			cout<<"il turno è ancora in corso non è possibile , impossibile eseguire questa operazione"<<endl;
		}
		else{

			cout<<"INIZIO DEL TURNO NUMERO ["<<lista_turni.size()+1<<"]"<<endl;
			//cout<< lista_turni.size()<<endl;

			//cout<<"turno numero "<<lista_turni.size() +1 <<endl;

			if(lista_turni.size()== 1)
				ordinaElo();
			else if (lista_turni.size()>1 && lista_turni.size()<= turni){
				ordinaPunti();
			}

//				Turno* turno = new Turno(lista_score);
				shared_ptr<Turno> turno(new Turno(lista_score));
				turno->generaAccoppiamenti();
				//turno->stampaAccoppiamenti();
				lista_turni.push_back(turno);
				this->stato_torneo = true;

			}


}

void Torneo:: risultatoAccoppiamento( int turno ,int accoppiamento ,ris ris1 ,ris ris2){

//	cout<<"Dimensione lista turni : "<<(int)lista_turni.at(turno-1)->partite.size()<<endl;

	if(turno != (int)lista_turni.size() && accoppiamento <  (int)lista_turni.at(turno-1)->partite.size() -1 )
		cout<<"Stai sbagliando turno "<<endl;
	else if(accoppiamento >  (int)lista_turni.at(turno-1)->partite.size() -1){
		cout<<" Non è presente tale accoppiamento"<<endl;
	}

	else{

		lista_turni.at(turno-1)->partite.at(accoppiamento)->risultato(ris1,ris2);
	}
}

void Torneo:: resetAccoppiamento(int turno , int accoppiamento){

	if(turno != (int)lista_turni.size())
		cout<<"Stai sbagliando turno "<<endl;
	else{
		lista_turni.at(turno-1)->partite.at(accoppiamento)->reset();
		cout<<"reset accoppiamento "<<accoppiamento<<" : effettuato"<<endl;
	}
}


bool Torneo:: controlloTurno(){

	int posizione = (int) lista_turni.size() -1 ;
	int check = 0;
	for(int i = 0; i< (int)lista_turni.at(posizione)->partite.size(); i++){

		check +=  lista_turni.at(posizione)->partite.at(i)->stato_partita;
	}
	if(check == 0){
		cout<<"Turni conclusi"<<endl;
		return true;
	}
		else{
			cout<<"Ci sono ancora dei turni in corso non conclusi"<<endl;
			return false;
		}
}


void  Torneo :: fineTurno(){

	if(this->stato_turno == true && stato_torneo == true  ){

		cout<<"il turno è ancora in corso non è possibile , impossibile eseguire questa operazione"<<endl;
	}

	else if(this->stato_turno == false  && stato_torneo == false ){

		cout<<"Non puoi terminare i tornei perchè sono già conclusi"<<endl;
	}

	else{

		if(this->stato_torneo == true) {

		this->stato_turno = false;
	// DEVO INSERIRE LE MODIFICHE NELLO SCORE
		ordinaPunti();

		cout<<"---------------------------------------------------------"<<endl;
		cout<<"CLASSIFICA INTERMEDIA TURNO "<<lista_turni.size()<<endl;
		cout<<endl;
		for(int i = 0;  i< (int)lista_score.size();i++){

			cout<<lista_score.at(i)->getGiocatore()->nome<<string(10,' ')<<"|"<<lista_score.at(i)->getPunteggio()<<"|"<<endl;
		}
		cout<<"---------------------------------------------------------"<<endl;

		if(lista_turni.size() >= turni){
			stato_torneo = false;
		}
		}

		}
	}


void  Torneo :: risultatiFinali(){

	if(stato_torneo == true)
		cout<<"Non è possibile ancora annunciare i risultati finali "<<endl;

	else{
			ordinaPunti();

			cout<<" "<<string(49,'_')<<endl;
			cout<<"| 	Classifica finale del torneo "<<nome<<string(4,' ')<<"|"<<endl;
			cout<<"|"<<string(49,' ')<<"|"<<endl;
			cout<<"| Nome giocatore";
			cout<<string(15,' ');
			cout<<"punteggio finale"<<string(3,' ')<< "|"<<endl;
			cout<<"|"<<string(49,'_');
			cout<<"|"<<endl;
			for(int i = 0;  i< (int)lista_score.size();i++){

				cout<<"|"<<lista_score.at(i)->getGiocatore()->nome;
				cout<<string(38 - lista_score.at(i)->getGiocatore()->nome.length() ,' ');

				std::stringstream stream;
				stream << std::fixed << std::setprecision(1) << lista_score.at(i)->getPunteggio();
				std::string s = stream.str();
				cout<<"|"<<s<<"|";
					cout<<string(6,' ')<<"|";
				cout<<endl;

				if(i<3){
					cout<<"|"<<string(49,'_')<<"|"<<endl;
				}
			}

			cout<<"|"<<string(49,'_')<<"|"<<endl;
	}

}

Torneo:: ~Torneo(){}
