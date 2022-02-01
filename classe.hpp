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
bool operator == (const point& P1,const point& P2);
double Distance(const point& P1, const point& P2);

class segment
{
    public:
    point P1, P2;
    segment(const point& P1=point(), const point& P2=point());

};
double produit_scalaire(const segment& S1,const segment& S2);
double norme(const segment& S1);
segment normale_au_milieu(const segment& S1);
segment normale(const segment& S1);
void affichage(const segment S);
bool point_segment(const segment& S,const point& P,double eps);
bool point_segment1(const segment& S,const point& P,double eps);
bool intersection_segment(segment seg1,segment seg2,double epsilon);
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
    obstacle(int ns,point * L); /*: nbsom(0){sommets=new point[ns];}*/
    void add(const point& P);
    obstacle(const obstacle& Ob);
    ~obstacle();
    obstacle& operator=(const obstacle& Ob);
};
void affichage(const obstacle& Ob);
#endif