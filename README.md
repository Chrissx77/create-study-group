# Programmazione 2
## Appello del 7 luglio 2021
## Progetto 3

## Istruzioni
1. Leggere attentamente la consegna. La consegna è disponibile nel file PDF presente nel repository.
2. Effettuare commit frequenti con commenti sensati.


## Istruzioni `git` da terminale
1. Clonare il repository utilizzando il link accessibile dal tasto "Code" - `git clone [inserire l'url]`
2. Aggiungere i file con `git add [nome dei file da aggiungere]`
3. Fare commit con `git commit -m "[messaggio di commit]"`
4. Fare push con `git push`. **Non utilizzare `origin master` perchè, essendo una classroom, non esiste il `master`**.


## Consegna

Il file 'Comande.txt' contiene le informazioni sugli ordini effettuati in una pizzeria nel seguente formato
```
COGNOME_CLIENTE,PIZZA,QUANTITA,PREZZO_UNITARIO
```
I campi `COGNOME_CLIENTE` e `PIZZA` sono dati di tipo testuale, il campo `QUANTITA` è un intero e il `PREZZO_UNITARIO` è un numero con la virgola.
Cognomi ripetuti vogliono dire che quel cliente ha acquistato più pizze di tipo diverso.


Il candidato scriva un programma in C++ che, utilizzando le opportune strutture dati, sia in grado di:
1. Caricare le informazioni presenti nel file;
2. Raggruppare le ordinazioni per cliente;
3. Cercare tutte le ordinazioni di un dato cliente, stamparle a video e calcolare il totale speso;
4. Eliminare dalle ordinazioni tutti i clienti che hanno speso meno della media;
	- (BONUS) Salvarle su un file;
5. BONUS: Stilare una classifica delle pizze più vendute.

Fornire una funzione `main` che esegua correttamente i metodi richiesti nei punti sopra.


Fornire inoltre un documento sintetico in formato PDF che spieghi le scelte progettuali, motivando le scelte relative alle strutture dati e agli algoritmi utilizzati. 

NB: Il progetto verrà compilato ed eseguito utilizzando il comando `g++`. 

Implementazioni “sofisticate”, o compilazioni gestite da IDE esterni, comporteranno altrettante capacità di utilizzo di g++ da parte dello studente che le propone.
