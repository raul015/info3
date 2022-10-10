#include "Circolo.hpp"
#include "Torneo.hpp"
#include"Data.hpp"
#include "Giocatore.hpp"
#include"Persona.hpp"
#include "Partita.hpp"

int main(void){


	Circolo& circolo = Circolo::instance(); // � un Singleton Pattern...

		cout<<"nome : "<<circolo.getName()<<endl;
		cout<<"numero : "<<circolo.getNumber()<<endl;

		shared_ptr<Data> data (new Data(1, 1, 1));
//		Data* data = new Data(1,1,1);


//		Torneo* torneo = new Torneo("Excelsior", 15.0,data,1,Ufficiale );

		shared_ptr<Torneo> torneo(new Torneo("Excelsior", 15.0,data,1,Ufficiale ));

		cout<<"sezione torneo"<<endl;
		cout<<"nome Torneo : "<<torneo->getNome()<<endl;
		cout<<"costo Torneo : "<<torneo->getCosto()<<endl;
		cout<<"data Torneo : "<< torneo->getData()->toString()<<endl;

//		Torneo* torneo1 = new Torneo("Excelsior1", 15.0,data,2,Ufficiale );
//		Torneo* torneo2= new Torneo("Excelsior2", 15.0,data,3,NonUfficiale );
//		Torneo* torneo3 = new Torneo("Excelsior3", 15.0,data,4,Ufficiale);

		shared_ptr<Torneo> torneo1(new Torneo("Excelsior1", 15.0,data,2,Ufficiale ));
		shared_ptr<Torneo> torneo2(new Torneo("Excelsior2", 15.0,data,3,NonUfficiale ));
		shared_ptr<Torneo> torneo3( new Torneo("Excelsior3", 15.0,data,4,Ufficiale));

		circolo.eliminaTorneo(torneo2);

		circolo.aggiungiTorneo(torneo);
		circolo.aggiungiTorneo(torneo1);
		circolo.aggiungiTorneo(torneo2);
		circolo.aggiungiTorneo(torneo3);
		circolo.aggiungiTorneo(torneo3);

		circolo.stampaListaTornei();

		circolo.eliminaTorneo(torneo2);


		circolo.eliminaTorneo(torneo2);
		circolo.stampaListaTornei();


//		Giocatore* p1 = new Giocatore("raul","luiz",1300);
//		cout<< p1->elo<<endl;

//		Giocatore* p2 = new Giocatore("Dom","Toretto",1400);
//		Giocatore* p3 = new Giocatore("Ema","Ciabattino",1500);
//		Giocatore* p4 = new Giocatore("Adi","Acquila",1000);
//		Giocatore* p5 = new Giocatore("Turco","Panino");
//		Giocatore* p6 = new Giocatore("Rob","Righetti",2000);
//		Giocatore* p7 = new Giocatore("Mario","Bros",1790);

		shared_ptr<Giocatore> p1 (new Giocatore("raul","luiz",1300));
		shared_ptr<Giocatore> p2 (new Giocatore("Dom","Toretto",1400));
		shared_ptr<Giocatore> p3 (new Giocatore("Ema","Ciabattino",1500));
		shared_ptr<Giocatore> p4 (new Giocatore("Adi","Acquila",1000));
		shared_ptr<Giocatore> p5 (new Giocatore("Turco","Panino"));
		shared_ptr<Giocatore> p6 (new Giocatore("Rob","Righetti",2000));
		shared_ptr<Giocatore> p7 (new Giocatore("Mario","Bros",1790));

		cout<<p2->elo<<endl;
		torneo->inserisci(p1);
		torneo->inserisci(p2);
		torneo->inserisci(p3);
		torneo->inserisci(p4);
		torneo->inserisci(p5);
		torneo->inserisci(p6);
		torneo->inserisci(p7);


		torneo->stampaRisultati();

		torneo->avvia();
//		cout<<"-----Stampa normale in base all'ordine di iscrizione"<<endl;
//		torneo->stampa();
//		torneo->ordinaElo();
//		cout<<"---- Post ordinamento elo ------"<<endl;
//		torneo->stampa();
//		torneo->ordinaPunti();
//		cout<<"----Post ordinamento Punti ---"<<endl;
//		torneo->stampa();

		// PRIMO TURNO


		torneo->avvioTurno();
		cout<<"inserimento dei risultati del turno"<<endl;

			// numero turno, accoppiamento, ris1, ris2
		torneo->risultatoAccoppiamento(1,1,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(1,0,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(1,2,Pareggio,Pareggio);
		torneo->risultatoAccoppiamento(1,3,Vittoria,Sconfitta);
		torneo->resetAccoppiamento(1,1);
		torneo->risultatoAccoppiamento(1,1,Sconfitta,Vittoria);
		torneo->controlloTurno();
		torneo->fineTurno();

		// SECONDO TURNO

		torneo->avvioTurno();
		torneo->risultatoAccoppiamento(2,1,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(2,0,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(2,2,Pareggio,Pareggio);
		torneo->risultatoAccoppiamento(2,3,Vittoria,Sconfitta);
		torneo->fineTurno();

		// TERZO TURNO

		torneo->avvioTurno();
		torneo->risultatoAccoppiamento(3,1,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(3,0,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(3,2,Pareggio,Pareggio);
		torneo->risultatoAccoppiamento(3,3,Vittoria,Sconfitta);
		torneo->fineTurno();

		// QUARTO TURNO

		torneo->avvioTurno();
		torneo->risultatoAccoppiamento(4,1,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(4,0,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(4,2,Pareggio,Pareggio);
		torneo->risultatoAccoppiamento(4,3,Vittoria,Sconfitta);
		torneo->fineTurno();


		// QUINTO TURNO

		torneo->avvioTurno();
		torneo->risultatoAccoppiamento(5,1,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(5,0,Vittoria,Sconfitta);
		torneo->risultatoAccoppiamento(5,2,Pareggio,Pareggio);
		torneo->risultatoAccoppiamento(5,3,Vittoria,Sconfitta);
		torneo->fineTurno();
		torneo->risultatiFinali();


//		Partita* partita1 = new Partita(p1,p2);
//		partita1->risultato(Vittoria, Sconfitta);


	return 0;
}



