
#include "mapa.h"

void alokuj_pamiec_macierz(mapka*m,int wiersze,int kolumny)
{
    m->wiersze=wiersze;
    m->kolumny=kolumny;
    
    m->mapa = (char**) malloc(sizeof(char*) * wiersze);
    for (int i=wiersze-1;i>=0;i--) 
    {
        m->mapa[i] = (char*) malloc(sizeof(char) * kolumny);
        for (int j=0;j< kolumny; j++)
        m->mapa[i][j] = j+1+i;
    }
    
}

void przesun_macierz(mapka *nowa,mapka*m,int dx, int dy)
{   
    for (int i = nowa->wiersze-1; i >= 0; i--)
    {
        for ( int j=0; j < nowa->kolumny; j++) 
        {   
            nowa->mapa[i][j]='.';
        }
    }

    for (int i = m->wiersze-1; i >= 0; i--)
    {
        for ( int j=0; j < m->kolumny; j++) 
        {   
            
            nowa->mapa[i+dy][j+dx]=m->mapa[i][j];
        }

    }
    nowa->p=m->p+dx;
    nowa->q=m->q+dy;
    
}


mapka* nowa_macierz_gora(mapka*m)
{
    mapka *nowa=(mapka*)malloc(sizeof(mapka));
    alokuj_pamiec_macierz(nowa,m->wiersze+N,m->kolumny);
    przesun_macierz(nowa,m,0,0);
    nowa->poczatkowy_x=m->poczatkowy_x;
    nowa->poczatkowy_y=m->poczatkowy_y;
    zwolnij(m);
    
    return nowa;

}

mapka* nowa_macierz_dol(mapka*m)
{
    mapka *nowa=(mapka*)malloc(sizeof(mapka));
    alokuj_pamiec_macierz(nowa,m->wiersze+N,m->kolumny);
    przesun_macierz(nowa,m,0,N);
    nowa->poczatkowy_x=m->poczatkowy_x;
    nowa->poczatkowy_y=m->poczatkowy_y;
    zwolnij(m);
        
    return nowa;

}

mapka* nowa_macierz_prawo(mapka*m)
{
    mapka *nowa=(mapka*)malloc(sizeof(mapka));
    alokuj_pamiec_macierz(nowa,m->wiersze,m->kolumny+N);
    przesun_macierz(nowa,m,0,0);
    nowa->poczatkowy_x=m->poczatkowy_x;
    nowa->poczatkowy_y=m->poczatkowy_y;
    zwolnij(m);
    
    
    return nowa;

}

mapka* nowa_macierz_lewo(mapka*m)
{
    mapka *nowa=(mapka*)malloc(sizeof(mapka));
    alokuj_pamiec_macierz(nowa,m->wiersze,m->kolumny+N);
    przesun_macierz(nowa,m,N,0);
    nowa->poczatkowy_x=m->poczatkowy_x;
    nowa->poczatkowy_y=m->poczatkowy_y;
    zwolnij(m);
    
    return nowa;

}


void wypisz(mapka* x)
{
    int i, j,k;
    k=0;


    for (i = x->wiersze-1; i >= 0; i--)
    {
        if(i==x->wiersze-1)
        {
            printf("    ");
            for(int k = 0; k < x->kolumny; k++)
            {
               printf("%4d",k+1);
            }
            printf("\n");
        }

        for (j=0; j < x->kolumny; j++) 
        {
            if(j==0)
            {
                printf("%4d",i+1);
            }
            printf("%4c", x->mapa[i][j]);
        }
        
        printf("\n");
    }
    
}

void wypisztxt(char*fnazwa,mapka* x)
{
    int i, j;
    FILE*fin=fopen(fnazwa,"w+");
    fprintf(fin,"%d\n%d\n",x->wiersze,x->kolumny);
    for (i = x->wiersze-1; i >= 0; i--)
    {
        for (j=0; j < x->kolumny; j++) 
        {
        fprintf(fin,"%c",x->mapa[i][j]);
        }
        fprintf(fin,"\n");
    }
    fclose(fin);
}

void wczytaj(char*fnazwa,mapka*x)
{
 FILE*fin=fopen(fnazwa,"r+");
    fscanf(fin, "%d%d ", &x->wiersze,&x->kolumny);
    for (int i=x->wiersze-1; i >= 0; i--) {
        for (int j=0; j < x->kolumny; j++) {

            fscanf(fin, "%c ", &x->mapa[i][j]);
        }
    }
 fclose(fin);
}

mapka* ustawienie_poczatkowe(mapka *x)
{   
    x=(mapka*)malloc(sizeof(mapka));
    alokuj_pamiec_macierz(x,N,N);
    x->p=2;
    x->q=2;

    for(int i=N-1;i>=0;i--)
    {
        for(int j=0; j<N;j++)
        x->mapa[i][j]='.';

    }
    return x;
}   


void zwolnij(mapka *x)
{
    int i;
    for (i=0;i<x->wiersze;i++) 
    free( x->mapa[i] );
    free(x->mapa);
    free(x);
}
