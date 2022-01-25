#include <iostream>
#include "classe.hpp"

int main()
{
	std::cout << "Hello world!" << std::endl;
	point P1=point(1,1);
	point P2=point(2,2);
	double a=distance(P1,P2);
	printf("%lf",a);

}