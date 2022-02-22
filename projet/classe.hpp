#ifndef classe_hpp
#define classe_hpp
#include <iostream>
#include <vector >
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std ;


class Point
{
    public:
    double x,y;
    Point(double xi=0.,double yi=0.) :x(xi),y(yi){}
};
bool operator == (const Point& P1,const Point& P2);
double distance(const Point& P1, const Point& P2);
ostream & operator <<(ostream &, const Point&);

class Segment
{
    public:
    Point P1, P2;
    Segment(const Point& pa=Point(),const Point& pb=Point());

};

bool operator ==(const Segment& , const Segment&);
double produit_scalaire(const Segment& S1,const Segment& S2);
double norme(const Segment& S1);
Segment normale_au_milieu(const Segment& S1);
Segment normale(const Segment& S1);
bool point_segment(const Segment& S,const Point& P,double eps);
bool point_segment1(const Segment& S,const Point& P,double eps);
bool intersection_segment(Segment seg1,Segment seg2,double epsilon);

ostream & operator <<(ostream &, const Segment&);

class arete: public Segment
{

};
/*
class arc: public Segment
{
  public :
    Segment edge;
    double length_arc;
    arc(const Segment& S,const double& Len):edge(S),length_arc(Len){};

};
*/

class Obstacle
{
	public:
    int nbsom;
    vector<Point> sommets;
    //Obstacle();
    Obstacle(int ns,const vector<Point> &obstacle_points); /*: n bsom(0){sommets=new Point[ns];}*/
    Obstacle(const Obstacle& ob);
    ~Obstacle();
    Obstacle& operator=(const Obstacle& ob);
    Obstacle& operator+=(Point& P);
    Obstacle& reset();
    vector<Segment> segments_of_obstacle() const;

};

ostream& operator<<(ostream& os,const Obstacle& ob);

bool intersection_segment(const Segment& seg1,const Segment& seg2, double epsilon,double eps);

int comptage_intersection(const Segment &seg,const Obstacle& obst);

bool intersection_segment_polygon(const Segment& seg,const Obstacle& polygone);


class Arc
{
  public :
    Segment edge;
    double length_arc;
    Arc(const Segment& S=Segment(),double Len=0);

};
ostream& operator<<(ostream& os,const Arc& A);




bool is_arc_valide(const Segment& seg,const vector<Obstacle> & vect_obstacles, int nb_obstacles);


class Graph
{
    public:
    Arc * liste_arcs;
    Point * liste_sommets;
    int nb_arcs;

    Graph(int nb_Obstacles,const vector<Obstacle> & vect_obstacles,const Point& a, const Point& b);
    ~Graph();

};

ostream & operator <<(ostream &, const Graph &);


vector<Obstacle> reading(char* nom_fichier);




#endif
