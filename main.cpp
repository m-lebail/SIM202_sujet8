#include <iostream>
#include "classe.hpp"

int main()
{
	std::cout << "Hello world!" << std::endl;
	point P1=point(0,0);
	point P2=point(1,0);
	point P3=point(1,1);
	point P4=point(0,1);
	point P5=point(2,2);
	//double a=Distance(P1,P2);
	segment S1=segment(P1,P2);
	segment S2=segment(P2,P3);
	segment S3=segment(P3,P4);
	segment S4=segment(P4,P1);

	segment SA=segment(P1,P2);
	affichage(SA);
	//printf("P1.x vaut:%lf\n ",P1.x);
	//double b=norme(S1);
	point  LA[4]={P1,P2,P3,P4};
	obstacle O(1,4,LA);
	affichage(O);
	/*
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
	affichage(S1);
	//point_segment1(S1,P3,0.1);
	point_segment(S1,P3,0.1);
	affichage(S2);
	bool w=intersection_segment(S1,S2,0.1);

	printf("%d\n",w);
	*/
	segment * L=O.liste_segment();
	/*
	for(int i=0;i<4;i++)
	{
		affichage(L[i]);
	}
	*/
	int m=comptage_intersection(SA,O);
	printf("m vaut %d\n",m);
}

//vérifier operator = pour obstacle!