#include <cstdlib>
#include <cmath>
#include "classe.hpp"

ostream& operator<<(ostream& os,const point& P){
    os <<"("<< P.x <<","<< P.y <<")" <<endl;
    return os;
}
double Distance(const point& P1, const point& P2)
{
    double distance;
    distance=(P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y);
    distance=sqrt(distance);
    return distance;
}
segment::segment(const point& Pa, const point& Pb)
    {
    P1=Pa;
    P2=Pb;

    }
double produit_scalaire(const segment& S1,const segment& S2)
{
    point P11=S1.P1;
    double P11x=S1.P1.x;
    point P12=S1.P2;
    point P21=S2.P1;
    point P22=S2.P2;

    double v1x=P11.x-P12.x;
    double v1y=P11.y-P12.y;
    double v2x=P21.x-P22.x;
    double v2y=P21.y-P22.y;
    double p=v1x*v2x+v1y*v2y;
    return(p);
}
double norme(const segment& S1)
{
    double N=produit_scalaire(S1,S1);
    N=sqrt(N);
    return(N);
}
//=========================================================================

//=========================================================================
ostream& operator <<(ostream& os,const arc& A){
    os << "("<<A.edge.P1.x << "," << A.edge.P1.y << ")-(" << A.edge.P2.x << "," << A.edge.P2.y << ")" << endl;
    os << "length = " << A.length_arc;
    return os;
}

//=========================================================================
//Obstacle
//=========================================================================
obstacle::obstacle(){
    nbsom = 0;
    sommets = vector<point>(0,point());
}


obstacle ::obstacle(int ns,point * L){
    nbsom = ns;
    for (int i = 0; i < nbsom; i++) sommets.push_back(L[i]);
}


obstacle ::obstacle(const obstacle& Ob)
{
    nbsom=Ob.nbsom;
    sommets=vector<point>(0,point());
    for(auto it = Ob.sommets.begin();it != Ob.sommets.end();++it){
        sommets.push_back(*it);
    }
}

obstacle::~obstacle()
{
    sommets.clear();
}

obstacle& obstacle::operator=(const obstacle& Ob)
{
    if (nbsom!=Ob.nbsom)
    {
        sommets.clear();
        sommets=vector<point>(0,point());
        nbsom=Ob.nbsom;
    }
    for(auto it=Ob.sommets.begin();it != Ob.sommets.end();it++) sommets.push_back(*it);
    return *this;
}
obstacle& obstacle::reset(){
    this->nbsom=0;
    this->sommets.clear();
    return *this;
}


obstacle& obstacle::operator+=(point& P){
    this->nbsom++;
    this->sommets.push_back(P);
    return *this;
}

ostream& operator<<(ostream& os,const obstacle& Ob){
    os << "Nb sommets = "<<Ob.nbsom << endl;
    for (auto it = Ob.sommets.begin(); it != Ob.sommets.end();++it){
        os << *it << endl;
    }
    return os;
}
