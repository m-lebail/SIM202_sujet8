#include <cstdlib>
#include <cmath>
#include <vector >
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
double distance(const point& P1, const point& P2)
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

segment* obstacle ::liste_segment()
{
    segment* liste_arretes=new segment[nbsom];


    for(int i=0;i<nbsom-1;++i){
        liste_arretes[i] = segment(sommets[i],sommets[i+1]);

    }

    liste_arretes[nbsom-1]=segment(sommets[nbsom-1],sommets[0]);
    return(liste_arretes);
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
    double d=distance(E,P);
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

/*
void affichage(const obstacle& Ob)
{
    int nbsom=Ob.nbsom;
    point * sommets=Ob.sommets;
    printf("Il y a  %d sommets\n",nbsom);
    for(int i=0;i<nbsom;i++) {
        printf("le sommet %d est :(%lf,%lf)\n",i,sommets[i].x,sommets[i].y);
    }
}
*/


bool intersection_segment(segment seg1,segment seg2, double epsilon,double eps)
{
    point point_a = seg1.P1;
    point point_b = seg1.P2;
    point point_p = seg2.P1;
    point point_q = seg2.P2;

    if(  (point_a == point_p) || (point_a == point_q) || (point_b == point_p) || (point_b == point_q) )
    {
        return false;
    }
    if(  abs( produit_scalaire(seg1,seg2) - norme(seg1)*norme(seg2) ) <= epsilon )
    {
        if(point_segment(seg2,point_a,epsilon) || point_segment(seg2,point_b,epsilon) ) //il n'y avait pas d'argument epsilon
        {
            return true;
        }
        else{return false;}
    }
    segment segment_ab=segment(point_a,point_b);
    segment segment_pq=segment(point_p,point_q);
    segment normale_ab = normale(segment_ab);
    segment normale_pq = normale(segment_pq);

    segment segment_pa=segment(point_p,point_a);
    segment segment_ap=segment(point_a,point_p);

    double alpha = produit_scalaire(segment_ap,normale_pq) / produit_scalaire(segment_ab,normale_pq);
    double beta = produit_scalaire(segment_pa,normale_ab) / produit_scalaire(segment_pq,normale_ab);

    if( (-eps <= alpha) && (alpha <= 1+eps) && (-eps <= beta) && (beta<= 1+eps))
    {
        printf("alpha = %lf\n",alpha);
        printf("%beta = %lf\n",beta);
        printf("Les deux segments s'intersectent\n");
        return true;
    }
    else
    {
        printf("alpha = %lf\n",alpha);
        printf("%beta = %lf\n",beta);
        printf("Les deux segments ne s'intersectent pas\n");
        return false;
    }

}

int comptage_intersection(segment& seg,obstacle& obst)
{


    point p1 = seg.P1;
    point p2 = seg.P2;
    double x_M = (p1.x+p2.x)/2;
    double y_M = (p1.y+p2.y)/2;
    point M = point(x_M,y_M);
    double x_M1 = x_M + 100;
    point M1 = point(x_M1,y_M);
    segment seg_milieu = segment(M,M1);
    int comptage_intersect = 0;

    for(int i=0;i<obst.nbsom;++i)
    {
        if( intersection_segment(seg_milieu,obst.liste_segment()[i],0.1,0) )
        {
            comptage_intersect++;
        }
    }
    return comptage_intersect;

}

//renvoie true si le segment est valide par rapport à l'obstacle passé en paramètre
bool intersection_segment_polygon(segment& seg, obstacle& polygone)
{
    for(int i=0;i<polygone.nbsom;++i)
    {
        if(intersection_segment(seg,polygone.liste_segment()[i],0.1,0))
        {
            return false;
        }
    }
    int nombre_intersection_projete_milieu = comptage_intersection(seg,polygone);
    if(nombre_intersection_projete_milieu % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

arc::arc(const segment& S,const double& Len)
{
    edge = S;
    length_arc = Len;
}

ostream& operator <<(ostream& os,const arc& A){
    os << "("<<A.edge.P1.x << "," << A.edge.P1.y << ")-(" << A.edge.P2.x << "," << A.edge.P2.y << ")" << endl;
    os << "length = " << A.length_arc;
    return os;
}

bool is_arc_valide(segment seg,vector<obstacle> & vect_obstacles, int nb_obstacles)
{

    vector <obstacle>::iterator its=vect_obstacles.begin();
    for(int i=0;i<nb_obstacles;++i,++its)
    {

        if(!intersection_segment_polygon(seg, *its))
        {
            return false;
        }
    }

    return true;
}

graph::graph(int nb_obstacles ,vector <obstacle> & vect_obstacles)
{
    liste_sommets = new point[100];
    int m = 0;
    int nbr_arcs_crees = 0;

    vector <obstacle>::iterator its=vect_obstacles.begin();

    for(int i=0;i<nb_obstacles;++i,++its)
    {
        auto it = sommets.begin();
        for(auto it = sommets.begin(); it!=sommets.end();++it)
        {
            liste_sommets[m] = its->it;
            m++;
        }
    }


    liste_arcs = new arc[(m*(m-1))/2];
    nb_arcs = (m*(m-1)/2);
    int length_p_k = 0;

    its = vect_obstacles.begin();

    for(int k=0;k<m;++k)
    {
        for(int p=k+1;p<m;++p)
        {
            if(is_arc_valide(segment(liste_sommets[k],liste_sommets[p]),vect_obstacles,nb_obstacles))
            {
                point p_k = liste_sommets[k];
                point p_p = liste_sommets[p];
                length_p_k = distance(p_k,p_p);
            }
            else
            {
                length_p_k = -1;
            }
            liste_arcs[nbr_arcs_crees] = arc(segment(liste_sommets[k],liste_sommets[p]),length_p_k);
            nbr_arcs_crees++;
        }
    }

}


graph::~graph()
{
    if(liste_sommets != 0)  delete [] liste_sommets;
    if(liste_arcs != 0)  delete [] liste_arcs;
}


ostream & operator <<(ostream &os , const graph &g)
{
    os << "affichage de tous les arcs :\n";
    for(int i=0; i<g.nb_arcs ; i++)
    {
       os<< g.liste_arcs[i].edge << " distance : " << g.liste_arcs[i].length_arc << "\n";
    }
    return os ;
}

