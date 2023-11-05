#ifndef LISTASTUDENTI_H
#define LISTASTUDENTI_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Nodo_Studente
{
	private:
		string matricola;
		string cognome;
		string nome;
		string citta;
		double mediavoti;
		Nodo_Studente* succ;
		Nodo_Studente* prec;
	public:
		Nodo_Studente(string m, string c, string n, string cit, double v)
		{
			matricola = m;
			cognome = c;
			nome = n;
			citta = cit;
			mediavoti = v;
			succ = NULL;
			prec = NULL;
		}
		string get_matricola(){return matricola;}
		string get_cognome(){return cognome;}
		string get_nome(){return nome;}
		string get_citta(){return citta;}
		double get_mediavoti(){return mediavoti;}	
		Nodo_Studente* get_succ(){return succ;}
		Nodo_Studente* get_prec(){return prec;}
		void set_succ(Nodo_Studente* x){succ = x;}
		void set_prec(Nodo_Studente* x){prec = x;}
};

class Lista_Studenti
{
	private:
		Nodo_Studente* testa;
		Nodo_Studente* coda;
	public:
		Lista_Studenti() : testa(NULL), coda(NULL){}
		Nodo_Studente* get_testa(){return testa;}
		Nodo_Studente* get_coda(){return coda;}
		void set_testa(Nodo_Studente* x){testa = x;}
		void set_coda(Nodo_Studente* x){coda = x;}
		bool lista_vuota()
		{
			if(testa == NULL || coda == NULL)
				return true;
			else return false;
		}
		Lista_Studenti* insert_decr(Nodo_Studente* x)
		{
			Nodo_Studente* nuovo = x;
			
			if(testa == NULL)
			{
				testa = nuovo;
				coda = nuovo;
				return this;
			}
			else if(nuovo->get_mediavoti() >= testa->get_mediavoti())
			{
				nuovo->set_succ(testa);
				testa->set_prec(nuovo);
				testa = nuovo;
			}
			else
			{
				Nodo_Studente* iter = testa;
				while((iter->get_succ() != NULL)&&(nuovo->get_mediavoti() < iter->get_mediavoti()))
					iter = iter->get_succ();
				if((iter != NULL) && (nuovo->get_mediavoti() > iter->get_mediavoti())) // INSERIAMO IN MEZZO
				{
					nuovo->set_prec(iter->get_prec());
					nuovo->set_succ(iter);
					iter->get_prec()->set_succ(nuovo);
					iter->set_prec(nuovo);
				}
				else
				{
					nuovo->set_prec(iter);
					iter->set_succ(nuovo);
					coda = nuovo;
				}
			}
			return this;
		}
		Lista_Studenti* insert(Nodo_Studente* x)
		{
			Nodo_Studente* nuovo = x;
			
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
		Nodo_Studente* estrai()
		{
			if(testa == NULL || coda == NULL)
				return NULL;	
			else
			{
				if(testa == coda)
				{
					Nodo_Studente* temp = coda;
					testa = NULL;
					coda = NULL;
					return temp;
				}
				else
				{
					Nodo_Studente* temp = coda;
					coda = coda->get_prec();
					coda->set_succ(NULL);
					return temp;
				}
			}
		}
};
#endif