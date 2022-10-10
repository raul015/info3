#ifndef SRC_DATA_HPP_
#define SRC_DATA_HPP_

#include<iostream>

using namespace std;


class Data{

public:
	Data(int giorno, int mese, int anno);
	int getGiorno();
	int getMese();
	int getAnno();
	string toString();

//	~Data(); altrimenti errore in data

private:

	int giorno;
	int mese;
	int anno;


};


#endif /* SRC_DATA_HPP_ */
