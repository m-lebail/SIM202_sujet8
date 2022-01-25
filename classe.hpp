#ifndef classe_h
#define classe_h
#include <iostream>
using namespace std ;

class point
{
    public:
    double x,y;
    point(double xi=0.,double yi=0.) :x(xi),y(yi){}  
};
double distance(const point& P1, const point& P2);

class segment
{
    public:
    point P1,P2;
    segment(const point& P1, const point& P2);

};
double produit_scalaire(const segment& S1,const segment& S2);

class arête: public segment
{

};
class arc: public segment
{

};
class obstacle
{
    int nbre_sommets;
    point * sommets;
};
