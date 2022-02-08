#ifndef classe_hpp
#define classe_hpp
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>

using namespace std ;

class point
{
    public:
    double x,y;
    point(double xi=0.,double yi=0.) :x(xi),y(yi){}  
};

ostream& operator<<(ostream& os,const point& P);
double Distance(const point& P1, const point& P2);

class segment
{
    public:
    point P1, P2;
    segment(const point& P1, const point& P2);

};
double produit_scalaire(const segment& S1,const segment& S2);
double norme(const segment& S1);

class arete
{
    public :
    segment aret;
    double length_arete;
    arete(const segment& S,const double& Len):aret(S),length_arete(Len){};

};
class arc
{
    public :
    segment edge;
    double length_arc;
    arc(const segment& S,const double& Len):edge(S),length_arc(Len){};

};
ostream& operator<<(ostream& os,const arc& A);
class obstacle
{	
	public:
    int nbsom;
    vector<point> sommets;
    obstacle();
    obstacle(int ns,point * L); /*: n bsom(0){sommets=new point[ns];}*/
    obstacle(const obstacle& Ob);
    ~obstacle();
    obstacle& operator=(const obstacle& Ob);
    obstacle& operator+=(point& P);
};
ostream& operator<<(ostream& os,const obstacle& Ob);
#endif
