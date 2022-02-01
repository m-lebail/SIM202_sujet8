#include <cstdlib>
#include <cmath>
#include "classe.hpp"


void affichage(const point P) 
{
    printf("le point est :(%lf,%lf)\n",P.x,P.y);

}

double Distance(const point& P1, const point& P2)
{
    double distance;
    /*
    printf("P1.x :%lf\n",P1.x);
    printf("P2.x :%lf\n",P2.x);
    printf("P1.y :%lf\n",P1.y);
    printf("P2.y :%lf\n",P2.y);
    */
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
    /*
    printf("P11.x :%lf\n",P11.x);
    printf("P11x :%lf\n",P11x);
    printf("v1x: %lf \n",v1x);
    printf("v2x: %lf \n",v2x);
    printf("v1y:%lf \n",v1y);
    printf("v2y:%lf \n",v2y);
    */
    double p=v1x*v2x+v1y*v2y;
    return(p);
}
double norme(const segment& S1)
{
    double N=produit_scalaire(S1,S1);
    N=sqrt(N);
    return(N);
}
segment normale(const segment& S1)
{
    point P1=S1.P1;
    point P2=S1.P2;
    double x_M=(P1.x+P2.x)/2;
    double y_M=(P1.y+P2.y)/2;
    double x_N=P2.y-P1.y+x_M;
    double y_N=P1.x-P2.x+y_M;
    point M=point(x_M,y_M);
    point N=point(x_N,y_N);
    segment A=segment(M,N);
    return(A);
}
void affichage(const segment S)
{
    printf("le premier point du segment est :(%lf,%lf)\n",S.P1.x,S.P1.y);
    printf("le deuxieme point du segment est :(%lf,%lf)\n",S.P2.x,S.P2.y);
}

bool point_segment(const segment& S,const point& P,double eps)
{
    double a=(S.P1.y-S.P2.y)/(S.P1.x-S.P2.x);
    double b=a*S.P1.x-S.P1.y;
    if((a*P.x+b+eps>=P.y)&(a*P.x+b-eps<=P.y))
        {
        double MIN=min(S.P1.y,S.P2.y)-eps;
        double MAX=max(S.P1.y,S.P2.y)+eps;
        if((MIN<=P.y)&(MAX>=P.y))
        {
            printf("Le point est dans le segment\n");
            return(true);
        }

         } 
    printf("Le point n'est pas dans le segment\n");  
    return(false);
}
//=========================================================================
//Obstacle
//=========================================================================
obstacle ::obstacle(int ns,point * L)
{
    nbsom=ns;
    sommets=new point [ns];
    for(int i=0;i<ns;i++)
        {
            sommets[i]=L[i];
            /*
            printf("Etape %d\n",i);
            affichage(L[i]);
            affichage(sommets[i]);
            */
        }

}


obstacle ::obstacle(const obstacle& Ob)
{
    nbsom=Ob.nbsom;
    sommets=0;
    for(int i=0;i<nbsom;i++) sommets[i]=Ob.sommets[i];
}

obstacle::~obstacle()
{
    delete[] sommets;
}
obstacle& obstacle::operator=(const obstacle& Ob)
{
    if (nbsom!=Ob.nbsom)
    {
        delete[] sommets;
        sommets=new point [Ob.nbsom];
        nbsom=Ob.nbsom;
    }
    for(int i=0;i<nbsom;i++) sommets[i]=Ob.sommets[i];
    return *this;
}

void obstacle:: add(const point& P)
{
    nbsom+=1;
    point * sommets1;
    sommets1=new point [nbsom-1];
     for(int i=0;i<nbsom-1;i++)sommets1[i]=sommets[i];
    delete[] sommets;
    sommets=new point [nbsom];
    for(int i=0;i<nbsom-1;i++)sommets[i]=sommets1[i];
    sommets[nbsom-1]=P;
}

void affichage(const obstacle& Ob) 
{
    int nbsom=Ob.nbsom;
    point * sommets=Ob.sommets;
    printf("Il y a  %d sommets\n",nbsom);
    for(int i=0;i<nbsom;i++) {
        printf("le sommet %d est :(%lf,%lf)\n",i,sommets[i].x,sommets[i].y);
    }
}