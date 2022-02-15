point* dijkstra(const point& A,const point& B, const graph& G)
{
    point* L=G.liste_sommets;
    //allocation
    matrice = new double * [N];
    for (int i=0; i<N; ++i) {
        matrice [i] = new double [N];
        }
    double l= new double [N];
    int p=new int [N];
    int S[1]={1};
    int T=new int [N-1];
    //initialisation
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<N; ++j) 
        {
            if()
            {
                matrice[i][j]=Distance(L[i],L[j]);
            }else{
                matrice[i][j]=inf; // inf ne marche pas
            }
        }  
    }

    for(int m=0;m<N;++m)
    {
        l[m]=matrice[1][m];
        p[m]=NIL;
    }
    for(int n=1;n<N;n++)
    {
        if (matrice[1][n]!=inf)
        {
            p[n]=1;
        }
    }
    for(int i=0;i<N-1;i++)
    {
        T[i]=i+2;
    }
    //itérations
    int ite=0;
    while(!T.empty())
    {
        ite+=1;
        int indice=1;
        double min=l[1];
        for(int k=0; k<N; ++k)
        {
            if(l[k]<min)
            {
                min=l[k];
                indice=k;
            }
        }
        //retirer k de T et rajouter à S
        for(int h=0,h<N-ite,h++)
        {
            if(l(h)>l(indice)+Distance(indice,h))
            {
                l(h)=l(indice)+Distance(indice,h);
                p(h=1);
            }
        }
    }
    //création de la liste de sommets en parcourant p en partant de B et remontatn prédécesseur par prédecesseur
    point *resultat;

    return(resultat);

}
/*liste des pb de l'algorithme dijkstra:
vecteur avec valeur infini ->comment faire?
comment rajouter et enlever des éléments à S et T?
créer le résultat
comment récupérer les données de la classe graph?

Danger:
Pour la boucle h, ite à la bonne valeur ? 
NIL?

*/
