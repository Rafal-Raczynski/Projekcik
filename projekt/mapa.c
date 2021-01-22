
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

int interpretuj_wspolrzedna_x(mapka*a)
{
  int x=(a->gra->current_x)-(a->poczatkowy_x)+(a->p);
  return x;
}

int interpretuj_wspolrzedna_y(mapka*a)
{
    int y=(a->gra->current_y)-(a->poczatkowy_y)+(a->q);
    return y;
}

mapka* nowa_macierz_gora(mapka*m)
{
    mapka *nowa=(mapka*)malloc(sizeof(mapka));
    alokuj_pamiec_macierz(nowa,m->wiersze+N,m->kolumny);
    przesun_macierz(nowa,m,0,0);
    nowa->gra=m->gra;
    nowa->graex=m->graex;
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
    nowa->gra=m->gra;
    nowa->graex=m->graex;
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
    nowa->gra=m->gra;
    nowa->graex=m->graex;
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
    nowa->gra=m->gra;
    nowa->graex=m->graex;
    nowa->poczatkowy_x=m->poczatkowy_x;
    nowa->poczatkowy_y=m->poczatkowy_y;
    zwolnij(m);
    
    return nowa;

}

int czy_pole_jest_na_krancu(mapka* m)
{
    if(m->p==0 || m->q==0 || m->q==m->wiersze-1 || m->p==m->kolumny-1 )
    return 1;
    return 0;
}

void nowa_macierz(mapka*m)
{
    
  if(m->p==0)
  {
    m=nowa_macierz_lewo(m);
  }
  
  if(m->q==0)
  {
    m=nowa_macierz_dol(m);
  }
  
   if(m->q==m->wiersze-1)
  {
    m=nowa_macierz_gora(m);
  }


    if(m->p==m->kolumny-1)
  {
    m=nowa_macierz_prawo(m);
  }

 
}

void wypisz(mapka* x)
{
    int i, j;
    
    for (i = x->wiersze-1; i >= 0; i--)
    {
        for (j=0; j < x->kolumny; j++) 
        {
        
        printf("%c", x->mapa[i][j]);
        }
        
        printf("\n");
    }
    
}

void wypisztxt(char*fnazwa,mapka* x)
{
    int i, j;
    FILE*fin=fopen(fnazwa,"w+");
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
for (int i=x->wiersze-1; i >= 0; i--) {
    for (int j=0; j < x->kolumny; j++) {

        fscanf(fin, "%c ", &x->mapa[i][j]);
    }
}
 fclose(fin);
}

void ustawienie_poczatkowe(mapka *x)
{   
    alokuj_pamiec_macierz(x,5,5);
    x->p=2;
    x->q=2;

    for(int i=5-1;i>=0;i--)
    {
        for(int j=0; j<5;j++)
        x->mapa[i][j]='.';

    }

}   

void uzupelnij(mapka*x)
{
    if(czy_pole_jest_na_krancu(x)==1)
    {
        nowa_macierz(x);
    }
    //printf("%d",x->gra->current_y-x->p)
    if(strcmp(x->gra->field_type,"grass")==0)
    x->mapa[interpretuj_wspolrzedna_y(x)][interpretuj_wspolrzedna_x(x)]='g';
    else
    x->mapa[interpretuj_wspolrzedna_y(x)][interpretuj_wspolrzedna_x(x)]='s';
}

void uzupelnijex(mapka*x)
{
    if(strcmp(x->graex->type1,"grass")==0)
    {
        x->mapa[x->graex->y1][x->graex->x1]='g';
    }
    else if (strcmp(x->graex->type1,"sand")==0)
    {
        x->mapa[x->graex->y1][x->graex->x1]='s';
    }
    else if (strcmp(x->graex->type1,"wall")==0)
    {
        x->mapa[x->graex->y1][x->graex->x1]='w';
    }

    if(strcmp(x->graex->type2,"grass")==0)
    {
        x->mapa[x->graex->y2][x->graex->x2]='g';
    }
    else if (strcmp(x->graex->type2,"sand")==0)
    {
        x->mapa[x->graex->y2][x->graex->x2]='s';
    }
    else if (strcmp(x->graex->type2,"wall")==0)
    {
        x->mapa[x->graex->y2][x->graex->x2]='w';
    }

    if(strcmp(x->graex->type3,"grass")==0)
    {
        x->mapa[x->graex->y3][x->graex->x3]='g';
    }
    else if (strcmp(x->graex->type3,"sand")==0)
    {
        x->mapa[x->graex->y3][x->graex->x3]='s';
    }
    else if (strcmp(x->graex->type3,"wall")==0)
    {
        x->mapa[x->graex->y3][x->graex->x3]='w';
    }



}

void zwolnij(mapka *x)
{
    int i;
     for (i=0;i<x->wiersze;i++) 
        free( x->mapa[i] );
    free(x->mapa);
    free(x);
}


