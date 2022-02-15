#include <iostream>
#include "classe.hpp"
#include <vector>

int main()
{
	std::cout << "Hello world!" << std::endl;
	point P1=point(0,2);
	point P2=point(2,2);
	point P3=point(2,6);
	point P4=point(0,6);
	point P5 =point(4,0);
	point P6 =point(8,0);
	point P7 =point(8,8);
	point P8 = point(4,4);

	//double a=distance(P1,P2);
	segment S1=segment(P4,P5);
	segment S2=segment(P2,P5);
	//int m = 0;
	/*
	printf("P1.x vaut:%lf\n ",P1.x);
	double b=norme(S1);
	point  LA[3]={P1,P2,P3};
	obstacle O(3,LA);
	affichage(O);
	O.add(P1);
	affichage(O);
	O.add(P2);
	O.add(P3);
	//obstacle G(O);
	printf("La distance entre les points est de :%lf",a);
	printf("\n");
	printf("La norme du segement est :%lf\n",b);

	//affichage(G);
	printf("P1.x vaut:%lf\n ",P1.x);
	*/
	//affichage(S1);
	//point_segment1(S1,P3,0.1);
	//point_segment(S1,P3,0.1);
	//affichage(S2);
	//bool b=intersection_segment(S1,S2,0.1,0);
	//printf("%d\n",b);

	point liste_points1[4] = {P1,P2,P3,P4};
	point liste_points2[4] = {P5,P6,P7,P8};


	obstacle test1 = obstacle(4,liste_points1);
	obstacle test2 = obstacle(4,liste_points2);
    affichage(test1);
    affichage(test2);

    /*
    printf("m = %d",m);

    m = comptage_intersection(S1,test1);
    printf("m = %d",m);

    vector<int> test{1,2};
    printf("ca marche toujours\n");

    */
    /*
    obstacle* vect_obstacles = new obstacle[2];
    vect_obstacles[0] = test1;
    vect_obstacles[1] = test2;
    */


    vector <obstacle> vect_obstacle;
    vect_obstacle.push_back(test1);

    //vect_obstacles.push_back(test1);

    printf("ca marche toujours\n");
    //bool valide;



    //valide = is_arc_valide(S2, vect_obstacles,2);
    //printf("valide = %d",valide);

    return 0;

}

