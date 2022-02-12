#include "lecture.hpp"

vector< obstacle> reading(char* nom_fichier){
	vector <vector <point> > list_obstacles;
	vector <point> Ob;
	ifstream infile(nom_fichier);
	string line;
	string obs("/");
	string comment("%");
	int nb_obs = 0;
	double a,b;
	while(getline(infile,line))
	{
		if (line[0] == obs[0]){
			nb_obs++;
			list_obstacles.push_back(Ob);
			Ob.reset();
			continue;
		}
		if (line[0] == comment[0]){
			continue;
		}
		istringstream iss(line);
		iss >> a >> b;
		point p(a,b);
		Ob+=p;
	}
	list_obstacles.push_back(obstacle);
	infile.close();
	printf("fin lecture \n");

	//Test lecture
	// for (auto iti = list_obstacles.begin(); iti != list_obstacles.end();++iti){
	// 	if (iti == list_obstacles.begin()){
	// 		cout << "Debut " << iti->begin()->x <<" "<< iti->begin()->y << endl;
  	// 		cout << "Fin " << ++iti->begin()->x <<" " << ++iti->begin()->y << endl;
	// 		}
	// 		else {
	// 			cout << "Nouvel obstacle " << endl;
	// 			cout << *iti;
	// 		}
	// 	}
	// }
	return list_obstacles;
}