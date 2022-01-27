#ifndef classe_hpp
#define classe_hpp
#include <iostream>
using namespace std ;

class point
{
    public:
    double x,y;
    point(double xi=0.,double yi=0.) :x(xi),y(yi){}  
};
double Distance(const point& P1, const point& P2);

class segment
{
    public:
    point P1, P2;
    segment(const point& P1, const point& P2);

};
double produit_scalaire(const segment& S1,const segment& S2);
double norme(const segment& S1);

class arete: public segment
{

};
class arc: public segment
{

};
class obstacle
{	
	public:
    int nbsom;
    point * sommets;
    obstacle(int ns): nbsom(0){sommets=new point[ns];}
    void add(const point& P);
    obstacle(const obstacle& Ob);
    ~obstacle();
    obstacle& operator=(const obstacle& Ob);
};
void affichage(const obstacle& Ob);
#endif