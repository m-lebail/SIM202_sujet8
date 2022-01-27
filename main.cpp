#include <iostream>
#include "classe.hpp"

int main()
{
	std::cout << "Hello world!" << std::endl;
	point P1=point(1,1);
	point P2=point(1,2);
	point P3=point(2,2);
	double a=Distance(P1,P2);
	segment S1=segment(P1,P2);
	double b=norme(S1);
	obstacle O(3);
	O.add(P1);
	O.add(P2);
	O.add(P3);
	printf("La distance entre les points est de :%lf",a);
	printf("\n");
	printf("La norme du segement est :%lf",b);
	affichage(O);
}