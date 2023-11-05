#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "ListaStudenti.h"
#include "ListoneGruppi.h"

void opera(ifstream& in, Lista_Studenti* A, Lista_Studenti* B)
{
	char op;
	string matricola;
	string cognome;
	string nome;
	string citta;
	double mediavoti=0.0;
	in >> op;
	while(op != ';')
	{
		matricola +=op;
		in.get(op);
	}
	if(matricola == "") return;
	in >> op;
	while(op != ';')
	{
		cognome +=op;
		in.get(op);
	}
	in >> op;
	while(op != ';')
	{
		nome +=op;
		in.get(op);
	}
	in >> op;
	while(op != ';')
	{
		citta += op;
		in.get(op);
	}
	in >> mediavoti;
	Nodo_Studente* nuovo = new Nodo_Studente(matricola,cognome,nome,citta,mediavoti);
	if(nuovo->get_mediavoti()>= 24)
			A->insert_decr(nuovo);
	if(nuovo->get_mediavoti()< 24)
			B->insert(nuovo);
}

void estrai(Lista_Studenti* A, Lista_Studenti* B, Listone* C)
{
	Nodo_Listone* x;
	Lista_Studenti* temp = new Lista_Studenti();
	while(!B->lista_vuota() && (!A->lista_vuota()))
	{
		Nodo_Studente* b1 = B->estrai();
		Nodo_Studente* b2 = B->estrai();
		temp = new Lista_Studenti();
		if((b1) && (b2))
		{
			double somma = b1->get_mediavoti();
			somma += b2->get_mediavoti();
				
			if((somma >= 40.00))
			{
				temp->insert(b1)->insert(b2);
				x = new Nodo_Listone(temp);
				C->insertListone(x);
			}
			else if(somma < 40.00)
			{
				Nodo_Studente* a = A->estrai();
				temp->insert(a)->insert(b1)->insert(b2);
				x = new Nodo_Listone(temp);
				C->insertListone(x);
			}
		}
		else if(b1)
		{
			Nodo_Studente* a = A->estrai();
			if(a)
			{
				temp->insert(a)->insert(b1);
				x = new Nodo_Listone(temp);
				C->insertListone(x);
			}
		}
		else
		{
			Nodo_Studente* a = A->estrai();
			if(a)
			{
				temp->insert(a)->insert(b2);
				x = new Nodo_Listone(temp);
				C->insertListone(x);
			}
		}
	}
	while(!A->lista_vuota())
	{
		Nodo_Studente* a1 = A->estrai();
		Nodo_Studente* a2 = A->estrai();
		temp = new Lista_Studenti();
		if((a1)&&(a2))
		{
			temp->insert(a1)->insert(a2);
			x = new Nodo_Listone(temp);
			C->insertListone(x);
		}
		else
		{
			if(a1)
				C->get_coda()->get_key()->insert(a1);
			else 
				C->get_coda()->get_key()->insert(a2);
		}
	}
	while(!B->lista_vuota())
	{
		Nodo_Studente* a1 = B->estrai();
		Nodo_Studente* a2 = B->estrai();
		temp = new Lista_Studenti();
		if((a1)&&(a2))
		{
			temp->insert(a1)->insert(a2);
			x = new Nodo_Listone(temp);
			C->insertListone(x);
		}
		else
		{
			if(a1)
				C->get_coda()->get_key()->insert(a1);
			else 
				C->get_coda()->get_key()->insert(a2);
		}
	}
}

void print_gruppi(Listone* C)
{
	Nodo_Listone* iter = C->get_testa();
	Nodo_Studente* iter1;
	int numero_studenti = 0;
	double media_parz = 0.0;
	double media_tot = 0.0;
	int i = 1;
	
	while(iter)
	{
		cout << "GRUPPO N°" << i << ": ";
		iter1 = iter->get_key()->get_testa();
		while(iter1)
		{
			numero_studenti++;
			iter1 = iter1->get_succ();
		}
		cout <<"(" << numero_studenti << " Studenti)" << endl;
		iter1 = iter->get_key()->get_testa();
		while(iter1)
		{
			media_parz += iter1->get_mediavoti();
			cout << iter1->get_matricola() << ": ";
			cout << iter1->get_cognome() << ", ";
			cout << iter1->get_mediavoti() << "." << endl;
			iter1 = iter1->get_succ();
		}
		media_tot = media_parz/numero_studenti;
		cout << "Media voti del gruppo: " << media_tot << "." << endl;
		cout << endl;
		numero_studenti = 0;
		media_parz = 0.0;
		media_tot = 0.0;
		i++;
		iter = iter->get_succ();
	}
}

int main()
{
	Lista_Studenti* A = new Lista_Studenti();
	Lista_Studenti* B = new Lista_Studenti();
	Listone* C = new Listone();
	
	ifstream ifile("Studenti.txt");
	while(!ifile.eof())
		opera(ifile,A,B);
	
	estrai(A,B,C);
	print_gruppi(C);
	
	return 0;
}


