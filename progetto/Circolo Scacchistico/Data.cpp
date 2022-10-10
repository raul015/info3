#include "Data.hpp"

Data::Data(int giorno,int mese,int anno){

		this->giorno = giorno;
		this->mese = mese;
		this->anno = anno;
		cout<<"Creazione data ["<<this->giorno<<"-"<<this->mese<<"-"<<this->anno<<"]"<<endl;
}

int Data::getGiorno(){return this->giorno;}
int Data::getMese(){return this->mese;}
int Data::getAnno(){return this->anno;}

string Data::toString(){

	string a = "";
	a+= to_string(this->giorno);
	a+= "-";
	a+= to_string(this->mese);
	a+= "-";
	a+= to_string(this->anno);

return a;
}





