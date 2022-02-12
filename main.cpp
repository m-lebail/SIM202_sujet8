#include <iostream>
#include "classe.hpp"

int main()
{
	char* nom_fichier = (char*)"obs.txt"; 

	vector <obstacle> obstacles;
	
	obstacles = reading(nom_fichier);

	//Affichage de la lecture
	for (auto iti = obstacles.begin(); iti != obstacles.end();++iti){
		if (iti == obstacles.begin()){
			cout << "Debut " << iti->sommets.begin()->x <<" "<< iti->sommets.begin()->y << endl;
  			cout << "Fin " << ++iti->sommets.begin()->x <<" " << ++iti->sommets.begin()->y << endl;
			}
			else {
				cout << "Nouvel obstacle " << endl;
				cout << *iti;
			}
		}
	//obstacle G(O);
	//printf("La distance entre les points est de :%lf",a);
	//printf("\n");
	//printf("La norme du segement est :%lf",b);
	//affichage(O);
	//arc A(S1,b);
	//cout << A;
	//printf("La norme du segement est :%lf\n",b);
	
	//affichage(G);
	//printf("P1.x vaut:%lf\n ",P1.x);
}