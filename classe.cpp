#include <cstdlib>
#include <cmath>
#include "classe.hpp"


void affichage(const point P) 
{
    printf("le point est :(%lf,%lf)\n",P.x,P.y);

}
bool operator == (const point& P1,const point& P2)
{
    if((P1.x==P2.x)&&(P1.y==P2.y))
    {
        return(true);
    }
    return(false);
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
segment normale_au_milieu(const segment& S1)
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
segment normale(const segment& S1)
{
    point P1=S1.P1;
    point P2=S1.P2;
    double x_M=P1.x;
    double y_M=P1.y;
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
    segment S1=segment(S.P1,P);
    double projete=produit_scalaire(S,S1)/(norme(S));
    double x_E=S.P1.x+projete*(S.P2.x-S.P1.x)/norme(S);
    double y_E=S.P1.y+projete*(S.P2.y-S.P1.y)/norme(S);
    point E=point(x_E,y_E);
    affichage(E);
    double d=Distance(E,P);
    printf("d vaut %lf\n",d);
    if(d<=eps)
    {
        double MIN=min(S.P1.x,S.P2.x)-eps;
        double MAX=max(S.P1.x,S.P2.x)+eps;
        if((MIN<=x_E)&&(MAX>=x_E))
        {
            printf("Le point est dans le segment\n");
            return(true);
        }
    }
    printf("Le point n'est pas dans le segment\n");  
    return(false);
}

bool point_segment1(const segment& S,const point& P,double eps)
{
    double a=(S.P1.y-S.P2.y)/(S.P1.x-S.P2.x);
    double b=a*S.P1.x-S.P1.y;
    if((a*P.x+b+eps>=P.y)&(a*P.x+b-eps<=P.y))
        {
        double MIN=min(S.P1.y,S.P2.y)-eps;
        double MAX=max(S.P1.y,S.P2.y)+eps;
        if((MIN<=P.y)&&(MAX>=P.y))
        {
            printf("Le point est dans le segment\n");
            return(true);
        }

         } 
    printf("Le point n'est pas dans le segment\n");  
    return(false);
}
bool intersection_segment(segment seg1,segment seg2, double epsilon)
{
    point point_a = seg1.P1;
    point point_b = seg1.P2;
    point point_p = seg2.P1;
    point point_q = seg2.P2;

    if(  (point_a == point_p) || (point_a == point_q) || (point_b == point_p) || (point_b == point_q) )
    {
        printf("Les deux segments ne s'intersectent pas\n");
        return false;
    }
    if(  abs( produit_scalaire(seg1,seg2) - norme(seg1)*norme(seg2) ) <= epsilon )
    {
        if(point_segment(seg2,point_a,epsilon) || point_segment(seg2,point_b,epsilon) ) //il n'y avait pas d'argument epsilon
        {
            printf("Les deux segments s'intersectent\n");
            return true;
        } else{
            printf("Les deux segments ne s'intersectent pas\n");
            return false;}
    }
    segment segment_ab=segment(point_a,point_b);
    segment segment_pq=segment(point_p,point_q);
    segment normale_ab = normale(segment_ab);
    segment normale_pq = normale(segment_pq);

    segment segment_pa=segment(point_p,point_a);
    segment segment_ap=segment(point_a,point_p);

    double alpha = produit_scalaire(segment_ap,normale_pq) / produit_scalaire(segment_ab,normale_pq);
    double beta = produit_scalaire(segment_pa,normale_ab) / produit_scalaire(segment_pq,normale_ab);
    printf("alpha=%lf\n",alpha);
    printf("beta=%lf\n",beta);

    if( (0 <= alpha) && (alpha <= 1) && (0 <= beta) && (beta <= 1))
    {
        printf("Les deux segments s'intersectent\n");
        return true;
    }
    else
    {
        printf("Les deux segments ne s'intersectent pas\n");
        return false;
    }

}
//=========================================================================
//Obstacle
//=========================================================================
obstacle ::obstacle(int numero,int ns,point * L)
{
    numerobs=numero;
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
    numerobs=Ob.numerobs;
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
        numerobs=Ob.numerobs;
    }
    for(int i=0;i<nbsom;i++) sommets[i]=Ob.sommets[i];
    return *this;
}
segment* obstacle ::liste_segment()
{
    segment* list=new segment[nbsom];
    for(int i=0;i<nbsom-1;i++)
    {
        list[i]=segment(sommets[i],sommets[i+1]);
    } 
    list[nbsom-1]=segment(sommets[nbsom-1],sommets[0]);
    return(list);
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
    int numero=Ob.numerobs;
    point * sommets=Ob.sommets;
    printf("Sur l'obstacle numero:%d il y a  %d sommets\n",numero,nbsom);
    for(int i=0;i<nbsom;i++) {
        printf("le sommet %d est :(%lf,%lf)\n",i,sommets[i].x,sommets[i].y);
    }
}

int comptage_intersection(const segment S, const obstacle Ob)
{
    /*
    double x_M=(P1.x+P2.x)/2;
    double y_M=(P1.y+P2.y)/2;
    point M=point(x_M,y_M);
    double x_M1=2*P1.x-x_M;
    double y_M1=2*P1.y-y_M;
    point M1=point(x_M1,y_M1);
    */
    return(0);
}