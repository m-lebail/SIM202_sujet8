bool intersection_segment(segment seg1,segment seg2)
{
    point_a = seg1.sommet1
    point_b = seg1.sommet2
    point_p = seg2.sommet1
    Point_q = seg2.sommet2

    if(  (point_a == point_p) || (point_a == point_q) || (point_b == point_p) || (point_b == point_q) )
    {
        return false;
    }
    if(  abs( produit_scalaire(seg1,seg2) - norme(seg1)*norme(seg2) ) <= epsilon )
    {
        if(is_on_seg(point_a,seg2) || is_on_seg(point_b,seg2) )
        {
            return true;
        }
        else{return false;}
    }

    normale_ab = normale(point_a,point_b);
    normale_pq = normale(point_p,point_q);

    segment_pa = segment(point_p,point_a);
    segment_ap = segment(point_a,point_p);

    alpha = produit_scalaire(segment_ap,normale_pq) / produit_scalaire(segment_ab,normale_pq);
    beta = produit_scalire(segment_pa,normale_ab) / produit_scalaire(segment_pq,normale_ab);

    if( (0 <= alpha <= 1) && (0 <= beta <= 1))
    {
        return true;
    }
    else
    {
        return false;
    }

}