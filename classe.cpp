#include <cstdlib>
#include <cmath>
#include "classe.hpp"

double Distance(const point& P1, const point& P2)
{
    double distance;
    distance=(P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y);
    distance=sqrt(distance);
    return(distance);
}
segment::segment(const point& P1, const point& P2)
    {
    point * sommets=new point[2];
    sommets[0]=P1;
    sommets[1]=P2;
    }
double produit_scalaire(const segment& S1,const segment& S2)
{
    point P11=S1.P1;
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