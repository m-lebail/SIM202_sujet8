#ifndef classe_hpp
#define classe_hpp
#include <iostream>
#include <vector >
using namespace std ;


class point
{
    public:
    double x,y;
    point(double xi=0.,double yi=0.) :x(xi),y(yi){}
};
bool operator == (const point& P1,const point& P2);
double distance(const point& P1, const point& P2);

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
/*
class arc: public segment
{
  public :
    segment edge;
    double length_arc;
    arc(const segment& S,const double& Len):edge(S),length_arc(Len){};

};
*/

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
    obstacle& reset();


};

class arc
{
  public :
    segment edge;
    double length_arc;
    arc(const segment& S=segment(),const double& Len=0);

};
ostream& operator<<(ostream& os,const arc& A);


class graph
{
    public:
    arc * liste_arcs;
    point * liste_sommets;
    int nb_arcs;

    graph(int nb_obstacles, vector<obstacle> & vect_obstacles);
    ~graph();

};

ostream & operator <<(ostream &, const graph &);


void affichage(const obstacle& Ob);

bool intersection_segment(segment seg1,segment seg2, double epsilon,double eps);

bool intersection_segment_polygon(segment& seg,obstacle& polygone);

int comptage_intersection(segment &seg,obstacle& obst);

bool is_arc_valide(segment seg, vector<obstacle> & vect_obstacles, int nb_obstacles);

#endif
