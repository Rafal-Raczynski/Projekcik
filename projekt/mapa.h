#ifndef eksploracja_h
#define eksploracja_h

#include <stdio.h>
#include <stdlib.h>
#include"cjsonik.h"
#define N 5
typedef struct Mapka
{
    char **mapa;
    stan*gra;
    stanex*graex;
    int p,q,wiersze,kolumny;
    int poczatkowy_x,poczatkowy_y;
    
}mapka;

void alokuj_pamiec_macierz(mapka*m,int wiersze,int kolumny);
void przesun_macierz(mapka *nowa,mapka*m,int dx, int dy);
mapka* nowa_macierz_gora(mapka*m);
mapka* nowa_macierz_prawo(mapka*m);
mapka* nowa_macierz_lewo(mapka*m);
mapka* nowa_macierz_dol(mapka*m);
mapka* nowa_macierz(mapka*m);
void wypisz(mapka* x);
void wypisztxt(char*fnazwa,mapka* x);
void wczytaj(char*fnazwa,mapka*x);
void ustawienie_poczatkowe(mapka *x);
void uzupelnij(mapka*x);
void uzupelnijex(mapka*x);
void zwolnij(mapka *x);

#endif