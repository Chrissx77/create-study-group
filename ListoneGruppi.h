#ifndef LISTONEGRUPPI_H
#define LISTONEGRUPPI_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Nodo_Listone
{
	private:
		Lista_Studenti* key;
		Nodo_Listone* succ;
		Nodo_Listone* prec;	
	public:
		Nodo_Listone(Lista_Studenti* x)
		{
			key = x;
			succ = NULL;
			prec = NULL;
		}
		Nodo_Listone* get_succ(){return succ;}
		Nodo_Listone* get_prec(){return prec;}
		Lista_Studenti* get_key(){return key;}
		void set_succ(Nodo_Listone* x){succ = x;}
		void set_prec(Nodo_Listone* x){prec = x;}
};

class Listone
{
	private:
		Nodo_Listone* testa;
		Nodo_Listone* coda;
	public:
		Listone() : testa(NULL), coda(NULL){}
		Nodo_Listone* get_testa(){return testa;}
		Nodo_Listone* get_coda(){return coda;}
		Listone* insertListone(Nodo_Listone* x)
		{
			Nodo_Listone* nuovo = x;
			if(testa == NULL)
			{
				testa = nuovo;
				coda = nuovo;
				return this;
			}
			else
			{
				nuovo->set_prec(coda);
				coda->set_succ(nuovo);
				coda = nuovo;
			}
			return this;
		}	
};
#endif