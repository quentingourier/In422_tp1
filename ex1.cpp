#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	time_t debut;
	time_t fin;		
	int temps;	
	char texte[150]; 
	struct tm * temps_local; 
	clock_t temps_systeme;

	cout << "--- TP 1 EXO 1 ---" << endl;
	cout <<	"Entrez une chaine de caracteres: "; 

	time(&debut); 
	cin >> texte; 
	time(&fin); 
	cout <<"\nVous avez mis "<<fin-debut<<" seconde(s)!"<<endl;

	temps_local=localtime(&fin); 
	cout << "La date d'aujourd'hui est: " << temps_local->tm_mday << "/" << temps_local->tm_mon+1 << "/" << temps_local->tm_year+1900 << endl;
	cout << "L'heure locale est: " << temps_local->tm_hour << ":" << temps_local->tm_min << ":" << temps_local->tm_sec << endl;
	temps_systeme = clock(); 
	cout << "Le programme a dure " << temps_systeme << " microsecondes!" << endl; 
	cout << "\nEntrez une touche pour quitter..." << endl;
	cin>>texte;

	return 0;
}
