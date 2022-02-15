#include <iostream>
#include "classe.hpp"
#include "lecture.hpp"

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
	
}
