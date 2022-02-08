#include <iostream>
#include "classe.hpp"

int main()
{
	point P1=point(4,7);
	point P2=point(1,2);
	point P3=point(2,2);
	//double a=Distance(P1,P2);
	//segment S1=segment(P1,P2);
	//printf("P1.x vaut:%lf\n ",P1.x);
	//double b=norme(S1);
	point  LA[3]={P1,P2,P3};
	obstacle P;
	obstacle O(3,LA);
	P+=P1;
	P+=P2;
	P+=P3;
	cout << O;
	cout << P;
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