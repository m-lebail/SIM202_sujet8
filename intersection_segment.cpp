bool intersection_segment(segment seg1,segment seg2, double epsilon)
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

    if( (0 <= alpha <= 1) && (0 <= beta <= 1))
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